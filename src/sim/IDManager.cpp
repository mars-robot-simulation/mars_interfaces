#include "IDManager.hpp"

#include <mars_utils/MutexLocker.h>


namespace mars
{
  namespace interfaces
  {
    constexpr unsigned long kMinimalID = 1;

    IDManager::IDManager() : nextID_(kMinimalID) {}

    void IDManager::addIfUnknown(const std::string& name)
    {
        if (isKnown(name))
        {
            return;
        }

        add(name);
    }

    void IDManager::add(const std::string& name)
    {
        if (isKnown(name))
        {
            throw std::logic_error(std::string{"IDManager::add tried adding already known item with name \""} + name + "\"");
        }

        const utils::MutexLocker locker{&mutex_};
        idMap_.left.insert({name, nextID_++});
    }

    void IDManager::removeEntry(const std::string& name)
    {
        if (!isKnown(name))
        {
            throw std::logic_error(std::string{"IDManager::removeEntry tried removing item with unknown name: "} + name);
        }

        const utils::MutexLocker locker{&mutex_};
        idMap_.left.erase(name);
    }

    void IDManager::removeEntry(unsigned long id)
    {
        if (!isKnown(id))
        {
            throw std::logic_error(std::string{"IDManager::removeEntry tried removing item with unknown id: "} + std::to_string(id));
        }

        const utils::MutexLocker locker{&mutex_};
        idMap_.right.erase(id);
    }

    unsigned long IDManager::getID(const std::string& name)
    {
        if (!isKnown(name))
        {
            // TODO: Add info message
            add(name);
        }

        const utils::MutexLocker locker{&mutex_};
        return idMap_.left.at(name);
    }

    std::string IDManager::getName(unsigned long id) const
    {
        if (!isKnown(id))
        {
            throw std::logic_error(std::string{"IDManager::getName tried getting item with unknown id: "} + std::to_string(id));
        }

        const utils::MutexLocker locker{&mutex_};
        return idMap_.right.at(id);
    }

    void IDManager::clear()
    {
        const utils::MutexLocker locker{&mutex_};
        nextID_ = kMinimalID;
        idMap_.clear();
    }

    size_t IDManager::size() const
    {
        const utils::MutexLocker locker{&mutex_};
        return idMap_.size();
    }


    bool IDManager::isKnown(const std::string& name) const
    {
        const utils::MutexLocker locker{&mutex_};
        return idMap_.left.find(name) != idMap_.left.end();
    }

    bool IDManager::isKnown(unsigned long id) const
    {
        const utils::MutexLocker locker{&mutex_};
        return idMap_.right.find(id) != idMap_.right.end();
    }
  }
}

#pragma once

#include <string>

#include <boost/bimap.hpp>
#include <mars_utils/Mutex.h>


namespace mars
{
  namespace interfaces
  {
    // @IDManager manages a bijective mapping from std::string to integer IDs starting at 1
    class IDManager
    {
    public:
      IDManager();
      ~IDManager() = default;

      // -- rule of five --
      IDManager(const IDManager&) = delete;
      void operator=(const IDManager&) = delete;
      IDManager(IDManager&&) = delete;
      void operator=(IDManager&&) = delete;

      bool isKnown(const std::string& name) const;
      bool isKnown(unsigned long id) const;

      unsigned long addIfUnknown(const std::string& name, const unsigned long desiredId = 0);
      unsigned long add(const std::string& name, const unsigned long desiredId = 0);

      void removeEntry(const std::string& name);
      void removeEntry(unsigned long id);

      unsigned long getID(const std::string& name) const;
      std::string getName(unsigned long id) const;

      void clear();
      size_t size() const;

    private:
      mutable utils::Mutex mutex_;
      unsigned long nextID_;
      boost::bimap<std::string, unsigned long> idMap_;
    };
  }
}

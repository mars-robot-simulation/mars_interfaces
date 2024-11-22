#pragma once

#include "../ContactData.hpp"
#include "../ConfigMapInterface.hpp"

#include <string>
#include <memory>
#include <inttypes.h>


namespace mars
{
    namespace core
    {
        class CollisionManager;
    }

    namespace interfaces
    {
        class ContactPluginInterface : public ConfigMapInterface
        {
        public:
            ContactPluginInterface() = default;
            virtual ~ContactPluginInterface() = default;

            const std::string& getFrameID() const { return frameID_; }

            // @priority: If multiple contact plugins affect the same contact, only the one with the highest priority is applied.
            // TODO: Handling the priority is not implemented in mars::core::CollisionManager yet (2024-06-06).
            virtual std::vector<int> priorities() const { return std::vector<int>{0}; }
            // @affects: Returns true, iff the contact plugin affects the given ContactData.
            virtual bool affects(const ContactData& contactData) const = 0;
            // @updateContact: Affect the given ContactData.
            virtual void updateContact(ContactData& contactData) = 0;
            // @reset: Enables resetting the internal state on reset of the simulation.
            virtual void reset() {};

        protected:
            friend class core::CollisionManager;
            void setFrameID(const std::string& frameID) { frameID_ = frameID; }
        private:
            std::string frameID_;
        };

        class ContactPluginInterfaceItem
        {
        public:
            ContactPluginInterfaceItem() = default;
            ContactPluginInterfaceItem(std::shared_ptr<ContactPluginInterface>& cpi, const std::string& pn)
            : contactPluginInterface{cpi}, pluginName{pn} {}
            ContactPluginInterfaceItem(ContactPluginInterfaceItem&& rhs)
            : contactPluginInterface{std::move(rhs.contactPluginInterface)}, pluginName{std::move(rhs.pluginName)} {}
            // Copy Constructor required from envire for creation of SpatioTemporal through ItemPtr creation.
            ContactPluginInterfaceItem(const ContactPluginInterfaceItem&) = default;

            ~ContactPluginInterfaceItem() = default;

            ContactPluginInterfaceItem& operator=(ContactPluginInterfaceItem&& rhs)
            {
                contactPluginInterface = std::move(rhs.contactPluginInterface);
                pluginName = std::move(rhs.pluginName);
                return *this;
            }

            // deleted
            ContactPluginInterfaceItem& operator=(const ContactPluginInterfaceItem&) = delete;

            std::shared_ptr<ContactPluginInterface> contactPluginInterface;
            std::string pluginName;
        };
    } // end namespace interfaces
} // end namespace mars

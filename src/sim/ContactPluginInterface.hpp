#pragma once

#include "../ContactData.hpp"
#include "../ConfigMapInterface.hpp"

#include <string>
#include <memory>
#include <inttypes.h>


namespace mars
{
    namespace interfaces
    {
        class ContactPluginInterface : public ConfigMapInterface
        {
        public:
            ContactPluginInterface() = default;
            virtual ~ContactPluginInterface() = default;

            // @priority: If multiple contact plugins affect the same contact, only the one with the highest priority is applied.
            // TODO: Handling the priority is not implemented in mars::core::CollisionManager yet (2024-06-06).
            virtual uint32_t priority() const { return 0; }
            // @affects: Returns true, iff the contact plugin affects the given ContactData.
            virtual bool affects(const ContactData& contactData) const = 0;
            // @updateContact: Affect the given ContactData.
            virtual void updateContact(ContactData& contactData) const = 0;
        };

        class ContactPluginInterfaceItem
        {
        public:
            std::shared_ptr<ContactPluginInterface> contactPluginInterface;
            std::string pluginName;

            bool operator==(const ContactPluginInterfaceItem& rhs) const
            {
                return contactPluginInterface.get() == rhs.contactPluginInterface.get();
            }
        };
    } // end namespace interfaces
} // end namespace mars
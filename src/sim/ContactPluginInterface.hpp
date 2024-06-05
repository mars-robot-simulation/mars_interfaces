#pragma once

#include "../ContactData.hpp"
#include "../ConfigMapInterface.hpp"

#include <string>
#include <memory>

namespace mars
{
    namespace interfaces
    {
        class ContactPluginInterface : public ConfigMapInterface
        {
        public:
            ContactPluginInterface(const std::string& frameID) : frameID_{frameID} {}
            virtual ~ContactPluginInterface() = default;

            const std::string& getFrameID() const { return frameID_; }
            void setFrameID(const std::string& frameID) { frameID_ = frameID; }

            virtual bool affects(const ContactData& contactData) const = 0;
            virtual void updateContact(ContactData& contactData) const = 0;
        private:
            std::string frameID_;
        };

        class ContactPluginInterfaceItem
        {
        public:
            std::shared_ptr<ContactPluginInterface> contactPluginInterface;
            std::string pluginName;
        };
    } // end namespace interfaces
} // end namespace mars
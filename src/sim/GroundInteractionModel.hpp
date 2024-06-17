#pragma once

#include "../ContactData.hpp"

namespace mars
{
    namespace interfaces
    {
        class ContactPluginInterface;

        class GroundInteractionModel
        {
        public:
            virtual void update(interfaces::ContactData& contactData) = 0;
            virtual void prePhysicsUpdate() = 0;
            virtual void registerUsingContactPlugin(const ContactPluginInterface* const contactPlugin) {}
            virtual void unregisterUsingContactPlugin(const ContactPluginInterface* const contactPlugin) {}
        };
    }
}
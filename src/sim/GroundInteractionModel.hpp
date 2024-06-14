#pragma once

#include "../ContactData.hpp"

namespace mars
{
    namespace interfaces
    {
        class GroundInteractionModel
        {
        public:
            virtual void update(interfaces::ContactData& contactData) = 0;
            virtual void prePhysicsUpdate() = 0;
        };
    }
}
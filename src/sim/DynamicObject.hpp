#pragma once

#include "../ContactData.hpp"
#include "../ConfigMapInterface.hpp"
#include <vector>

namespace mars
{
    namespace interfaces
    {

        /**
         * Interface class for the physical layer.
         *
         */
        class DynamicObject : public ConfigMapInterface
        {
        public:
            // TODO: Add set- and getPose.
            virtual ~DynamicObject() {}
            virtual void getPosition(utils::Vector *pos) const = 0;
            virtual void setPosition(const utils::Vector &pos) = 0;
            virtual void getRotation(utils::Quaternion *q) const = 0;
            virtual void setRotation(const utils::Quaternion &q) = 0;
            virtual void getLinearVelocity(utils::Vector *vel) const = 0;
            virtual void setLinearVelocity(const utils::Vector &vel) = 0;
            virtual void getAngularVelocity(utils::Vector *vel) const = 0;
            virtual void setAngularVelocity(const utils::Vector &vel) = 0;
            virtual void getForce(utils::Vector *f) const = 0;
            virtual void getTorque(utils::Vector *t) const = 0;
            virtual void addContact(const ContactData& contact) = 0;
            virtual const std::string& getName() const = 0;
            virtual void addLinkedFrame(std::shared_ptr<DynamicObject> linked) = 0;
            virtual bool isLinkedFrame(std::shared_ptr<DynamicObject> linked) = 0;
            virtual std::vector<std::shared_ptr<DynamicObject>> getLinkedFrames(void) = 0;
        };

        class DynamicObjectItem
        {
        public:
            std::shared_ptr<DynamicObject> dynamicObject;
            std::string pluginName;
        };

    } // end of namespace interfaces
} // end of namespace mars

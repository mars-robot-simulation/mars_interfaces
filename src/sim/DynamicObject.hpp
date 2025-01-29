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
            virtual ~DynamicObject() {}
            virtual void getPosition(utils::Vector *pos) const = 0;
            virtual void setPosition(const utils::Vector &pos) = 0;
            virtual void getRotation(utils::Quaternion *q) const = 0;
            virtual void setRotation(const utils::Quaternion &q) = 0;
            virtual void getPose(utils::Vector* position, utils::Quaternion* rotation) const = 0;
            virtual void setPose(const utils::Vector& position, const utils::Quaternion& rotation, const bool reset_velocities = false) = 0;
            virtual void getLinearVelocity(utils::Vector *vel) const = 0;
            virtual void setLinearVelocity(const utils::Vector &vel) = 0;
            virtual void getAngularVelocity(utils::Vector *vel) const = 0;
            virtual void setAngularVelocity(const utils::Vector &vel) = 0;
            virtual void getLinearAcceleration(utils::Vector *vel) const = 0;
            virtual void getForce(utils::Vector *f) const = 0;
            virtual void getTorque(utils::Vector *t) const = 0;
            virtual void addForce(const utils::Vector &f, const utils::Vector &p) = 0;
            virtual void addForce(const utils::Vector &f) = 0;
            virtual void addContact(const ContactData& contact) = 0;
            virtual const utils::Vector rotateAtPoint(  const utils::Vector &rotation_point,
                                                        const utils::Quaternion &rotation,
                                                        bool move_group) = 0;
            virtual const std::string& getName() const = 0;
            virtual const utils::Vector& getContactForceVector() const = 0;
            virtual const sReal& getContactForce() const = 0;
            virtual void addLinkedFrame(std::shared_ptr<DynamicObject> linked) = 0;
            virtual bool isLinkedFrame(std::shared_ptr<DynamicObject> linked) = 0;
            virtual std::vector<std::shared_ptr<DynamicObject>> getLinkedFrames(void) = 0;
        };

        class DynamicObjectItem
        {
        public:
            DynamicObjectItem() = default;
            DynamicObjectItem(std::shared_ptr<DynamicObject>&& dynamicObject, const std::string& pluginName)
            : dynamicObject{dynamicObject}, pluginName{pluginName}
            {}

            std::shared_ptr<DynamicObject> dynamicObject;
            std::string pluginName;
        };

    } // end of namespace interfaces
} // end of namespace mars

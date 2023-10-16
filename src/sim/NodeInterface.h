#pragma once

#include "../NodeData.h"
#include "../sensor_bases.h"

#include "PhysicsInterface.h"

namespace mars
{
    namespace interfaces
    {

        /**
         * Interface class for the physical layer.
         *
         */
        class NodeInterface
        {
        public:
            virtual ~NodeInterface() {}
            virtual bool createNode(NodeData *node) = 0;
            virtual void getPosition(utils::Vector *pos) const = 0;
            virtual const utils::Vector setPosition(const utils::Vector &pos, bool move_group) = 0;
            virtual void getRotation(utils::Quaternion *q) const = 0;
            virtual const utils::Quaternion setRotation(const utils::Quaternion &q, bool move_group) =0;
            virtual void getLinearVelocity(utils::Vector *vel) const = 0;
            virtual void getAngularVelocity(utils::Vector *vel) const = 0;
            virtual void getForce(utils::Vector *f) const = 0;
            virtual void getTorque(utils::Vector *t) const = 0;
            virtual void setWorldObject(std::shared_ptr<PhysicsInterface> world) = 0;
            virtual const utils::Vector rotateAtPoint(const utils::Vector &rotation_point,
                                                      const utils::Quaternion &rotation,
                                                      bool move_group) = 0;
            virtual bool changeNode(NodeData *node) = 0;
            virtual void setLinearVelocity(const utils::Vector &velocity) = 0;
            virtual void setAngularVelocity(const utils::Vector &velocity) = 0;
            virtual void setForce(const utils::Vector &f) = 0;
            virtual void setTorque(const utils::Vector &t) = 0;
            virtual void addForce(const utils::Vector &f, const utils::Vector &p) = 0;
            virtual void addForce(const utils::Vector &f) = 0;
            virtual void addTorque(const utils::Vector &t) = 0;
            virtual bool getGroundContact(void) const = 0;
            virtual void getContactPoints(std::vector<utils::Vector> *contact_points) const = 0;
            virtual void getContactIDs(std::list<interfaces::NodeId> *ids) const = 0;
            virtual sReal getGroundContactForce(void) const = 0;
            virtual void setContactParams(contact_params &c_params) = 0;
            virtual void addSensor(BaseSensor *s_cfg) = 0;
            virtual void removeSensor(BaseSensor *s_cfg) = 0;
            virtual void handleSensorData(bool physics_thread = true) = 0;
            virtual void destroyNode(void) = 0;
            virtual void getMass(sReal *mass, sReal *inertia=0) const = 0;
            virtual const utils::Vector getContactForce(void) const = 0;
            virtual sReal getCollisionDepth(void) const = 0;
        };

    } // end of namespace interfaces
} // end of namespace mars

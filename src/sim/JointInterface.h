#pragma once

#include "NodeInterface.h"
#include "../JointData.h" // her is declared the jointStruct
#include "../ConfigMapInterface.hpp"

namespace mars
{
    namespace interfaces
    {

        class JointInterface : public ConfigMapInterface
        {
        public:
            virtual ~JointInterface() {}
            // create the joint using the joint structure given as argument
            /*
              virtual bool createJoint(JointData *joint,
              const std::shared_ptr<NodeInterface> node1, 
              const std::shared_ptr<NodeInterface> i_node2) = 0; // physic interfaces for the node
            */
            virtual void getName(std::string *name) const = 0;
            virtual JointType getType() const = 0;
            virtual void getAnchor(utils::Vector *anchor) const = 0;
            virtual void setAnchor(const utils::Vector &anchor) = 0;
            virtual void setAxis(const utils::Vector &axis) = 0;
            virtual void setAxis2(const utils::Vector &axis) = 0;
            virtual void getAxis(utils::Vector *axis) const = 0;
            virtual void getAxis2(utils::Vector *axis) const = 0;
            virtual void setWorldObject(std::shared_ptr<PhysicsInterface> world) = 0;
            virtual void setForceLimit(sReal max_force) = 0;
            virtual void setForceLimit2(sReal max_force) = 0;
            virtual void setVelocity(sReal velocity) = 0;
            virtual void setVelocity2(sReal velocity) = 0;
            virtual sReal getVelocity(void) const = 0;
            virtual sReal getVelocity2(void) const = 0;
            virtual void setJointAsMotor(int axis) = 0;
            virtual void unsetJointAsMotor(int axis) = 0;
            virtual sReal getPosition(void) const = 0;
            virtual sReal getPosition2(void) const = 0;
            virtual void getForce1(utils::Vector *f) const = 0;
            virtual void getForce2(utils::Vector *f) const = 0;
            virtual void getTorque1(utils::Vector *t) const = 0;
            virtual void getTorque2(utils::Vector *t) const = 0;
            virtual void setTorque(sReal torque) = 0;
            virtual void setTorque2(sReal torque) = 0;
            virtual void reattacheJoint(void) = 0;
            virtual void getAxisTorque(utils::Vector *t) const = 0;
            virtual void getAxis2Torque(utils::Vector *t) const = 0;
            virtual void update(void) = 0;
            virtual void getJointLoad(utils::Vector *t) const = 0;
            virtual void changeStepSize(const JointData &jointS) = 0;
            virtual sReal getMotorTorque(void) const = 0;
            virtual sReal getLowStop() const = 0;
            virtual sReal getHighStop() const = 0;
            virtual sReal getLowStop2() const = 0;
            virtual sReal getHighStop2() const = 0;
            virtual sReal getCFM() const = 0;
            virtual void setLowStop(sReal lowStop) = 0;
            virtual void setHighStop(sReal lowStop) = 0;
            virtual void setLowStop2(sReal lowStop) = 0;
            virtual void setHighStop2(sReal lowStop) = 0;
            virtual void setCFM(sReal cfm) = 0;
            // TODO: Discuss: Should this be called differently?
            virtual void setOfflinePosition(sReal value) = 0;
        };

        class JointInterfaceItem
        {
        public:
            std::shared_ptr<JointInterface> jointInterface;
            std::string pluginName;
        };

    } // end of namespace interfaces
} // end of namespace mars

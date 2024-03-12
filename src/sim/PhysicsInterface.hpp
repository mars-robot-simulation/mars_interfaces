#pragma once

#include "../MARSDefs.h"

#include <mars_utils/Vector.h>
#include <configmaps/ConfigMap.hpp>

#include <memory>
#include <vector>

namespace mars
{

    namespace data_broker
    {
        class DataBrokerInterface;
    }

    namespace interfaces
    {

        class NodeInterface;
        class DynamicObject;
        class JointInterface;

        enum PhysicsError
        {
            PHYSICS_NO_ERROR = 0,
            PHYSICS_DEBUG,
            PHYSICS_ERROR,
            PHYSICS_UNKNOWN,
        };

        class PhysicsInterface
        {

        public:
            sReal ground_friction, ground_cfm, ground_erp;
            sReal step_size; /**< Step size in seconds */
            utils::Vector world_gravity;
            bool fast_step;
            bool draw_contact_points;
            sReal world_cfm, world_erp;

            virtual ~PhysicsInterface() {}
            virtual std::string getLibName() = 0;
            virtual void initTheWorld(void) = 0;
            virtual void freeTheWorld(void) = 0;
            virtual void clearPreviousStep() = 0;
            virtual void stepTheWorld(void) = 0;
            virtual bool existsWorld(void) const = 0;
            virtual const utils::Vector getCenterOfMass(const std::vector<std::shared_ptr<NodeInterface>> &nodes) const = 0;
            virtual std::shared_ptr<DynamicObject> createFrame(data_broker::DataBrokerInterface *dataBroker, configmaps::ConfigMap &config) = 0;
            virtual std::shared_ptr<DynamicObject> getFrame(const std::string &name) = 0;
            virtual void removeFrame(const std::string &name) = 0;

            // todo: replace ODEObject by interface
            virtual void createObject(configmaps::ConfigMap &config) = 0;
            virtual std::shared_ptr<JointInterface> createJoint(data_broker::DataBrokerInterface *dataBroker, configmaps::ConfigMap &config) = 0;
            virtual std::shared_ptr<JointInterface> getJoint(std::string name) = 0;

            virtual void exportWorld() = 0;
        };

        class PhysicsInterfaceItem
        {
        public:
            std::shared_ptr<PhysicsInterface> physicsInterface;
            std::string pluginName;
        };

    } // end of namespace interfaces
} // end of namespace mars

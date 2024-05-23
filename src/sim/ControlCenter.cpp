
#define FORWARD_DECL_ONLY
//#define ROCK
#include "ControlCenter.h"

#include "CollisionInterface.hpp"
#include "PhysicsInterface.hpp"

namespace mars
{

    namespace interfaces
    {
        data_broker::DataBrokerInterface *ControlCenter::theDataBroker = nullptr;
        std::shared_ptr<envire::core::EnvireGraph> ControlCenter::envireGraph = nullptr;
        std::shared_ptr<envire::core::TreeView> ControlCenter::graphTreeView = nullptr;
        std::shared_ptr<CollisionInterface> ControlCenter::collision = nullptr;
        std::shared_ptr<MotorManagerInterface> ControlCenter::motors = nullptr;
        std::shared_ptr<JointManagerInterface> ControlCenter::joints = nullptr;
        std::shared_ptr<SensorManagerInterface> ControlCenter::sensors = nullptr;
        NodeManagerInterface* ControlCenter::nodes = nullptr;

        std::unique_ptr<IDManager> ControlCenter::motorIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::jointIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::linkIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::sensorIDManager = nullptr;

        LoadCenter* ControlCenter::loadCenter = nullptr;

      ControlCenter::ControlCenter() :
            cfg{nullptr},
            controllers{nullptr},
            sim{nullptr},
            graphics{nullptr},
            entities{nullptr},
            dataBroker{nullptr}
        {}

        ControlCenter::~ControlCenter()
        {
            // TODO: Figure out what is left to be deleted. 
            //  E.g. cfg should be freed by releasing the library in the destructor of Simulator
            //  and ControlCenter will be destructed AFTER sim WAS destructed.
            if (nodes)
            {
                delete nodes;
                nodes = nullptr;
            }
        }

        configmaps::ConfigMap SubControlCenter::getConfigMap() const
        {
            configmaps::ConfigMap result;
            result["prefix"] = getPrefix();
            result["Collision Interface"] = collision->getConfigMap();
            result["Physics Interface"] = physics->getConfigMap();

            return result;
        }

        std::vector<std::string> SubControlCenter::getEditPattern(const std::string& basePath) const
        {
            return std::vector<std::string>{""};
        }

        void SubControlCenter::edit(const std::string& configPath, const std::string& value)
        {}

        SubControlCenter::SubControlCenter() : 
            physics{nullptr},
            collision{nullptr},
            prefix{""}
        {}
    } // end of namespace interfaces
} // end of namespace mars

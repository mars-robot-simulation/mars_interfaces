
#define FORWARD_DECL_ONLY
//#define ROCK
#include "ControlCenter.h"

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

        std::unique_ptr<IDManager> ControlCenter::motorIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::jointIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::linkIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::sensorIDManager = nullptr;

        ControlCenter::ControlCenter() : 
            cfg{nullptr},
            nodes{nullptr},
            controllers{nullptr},
            sensors{nullptr},
            sim{nullptr},
            graphics{nullptr},
            entities{nullptr},
            loadCenter{nullptr},
            dataBroker{nullptr}
        {}

        ControlCenter::~ControlCenter()
        {
            // TODO: Figure out what is left to be deleted. 
            //  E.g. cfg should be freed by releasing the library in the destructor of Simulator
            //  and ControlCenter will be destructed AFTER sim WAS destructed.
        }

        configmaps::ConfigMap SubControlCenter::getConfigMap() const
        {
            configmaps::ConfigMap result;
            result["prefix"] = getPrefix();

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

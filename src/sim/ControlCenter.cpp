
#define FORWARD_DECL_ONLY
//#define ROCK
#include "ControlCenter.h"

namespace mars
{

    namespace interfaces
    {
        data_broker::DataBrokerInterface *ControlCenter::theDataBroker = NULL;
        std::shared_ptr<envire::core::EnvireGraph> ControlCenter::envireGraph = nullptr;
        std::shared_ptr<envire::core::TreeView> ControlCenter::graphTreeView = nullptr;
        std::shared_ptr<CollisionInterface> ControlCenter::collision = nullptr;
        std::shared_ptr<MotorManagerInterface> ControlCenter::motors = nullptr;
        std::shared_ptr<JointManagerInterface> ControlCenter::joints = nullptr;

        std::unique_ptr<IDManager> ControlCenter::jointIDManager = nullptr;
        std::unique_ptr<IDManager> ControlCenter::linkIDManager = nullptr;

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
    } // end of namespace interfaces
} // end of namespace mars

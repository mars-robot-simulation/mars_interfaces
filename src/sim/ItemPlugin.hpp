#pragma once

#include <configmaps/ConfigData.h>

#include <lib_manager/LibInterface.hpp>
#include <lib_manager/LibManager.hpp>

#include <string>
#include <memory>

namespace envire
{
    namespace core
    {
        class EnvireGraph;
        class TreeView;
    }
}

namespace mars
{
    namespace interfaces
    {

        class ItemPlugin : public lib_manager::LibInterface

        {

        public:

            ItemPlugin(lib_manager::LibManager *theManager,
                       std::string libName) : LibInterface(theManager), libName(libName)
            {
                if(libManager)
                {
                    libManager->acquireLibrary(libName);
                }
            }

            virtual ~ItemPlugin()
            {
                if(libManager)
                {
                    libManager->releaseLibrary(libName);
                }
            }

            virtual void initPlugin(std::shared_ptr<envire::core::EnvireGraph> graph,
                                    std::shared_ptr<envire::core::TreeView> tree,
                                    std::string frameId,
                                    configmaps::ConfigMap config) {};

            const std::string getLibName() const {return libName;}

        private:
            std::string libName;
        };

        class ItemPluginItem
        {
        public:
            ItemPluginItem() = default;
            ItemPluginItem(std::shared_ptr<ItemPlugin>& itemPlugin, const std::string& libName)
            : itemPlugin{itemPlugin}, libName{libName}
            {}

            std::shared_ptr<ItemPlugin> itemPlugin;
            std::string libName;
        };
    } // end of namespace interfaces
} // end of namespace mars

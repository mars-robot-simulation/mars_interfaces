#pragma once

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
                libManager->acquireLibrary(libName);
            }

            virtual ~ItemPlugin()
            {
                libManager->releaseLibrary(libName);
            }

            virtual void initPlugin(std::shared_ptr<envire::core::EnvireGraph> graph,
                                    std::shared_ptr<envire::core::TreeView> tree,
                                    std::string frame) {};

            std::string getLibName() {return libName;}

        private:
            std::string libName;
        };

        class ItemPluginItem
        {
        public:
            ItemPluginItem() = default;
            ItemPluginItem(std::shared_ptr<ItemPlugin>&& itemPlugin, const std::string& libName)
            : itemPlugin{itemPlugin}, libName{libName}
            {}

            std::shared_ptr<ItemPlugin> itemPlugin;
            std::string libName;
        };
    } // end of namespace interfaces
} // end of namespace mars

#ifdef PLUGIN_WITH_MARS_GUI
#include "MarsPluginTemplateGUI.h"
#else

#pragma once

#include "ControlCenter.h"
#include "../MARSDefs.h"
#include "PluginInterface.h"
#include "SimulatorInterface.h"

#include <lib_manager/LibInterface.hpp>
#include <cfg_manager/CFGManagerInterface.h>

#include <string>

namespace mars
{
    namespace interfaces
    {

        class MarsPluginTemplate : public lib_manager::LibInterface,
                                   public PluginInterface
        {

        public:

            MarsPluginTemplate(lib_manager::LibManager *theManager, std::string libName) :
                LibInterface(theManager), PluginInterface(nullptr), mars(nullptr)
            {

                lib_manager::LibInterface *lib;
                lib = libManager->getLibrary("mars_core");
                if(lib)
                {
                    if( (mars = dynamic_cast<SimulatorInterface*>(lib)) )
                    {
                        control = mars->getControlCenter();
                        newPlugin.name = libName;
                        newPlugin.p_interface = dynamic_cast<PluginInterface*>(this);
                        newPlugin.p_destroy = 0;
                        newPlugin.timer = newPlugin.timer_gui = 0;
                        newPlugin.t_count = newPlugin.t_count_gui = 0;

                        if(control->cfg)
                        {
                            resourcesPath = control->cfg->getOrCreateProperty("Preferences",
                                                                              "resources_path",
                                                                              "").sValue;

                            configPath = control->cfg->getOrCreateProperty("Config",
                                                                           "config_path",
                                                                           ".").sValue;
                        }
                    }
                }

                // this part should be the last line of the contructor
                // we can get a timing problem if mars want to use the
                // plugin before the contructor is finished -> so the last part here
                // is to register the plugin to mars
                if(mars) mars->addPlugin(newPlugin);
            }

            ~MarsPluginTemplate()
            {
                if(mars)
                {
                    mars->removePlugin(newPlugin.p_interface);
                    libManager->releaseLibrary("mars_core");
                }
            }

        private:
            SimulatorInterface *mars;
            pluginStruct newPlugin;

        protected:
            std::string configPath;
            std::string resourcesPath;
        };

    } // end of namespace interfaces
} // end of namespace mars

#endif

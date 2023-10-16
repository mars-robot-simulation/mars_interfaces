#pragma once

#include "ControlCenter.h"
#include "../MARSDefs.h"
#include "PluginInterface.h"
#include "SimulatorInterface.h"

#include <lib_manager/LibInterface.hpp>
#include <cfg_manager/CFGManagerInterface.h>

#include <string>

#include <main_gui/GuiInterface.h>

namespace mars
{
    namespace interfaces
    {

        class MarsPluginTemplateGUI : public lib_manager::LibInterface,
                                      public PluginInterface
        {

        public:

            MarsPluginTemplateGUI(lib_manager::LibManager *theManager, std::string libName) :
                LibInterface(theManager), PluginInterface(NULL), mars(NULL)
            {

                lib_manager::LibInterface *lib;
                lib = libManager->getLibrary("mars_core");
                pluginStruct newplugin;
                if(lib)
                {
                    if( (mars = dynamic_cast<SimulatorInterface*>(lib)) )
                    {
                        control = mars->getControlCenter();
                        newplugin.name = libName;
                        newplugin.p_interface = dynamic_cast<PluginInterface*>(this);
                        newplugin.p_destroy = 0;
                        newplugin.timer = newplugin.timer_gui = 0;
                        newplugin.t_count = newplugin.t_count_gui = 0;

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

                gui = libManager->getLibraryAs<main_gui::GuiInterface>("main_gui");
                // this part should be the last line of the contructor
                // we can get a timing problem if mars want to use the
                // plugin before the contructor is finished -> so the last part here
                // is to register the plugin to mars
                if(mars)
                {
                    mars->addPlugin(newplugin);
                }
            }

            ~MarsPluginTemplateGUI()
            {
                if(mars) libManager->releaseLibrary("mars_core");
                if(gui) libManager->releaseLibrary("main_gui");
            }

        private:
            SimulatorInterface *mars;

        protected:
            std::string configPath;
            std::string resourcesPath;
            main_gui::GuiInterface *gui;
        };

    } // end of namespace interfaces
} // end of namespace mars


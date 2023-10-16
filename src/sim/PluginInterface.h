
#pragma once

#include <mars_interfaces/MARSDefs.h> // for sReal

#include <string>

namespace mars
{
    namespace interfaces
    {

        class ControlCenter;

        /**
         * The interface to load plugin dynamically into the simulation
         *
         */
        class PluginInterface
        {
        public:
            PluginInterface(ControlCenter *control)
            {
                this->control = control;
            }
            virtual ~PluginInterface(void) {}
            virtual void update(sReal time_ms) = 0;
            virtual void reset(void) = 0;
            virtual void init(void) = 0;
            virtual void handleError(void) {};
            virtual void getSomeData(void* data) {(void)data;};
            virtual void preStepChecks(void){};

        protected:
            ControlCenter *control;

        };

        typedef void *pDestroyPlugin(PluginInterface *sp);
        typedef PluginInterface* create_plugin(ControlCenter *control);

        struct pluginStruct
        {
            std::string name;
            PluginInterface *p_interface;
            pDestroyPlugin *p_destroy;
            double timer, timer_gui;
            int t_count, t_count_gui;
        };

        void destroy_plugin(PluginInterface *sp);

    } // end of namespace interfaces
} // end of namespace mars


#pragma once

#include "../sim_common.h"

#include <list>

namespace mars
{
    namespace interfaces
    {

        /**
         * The Interface to load controller dynamically into the simulation
         *
         */
        class ControllerInterface
        {
        public:
            ControllerInterface(void) {};
            virtual ~ControllerInterface(void) {};
            virtual void update(sReal time_ms, sReal *sensors,
                                sReal *motors, int *flags, char **other) = 0;
            virtual void handleError(void) {}
            virtual std::list<sReal> getSensorValues(void) = 0;
        };

        typedef ControllerInterface* create_controller(void);
        typedef void destroy_controller(ControllerInterface*);

    } // end of namespace interfaces
} // end of namespace mars

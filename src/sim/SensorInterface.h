#pragma once

#include "ControlCenter.h"
#include "../sensor_bases.h"

namespace mars
{
    namespace interfaces
    {

        class SensorInterface
        {
        public:
            SensorInterface(ControlCenter *center):
                control(center) {}
            virtual ~SensorInterface() {}

        protected:
            ControlCenter *control;

        };

    } // end of namespace interfaces
} // end of namespace mars

#pragma once

#include "MARSDefs.h"

namespace mars
{
    namespace interfaces
    {

        struct camera_sensor_config
        {
            explicit camera_sensor_config()
            {
                depthImage = false;
            };
            int image_width;
            int image_height;
            sReal offset;
            bool depthImage;
        }; // end of struct camera_sensor_config

    } // end of namespace interfaces
} // end of namespace mars

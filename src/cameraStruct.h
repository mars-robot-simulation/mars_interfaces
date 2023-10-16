#pragma once

#include <mars_utils/Vector.h>
#include <mars_utils/Quaternion.h>

namespace mars
{

    namespace interfaces
    {

        /**
         * this struct seems to be used to get information about a camera
         * which can be accessed through the sensor interface.
         */
        struct cameraStruct
        {
            utils::Vector pos;
            utils::Quaternion rot; //rotation

            /**
             * camera intrinsic parameters
             * As defined in http://opencv.willowgarage.com/documentation/camera_calibration_and_3d_reconstruction.html
             *
             * u = scale_x * x + center_x
             * v = scale_y * y + center_y
             *
             * where u, v are pixel coordinates and x, y scene coordinates
             */
            double center_x, center_y;
            double scale_x, scale_y;
        }; // end of struct cameraStruct


    } // end of namespace interfaces

} // end of namespace mars

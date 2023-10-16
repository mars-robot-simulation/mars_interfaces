#pragma once

#include "MARSDefs.h"
#include <mars_utils/Vector.h>

namespace mars
{
    namespace interfaces
    {

        struct contact_params
        {
            void setZero()
            {
                max_num_contacts = 4;
                erp = 0.1;
                cfm = 0.00000001;
                friction1 = 0.8;
                friction2 = 0.8;
                friction_direction1 = 0;
                motion1 = motion2 = 0;
                fds1 = fds2 = 0;
                bounce = bounce_vel = 0;
                approx_pyramid = 1;
                coll_bitmask = 65535;
                depth_correction = 0.0;
                rolling_friction = 0.0;
                rolling_friction2 = 0.0;
                spinning_friction = 0.0;
            }

            contact_params()
            {
                setZero();
            }

            int max_num_contacts;
            sReal erp, cfm;
            sReal friction1, friction2;
            utils::Vector *friction_direction1;
            sReal motion1, motion2;
            sReal fds1, fds2;
            sReal bounce, bounce_vel;
            bool approx_pyramid;
            int coll_bitmask;
            sReal depth_correction;
            sReal rolling_friction, rolling_friction2, spinning_friction;
        }; // end of struct contact_params

    } // end of namespace interfaces
} // end of namespace mars

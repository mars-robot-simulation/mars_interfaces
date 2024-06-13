#pragma once

#include "MARSDefs.h"
#include <mars_utils/Vector.h>

namespace mars
{
    namespace interfaces
    {
        enum ContactMaterial
        {
            kUnknown = 0,
            kSand = 10,
            kGravel = 20,
            kExtrusive = 30,
            kConcrete = 40,
            kWood = 50
        };

        struct contact_params
        {
            void setZero()
            {
                *this = contact_params{};
            }

            contact_params() :
                max_num_contacts{4},
                erp{1e-1},
                cfm{1e-8},
                friction1{0.8},
                friction2{0.8},
                friction_direction1{nullptr},
                motion1{0},
                motion2{0},
                fds1{0},
                fds2{0},
                bounce{0},
                bounce_vel{0},
                approx_pyramid{true},
                coll_bitmask{65535}, // TODO: convert from bit representation
                depth_correction{0.0},
                rolling_friction{0.0},
                rolling_friction2{0.0},
                spinning_friction{0.0}
            {}

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

        // TODO: Change to constexpr with >=C++14
        const contact_params kDefaultContactParameters{};
    } // end of namespace interfaces
} // end of namespace mars

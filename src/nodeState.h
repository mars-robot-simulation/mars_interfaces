#pragma once

#include <mars_utils/Vector.h>

namespace mars
{

    namespace interfaces
    {

        /**
         * \brief A physical state of the node.
         *
         * This struct should include the position, orientation, and velocities of a
         * node. Currently only the linear and angular velocity is used. While the
         * position and orientation is not included.
         * \deprecated A force and a torque of the nodeState is not futher used by
         *             the simulation.
         */
        struct nodeState
        {
            /**
             * The linear velocity of a node.
             */
            utils::Vector l_vel;

            /**
             * The angular velocity of a node.
             */
            utils::Vector a_vel;

            /**
             * The force velocity of a node.
             */
            utils::Vector f;

            /**
             * The torque of a node.
             */
            utils::Vector t;
        }; // end of struct nodeState

    } // end of namespace interfaces

} // end of namespace mars

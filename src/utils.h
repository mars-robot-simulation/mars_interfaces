#pragma once

#include "MARSDefs.h"
#include "sim_common.h"
#include "NodeData.h"


#include <string>

namespace mars {

    namespace interfaces {

        /**\brief get the absolute position of a new node by its relative position */
        void getAbsFromRel(const NodeData &node1, NodeData *node2);
        void getRelFromAbs(const NodeData &node1, NodeData *node2);

        /**\brief Helper function to get type-id from string in scene file.
         * \return the found id or JOINT_TYPE_UNDEFINED on error.
         */
        JointType getJointType(const std::string &text);

        /**\brief Return a string for the joint-type.
         * \return NULL on error.
         */
        const char* getJointTypeString(JointType type);

    } // end of namespace interfaces

} // namespace mars

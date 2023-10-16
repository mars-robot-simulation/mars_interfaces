#pragma once

#include "MARSDefs.h"
#include <mars_utils/Vector.h>
#include <configmaps/ConfigData.h>

#include <string>

namespace mars
{
    namespace interfaces
    {

        // forward declaration
        class LoadCenter;

        /**
         * JointData is a class to exchange joint information between
         * the simulation modules
         */
        class JointData
        {
        public:
            /**
             * @brief default constructor will leave the joint struct
             * initialized with 0 values
             */
            explicit JointData( const std::string& name = "",
                                JointType type = JOINT_TYPE_UNDEFINED,
                                unsigned long node_id1 = 0,
                                unsigned long node_id2 = 0 );

            /**
             * @brief initialize joint struct with zero values.
             *
             * mainly kept for compatibility with ZERO_JOINT_STRUCT macro
             */
            void init( const std::string& name = "",
                       JointType type = JOINT_TYPE_UNDEFINED,
                       unsigned long node_id1 = 0, unsigned long node_id2 = 0 );


            bool fromConfigMap(configmaps::ConfigMap *config, std::string filenamePrefix,
                               LoadCenter *loadCenter = 0);
            void toConfigMap(configmaps::ConfigMap *config,
                             bool skipFilenamePrefix = false);
            void getFilesToSave(std::vector<std::string> *fileList);
            void print();

            configmaps::ConfigMap config;
            std::string name;         // the joints name
            std::string frameID;
            unsigned long index; // index umber of the joint
            JointType type;            // type of the joint in the physic
            unsigned long nodeIndex1; // index of the first node the joint is connected to
            unsigned long nodeIndex2; // index of the second node the joint is connected to
            utils::Vector anchor; // the anchor positino of the joint
            int anchorPos; // the anchor configuration as node1,node2,center or custom
            utils::Vector axis1;  // the first axis rotation, defined through a (0,0,0) point and
            // and the given position
            // 1,0,0 --> the x axis and so on
            utils::Vector axis2;  // the second axis rotation
            // the spring and damping constants
            sReal spring_constant;
            sReal damping_constant;
            sReal lowStopAxis1;
            sReal highStopAxis1;
            sReal damping_const_constraint_axis1;
            sReal spring_const_constraint_axis1;
            sReal lowStopAxis2;
            sReal highStopAxis2;
            sReal damping_const_constraint_axis2;
            sReal spring_const_constraint_axis2;
            sReal angle1_offset;
            sReal angle2_offset;
            bool invertAxis;
        }; // end of struct JointData

    } // end of namespace interfaces
} // end of namespace mars


#include "JointData.h"
#include "utils.h"
#define FORWARD_DECL_ONLY
#include "Logging.hpp"
#include "sim/ControlCenter.h"

#include "sim/LoadCenter.h"
#include <mars_utils/mathUtils.h>

// should add some error handling for ConfigItem::get...()

#define GET_VALUE(str, val, type)                 \
    if((it = config->find(str)) != config->end()) \
        val = it->second

#define GET_OBJECT(str, val, type)                \
    if((it = config->find(str)) != config->end()) \
        type##FromConfigItem(it->second, &val);

#define SET_VALUE(str, val)                     \
    if(val != defaultJoint.val)                 \
        (*config)[str] = val

#define SET_OBJECT(str, val, type)                                      \
    if(1 || val.squaredNorm() - defaultJoint.val.squaredNorm() < 0.0000001) { \
        type##ToConfigItem((*config)[str], &val);                       \
    }

namespace mars
{
    namespace interfaces
    {

        using namespace mars::utils;

        JointData::JointData( const std::string& name, JointType type,
                              unsigned long node_id1,
                              unsigned long node_id2)
        {
            init( name, type, node_id1, node_id2 );
        }

        void JointData::init( const std::string& name, JointType type,
                              unsigned long node_id1,
                              unsigned long node_id2)
        {
            this->name = name;
            index = 0;
            this->type = type;
            nodeIndex1 = node_id1;
            nodeIndex2 = node_id2;
            anchorPos = 0;
            spring_constant = 0;
            damping_constant = 0;
            lowStopAxis1 = 0;
            highStopAxis1 = 0;
            damping_const_constraint_axis1 = 0;
            spring_const_constraint_axis1 = 0;
            lowStopAxis2 = 0;
            highStopAxis2 = 0;
            damping_const_constraint_axis2 = 0;
            spring_const_constraint_axis2 = 0;
            angle1_offset = 0;
            angle2_offset = 0;
            anchor.setZero();
            axis1.setZero();
            axis1.setZero();
            axis2.setZero();
            invertAxis = false;
            frameID = "";
        }

        bool JointData::fromConfigMap(ConfigMap *config,
                                      std::string filenamePrefix,
                                      LoadCenter *loadCenter)
        {
            this->config = *config;
            CPP_UNUSED(filenamePrefix);
            CPP_UNUSED(loadCenter);
            ConfigMap::iterator it;
            unsigned int mapIndex;
            GET_VALUE("mapIndex", mapIndex, UInt);

            name = config->get("name", name);
            if((it = config->find("type")) != config->end())
            {
                type = getJointType((std::string)it->second);
                if(type == JOINT_TYPE_UNDEFINED)
                {
                    LOG_ERROR("JointData: type given is undefined");
                }
            }
            else
            {
                LOG_ERROR("JointData: no type given for joint");
            }
            GET_VALUE("index", index, ULong);
            GET_VALUE("nodeindex1", nodeIndex1, ULong);
            if(!nodeIndex1)
            {
                LOG_ERROR("JointData: no first node attached to joint");
            }
            else if(mapIndex && loadCenter)
            {
                nodeIndex1 = loadCenter->getMappedID(nodeIndex1, MAP_TYPE_NODE,
                                                     mapIndex);
            }

            GET_VALUE("nodeindex2", nodeIndex2, ULong);
            if(mapIndex && loadCenter)
            {
                nodeIndex2 = loadCenter->getMappedID(nodeIndex2, MAP_TYPE_NODE,
                                                     mapIndex);
            }

            { // handle axis 1
                GET_OBJECT("axis1", axis1, vector);
                GET_VALUE("lowStopAxis1", lowStopAxis1, Double);
                GET_VALUE("highStopAxis1", highStopAxis1, Double);
                GET_VALUE("damping_const_constraint_axis1",
                          damping_const_constraint_axis1, Double);
                GET_VALUE("spring_const_constraint_axis1",
                          spring_const_constraint_axis1, Double);
                GET_VALUE("angle1_offset", angle1_offset, Double);
            }

            { // handle axis 2
                GET_OBJECT("axis2", axis2, vector);
                GET_VALUE("lowStopAxis2", lowStopAxis2, Double);
                GET_VALUE("highStopAxis2", highStopAxis2, Double);
                GET_VALUE("damping_const_constraint_axis2",
                          damping_const_constraint_axis2, Double);
                GET_VALUE("spring_const_constraint_axis2",
                          spring_const_constraint_axis2, Double);
                GET_VALUE("angle2_offset", angle2_offset, Double);
            }

            std::string tmpanchorpos = config->get("anchorpos", std::string("1"));
            if(tmpanchorpos == "1" || tmpanchorpos == "node1")
            {
                anchorPos = 1;
            }
            else if(tmpanchorpos == "2" || tmpanchorpos == "node2")
            {
                anchorPos = 2;
            }
            else if(tmpanchorpos == "3" || tmpanchorpos == "center")
            {
                anchorPos = 3;
            }
            else if(tmpanchorpos == "4" || tmpanchorpos == "custom")
            {
                anchorPos = 4;
            }
            GET_OBJECT("anchor", anchor, vector);
            GET_VALUE("invertAxis", invertAxis, Bool);

            return true;
        }

        void JointData::toConfigMap(ConfigMap *config, bool skipFilenamePrefix)
        {
            CPP_UNUSED(skipFilenamePrefix);
            JointData defaultJoint;
            *config = this->config;
            SET_VALUE("name", name);

            {
                std::string tmp = getJointTypeString(type);
                (*config)["type"] = tmp;
            }

            SET_VALUE("index", index);
            SET_VALUE("nodeindex1", nodeIndex1);
            SET_VALUE("nodeindex2", nodeIndex2);

            if(type != 0 && type != 4 && type != 6)
            { // handle axis 1
                SET_OBJECT("axis1", axis1, vector);
                SET_VALUE("lowStopAxis1", lowStopAxis1);
                SET_VALUE("highStopAxis1", highStopAxis1);
                SET_VALUE("damping_const_constraint_axis1",
                          damping_const_constraint_axis1);
                SET_VALUE("spring_const_constraint_axis1",
                          spring_const_constraint_axis1);
                SET_VALUE("angle1_offset", angle1_offset);
            }

            // todo: hande this via utils
            if(type == 2 || type == 5)
            { // handle axis 2
                SET_OBJECT("axis2", axis2, vector);
                SET_VALUE("lowStopAxis2", lowStopAxis2);
                SET_VALUE("highStopAxis2", highStopAxis2);
                SET_VALUE("damping_const_constraint_axis2",
                          damping_const_constraint_axis2);
                SET_VALUE("spring_const_constraint_axis2",
                          spring_const_constraint_axis2);
                SET_VALUE("angle2_offset", angle2_offset);
            }

            if(anchorPos == 1)
            {
                (*config)["anchorpos"] = "node1";
            }
            else if(anchorPos == 2)
            {
                (*config)["anchorpos"] = "node2";
            }
            else if(anchorPos == 3)
            {
                (*config)["anchorpos"] = "center";
            }
            else if(anchorPos == 4)
            {
                (*config)["anchorpos"] = "custom";
            }
            SET_OBJECT("anchor", anchor, vector);
            SET_VALUE("invertAxis", invertAxis);
        }

        void JointData::getFilesToSave(std::vector<std::string> *fileList)
        {
            CPP_UNUSED(fileList);
        }

        void JointData::print()
        {
            std::cout << "name: " <<  name << std::endl;
            std::cout << "index: " <<  index << std::endl;
            std::cout << "type: " <<  type << std::endl;

            std::cout << "nodeIndex1: " <<  nodeIndex1 << std::endl;
            std::cout << "nodeIndex2: " <<  nodeIndex2 << std::endl;

            std::cout << "anchor: " <<  anchor << std::endl;
            std::cout << "anchorPos: " <<  anchorPos << std::endl;

            std::cout << "axis1: " <<  axis1 << std::endl;
            std::cout << "axis2: " <<  axis2 << std::endl;

            std::cout << "spring_constant: " << spring_constant << std::endl;
            std::cout << "damping_constant: " << damping_constant << std::endl;

            std::cout << "lowStopAxis1: " << lowStopAxis1 << std::endl;
            std::cout << "highStopAxis1: " << highStopAxis1 << std::endl;
            std::cout << "damping_const_constraint_axis1: " << damping_const_constraint_axis1 << std::endl;
            std::cout << "spring_const_constraint_axis1: " << spring_const_constraint_axis1 << std::endl;

            std::cout << "lowStopAxis2: " << lowStopAxis2 << std::endl;
            std::cout << "highStopAxis2: " << highStopAxis2 << std::endl;
            std::cout << "damping_const_constraint_axis2: " << damping_const_constraint_axis2 << std::endl;
            std::cout << "spring_const_constraint_axis2: " << spring_const_constraint_axis2 << std::endl;

            std::cout << "angle1_offset: " << angle1_offset << std::endl;
            std::cout << "angle2_offset: " << angle2_offset << std::endl;

            std::cout << "invertAxis: " << invertAxis << std::endl;
        }

    } // end of namespace interfaces
} // end of namespace mars

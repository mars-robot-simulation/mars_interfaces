#include "utils.h"

#include <cstdio>
#include <cmath>
#include <sstream>
#include <iostream>
#include <cassert>

namespace mars
{
    namespace interfaces
    {

        using namespace std;
        using namespace mars::utils;
    
        void getAbsFromRel(const NodeData &node1, NodeData* node2)
        {
            node2->pos = node1.pos + node1.rot * node2->pos;
            node2->rot = node1.rot * node2->rot;
        }

        void getRelFromAbs(const NodeData &node1, NodeData *node2)
        {
            node2->pos = node1.rot.inverse() * (node2->pos-node1.pos);
            node2->rot = node1.rot.inverse()*node2->rot;
        }

        /* keep this in sync with the JointTypes struct. */
        static const char* sJointTypeStrings[NUMBER_OF_JOINT_TYPES] =
        {
            "undefined",
            "hinge",
            "hinge2",
            "slider",
            "ball",
            "universal",
            "fixed",
            "istruct-spine"
        };
    
        const char* getJointTypeString(JointType type)
        {
            if (type >= NUMBER_OF_JOINT_TYPES)
            {
                std::cerr << "getJointTypeString(JointType id): invalid joint type id " << (int)type << std::endl;
                //throw exception here?
          
                return NULL;
            }
            return sJointTypeStrings[type];
        }
    
        JointType getJointType(const std::string& text)
        {
            assert(sizeof(sJointTypeStrings) / sizeof(char*) == NUMBER_OF_JOINT_TYPES);
      
            //keep this in sync with the correct ids (from mars_core/src/MARSDefs.h)
            for (int i = 0; i < NUMBER_OF_JOINT_TYPES; ++i)
            {
                if (text == sJointTypeStrings[i])
                {
                    return (JointType)i;
                }
            }
      
            //this type string might also be the type-id encoded in a decimal string.
            std::istringstream iss(text);
            int numberFromString;
            if ( !(iss >> numberFromString).fail() )
            {
                //conversion to integer was ok but is this a valid type id?
                if (numberFromString > 0 && numberFromString < NUMBER_OF_JOINT_TYPES)
                {
                    //yes, it is.
                    return (JointType)numberFromString;
                }
            }
      
            //string not found and conversion to integer not successful.
            std::cerr << __FILE__": Could not get joint type from string \""
                      << text << "\"." << std::endl;
            return JOINT_TYPE_UNDEFINED;
        }
    
    } // end of namespace interfaces

} // end of namespace mars

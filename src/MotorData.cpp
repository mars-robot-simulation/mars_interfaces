
#include "MotorData.h"
#include "sim/LoadCenter.h"
//#include <initializer_list>

#define GET_VALUE(str, val, type)                                       \
    if((it = config->find(str)) != config->end()) {                     \
        val = it->second;                                               \
    } else if ((it = config->find(legacynames[str])) != config->end()) { \
        val = it->second;                                               \
    }

#define SET_VALUE(str, val)                     \
    if(val != defaultMotor.val)                 \
        (*config)[str] = val

namespace mars
{
    namespace interfaces
    {

        using namespace configmaps;

        std::map<std::string, std::string> MotorData::legacynames = init_legacynames();

//    C++ 11:
//     MotorData::legacynames = {{"maxEffort", "motorMaxForce"},
//        {"maxSpeed", "maximumVelocity"}};

        MotorData::MotorData(const std::string& name, MotorType type)
        {
            init( name, type );
        }

        void MotorData::init(const std::string& name, MotorType type)
        {
            this->name = name;
            this->type = type;
            index = 0;
            jointIndex = 0;
            jointIndex2 = 0;
            axis = 1;
            value = 0;
            maxSpeed = 0;
            maxEffort = 0;
            maxAcceleration = 0;
            p = 0;
            i = 0;
            d = 0;
            maxValue = M_PI;
            minValue = -M_PI;
            minSpeed = 0;
            this->jointName = "";
        }

        bool MotorData::fromConfigMap(ConfigMap *config,
                                      std::string filenamePrefix,
                                      LoadCenter *loadCenter)
        {
            CPP_UNUSED(filenamePrefix);
            CPP_UNUSED(loadCenter);
            ConfigMap::iterator it;
            unsigned int mapIndex;
            GET_VALUE("mapIndex", mapIndex, UInt);

            name = config->get("name", name);
            GET_VALUE("index", index, ULong);
            GET_VALUE("jointIndex", jointIndex, ULong);
            GET_VALUE("jointIndex2", jointIndex2, ULong);
            if(mapIndex && loadCenter)
            {
                if(jointIndex)
                {
                    jointIndex = loadCenter->getMappedID(jointIndex, MAP_TYPE_JOINT,
                                                         mapIndex);
                }
                if(jointIndex2)
                {
                    jointIndex2 = loadCenter->getMappedID(jointIndex2, MAP_TYPE_JOINT,
                                                          mapIndex);
                }
            }

            GET_VALUE("axis", axis, Int);
            GET_VALUE("maxSpeed", maxSpeed, Double);
            GET_VALUE("maxEffort", maxEffort, Double);
            GET_VALUE("maxAcceleration", maxAcceleration, Double);

            std::string tmpmotortype;
            tmpmotortype = config->get("type", tmpmotortype);
            if (tmpmotortype=="1" || tmpmotortype=="PID" || tmpmotortype=="generic_bldc")
            {
                type = MOTOR_TYPE_POSITION;
            } else if (tmpmotortype=="2" || tmpmotortype=="DC" || tmpmotortype=="generic_dc")
            {
                type = MOTOR_TYPE_VELOCITY;
            } else if (tmpmotortype=="7" || tmpmotortype=="direct_torque" ||
                       tmpmotortype=="direct_effort")
            {
                type = MOTOR_TYPE_DIRECT_EFFORT;
            } else if (tmpmotortype=="8" || tmpmotortype=="ff_torque")
            {
                type = MOTOR_TYPE_FF_EFFORT;
            }

            GET_VALUE("p", p, Double);
            GET_VALUE("i", i, Double);
            GET_VALUE("d", d, Double);
            //To avoid "ambiguous overload for ‘operator=’" error.
            if((it = config->find("joint")) != config->end())
            {                         
                jointName = (std::string)((*config)["joint"]);                                   
            }
            GET_VALUE("position", value, Double);
            GET_VALUE("maxPosition", maxValue, Double);
            GET_VALUE("minPosition", minValue, Double);

            this->config = *config;

            return 1;
        }

        void MotorData::toConfigMap(ConfigMap *config, bool skipFilenamePrefix)
        {
            CPP_UNUSED(skipFilenamePrefix);
            MotorData defaultMotor;
            *config = this->config;
            SET_VALUE("name", name);
            SET_VALUE("index", index);
            SET_VALUE("jointIndex", jointIndex);
            SET_VALUE("jointIndex2", jointIndex2);
            SET_VALUE("axis", axis);
            SET_VALUE("maxSpeed", maxSpeed);
            SET_VALUE("maxEffort", maxEffort);

            if(type==2)
            {
                (*config)["type"] = "DC";
            }
            else if (type == 1)
            {
                (*config)["type"] = "PID";
            }
            else if (type == 7)
            {
                (*config)["type"] = "direct_torque";
            }
            else
            {
                (*config)["type"] = type;
            }

            SET_VALUE("p", p);
            SET_VALUE("i", i);
            SET_VALUE("d", d);

            SET_VALUE("position", value);
            SET_VALUE("joint", jointName);
            SET_VALUE("maxPosition", maxValue);
            SET_VALUE("minPosition", minValue);
        }

        void MotorData::getFilesToSave(std::vector<std::string> *fileList)
        {
            CPP_UNUSED(fileList);
        }

    } // end of namespace interfaces
} // end of namespace mars

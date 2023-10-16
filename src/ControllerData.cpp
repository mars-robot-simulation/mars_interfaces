#include "ControllerData.h"
#include "sim/LoadCenter.h"

#define GET_VALUE(str, val, type)                 \
    if((it = config->find(str)) != config->end()) \
        val = it->second


#define SET_VALUE(str, val)                     \
    (*config)[str] = val

namespace mars
{
    namespace interfaces
    {

        using namespace configmaps;

        ControllerData::ControllerData()
        {
            rate = 20;
        }

        bool ControllerData::fromConfigMap(ConfigMap *config,
                                           std::string filenamePrefix,
                                           LoadCenter *loadCenter)
        {
            CPP_UNUSED(filenamePrefix);
            CPP_UNUSED(loadCenter);
            ConfigMap::iterator it;
            std::vector<ConfigItem>::iterator it2;
            unsigned int mapIndex = (*config)["mapIndex"];
            unsigned long _id;

            GET_VALUE("index", id, ULong);
            GET_VALUE("rate", rate, Double);
            dylib_path = config->get("dylib_path", dylib_path);

            if((it = config->find("sensorid")) != config->end())
            {
                ConfigVector _ids = (*config)["sensorid"];
                for(it2=_ids.begin(); it2!=_ids.end(); ++it2)
                {
                    if((_id = *it2))
                    {
                        if(mapIndex)
                        {
                            _id = loadCenter->getMappedID(_id, MAP_TYPE_SENSOR, mapIndex);
                        }
                        sensors.push_back(_id);
                    }
                }
            }

            if((it = config->find("motorid")) != config->end())
            {
                ConfigVector _ids = (*config)["motorid"];
                for(it2=_ids.begin(); it2!=_ids.end(); ++it2)
                {
                    if((_id = *it2))
                    {
                        if(mapIndex)
                        {
                            _id = loadCenter->getMappedID(_id, MAP_TYPE_MOTOR, mapIndex);
                        }
                        motors.push_back(_id);
                    }
                }
            }

            if((it = config->find("nodeid")) != config->end()) {
                ConfigVector _ids = (*config)["nodeid"];
                for(it2=_ids.begin(); it2!=_ids.end(); ++it2) {
                    if((_id = *it2)){
                        if(mapIndex) {
                            _id = loadCenter->getMappedID(_id, MAP_TYPE_NODE, mapIndex);
                        }
                        sNodes.push_back(_id);
                    }
                }
            }

            return true;
        }

        void ControllerData::toConfigMap(ConfigMap *config,
                                         bool skipFilenamePrefix)
        {
            CPP_UNUSED(skipFilenamePrefix);
            std::vector<unsigned long>::iterator it;

            SET_VALUE("index", id);
            SET_VALUE("rate", rate);
            SET_VALUE("dylib_path", dylib_path);

            for(it=sensors.begin(); it!=sensors.end(); ++it)
            {
                (*config)["sensorid"] << *it;
            }
            for(it=motors.begin(); it!=motors.end(); ++it)
            {
                (*config)["motorid"] << *it;
            }
            for(it=sNodes.begin(); it!=sNodes.end(); ++it)
            {
                (*config)["nodeid"] << *it;
            }
        }

        void ControllerData::getFilesToSave(std::vector<std::string> *fileList)
        {

        }

    } // end of namespace interfaces
} // end of namespace mars

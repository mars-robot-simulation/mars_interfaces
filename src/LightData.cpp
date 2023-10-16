
#include "LightData.h"
#include "MARSDefs.h"
#include <mars_utils/mathUtils.h>

#define GET_VALUE(str, val, type)                 \
    if((it = config->find(str)) != config->end()) \
        val = it->second

#define GET_OBJECT(str, val, type)                \
    if((it = config->find(str)) != config->end()) \
        type##FromConfigItem(it->second, &val);

#define SET_VALUE(str, val)                     \
    (*config)[str] = val

#define SET_OBJECT(str, val, type)              \
    type##ToConfigItem((*config)[str], &val);

namespace mars
{
    namespace interfaces
    {

        using namespace mars::utils;
        using namespace configmaps;

        bool LightData::fromConfigMap(ConfigMap *config,
                                      std::string filenamePrefix,
                                      LoadCenter *loadCenter)
        {
            CPP_UNUSED(filenamePrefix);
            CPP_UNUSED(loadCenter);
            ConfigMap::iterator it;
            map = *config;
            name = config->get("name", name);
            GET_OBJECT("position", pos, vector);
            GET_OBJECT("lookat", lookAt, vector);
            if((it = config->find("ambient")) != config->end())
                ambient.fromConfigItem(it->second);
            if((it = config->find("diffuse")) != config->end())
                diffuse.fromConfigItem(it->second);
            if((it = config->find("specular")) != config->end())
                specular.fromConfigItem(it->second);
            GET_VALUE("constantAttenuation", constantAttenuation, Double);
            GET_VALUE("linearAttenuation", linearAttenuation, Double);
            GET_VALUE("quadraticAttenuation", quadraticAttenuation, Double);
            GET_VALUE("type", type, Int);
            GET_VALUE("angle", angle, Double);
            GET_VALUE("exponent", exponent, Double);
            GET_VALUE("directional", directional, Bool);
            node = config->get("nodeName", node);
            drawID = 0;
            return true;
        }

        void LightData::toConfigMap(ConfigMap *config,
                                    bool skipFilenamePrefix)
        {
            CPP_UNUSED(skipFilenamePrefix);
            LightData defaultLight;

            *config = map;
            SET_VALUE("index", index);
            SET_VALUE("name", name);
            SET_OBJECT("position", pos, vector);
            SET_OBJECT("lookat", lookAt, vector);

            if(ambient != defaultLight.ambient)
            {
                ambient.toConfigItem((*config)["ambient"]);
            }

            if(diffuse != defaultLight.diffuse)
            {
                diffuse.toConfigItem((*config)["diffuse"]);
            }

            if(specular != defaultLight.specular)
            {
                specular.toConfigItem((*config)["specular"]);
            }

            SET_VALUE("constantAttenuation", constantAttenuation);
            SET_VALUE("linearAttenuation", linearAttenuation);
            SET_VALUE("quadraticAttenuation", quadraticAttenuation);
            SET_VALUE("type", type);
            SET_VALUE("angle", angle);
            SET_VALUE("exponent", exponent);
            SET_VALUE("directional", directional);
            SET_VALUE("nodeName", node);
        }

        void LightData::getFilesToSave(std::vector<std::string> *fileList)
        {
        }

    } // end of namespace interfaces
} // end of namespace mars

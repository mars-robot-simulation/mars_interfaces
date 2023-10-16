#pragma once

#include <mars_utils/Color.h>
#include <configmaps/ConfigData.h>
#include <mars_utils/Vector.h>

#include <string>

namespace mars
{
    namespace interfaces
    {

        // forward declaration
        class LoadCenter;

        /**
         * LightData is a struct to exchange light information between the
         * Dialog_Add_Light, the MainWindow and the osg widget
         */
        class LightData
        {
        public:
            bool fromConfigMap(configmaps::ConfigMap *config, std::string filenamePrefix,
                               LoadCenter *loadCenter = 0);
            void toConfigMap(configmaps::ConfigMap *config,
                             bool skipFilenamePrefix = false);
            void getFilesToSave(std::vector<std::string> *fileList);

            unsigned int index;
            std::string name; //light name
            utils::Vector pos; //light position
            utils::Vector lookAt; //light direction
            utils::Color ambient; //color of the ambient part of the light
            utils::Color diffuse; //color of the diffuse part of the light
            utils::Color specular; //specular color of the light
            double constantAttenuation;
            double linearAttenuation;
            double quadraticAttenuation;
            int type;
            double angle; //angle of the spot cutoff
            double exponent; //spot exponent
            bool directional; //directional light
            std::string node; // where the light should be attached
            unsigned long drawID;
            configmaps::ConfigMap map;
        }; // end of struct LightData

    } // end of namespace interfaces
} // end of namespace mars

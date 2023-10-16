#pragma once

#include <vector>
#include <string>

#include "MARSDefs.h"
#include <configmaps/ConfigData.h>

namespace mars
{
    namespace interfaces
    {

        // forward declaration
        class LoadCenter;

        class ControllerData
        {
        public:
            ControllerData();

            bool fromConfigMap(configmaps::ConfigMap *config, std::string filenamePrefix,
                               LoadCenter *loadCenter = 0);
            void toConfigMap(configmaps::ConfigMap *config,
                             bool skipFilenamePrefix = false);
            void getFilesToSave(std::vector<std::string> *fileList);

            unsigned long id;
            sReal rate;
            std::vector<unsigned long> motors;
            std::vector<unsigned long> sensors;
            std::vector<unsigned long> sNodes;
            std::string dylib_path;
        }; // end of class ControllerData

    } // end of namespace interfaces
} // end of namespace mars


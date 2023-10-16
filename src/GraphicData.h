#pragma once

#include "MARSDefs.h"
#include <mars_utils/Color.h>
#include <configmaps/ConfigData.h>

namespace mars
{
    namespace interfaces
    {

        // forward declaration
        class LoadCenter;

        class GraphicData
        {
        public:
            GraphicData();

            bool fromConfigMap(configmaps::ConfigMap *config, std::string filenamePrefix,
                               LoadCenter *loadCenter = 0);
            void toConfigMap(configmaps::ConfigMap *config,
                             bool skipFilenamePrefix = false);
            void getFilesToSave(std::vector<std::string> *fileList);

            utils::Color clearColor;
            bool fogEnabled;
            sReal fogDensity;
            sReal fogStart;
            sReal fogEnd;
            utils::Color fogColor;
        };

    } // end of namespace interfaces
} // end of namespace mars

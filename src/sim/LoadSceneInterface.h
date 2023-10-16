
#pragma once

#include <string>

#include <lib_manager/LibInterface.hpp>
#include <mars_utils/Vector.h>

namespace mars
{

    namespace interfaces
    {

        class LoadSceneInterface : public lib_manager::LibInterface
        {
        public:
            LoadSceneInterface(lib_manager::LibManager *theManager) :
                lib_manager::LibInterface(theManager) {}
            virtual ~LoadSceneInterface() {}

            virtual bool loadFile(std::string filename, std::string tmpPath,
                                  std::string robotname) = 0;
            virtual bool loadFile(std::string filename, std::string tmpPath,
                                  std::string robotname, utils::Vector pos, utils::Vector rot) = 0;
            virtual int saveFile(std::string filename, std::string tmpPath) = 0;
        };

    } // end of namespace interfaces
} // end of namespace mars

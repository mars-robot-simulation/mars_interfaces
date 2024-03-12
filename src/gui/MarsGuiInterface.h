#pragma once

#include <lib_manager/LibInterface.hpp>

namespace mars
{
    namespace interfaces
    {

        /**
         * \brief Sets up the main gui of the simulation and handles various generic gui options.
         */
        class MarsGuiInterface : public lib_manager::LibInterface
        {

        public:
            MarsGuiInterface(lib_manager::LibManager *theManager) : lib_manager::LibInterface(theManager) {}
            virtual ~MarsGuiInterface() {}
  
            virtual void setupGui() = 0;
        };

    } // end of namespace interfaces
} // end of namespace mars

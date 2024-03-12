#pragma once

#include <string>

#include <mars_utils/mathUtils.h>

namespace mars
{
    namespace interfaces
    {
        class AbsolutePose
        {
        public:
            std::string frameId;
            utils::Vector position;
            utils::Quaternion rotation;
        };

    } // end of namespace interfaces
} // end of namespace mars

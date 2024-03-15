#pragma once

#include "../ConfigMapInterface.hpp"

#include <string>

#include <mars_utils/mathUtils.h>


namespace mars
{
    namespace interfaces
    {
        class AbsolutePose : public ConfigMapInterface
        {
        public:
            std::string frameId;
            utils::Vector position;
            utils::Quaternion rotation;

            // -- mars::interfaces::ConfigMapInterface --
            virtual configmaps::ConfigMap getConfigMap() const override;
            virtual std::vector<std::string> getEditPattern(const std::string& basePath) const override;
            virtual void edit(const std::string& configPath, const std::string& value) override;
        };

    } // end of namespace interfaces
} // end of namespace mars

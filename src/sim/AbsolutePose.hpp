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

            virtual configmaps::ConfigMap getConfigMap() const override
            {
                configmaps::ConfigMap result;

                configmaps::ConfigItem positionItem;
                mars::utils::vectorToConfigItem(&positionItem, const_cast<utils::Vector*>(&position));
                result["position"] = positionItem;

                configmaps::ConfigItem rotationItem;
                mars::utils::quaternionToConfigItem(&rotationItem, const_cast<utils::Quaternion*>(&rotation));
                result["rotation"] = rotationItem;

                return result;
            }

            virtual std::vector<std::string> getEditPattern(const std::string& basePath) const override
            {
                return std::vector<std::string>{""};
            }

            virtual void edit(const std::string& configPath, const std::string& value) override
            {}
        };

    } // end of namespace interfaces
} // end of namespace mars

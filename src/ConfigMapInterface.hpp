#pragma once

#include <string>
#include <configmaps/ConfigMap.hpp>

namespace mars
{
    namespace interfaces
    {
        class ConfigMapInterface
        {
        public:
            virtual configmaps::ConfigMap getConfigMap() const = 0;
            virtual std::vector<std::string> getEditPattern(const std::string& basePath) const = 0;
            virtual void edit(const std::string& configPath, const std::string& value) = 0;
        };
    } // end namespace interfaces
} // end namespace mars

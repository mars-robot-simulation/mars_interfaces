#include "AbsolutePose.hpp"

namespace mars
{
  namespace interfaces
  {
        configmaps::ConfigMap AbsolutePose::getConfigMap() const
        {
            configmaps::ConfigMap result;
            result["position"] = mars::utils::vectorToConfigItem(position);
            result["rotation"] = mars::utils::quaternionToConfigItem(rotation, true);

            return result;
        }

        std::vector<std::string> AbsolutePose::getEditPattern(const std::string& basePath) const
        {
            return std::vector<std::string>{""};
        }

        void AbsolutePose::edit(const std::string& configPath, const std::string& value)
        {}
    }
} // end of namespace mars

#include "AbsolutePose.hpp"

namespace mars
{
  namespace interfaces
  {
        void AbsolutePose::setPosition(const utils::Vector& position)
        {
            position_ = position;
            if (!initialPosition_.has_value())
            {
                initialPosition_ = position;
            }
        }

        void AbsolutePose::setRotation(const utils::Quaternion& rotation)
        {
            rotation_ = rotation;
            if (!initialRotation_.has_value())
            {
                initialRotation_ = rotation;
            }
        }

        void AbsolutePose::resetPose()
        {
            position_ = *initialPosition_;
            rotation_ = *initialRotation_;
        }

        configmaps::ConfigMap AbsolutePose::getConfigMap() const
        {
            configmaps::ConfigMap result;
            result["position"] = mars::utils::vectorToConfigItem(position_);
            result["rotation"] = mars::utils::quaternionToConfigItem(rotation_, true);

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

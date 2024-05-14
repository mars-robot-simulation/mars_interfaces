#include "AbsolutePose.hpp"

namespace mars
{
    namespace interfaces
    {
        // This currently intentionally does not set the initial pose as usually the initial pose is unknown when AbsolutePose is constructed.
        AbsolutePose::AbsolutePose() : position_{.0, .0, .0}, rotation_{1.0, .0, .0, .0}
        {}

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

        bool AbsolutePose::isInInitialPose(const double eps) const
        {
            assert(initialPosition_.has_value());
            assert(initialRotation_.has_value());

            const bool positionIsInitial = position_.isApprox(*initialPosition_, eps);
            const bool rotationIsInitial = rotation_.coeffs().isApprox(initialRotation_->coeffs(), eps);
            return positionIsInitial && rotationIsInitial;
        }

        base::TransformWithCovariance AbsolutePose::resetPose()
        {
            assert(initialPosition_.has_value());
            assert(initialRotation_.has_value());

            const auto currentPose = base::TransformWithCovariance{position_, rotation_};
            const auto initialPose = base::TransformWithCovariance{*initialPosition_, *initialRotation_};
            position_ = *initialPosition_;
            rotation_ = *initialRotation_;
            return currentPose.inverse() * initialPose;
        }

        configmaps::ConfigMap AbsolutePose::getConfigMap() const
        {
            configmaps::ConfigMap result;
            result["position"] = mars::utils::vectorToConfigItem(position_);
            result["rotation"] = mars::utils::quaternionToConfigItem(rotation_, true);
            if (initialPosition_.has_value())
            {
                result["initial position"] = mars::utils::vectorToConfigItem(*initialPosition_);
            }
            if (initialRotation_.has_value())
            {
                result["initial rotation"] = mars::utils::quaternionToConfigItem(*initialRotation_, true);
            }

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

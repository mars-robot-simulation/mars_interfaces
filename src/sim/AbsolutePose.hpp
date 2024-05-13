#pragma once

#include "../ConfigMapInterface.hpp"

#include <string>
#include <boost/optional.hpp>

#include <mars_utils/mathUtils.h>


namespace mars
{
    namespace interfaces
    {
        class AbsolutePose : public ConfigMapInterface
        {
        public:
            void setPosition(const utils::Vector& position);
            void setRotation(const utils::Quaternion& rotation);
            void setFrameId(const std::string& frameId) { frameId_ = frameId; }
            const utils::Vector& getPosition() const { return position_; }
            const utils::Quaternion& getRotation() const { return rotation_; }
            const std::string& getFrameId() const { return frameId_; }

            void resetPose();

            // -- mars::interfaces::ConfigMapInterface --
            virtual configmaps::ConfigMap getConfigMap() const override;
            virtual std::vector<std::string> getEditPattern(const std::string& basePath) const override;
            virtual void edit(const std::string& configPath, const std::string& value) override;
        private:
            std::string frameId_;
            utils::Vector position_;
            utils::Quaternion rotation_;

            boost::optional<utils::Vector> initialPosition_;
            boost::optional<utils::Quaternion> initialRotation_;
        };

    } // end of namespace interfaces
} // end of namespace mars

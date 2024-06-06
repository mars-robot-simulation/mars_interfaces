#pragma once

#include <memory>

#include "../ConfigMapInterface.hpp"
//Backward compatibility remove this include as soon as possible
#include "../Logging.hpp"

#include "IDManager.hpp"

#ifndef LOG_ERROR
#define LOG_ERROR(...) typedef int Deprication_Error_If_you_need_LOG_XXXX_from_mars_please_include_mars_logging_Logging_hpp[-1]
#define LOG_DEBUG(...) typedef int Deprication_Error_If_you_need_LOG_XXXX_from_mars_please_include_mars_logging_Logging_hpp[-1]
#define LOG_FATAL(...) typedef int Deprication_Error_If_you_need_LOG_XXXX_from_mars_please_include_mars_logging_Logging_hpp[-1]
#define LOG_INFO(...) typedef int Deprication_Error_If_you_need_LOG_XXXX_from_mars_please_include_mars_logging_Logging_hpp[-1]
#define LOG_WARN(...) typedef int Deprication_Error_If_you_need_LOG_XXXX_from_mars_please_include_mars_logging_Logging_hpp[-1]
#endif


// Include stddef for basic defs like NULL
#include <cstddef>

namespace envire
{
    namespace core
    {
        class EnvireGraph;
        class TreeView;
    }
}

namespace mars
{
    namespace cfg_manager
    {
        class CFGManagerInterface;
    }

    namespace data_broker
    {
        class DataBrokerInterface;
    }

    namespace interfaces
    {
        class NodeManagerInterface;
        class JointManagerInterface;
        class MotorManagerInterface;
        class ControllerManagerInterface;
        class SensorManagerInterface;
        class SimulatorInterface;
        class EntityManagerInterface;
        class LoadCenter;
        class GraphicsManagerInterface;
        class CollisionInterface;
        class CollisionHandler;
        class PhysicsInterface;

        class PhysicsInterfaceItem;

 
        class ControlCenter
        {
        public:
            ControlCenter();
            ~ControlCenter();

            ControlCenter(const ControlCenter&) = delete;
            ControlCenter operator=(const ControlCenter&) = delete;
            ControlCenter(ControlCenter&&) = delete;
            ControlCenter operator=(ControlCenter&&) = delete;

            cfg_manager::CFGManagerInterface *cfg;
            ControllerManagerInterface *controllers;
            SimulatorInterface *sim;
            GraphicsManagerInterface *graphics;
            EntityManagerInterface *entities;

            static LoadCenter *loadCenter;
            std::map<std::pair<std::string, std::string>, CollisionHandler*> collisionHandlers;
            static std::shared_ptr<CollisionInterface> collision;

            static data_broker::DataBrokerInterface *theDataBroker;
            static std::shared_ptr<envire::core::EnvireGraph> envireGraph;
            std::shared_ptr<envire::core::EnvireGraph> envireGraph_;
            static std::shared_ptr<envire::core::TreeView> graphTreeView;
            std::shared_ptr<envire::core::TreeView> graphTreeView_;
            static std::shared_ptr<MotorManagerInterface> motors;
            static std::shared_ptr<JointManagerInterface> joints;
            static std::shared_ptr<SensorManagerInterface> sensors;
            static NodeManagerInterface* nodes;

            std::shared_ptr<IDManager> motorIDManager;
            std::shared_ptr<IDManager> jointIDManager;
            std::shared_ptr<IDManager> linkIDManager;
            std::shared_ptr<IDManager> sensorIDManager;

            static std::shared_ptr<IDManager> motorIDManager_;
            static std::shared_ptr<IDManager> jointIDManager_;
            static std::shared_ptr<IDManager> linkIDManager_;
            static std::shared_ptr<IDManager> sensorIDManager_;

            // deprecated
            // use instead ControlCenter::theDataBroker
            data_broker::DataBrokerInterface *dataBroker;
        };

        class SubControlCenter : public ConfigMapInterface
        {
        public:
            SubControlCenter();
            ~SubControlCenter() = default;

            SubControlCenter(const SubControlCenter&) = delete;
            SubControlCenter operator=(const SubControlCenter&) = delete;
            SubControlCenter(SubControlCenter&&) = delete;
            SubControlCenter operator=(SubControlCenter&&) = delete;

            std::shared_ptr<PhysicsInterface> physics;
            std::shared_ptr<CollisionInterface> collision;
            ControlCenter *control;

            void setPrefix(const std::string &prefix)
            {
                this->prefix = prefix;
            }

            void setFrameId(const std::string &frameId)
            {
                this->frameId = frameId;
            }

            const std::string& getPrefix() const
            {
                return prefix;
            }

            const std::string& getFrameId() const
            {
                return frameId;
            }

            // -- mars::interfaces::ConfigMapInterface --
            virtual configmaps::ConfigMap getConfigMap() const override;
            virtual std::vector<std::string> getEditPattern(const std::string& basePath) const override;
            virtual void edit(const std::string& configPath, const std::string& value) override;
        private:
            std::string prefix;
            std::string frameId;
        };
    } // end of namespace interfaces
} // end of namespace mars

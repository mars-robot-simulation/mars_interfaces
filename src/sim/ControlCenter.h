#pragma once

#include <memory>

//Backward compatibility remove this include as soon as possible
#include "../Logging.hpp"

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
    namespace main_gui
    {
        class GuiInterface;
    }

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
        class ControlCenter;
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

        /**
         * The declaration of the ControlCenter.
         *
         */
        class ControlCenter
        {
        public:
            ControlCenter()
            {
                sim = NULL;
                cfg = NULL;
                nodes  = NULL;
                joints = NULL;
                motors = NULL;
                controllers = NULL;
                sensors = NULL;
                graphics = NULL;
                dataBroker = NULL;
                loadCenter = NULL;
                collision = NULL;
                //physics = NULL;
            }

            cfg_manager::CFGManagerInterface *cfg;
            NodeManagerInterface *nodes;
            JointManagerInterface *joints;
            ControllerManagerInterface *controllers;
            SensorManagerInterface *sensors;
            SimulatorInterface *sim;
            GraphicsManagerInterface *graphics;
            EntityManagerInterface *entities;

            LoadCenter *loadCenter;
            std::map<std::pair<std::string, std::string>, CollisionHandler*> collisionHandlers;
            static std::shared_ptr<CollisionInterface> collision;
            // TODO: do we need physic in the main simulation control center?
            //std::shared_ptr<PhysicsInterface> physics;

            static data_broker::DataBrokerInterface *theDataBroker;
            static std::shared_ptr<envire::core::EnvireGraph> envireGraph;
            static std::shared_ptr<envire::core::TreeView> graphTreeView;
            static std::shared_ptr<MotorManagerInterface> motors;


            // deprecated
            // use instead ControlCenter::theDataBroker
            data_broker::DataBrokerInterface *dataBroker;
        };

        class SubControlCenter
        {
        public:
            SubControlCenter()
            {
                physics = nullptr;
                collision = nullptr;
                prefix = "";
            }

            std::shared_ptr<PhysicsInterface> physics;
            std::shared_ptr<CollisionInterface> collision;

            void setPrefix(const std::string &prefix)
            {
                this->prefix = prefix;
                //frameId = "SubWorld::" + prefix;
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
        private:
            std::string prefix;
            std::string frameId;
        };
    } // end of namespace interfaces
} // end of namespace mars

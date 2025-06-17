#pragma once

#include "PhysicsInterface.h"
#include "PluginInterface.h"
#include "../sim_common.h"
#include "../graphics/draw_structs.h"
#include "../LightData.h"
#include <mars_utils/Vector.h>

#include <mars_interfaces/sim/ControlCenter.h>

namespace lib_manager
{
    class LibManager;
}

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

    namespace interfaces
    {

        class SimulatorInterface
        {
        public:

            static SimulatorInterface* getInstance(lib_manager::LibManager *libManager);
            virtual ~SimulatorInterface() {}

            // controlling the simulation
            virtual void runSimulation(bool startThread = true) = 0;
            virtual void step(bool setState = false) = 0;
            virtual void StartSimulation() = 0;
            virtual void StopSimulation() = 0;
            virtual void resetSim(bool resetGraphics=true) = 0;
            virtual bool isSimRunning() const = 0;
            virtual bool startStopTrigger() = 0;
            virtual void singleStep(void) = 0;
            virtual void newWorld(bool clear_all=false) = 0;
            virtual void exitMars(void) = 0;
            virtual void readArguments(int argc, char **argv) = 0;
            virtual ControlCenter* getControlCenter(void) const = 0;

            // simulation contents
            virtual void addLight(LightData light) = 0;
            virtual void connectNodes(unsigned long id1, unsigned long id2) = 0;
            virtual void disconnectNodes(unsigned long id1, unsigned long id2) = 0;
            virtual void connectDynamicObjects(const std::string &name1, const std::string &name2) = 0;
            virtual void disconnectDynamicObjects(const std::string &name1, const std::string &name2) = 0;

            virtual void rescaleEnvironment(sReal x, sReal y, sReal z) = 0;

            // scenes
            virtual int loadScene(const std::string &filename, const std::string &robotname, bool threadsave=false, bool blocking=false) = 0;
            virtual int loadScene(const std::string &filename, bool wasrunning=false,
                                  const std::string &robotname = "", bool threadsave=false, bool blocking=false) = 0;
            virtual int loadScene(const std::string &filename, const std::string &robotname, utils::Vector pos, utils::Vector rot,
                                  bool threadsave=false, bool blocking=false, bool wasrunning=false) = 0;
            virtual int saveScene(const std::string &filename, bool wasrunning) = 0;
            /**make sure the string objects exist during the execution of those functions even if they
             * are running in a different thread; it would probably be better to just copy them instead
             * of using references
             */
            virtual void exportScene() const = 0;
            virtual bool sceneChanged() const = 0;
            virtual void sceneHasChanged(bool reset) = 0;

            //threads
            bool allConcurrencysHandled();
            virtual void setSyncThreads(bool value) = 0;
            virtual void physicsThreadLock(void) = 0;
            virtual void physicsThreadUnlock(void) = 0;

            //physics
            virtual std::shared_ptr<PhysicsInterface> getPhysics(void) const = 0;
            virtual void handleError(PhysicsError error) = 0;
            virtual void setGravity(const utils::Vector &gravity) = 0;
            virtual const utils::Vector& getGravity(void) = 0;
            virtual int checkCollisions(void) = 0;
            virtual bool hasSimFault() const = 0;
            // @getStepSizeS: Returns step size of the physics simulations in seconds.
            virtual interfaces::sReal getStepSizeS() const = 0;

            //graphics
            virtual void finishedDraw(void) = 0;
            virtual void allowDraw(void) = 0;
            virtual bool getAllowDraw(void) = 0;
            virtual bool getSyncGraphics(void) = 0;

            //plugins
            virtual void addPlugin(const pluginStruct& plugin) = 0;
            virtual void removePlugin(PluginInterface *pl) = 0;
            virtual void switchPluginUpdateMode(int mode, PluginInterface *pl) = 0;
            virtual void sendDataToPlugin(int plugin_index, void* data) = 0;

            // access graph
            // TODO: probably it is temporary and will be moved in the extra class
            virtual std::shared_ptr<envire::core::EnvireGraph> getGraph() = 0;
            virtual std::string getRootFrame() = 0;

            virtual std::shared_ptr<SubControlCenter> createSubWorld(const std::string &name) = 0;

            virtual void saveGraph(const std::string &fileName) = 0;


            /*
             *  returns the calculated simulation time + the start timestamp
             */
            virtual unsigned long getTime() = 0;
            virtual sReal getVectorCollision(utils::Vector position, utils::Vector ray) = 0;
            virtual void rotate( std::string origin, double angle, utils::Vector axis) = 0;
            virtual void translate( std::string origin, utils::Vector v) = 0;
        };


    } // end of namespace interfaces
} // end of namespace mars

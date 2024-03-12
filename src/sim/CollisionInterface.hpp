#pragma once

#include "../MARSDefs.h"
#include "../ContactData.hpp"
#include "../ConfigMapInterface.hpp"

#include <mars_utils/Vector.h>
#include <configmaps/ConfigMap.hpp>

#include <memory>
#include <vector>

namespace mars
{
    namespace ode_collision
    {
        class Object;
    }

    namespace data_broker
    {
        class DataBrokerInterface;
    }

    namespace interfaces
    {

        class DynamicObject;

        class CollisionInterface : public ConfigMapInterface
        {

        public:
            sReal ground_friction, ground_cfm, ground_erp;
            bool draw_contact_points;

            virtual ~CollisionInterface() {}
            virtual void initSpace(void) = 0;
            virtual void freeSpace(void) = 0;
            virtual void generateContacts(void) = 0;
            virtual void swapContacts(std::vector<ContactData> &contactVector) = 0;
            virtual void getContacts(std::vector<ContactData> &contactVector) = 0;
            virtual void getContacts(std::shared_ptr<CollisionInterface> other, std::vector<ContactData> &contactVector) = 0;
            virtual bool existsSpace(void) const = 0;
            virtual sReal getVectorCollision(const utils::Vector &pos, const utils::Vector &ray) const = 0;
            virtual void getSphereCollision(const utils::Vector &pos,
                                            const double r,
                                            std::vector<utils::Vector> &contacts,
                                            std::vector<double> &depths) const = 0;
            virtual ode_collision::Object* createObject(configmaps::ConfigMap &config, std::shared_ptr<DynamicObject> movalbe=nullptr) = 0;
            virtual void updateTransforms(void) = 0;
            virtual void showDebugObjects(bool show) = 0;
        };

        class CollisionInterfaceItem {
        public:
            std::shared_ptr<CollisionInterface> collisionInterface;
            std::string pluginName;
        };

    } // end of namespace interfaces
} // end of namespace mars

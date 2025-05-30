#pragma once

#include "contact_params.h"
#include "MARSDefs.h"

#include <mars_utils/Vector.h>
#include <mars_utils/Quaternion.h>

#include <string>
#include <map>
#include <memory>


namespace mars
{
    namespace interfaces
    {

        class DynamicObject;

        /**
         * ContactData is a struct/class to exchange contact information between the collision
         * library used and the physics library
         *
         */
        struct ContactData
        {
            /**
             * @brief default constructor that takes name, position and orientation arguments
             */
            ContactData() {
                surfaceDepth = 0;
                surfaceType = 0;
                surfaceVariance = 1.0;
            }

            //static const char* toString(const NodeType &type);


            // bool fromConfigMap(configmaps::ConfigMap *config, std::string filenamePrefix,
            //                    LoadCenter *loadCenter = 0);
            // void toConfigMap(configmaps::ConfigMap *config,
            //                  bool skipFilenamePrefix = false,
            //                  bool exportDefault = false);

            std::string frameID;
            std::string nameObject1, nameObject2;


            /**
             * The position of the contact.
             * \verbatim Default value: (0.0, 0.0, 0.0) \endverbatim
             */
            utils::Vector pos;

            /**
             * The normal vector of the contact.
             * \verbatim Default value: (0.0, 0.0, 0.0) \endverbatim
             */
            utils::Vector normal;

            /**
             * Depth of the contact. \verbatim Default value: 0.0 \endverbatim
             */
            sReal depth;

            sReal simulationStepSize;
            sReal surfaceDepth;
            sReal surfaceVariance;
            int surfaceType;

            /**
             * The contact params define the physical contact properties.
             */
            contact_params c_params;

            std::shared_ptr<DynamicObject> body1;
            std::shared_ptr<DynamicObject> body2;
            ContactMaterial contactMaterialObject1;
            ContactMaterial contactMaterialObject2;

        }; // end of struct ContactData

    } // end of namespace interfaces

} // end of namespace mars

#pragma once

#include "MARSDefs.h"
#include <mars_utils/Vector.h>
#include <mars_utils/Quaternion.h>

#include <string>

namespace mars
{
    namespace interfaces
    {

        /**
         * core_objects_exchange is a struct to exchange core objects information
         * between the modules of the simulation. This object is mostly used to
         * get the main object information without any overhead. For instance to
         * create lists of objects in the GUI.
         */
        struct core_objects_exchange
        {
            core_objects_exchange()
            {
                setZero();
            }

            void setZero()
            {
                pos.setZero();
                rot.setIdentity();
                visOffsetPos.setZero();
                visOffsetRot.setIdentity();
                index = 0;
                value = 0;
                groupID = 0;
            }

            /**
             * The name of the object.
             */
            std::string name;

            /**
             * The position of the object.
             */
            utils::Vector pos;

            /**
             * The orientation of the object. \sa Quaternion
             */
            utils::Quaternion rot;

            /**
             * The offset position of the visual representation.
             */
            utils::Vector visOffsetPos;

            /**
             * The offset orientation of the visual representation. \sa Quaternion
             */
            utils::Quaternion visOffsetRot;

            /**
             * The unique id of the object. A joint and a node can have the same id,
             * the ids are only unique for the same types of objects.
             */
            unsigned long index;

            /**
             * The groupID of the object if the object is a node.
             */
            unsigned int groupID;

            /**
             * A value that is used in different ways depending on the type of object.
             */
            sReal value;
        }; // end of struct core_objects_exchange

    } // end of namespace interfaces
} // end of namespace mars

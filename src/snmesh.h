#pragma once

#include "MARSDefs.h"
#include <mars_utils/Color.h>

namespace mars
{

    namespace interfaces
    {

        //mesh structure
        struct snmesh
        {
            void setZero()
            {
                vertices = 0;
                normals = 0;
                color= 0;
                tCoords = 0;
                indices = 0;
                indexcount = 0;
                vertexcount = 0;
            }

            snmesh()
            {
                setZero();
            }

            mydVector3 *vertices;
            mydVector3 *normals;
            utils::Color *color;
            mydVector2 *tCoords;

            int *indices;
            int indexcount;
            int vertexcount;

        }; // end of struct snmesh

    } // end of namespace interfaces

} // end of namespace mars

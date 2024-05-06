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
            void setZero(bool free_memory = false)
            {
                if (free_memory)
                {
                    freeMemory();
                }

                vertices = nullptr;
                normals = nullptr;
                color = nullptr;
                tCoords = nullptr;
                indices = nullptr;
                indexcount = 0;
                vertexcount = 0;
            }

            snmesh()
            {
                setZero();
            }

            void freeMemory()
            {
                if (vertices)
                {
                    delete vertices;
                }
                if (normals)
                {
                    delete normals;
                }
                if (color)
                {
                    delete color;
                }
                if (tCoords)
                {
                    delete tCoords;
                }
                if (indices)
                {
                    delete indices;
                }
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

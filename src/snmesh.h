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
            snmesh() :
                vertices{nullptr},
                normals{nullptr},
                color{nullptr},
                tCoords{nullptr},
                indices{nullptr},
                indexcount{0},
                vertexcount{0}
            {}

            ~snmesh() = default;

            void setZero(bool free_memory = false)
            {
                if (free_memory)
                {
                    freeMemory();
                }

                *this = snmesh{};
            }


            void freeMemory()
            {
                // TODO: It seems like this memory also may be deallocated from somewhere else without calling setZero resulting in a double delete. This should be cleaned up.
                // if (vertices)
                // {
                //     delete[] vertices;
                //     vertices = nullptr;
                // }
                // if (normals)
                // {
                //     delete normals;
                //     normals = nullptr;
                // }
                // if (color)
                // {
                //     delete color;
                //     color = nullptr;
                // }
                // if (tCoords)
                // {
                //     delete tCoords;
                //     tCoords = nullptr;
                // }
                // if (indices)
                // {
                //     delete indices;
                //     indices = nullptr;
                // }
            }

            mydVector3* vertices;
            mydVector3* normals;
            utils::Color* color;
            mydVector2* tCoords;

            int* indices;
            int indexcount;
            int vertexcount;

        }; // end of struct snmesh

    } // end of namespace interfaces

} // end of namespace mars

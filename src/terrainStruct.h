#pragma once

#include "MaterialData.h"
#include <string>

namespace mars
{

    namespace interfaces
    {

        /**
         * terrainStruct is a struct to exchange height maps between the GUI and the simulation
         */
        struct terrainStruct
        {
            terrainStruct()
                : width(0), height(0), 
                  targetWidth(0), targetHeight(0), 
                  scale(1.0), 
                  texScaleX(0.1),
                  texScaleY(0.1),
                  pixelData(NULL),
                  mesh(0) {}

            std::string name; //the joints name
            std::string srcname;
            MaterialData material;
            int width;
            int height;
            double targetWidth;
            double targetHeight;
            double scale;
            double texScaleX, texScaleY; // texture scaling - a value of 0 will fit the complete terrain
            double *pixelData;
            int mesh;

        }; // end of struct terrainStruct

    } // end of namespace interfaces

} // end of namespace mars

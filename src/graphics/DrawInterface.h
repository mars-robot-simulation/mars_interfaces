#prama once

#include "draw_structs.h"
#include <vector>

namespace mars
{
    namespace interfaces
    {

        struct draw_item;

        /**
         * The interface DrawInterface is used for updating draw_item structs via an update function
         */
        class DrawInterface
        {

        public:
            /** 
             * This is the update function that updates the position of the vertices of all draw_item
             * structs contained in drawItems
             */
            virtual void update(std::vector<draw_item> *drawItems) = 0;
            virtual ~DrawInterface(){}
        }; // end of class DrawInterface

    } // end of namespace interfaces
} // end of namespace mars

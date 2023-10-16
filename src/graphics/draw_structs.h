#pragma once

#include "DrawInterface.h"
#include "../MARSDefs.h"

#include <mars_utils/Color.h>
#include <mars_utils/Vector.h>

#include <string>
#include <vector>


#define DRAW_STATE_CREATE    1
#define DRAW_STATE_UPDATE    2
#define DRAW_STATE_ERASE     3

#define HUD_ELEMENT_LABEL    1
#define HUD_ELEMENT_TERMINAL 2
#define HUD_ELEMENT_TEXTURE  3
#define HUD_ELEMENT_LINES    4
#define HUD_ELEMENT_OSGNODE  5


namespace mars
{
    namespace interfaces
    {

        class DrawInterface;

        enum DrawType
        {
            DRAW_UNKNOWN = 0,
            DRAW_LINE,
            DRAW_POINT,
            DRAW_ARROW,
            DRAW_TEXT,
            DRAW_RECTANGLE,
            DRAW_HUD_RECT,
            DRAW_TRIANGLE_SET,
            DRAW_POINTS,
            DRAW_CIRCLE,
            DRAW_LINE_STRIP,
            DRAW_LINES,
            DRAW_LAST // keep last
        };

        /**
         * \brief draw_item is a struct that is used to draw elements
         * directly to the gui
         */
        struct draw_item
        {
            unsigned long id; //id of the element
            DrawType type; //type of the element, has to be one of the ones defined above
            mars::interfaces::sReal width;	// TODO : give length as vector ... ?
            mars::interfaces::sReal height;	// 		  Anyhow, make this more uniform!!
            mars::utils::Vector offset;
            mars::utils::Vector start; //start position of the line and arrow
            mars::utils::Vector end; //end position of line and arrow
            mars::utils::Vector pos; //position point for polygon
            mars::utils::Vector axis;
            mars::utils::Color myColor; //color of the draw item
            mars::utils::Color borderColor; //color of the draw item
            mars::interfaces::sReal point_size; //line or point size of the item
            // name of the item, will later be used for text or for text next
            // to the appropriate line or point
            std::string label;
            int draw_state;
            std::string texture;
            std::vector<float> vertices;
            int t_width, t_height;
            void *t_data;
            int align_to_view;
            int get_light;
            int resolution;
        }; // end of struct draw_item

        /** \brief drawStruct connects a vector of draw_item objects with
         * their update interface DrawInterface
         */
        struct drawStruct
        {
            // pointer to the interface with the update function for the vectors
            DrawInterface *ptr_draw;
            // list of draw_items controlled by the ptr_draw->update function
            std::vector<draw_item> drawItems;
        }; // end of struct drawStruct


        struct hudElementStruct
        {
            int id;
            int type;
            int width, height, texture_width, texture_height;
            double posx, posy;
            double background_color[4];
            double border_color[4];
            double border_width;
            double padding[4];
            int font_size;
            int direction;
        }; // end of struct hudElementStruct

    } // end of namespace interfaces
} // end of namespace mars

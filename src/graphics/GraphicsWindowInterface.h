#prama once

#include "GraphicsCameraInterface.h"
#include "GraphicsEventInterface.h"
#include <mars_utils/Color.h>

namespace osg
{
    class Group;
}

namespace mars
{
    namespace interfaces
    {

        class GraphicsWindowInterface
        {

        public:

            virtual ~GraphicsWindowInterface() {}
            virtual const std::string getName() const = 0;
            virtual GraphicsCameraInterface* getCameraInterface() const = 0;
            virtual void grabFocus() = 0;
            virtual void setClearColor(mars::utils::Color color) = 0;
            virtual const mars::utils::Color& getClearColor() const = 0;
            virtual void switchHudElemtVis(int num_element) = 0;
            virtual void setFullscreen(bool val, int display = 1) = 0;
            virtual void setGrabFrames(bool grab) = 0;
            virtual void setSaveFrames(bool grab) = 0;
            /**
             * This function copies the image data in the given buffer.
             * It assumes that the buffer ist correctly initalized
             * with a char array of the size width * height * 4
             *
             * @param buffer buffer in which the image gets copied
             * @param width returns the width of the image
             * @param height returns the height of the image
             * */
            virtual void getImageData(char *buffer, int &width, int &height) = 0;
            virtual void getImageData(void **data, int &width, int &height) = 0;

            /**
             * This function copies the depth image in the given buffer.
             * It assumes that the buffer ist correctly initalized
             * with a double array of the size width * height
             *
             * @param buffer buffer in which the image gets copied
             * @param width returns the width of the image
             * @param height returns the height of the image
             * */
            virtual void getRTTDepthData(float *buffer, int &width, int &height) = 0;
            virtual void getRTTDepthData(float **data, int &width, int &height) = 0;
            virtual osg::Group* getScene() = 0;
            virtual void setScene(osg::Group *scene) = 0;
            virtual void addGraphicsEventHandler(GraphicsEventInterface *graphicsEventHandler) = 0;

            virtual void setHUDViewOffsets(double x1, double y1,
                                           double x2, double y2) = 0;
            virtual void setupDistortion(double factor) = 0;

        }; // end of class GraphicsWindowInterface

    } // end of namespace interfaces
} // end of namespace mars

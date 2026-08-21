#pragma once

#include <mars_utils/Vector.h>

namespace mars
{
    namespace interfaces
    {
        class ManipulatorClient
        {
        public:
            ManipulatorClient() {}
            virtual ~ManipulatorClient() {}

            virtual void moveX(double value) = 0;
            virtual void moveY(double value) = 0;
            virtual void moveZ(double value) = 0;
            virtual void rotX(double value) = 0;
            virtual void rotY(double value) = 0;
            virtual void rotZ(double value) = 0;
            virtual void scaleX(double value) = 0;
            virtual void scaleY(double value) = 0;
            virtual void scaleZ(double value) = 0;
            virtual bool keyPress(char c) = 0;
        };

        class UVPointerClient
        {
        public:
            UVPointerClient() {}
            virtual ~UVPointerClient() {}
            virtual bool pointerEvent(double s, double t) = 0;
            virtual bool pointerClickEvent(double s, double t) = 0;
            virtual bool pointerReleaseEvent() = 0;
            virtual bool pointerRayEvent(utils::Vector start,
                                         utils::Vector end) = 0;
            virtual bool pointerRayClickEvent(utils::Vector start,
                                              utils::Vector end) = 0;
        };
    }
}

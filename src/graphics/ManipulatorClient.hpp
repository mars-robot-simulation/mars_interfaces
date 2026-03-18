#pragma once

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
            virtual bool keyPress(char c) = 0;
        };
    }
}

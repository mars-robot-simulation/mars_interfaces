#pragma once

namespace mars
{
    namespace interfaces
    {

        /**
         * The Interface to load controller dynamically into the simulation
         *
         */
        class GraphicsUpdateInterface
        {
        public:
            GraphicsUpdateInterface(void) {}
            virtual ~GraphicsUpdateInterface(void) {}
            virtual void preGraphicsUpdate(void) {}
            virtual void postGraphicsUpdate(void) {}
        }; // end of class GraphicsUpdateInterface

    } // end of namespace interfaces
} // end of namespace mars

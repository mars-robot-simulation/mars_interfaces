#pragma once

namespace mars
{
    namespace interfaces
    {

        class GraphicsEventClient
        {
        public:
            virtual ~GraphicsEventClient() {}
            virtual void selectEvent(unsigned long id, bool mode) = 0;
        }; // end of class GraphicsEventClient

    } // end of namespace interfaces
} // end of namespace mars

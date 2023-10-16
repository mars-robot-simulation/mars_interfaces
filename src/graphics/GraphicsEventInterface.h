#pragma once

#include "GuiEventInterface.h"

namespace mars
{
    namespace interfaces
    {

        class GraphicsEventInterface
        {
        public:
            virtual ~GraphicsEventInterface() {}
            virtual void emitKeyDownEvent(int key, unsigned int modKey,
                                          unsigned long win_id) {}
            virtual void emitKeyUpEvent(int key, unsigned int modKey,
                                        unsigned long win_id) {}
            virtual void emitQuitEvent(unsigned long win_id) {}
            virtual void emitSetAppActive(unsigned long win_id = 0) {}
            virtual void emitNodeSelectionChange(unsigned long win_id, int mode) {}
            virtual void emitGeometryChange(unsigned long win_id,
                                            int left, int top,
                                            int width, int height) {}
            virtual void emitPickEvent(int x, int y) {}
            virtual void mouseMove(int x, int y) {}
            virtual void mousePress(int x, int y, int button) {}
            virtual void mouseRelease(int x, int y, int button) {}

        }; // end of class GraphicsEventInterface

    } // end of namespace interfaces
} // end of namespace mars

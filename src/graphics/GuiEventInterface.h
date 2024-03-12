#pragma once

namespace mars
{
    namespace interfaces
    {

        class GuiEventInterface
        {
        public:
            enum KeyType
            {
                Key_Backspace,
                Key_Tab,
                Key_Return,
                Key_Pause,
                Key_ScrollLock,
                Key_Escape,
                Key_Delete,
                Key_Home,
                Key_Left,
                Key_Up,
                Key_Right,
                Key_Down,
                Key_PageUp,
                Key_PageDown,
                Key_End,
                Key_Print,
                Key_Space,
                Key_Enter,
                Key_Insert,
                Key_NumLock,
                Key_Equal,
                Key_multiply,
                Key_Plus,
                Key_Minus,
                Key_Slash,
                Key_0,
                Key_1,
                Key_2,
                Key_3,
                Key_4,
                Key_5,
                Key_6,
                Key_7,
                Key_8,
                Key_9,
                Key_F1,
                Key_F2,
                Key_F3,
                Key_F4,
                Key_F5,
                Key_F6,
                Key_F7,
                Key_F8,
                Key_F9,
                Key_F10,
                Key_F11,
                Key_F12
            };

            enum KeyModifiers
            {
                ShiftModifier    =  1,
                ControlModifier  =  2,
                AltModifier      =  4,
                MetaModifier     =  8,
                KeypadModifier   = 16
            };

            virtual ~GuiEventInterface() {}

            virtual void keyDownEvent(int key, unsigned int mod, unsigned long win_id) = 0;
            virtual void keyUpEvent(int key, unsigned int mod, unsigned long win_id) = 0;
            virtual void quitEvent(unsigned long win_id) = 0;
            virtual void setAppActive(unsigned long win_id = 0) = 0;

        }; // end of class GuiEventInterface

    } // end of namespace interfaces
} // end of namespace mars

#pragma once

#include <iostream>
#include <string>

#define ESC "\x1b"
#define CSI "\x1b["
#define OSC "\x1b]"
#define BACKSLASH "\\"
#define STRING_TERMINATOR "\x1b\\"
#define RESET "\x1b[0m"

#define BEL '\x07' // Bell
#define BS '\x08' // Backspace
#define TAB '\x09' // Tab
#define LF '\x0a' // Line Feed
#define VT '\x0b' // Vertical Tab
#define FF '\x0c' // Form Feed
#define CR '\x0d' // Carriage Return
#define DEL '\x7f' // Delete

#define SS "\33[2J\33[H" // Scroll Screen


const std::string ESC_(ESC);
const std::string CSI_(CSI);
const std::string OSC_(OSC);
const std::string BACKSLASH_(BACKSLASH);
const std::string STRING_TERMINATOR_(STRING_TERMINATOR);
const std::string RESET_(RESET);


namespace cursor {
    namespace positioning {
        #define CUU_ 'A' // "CUrsor Up"
        #define CUD_ 'B' // "CUrsor Down"
        #define CUF_ 'C' // "CUrsor Forward"
        #define CUB_ 'D' // "CUrsor Backward"

        #define CNL_ 'E' // "Cursor Next Line"
        #define CPL_ 'F' // "Cursor Previous Line"

        #define CHA_ 'H' // "Cursor Horizontal Absolute"
        #define VPA_ 'd' // "Vertical Position Absolute"

        #define CUP_ 'H' // "CUrsor Position"
        #define HVP_ 'f' // "Horizontal Vertical Position"

        // WARNING: The following were only found in ANSI.SYS
        #define ANSISYSSC 's' // "Save Cursor [Position]"
        #define ANSISYSRC 'u' // "Restore Cursor [Position]"

        // WARNING: Some of the following were introduced with VT100 and may not be supported by all terminals
        std::string DECSC = ESC_ + '7';
        std::string DECSR = ESC_ + '8';
        std::string RI = ESC_ + 'M'; // "Reverse Index"
    }

    namespace visibility {
        // https://docs.microsoft.com/en-us/windows/console/setconsolecursorinfo equivalent
        #define ATT160E_ "?12h" // "Cursor Blinking Enable"
        #define ATT160D_ "?12l" // "Cursor Blinking Disable"
        #define DECTCEMS_ "?25h" // "Cursor Show"
        #define DECTCEMH_ "?25l" // "Cursor Hide"

        std::string show = CSI_ + std::string(DECTCEMS_);
        std::string hide = CSI_ + std::string(DECTCEMH_);
    }

    namespace arrows {
        #define UP_ 'A' // "Arrow Up"
        #define DOWN_ 'B' // "Arrow Down"
        #define RIGHT_ 'C' // "Arrow Right"
        #define LEFT_ 'D' // "Arrow Left"

        #define HOME_ 'H' // "Home"
        #define END_ 'F' // "End"
    }
}


namespace viewport {
    namespace positioning {
        #define SU_ 'S' // "Scroll Up"
        #define SD_ 'T' // "Scroll Down"

        void scrollUp(int lines) {
            std::cout << CSI + lines + SU_;
        }

        void scrollDown(int lines) {
            std::cout << CSI + lines + SD_;
        }
    }

    namespace title {
        #define SWT_ '0' // "Set Window Title"
        #define SWT_ALIAS '2' // "Set Window Title"

        void setTitle(const std::string title) {
            std::cout << OSC + SWT_ + ';' + title + STRING_TERMINATOR;
        }
    }

    namespace sizes {
        #define DECCOLM_132_ std::string("?3h") // "132 Column Mode"
        #define DECCOLM_80_ std::string("?3l") // "80 Column Mode"

        std::string DECCLM_132 = CSI_ + DECCOLM_132_;
        std::string DECCLM_80 = CSI_ + DECCOLM_80_;
    }
}
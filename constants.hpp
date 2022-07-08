#pragma once

#include <iostream>

#define ESC '\x1b'
#define CSI "\x1b["
#define OSC "\x1b]"
#define BACKSLASH '\\'
#define STRING_TERMINATOR ESC + BACKSLASH


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
        const char DECSC = ESC + '7';
        const char DECSR = ESC + '8';
        const char RI = ESC + 'M'; // "Reverse Index"
    }

    namespace visibility {
        // https://docs.microsoft.com/en-us/windows/console/setconsolecursorinfo equivalent
        #define ATT160E_ "?12h" // "Cursor Blinking Enable"
        #define ATT160D_ "?12l" // "Cursor Blinking Disable"
        #define DECTCEMS_ "?25h" // "Cursor Show"
        #define DECTCEMH_ "?25l" // "Cursor Hide"
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
#include "constants.hpp"


class Cursor {
public:
    void moveUp(int n) {
        std::cout << CSI << n << CUU_;
    }
    void moveDown(int n) {
        std::cout << CSI << n << CUD_;
    }
    void moveForward(int n) {
        std::cout << CSI << n << CUF_;
    }
    void moveBackward(int n) {
        std::cout << CSI << n << CUB_;
    }
    void nextLine(int n) {
        std::cout << CSI << n << CNL_;
    }
    void previousLine(int n) {
        std::cout << CSI << n << CPL_;
    }
    void horizontalAbsolute(int n) {
        std::cout << CSI << n << CHA_;
    }
    void verticalAbsolute(int n) {
        std::cout << CSI << n << VPA_;
    }
    void position(int x, int y) {
        std::cout << CSI << y << ';' << x << CUP_;
    }

    void savePosition() {
        std::cout << CSI << ANSISYSSC;
    }
    void restorePosition() {
        std::cout << CSI << ANSISYSRC;
    }
};
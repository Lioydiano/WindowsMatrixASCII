#include "constants.hpp"
#include "matrix.hpp"


class Cursor {
public:
    int x;
    int y;
    Field *field;

    Cursor() {
        this->x = 0;
        this->y = 0;
    }
    Cursor(Field *field) {
        this->x = 0;
        this->y = 0;
        this->field = field;
    }
    Cursor(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Cursor(int x, int y, Field *field) {
        this->x = x;
        this->y = y;
        this->field = field;
    }

    void moveUp(int n) {
        std::cout << CSI << n << CUU_;
        this->y -= n;
    }
    void moveDown(int n) {
        std::cout << CSI << n << CUD_;
        this->y += n;
    }
    void moveForward(int n) {
        std::cout << CSI << n << CUF_;
        this->x += n;
    }
    void moveBackward(int n) {
        std::cout << CSI << n << CUB_;
        this->x -= n;
    }

    void nextLine(int n) {
        std::cout << CSI << n << CNL_;
        this->y += n;
    }
    void previousLine(int n) {
        std::cout << CSI << n << CPL_;
        this->y -= n;
    }

    void horizontalAbsolute(int x) {
        std::cout << CSI << x << CHA_;
        this->x = x;
    }
    void verticalAbsolute(int y) {
        std::cout << CSI << y << VPA_;
        this->y = y;
    }
    void position(int x, int y) {
        std::cout << CSI << y << ';' << x << CUP_;
        this->x = x;
        this->y = y;
    }

    void savePosition() {
        std::cout << CSI << ANSISYSSC;
    }
    void restorePosition() {
        std::cout << CSI << ANSISYSRC;
    }
};
#include <vector>

#include "constants.hpp"


class Style {
public:
    int lenght;
    std::vector<int> codes;

    Style() {
        this->lenght = 0;
        this->codes = {};
    }

    Style(int codes[]) {
        this->lenght = sizeof(codes)/sizeof(int);
        for (int i = 0; i < this->lenght; i++)
            this->codes.push_back(codes[i]);
    }

    Style(std::vector<int> codes) {
        this->lenght = codes.size();
        this->codes = codes;
    }

    void printOpening() {
        for (int i = 0; i < this->codes.size(); i++)
            std::cout << CSI << this->codes[i] << "m;";
        std::cout << BS;
    }

    void printClosing() {
        std::cout << CSI << RESET;
    }
};
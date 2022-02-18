#include <string>
#include <vector>
#ifndef gameEvolution_h
#define gameEvolution_h

class gameEvolution {
    public:
        gameEvolution();
        ~gameEvolution();
        gameEvolution(const int& rows, const int& columns, const int& cells);
        gameEvolution(std::string path);
        void TakeStep();
        void PrintGrid();

    private:
        int columns_;
        int rows_;
        int cells_;
        std::vector<std::vector<char>> vec2D_1_;
        std::vector<std::vector<char>> vec2D_2_;
};

#endif
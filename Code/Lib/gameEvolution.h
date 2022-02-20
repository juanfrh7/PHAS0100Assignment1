#include <string>
#include <vector>
#include <memory>
#ifndef gameEvolution_h
#define gameEvolution_h

class gameEvolution {
    public:
        gameEvolution();
        ~gameEvolution();
        gameEvolution(std::shared_ptr<DataStructure> const& grid);
        void TakeStep();
        void PrintGrid();

    private:
        int columns_;
        int rows_;
        int cells_;
        std::vector<std::vector<char>> vec2D_;
        std::shared_ptr<DataStructure> grid_;
};

#endif
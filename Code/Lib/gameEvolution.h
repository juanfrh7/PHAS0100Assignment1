#include <string>
#include <vector>
#include <memory>
#include "DataStructure.h"
#ifndef gameEvolution_h
#define gameEvolution_h

class gameEvolution {
    public:
        gameEvolution();
        ~gameEvolution();
        gameEvolution(std::shared_ptr<DataStructure> const& grid);
        void CreateGrid();
        void CreateGridFromFile();
        void TakeStep();
        void PrintGrid();
        void PrintOriginalGrid();
        std::vector<std::vector<char>> ReturnVec();

    private:
        int columns_;
        int rows_;
        int cells_;
        std::vector<std::vector<char>> vec2D_;
        std::vector<std::vector<char>> original_;
        std::shared_ptr<DataStructure> grid_;
};

#endif
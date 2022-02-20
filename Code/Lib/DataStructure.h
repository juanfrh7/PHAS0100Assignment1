#include <string>
#include <vector>
#ifndef DataStructure_h
#define DataStructure_h

class DataStructure {
    public:
        DataStructure();
        DataStructure(const int& rows, const int& columns);
        DataStructure(const int& rows, const int& columns, const int& cells);
        DataStructure(std::string path);
        ~DataStructure();
        void Create2DGrid();
        void SetRandomlyAlive();
        void PrintGrid();
        char GetCellContent(int x, int y);
        void SetCellContent(int x, int y, char cell);
        int CountAliveNeighbourCell(int x, int y);
        std::vector<std::vector<char>> ReturnVec();

    private:
        int columns_;
        int rows_;
        int cells_;
        std::vector<std::vector<char>> vec2D_;
};

#endif
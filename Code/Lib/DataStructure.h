#include <string>
#include <vector>
#ifndef DataStructure_h
#define DataStructure_h

class DataStructure {
    public:
        DataStructure();
        DataStructure(const int& rows, const int& columns);
        DataStructure(const int& rows, const int& columns, const int& cells);
        DataStructure(std::string& path);
        ~DataStructure();
        void Create2DGrid();
        void SetRandomlyAlive();
        void PrintGrid();
        char GetCellContent(int row, int col);
        void SetCellContent(int row, int col, char cell);
        int CountAliveNeighbourCell(int row, int col);
        std::vector<std::vector<char>> ReturnVec();
        int ReturnColumns();
        int ReturnRows();
        int ReturnCells();

    private:
        int columns_;
        int rows_;
        int cells_;
        std::vector<std::vector<char>> vec2D_;
};

#endif
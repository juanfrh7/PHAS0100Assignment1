#include "DataStructure.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include<time.h>
#include<random>
#include<vector>

DataStructure::DataStructure() {
    columns_ = 0;
    rows_ = 0;
    cells_ = 0;
}

DataStructure::~DataStructure() {
}

DataStructure::DataStructure(const int& columns, const int& rows) {
    srand(time(0));
    columns_ = columns;
    rows_ = rows;
    cells_ = rand() % ((columns-1)*(rows-1));
}

DataStructure::DataStructure(const int& rows, const int& columns, const int& cells) {
    columns_ = columns;
    rows_ = rows;
    cells_ = cells;
}

DataStructure::DataStructure(std::string& path) {
    //Open files
    std::ifstream in(path);
    std::vector<std::vector<char>> vec2D;
    
    if (in) {
        std::string line;
        
        while (std::getline(in, line)) {
            vec2D.push_back(std::vector<char>());
            
            // Break down the row into column values
            std::stringstream split(line);
            char value;
            
            while (split >> value)
                vec2D.back().push_back(value);
        }
    }
    columns_ = vec2D.size();
    rows_ = vec2D[0].size();
    vec2D_ = vec2D;
}

void DataStructure::Create2DGrid(){
    std::vector<std::vector<char>> vec2D(rows_, std::vector<char> (columns_, '-'));
    vec2D_ = vec2D;
}

void DataStructure::SetRandomlyAlive(){
    for(int i = 0; i < cells_; i++){
        int random_x = rand() % (columns_-1);
        int random_y = rand() % (rows_-1);
        if(vec2D_[random_x][random_y] == 'o'){
            i--;
            continue;
        }
        else{
            vec2D_[random_x][random_y] = 'o';
        }
    }
}

int DataStructure::CountAliveNeighbourCell(int row, int col){
    int start = 0;
    int alive = 0;
    if(row+1>=start && row+1<rows_ && col>=start && col<columns_ && vec2D_[row+1][col] == 'o'){
        ++alive;
    }
    if(row+1>=start && row+1<rows_ && col-1>=start && col-1<columns_ && vec2D_[row+1][col-1] == 'o'){
        ++alive;
    }
    if(row>=start && row<rows_ && col-1>=start && col-1<columns_ && vec2D_[row][col-1] == 'o'){
        ++alive;
    }
    if(row-1>=start && row-1<rows_ && col-1>=start && col-1<columns_ && vec2D_[row-1][col-1] == 'o'){
        ++alive;
    }
    if(row-1>=start && row-1<rows_ && col>=start && col<columns_ && vec2D_[row-1][col] == 'o'){
        ++alive;
    }
    if(row-1>=start && row-1<rows_ && col+1>=start && col+1<columns_ && vec2D_[row-1][col+1] == 'o'){
        ++alive;
    }
    if(row>=start && row<rows_ && col+1>=start && col+1<columns_ && vec2D_[row][col+1] == 'o'){
        ++alive;
    }
    if(row+1>=start && row+1<rows_ && col+1>=start && col+1<columns_ && vec2D_[row+1][col+1] == 'o'){
        ++alive;
    }
    return alive;
}

void DataStructure::PrintGrid(){ 
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << vec2D_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

char DataStructure::GetCellContent(int row, int col){ 
    if(vec2D_[row][col] == '-'){
        return '-';
    }
    else{
        return 'o';
    }
}

void DataStructure::SetCellContent(int row, int col, char cell){ 
    if (cell == 'o'){
        if(vec2D_[row][col] == '-'){
            vec2D_[row][col] = 'o';
        }
    }
    if (cell == '-'){
        if(vec2D_[row][col] == 'o'){
            vec2D_[row][col] = '-';
        }
    }
}


std::vector<std::vector<char>> DataStructure::ReturnVec(){ 
    return vec2D_;
}

int DataStructure::ReturnColumns(){ 
    return columns_;
}

int DataStructure::ReturnCells(){ 
    return cells_;
}

int DataStructure::ReturnRows(){ 
    return rows_;
}
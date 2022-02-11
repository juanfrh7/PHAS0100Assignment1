#include "DataStructure.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
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

DataStructure::DataStructure(std::string) {
}

void DataStructure::Create2DGrid(){
    std::vector<std::vector<char>> vec2D(rows_, std::vector<char> (columns_, '-'));
    vec2D_ = vec2D;
}

void DataStructure::SetRandomlyAlive(){
    for(int i = 0; i < cells_; i++){
        int random_x = rand() % (columns_);
        int random_y = rand() % (rows_);
        if(vec2D_[random_x][random_y] == 'o'){
            i--;
            continue;
        }
        else{
            vec2D_[random_x][random_y] = 'o';
        }
    }
}

void DataStructure::CountAliveNeighbourCell(int x, int y){
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

void DataStructure::GetCellContent(int x, int y){ 
    if(vec2D_[x][y] == '-'){
        std::cout << "Cell (" << x << "," << y << ") is dead."<< std::endl;
    }
    else{
        std::cout << "Cell (" << x << "," << y << ") is alive."<< std::endl;
    }
}

void DataStructure::SetCellContent(int x, int y){ 
    if(vec2D_[x][y] == '-'){
        vec2D_[x][y] = 'o';
    }
    else{
        std::cout << "Cell (" << x << "," << y << ") is already alive!"<< std::endl;
    }
}

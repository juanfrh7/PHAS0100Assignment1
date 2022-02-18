#include "gameEvolution.h"
#include "DataStructure.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include<time.h>
#include<random>
#include<vector>

gameEvolution::gameEvolution() {
    columns_ = 0;
    rows_ = 0;
    cells_ = 0;
}

gameEvolution::~gameEvolution() {
}

gameEvolution::gameEvolution(const int& rows, const int& columns, const int& cells) {
    columns_ = columns;
    rows_ = rows;
    cells_ = cells;
    DataStructure initial(rows, columns, cells);
    initial.Create2DGrid();
}

gameEvolution::gameEvolution(std::string path) {
    DataStructure initial(path);
    initial.Create2DGrid();
}

void gameEvolution::TakeStep(){
} 

void gameEvolution::PrintGrid(){ 
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << vec2D_2_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
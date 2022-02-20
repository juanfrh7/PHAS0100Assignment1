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

gameEvolution::gameEvolution(std::shared_ptr<DataStructure> const& grid) {
    grid_ = grid;
}

void gameEvolution::TakeStep(){

} 

void gameEvolution::PrintGrid(){ 
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << vec2D_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
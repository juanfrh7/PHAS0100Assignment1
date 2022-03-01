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

void gameEvolution::CreateGridFromFile(){
    columns_ = grid_->ReturnColumns();
    rows_ = grid_->ReturnRows();
    cells_ = grid_->ReturnCells();
    vec2D_ = grid_->ReturnVec();
    original_ = grid_->ReturnVec();
}

void gameEvolution::CreateGrid(){
    columns_ = grid_->ReturnColumns();
    rows_ = grid_->ReturnRows();
    cells_ = grid_->ReturnCells();
    grid_->Create2DGrid();
    grid_->SetRandomlyAlive();
    vec2D_ = grid_->ReturnVec();
    original_ = grid_->ReturnVec();
}

void gameEvolution::TakeStep(){
    grid_->SetGrid(vec2D_);
    std::vector<std::vector<char>> vec2D_2 = grid_->ReturnVec();

    for(int j = 0; j < rows_; j++)
    {
        for(int i = 0; i < columns_; i++)
        {
            int neighbours = grid_->CountAliveNeighbourCell(i, j);
            char cell = grid_->GetCellContent(i, j);

            if(vec2D_[i][j] == 'o' && (neighbours == 2 || neighbours == 3)){
                vec2D_2[i][j] = 'o';
                }

            else if(vec2D_[i][j] == '-' && neighbours == 3){
                vec2D_2[i][j] = 'o';
                }

            else{
                vec2D_2[i][j] = '-';
            }
        }
    }
    vec2D_ = vec2D_2;
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

void gameEvolution::PrintOriginalGrid(){ 
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << original_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<char>> gameEvolution::ReturnVec(){
    return vec2D_;
}
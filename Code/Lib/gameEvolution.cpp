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
}

void gameEvolution::CreateGrid(){
    columns_ = grid_->ReturnColumns();
    rows_ = grid_->ReturnRows();
    cells_ = grid_->ReturnCells();
    grid_->Create2DGrid();
    grid_->SetRandomlyAlive();
    vec2D_ = grid_->ReturnVec();
}

void gameEvolution::TakeStep(){
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            if(grid_->GetCellContent(i, j) == 'o'){
                if(grid_->CountAliveNeighbourCell(i, j) == 2 || grid_->CountAliveNeighbourCell(i, j) == 3){
                    grid_->SetCellContent(i, j, 'o');
                }
                else if(grid_->CountAliveNeighbourCell(i, j) < 2 || grid_->CountAliveNeighbourCell(i, j) > 3){
                    grid_->SetCellContent(i, j, '-');
                }
            }
            if(grid_->GetCellContent(i, j) == '-'){
                if(grid_->CountAliveNeighbourCell(i, j) == 3){
                    grid_->SetCellContent(i, j, 'o');
                }
                else{
                    grid_->SetCellContent(i, j, '-');
                }
            }
        }
    }
    vec2D_ = grid_->ReturnVec();
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
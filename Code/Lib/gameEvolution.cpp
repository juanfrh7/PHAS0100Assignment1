#include "gameEvolution.h"
#include "DataStructure.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include<random>
#include<vector>
   

gameEvolution::gameEvolution() {
    columns_ = 10;
    rows_ = 10;
    cells_ = 0;
}

//-----------------------------------------------------------------------------------------//

gameEvolution::~gameEvolution() {
}

//-----------------------------------------------------------------------------------------//

gameEvolution::gameEvolution(std::shared_ptr<DataStructure> const& grid) {
    //Constructor that stores the smart pointer in the class

    grid_ = grid;
}

//-----------------------------------------------------------------------------------------//

void gameEvolution::CreateGridFromFile(){
    //Function that creates the grid from a file

    columns_ = grid_->ReturnColumns();
    rows_ = grid_->ReturnRows();
    cells_ = grid_->ReturnCells();
    vec2D_ = grid_->ReturnVec();
    original_ = grid_->ReturnVec();
}

//-----------------------------------------------------------------------------------------//

void gameEvolution::CreateGrid(){
    //Function that creates the grid from dimensions and cells

    columns_ = grid_->ReturnColumns();
    rows_ = grid_->ReturnRows();
    cells_ = grid_->ReturnCells();
    grid_->Create2DGrid();
    grid_->SetRandomlyAlive();
    vec2D_ = grid_->ReturnVec();
    original_ = grid_->ReturnVec();
}

//-----------------------------------------------------------------------------------------//

void gameEvolution::TakeStep(){
    //Function that evolves the system according to the rules of the game

    grid_->SetGrid(vec2D_);
    std::vector<std::vector<char>> vec2D_2 = grid_->ReturnVec();

    for(int j = 0; j < rows_; j++)
    {
        for(int i = 0; i < columns_; i++)
        {
            int neighbours = grid_->CountAliveNeighbourCell(i, j);
            char cell = grid_->GetCellContent(i, j);

            //A live cell with two or three alive neighbours should become a live cell
            if(vec2D_[i][j] == 'o' && (neighbours == 2 || neighbours == 3)){
                vec2D_2[i][j] = 'o';
                }

            //A dead cell with exactly three live neighbours should become a live cell
            else if(vec2D_[i][j] == '-' && neighbours == 3){
                vec2D_2[i][j] = 'o';
                }

            //A live cell with less than two and more than three live neighbours should die
            else{
                vec2D_2[i][j] = '-';
            }
        }
    }
    vec2D_ = vec2D_2;
}

//-----------------------------------------------------------------------------------------//

void gameEvolution::PrintGrid(){ 
    //Function that prints current grid

    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << vec2D_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//-----------------------------------------------------------------------------------------//

void gameEvolution::PrintOriginalGrid(){ 
    //Function that prints original grid

    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < columns_; j++)
        {
            std::cout << original_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//-----------------------------------------------------------------------------------------//

std::vector<std::vector<char>> gameEvolution::ReturnVec(){ 
    // Function that returns the current vector grid

    return vec2D_;
}

//-----------------------------------------------------------------------------------------//

int gameEvolution::ReturnColumns(){ 
    // Function that returns the number of columns
    return columns_;
}

//-----------------------------------------------------------------------------------------//

int gameEvolution::ReturnCells(){ 
    // Function that returns the number of cells

    return cells_;
}

//-----------------------------------------------------------------------------------------//

int gameEvolution::ReturnRows(){
    // Function that returns the number of rows

    return rows_;
}
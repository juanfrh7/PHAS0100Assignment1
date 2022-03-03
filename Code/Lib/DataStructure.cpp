#include "DataStructure.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include<time.h>
#include<random>
#include<vector>
#include <cstring>

DataStructure::DataStructure() {
    columns_ = 10;
    rows_ = 10;
    cells_ = 0;
}  

//-----------------------------------------------------------------------------------------//

DataStructure::~DataStructure() {
}

//-----------------------------------------------------------------------------------------//

DataStructure::DataStructure(const int& columns, const int& rows) {
    // Constructor given the number of columns and rows

    //Check that the arguments are within the accepted range
    if (columns <= 1 || rows <= 1)
        throw std::invalid_argument("Columns and rows should be grater than 1");
    
    //Check that the arguments have the correct type
    if ((strcmp(typeid(rows).name(),  "i") == 1) || (strcmp(typeid(columns).name(),  "i") == 1))
        throw std::invalid_argument("Columns and rows should integers");

    srand(time(0));
    columns_ = columns;
    rows_ = rows;
    cells_ = rand() % (columns * rows);
}

//-----------------------------------------------------------------------------------------//

DataStructure::DataStructure(const int& rows, const int& columns, const int& cells) {
    // Constructor given the number of columns, rows and alive cells

    //Check that the arguments are within the accepted range
    if (columns <= 1 || rows <= 1 || cells < 0)
        throw std::invalid_argument("Columns and rows should be grater than 1, and cells greater than 0");

    //Check that the arguments have the correct type
    if ((strcmp(typeid(rows).name(),  "i") == 1) || (strcmp(typeid(columns).name(),  "i") == 1) || (strcmp(typeid(cells).name(),  "c") == 1))
        throw std::invalid_argument("Columns, rows and cells should be integers");

    columns_ = columns;
    rows_ = rows;
    cells_ = cells;
}

//-----------------------------------------------------------------------------------------//

DataStructure::DataStructure(std::string& path ) {
    // Constructor given a patfile

    //Open files
    std::ifstream file_(path);
    std::vector<std::vector<char>> vec2D;
    
    if (file_) {
        std::string line;
        
        while (std::getline(file_, line)) {
            vec2D.push_back(std::vector<char>());
            
            // Break down the row into column values
            std::stringstream split(line);
            char value;
            
            while (split >> value)
                vec2D.back().push_back(value);
        }
    }

    //Check if the vector is empty
    if (vec2D.empty()){
        throw std::invalid_argument("File is empty");
    }

    //Store the values of rows, columns and vec
    rows_ = vec2D.size();
    columns_ = vec2D[0].size();
    vec2D_ = vec2D;
}

//-----------------------------------------------------------------------------------------//

void DataStructure::Create2DGrid(){
    // Function that initialises the grid

    std::vector<std::vector<char>> vec2D(rows_, std::vector<char> (columns_, '-'));
    vec2D_ = vec2D;
}

//-----------------------------------------------------------------------------------------//

void DataStructure::SetRandomlyAlive(){
    // Function that sets the status of each cell randomly 

    for(int i = 0; i < cells_; i++){
        //Create two random coordinates
        int random_x = rand() % (columns_);
        int random_y = rand() % (rows_);

        //If cell is already alive, go back one step
        if(vec2D_[random_x][random_y] == 'o'){
            i--;
            continue;
        }
        //If cell is dead, set alive
        else{
            vec2D_[random_x][random_y] = 'o';
        }
    }
}

//-----------------------------------------------------------------------------------------//

int DataStructure::CountAliveNeighbourCell(int row, int col){
    // Function that returns the number of alive neighbours

    //Check that the arguments are within the accepted range
    if (row < 0 || col < 0 || row > rows_ || col > columns_)
        throw std::invalid_argument("Rows and columns should be within the correct range");

    //Check that the arguments have the correct type
    if ((strcmp(typeid(row).name(),  "i") == 1) || (strcmp(typeid(col).name(),  "i") == 1))
        throw std::invalid_argument("Columns and rows should be integers");
    
    int start = 0;
    int alive = 0;
    //Check right neighbour
    if(row+1>=start && row+1<rows_ && col>=start && col<columns_ && vec2D_[row+1][col] == 'o'){
        ++alive;
    }
    //Check lower right corner neighbour
    if(row+1>=start && row+1<rows_ && col-1>=start && col-1<columns_ && vec2D_[row+1][col-1] == 'o'){
        ++alive;
    }
    //Check lower neighbour
    if(row>=start && row<rows_ && col-1>=start && col-1<columns_ && vec2D_[row][col-1] == 'o'){
        ++alive;
    }
    //Check lower left corner neighbour
    if(row-1>=start && row-1<rows_ && col-1>=start && col-1<columns_ && vec2D_[row-1][col-1] == 'o'){
        ++alive;
    }
    //Check left neighbour
    if(row-1>=start && row-1<rows_ && col>=start && col<columns_ && vec2D_[row-1][col] == 'o'){
        ++alive;
    }
    //Check upper left corner neighbour
    if(row-1>=start && row-1<rows_ && col+1>=start && col+1<columns_ && vec2D_[row-1][col+1] == 'o'){
        ++alive;
    }
    //Check upper neighbour
    if(row>=start && row<rows_ && col+1>=start && col+1<columns_ && vec2D_[row][col+1] == 'o'){
        ++alive;
    }
    //Check upper right corner neighbour
    if(row+1>=start && row+1<rows_ && col+1>=start && col+1<columns_ && vec2D_[row+1][col+1] == 'o'){
        ++alive;
    }
    return alive;
}

//-----------------------------------------------------------------------------------------//

void DataStructure::PrintGrid(){ 
    // Function that prints the current grid

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

char DataStructure::GetCellContent(int row, int col){ 
    // Function that returns the state of a cell given its coordinate

    //Check that the arguments are within the accepted range
    if (row < 0 || col < 0 || row > rows_ || col > columns_)
        throw std::invalid_argument("Rows and columns should be within the correct range");
    
    //Check that the arguments have the correct type
    if ((strcmp(typeid(row).name(),  "i") == 1) || (strcmp(typeid(col).name(),  "i") == 1))
        throw std::invalid_argument("Columns and rows should be integers");

    //if the cell is dead, return -
    if(vec2D_[row][col] == '-'){
        return '-';
    }
    //if the cell is alive, return o
    else{
        return 'o';
    }
}

//-----------------------------------------------------------------------------------------//

void DataStructure::SetCellContent(int row, int col, char cell){ 
    // Function that changes the state of a cell given its coordinates

    //Check that the arguments are within the accepted range
    if (row < 0 || col < 0 || row > rows_ || col > columns_ )
        throw std::invalid_argument("Rows and columns should be within the correct range");

    //Check that the arguments have the correct type
    if ((strcmp(typeid(row).name(),  "i") == 1) || (strcmp(typeid(col).name(),  "i") == 1) || (strcmp(typeid(cell).name(),  "c") == 1))
        throw std::invalid_argument("Columns and rows should be integers, and cell a char");

    //if the cell is dead, set it alive
    if (cell == 'o'){
        if(vec2D_[row][col] == '-'){
            vec2D_[row][col] = 'o';
        }
    }
    //if the cell is alive, kill it
    if (cell == '-'){
        if(vec2D_[row][col] == 'o'){
            vec2D_[row][col] = '-';
        }
    }
}

//-----------------------------------------------------------------------------------------//

void DataStructure::SetGrid(std::vector<std::vector<char>> vec){ 
    // Function that sets the grid of the class to the given vector

    vec2D_ = vec;
}

//-----------------------------------------------------------------------------------------//

std::vector<std::vector<char>> DataStructure::ReturnVec(){ 
    // Function that returns the current vector grid

    return vec2D_;
}

//-----------------------------------------------------------------------------------------//

int DataStructure::ReturnColumns(){ 
    // Function that returns the number of columns
    return columns_;
}

//-----------------------------------------------------------------------------------------//

int DataStructure::ReturnCells(){ 
    // Function that returns the number of cells

    return cells_;
}

//-----------------------------------------------------------------------------------------//

int DataStructure::ReturnRows(){
    // Function that returns the number of rows

    return rows_;
}
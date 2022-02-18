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

DataStructure::DataStructure(std::string path) {
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
    rows_ = vec2D.size();
    columns_ = vec2D[0].size();
    vec2D_ = vec2D;
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

int DataStructure::CountAliveNeighbourCell(int x, int y){
    int i, j, count=0;
    for(i=x-1; i<=x+1; i++){
        for(j=y-1;j<=y+1;j++){
            if((i==x && j==y) || (i<0 || j<0) || (i>=rows_ || j>=columns_)){
                continue;
            }
            if(vec2D_[i][j]=='o'){
                count++;
            }
        }
    } 
    return count;
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


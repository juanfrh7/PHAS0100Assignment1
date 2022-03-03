/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "DataStructure.h"
#include "gameEvolution.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>
#include <stdexcept>

TEST_CASE( "Data Structure test 1", "[columns, rows and random cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = row * col;
  std::vector<std::vector<char>> vec(row, std::vector<char> (col, '-'));
  DataStructure initial(row, col);
  initial.Create2DGrid();

  //First check that the class stores and outputs correctly the variables
  auto get_row = initial.ReturnRows();
  auto get_col = initial.ReturnColumns();
  auto get_cell = initial.ReturnCells();
  auto get_vec = initial.ReturnVec();

  REQUIRE( get_row == row );
  REQUIRE( get_col == col );
  REQUIRE( get_cell <=  cells );
  REQUIRE( get_vec ==  vec );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_cell).name(),  "i") == 0  );
  REQUIRE( strcmp(typeid(initial).name(),  "13DataStructure") == 0  );
}

TEST_CASE( "Data Structure test 2", "[Set/Get cell content function]" ) {
  int col = 10;
  int row = 10;

  DataStructure initial(row, col);
  initial.Create2DGrid();

  //Check that setting an alive cell ouputs the correct type and cell content
  initial.SetCellContent(5, 5, 'o');
  REQUIRE( initial.GetCellContent(5, 5) == 'o' );
  REQUIRE( strcmp(typeid(initial.GetCellContent(5, 5)).name(), "c") == 0 );

  //Check that setting a dead cell ouputs the correct type and cell content
  initial.SetCellContent(5, 5, '-');
  REQUIRE( initial.GetCellContent(5, 5) == '-' );
  REQUIRE( strcmp(typeid(initial.GetCellContent(5, 5)).name(), "c") == 0 );
}

TEST_CASE( "Data Structure test 3", "[columns, rows and cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = 10;
  std::vector<std::vector<char>> vec(row, std::vector<char> (col, '-'));
  DataStructure initial(row, col, cells);
  initial.Create2DGrid();

  //First check that the class stores and outputs correctly the variables
  auto get_row = initial.ReturnRows();
  auto get_col = initial.ReturnColumns();
  auto get_cell = initial.ReturnCells();
  auto get_vec = initial.ReturnVec();

  REQUIRE( get_row == row );
  REQUIRE( get_col == col );
  REQUIRE( get_cell ==  cells );
  REQUIRE( get_vec ==  vec );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_cell).name(),  "i") == 0  );
  REQUIRE( strcmp(typeid(initial).name(),  "13DataStructure") == 0  );
}

TEST_CASE( "Data Structure test 4", "[columns and rows from path]" ) {

  std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
  DataStructure initial(path);

 //First check that the class stores and outputs correctly the variables
  auto get_row = initial.ReturnRows();
  auto get_col = initial.ReturnColumns();

  REQUIRE( get_row == 12 );
  REQUIRE( get_col == 12 );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
}

TEST_CASE( "Data Structure test 5", "[Count alive neighbour cells function]" ) {

  std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
  DataStructure initial(path);

  //Check at the centre of the grid with alive cells
  auto x = initial.CountAliveNeighbourCell(2, 1);

  //Check at a corner with no alive cells
  auto y = initial.CountAliveNeighbourCell(0, 0);

  //Check at a border with alive cells
  auto z = initial.CountAliveNeighbourCell(11, 3);

  REQUIRE( x == 3 );
  REQUIRE( y == 0 );
  REQUIRE( z == 2 );

  //Check that it ouputs the correct type
  REQUIRE( strcmp(typeid(x).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(y).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(z).name(),  "i") == 0  );
}

TEST_CASE( "Data Structure negative test 1", "[Invalid ranges]" ) {

  int col = -20;
  int row = 0;

  try
  {
    DataStructure initial(row, col);
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(),  "Columns and rows should be grater than 1") == 0 );
  }
}

TEST_CASE( "Data Structure negative test 2", "[Invalid ranges]" ) {

  int col = -200;
  int row = -10;
  int cell = -3;

  try
  {
    DataStructure initial(row, col, cell);
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(), "Columns and rows should be grater than 1, and cells greater than 0") == 0 );
  }
}

TEST_CASE( "Data Structure negative test 3", "[Empty file]" ) {

  try
  {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/input.txt";
    DataStructure initial(path);
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(), "File is empty") == 0 );
  }
}

TEST_CASE( "Data Structure negative test 4", "[Invalid count alive neighbour cell argument and type]" ) {

  try
  {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
    DataStructure initial(path);
    initial.CountAliveNeighbourCell(100, 100);
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(), "Rows and columns should be within the correct range") == 0 );
  }
}

TEST_CASE( "Data Structure negative test 5", "[Get cell content]" ) {

  try
  {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
    DataStructure initial(path);
    initial.GetCellContent(100, 100);
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(), "Rows and columns should be within the correct range") == 0 );
  }
}

TEST_CASE( "Data Structure negative test 6", "[Set cell content]" ) {

  try
  {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
    DataStructure initial(path);
    initial.SetCellContent(-100, -100, 'o');
  }

  //check that it outputs the correct message
  catch (std::invalid_argument& e)
  {
    REQUIRE( strcmp(e.what(), "Rows and columns should be within the correct range") == 0 );
  }

}

TEST_CASE( "Evolution test 1", "[columns, rows and random cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = row * col;
  std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(row, col);
  gameEvolution evolution(initial);
  evolution.CreateGrid();

  //First check that the class stores and outputs correctly the variables
  auto get_row = evolution.ReturnRows();
  auto get_col = evolution.ReturnColumns();
  auto get_cell = evolution.ReturnCells();

  REQUIRE( get_row == row );
  REQUIRE( get_col == col );
  REQUIRE( get_cell <=  cells );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_cell).name(),  "i") == 0  );
}


TEST_CASE( "Evolution test 2", "[columns, rows and cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = 10;
  std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(row, col, cells);
  gameEvolution evolution(initial);
  evolution.CreateGrid();

  //First check that the class stores and outputs correctly the variables
  auto get_row = evolution.ReturnRows();
  auto get_col = evolution.ReturnColumns();
  auto get_cell = evolution.ReturnCells();

  REQUIRE( get_row == row );
  REQUIRE( get_col == col );
  REQUIRE( get_cell ==  cells );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_cell).name(),  "i") == 0  );

}

TEST_CASE( "Structure test 3", "[columns and rows from path]" ) {

  std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
  std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
  gameEvolution evolution(initial);
  evolution.CreateGridFromFile();

 //First check that the class stores and outputs correctly the variables
  auto get_row = evolution.ReturnRows();
  auto get_col = evolution.ReturnColumns();

  REQUIRE( get_row == 12 );
  REQUIRE( get_col == 12 );

  //Second, check that the type of the variables are correct
  REQUIRE( strcmp(typeid(get_row).name(),  "i") == 0 );
  REQUIRE( strcmp(typeid(get_col).name(),  "i") == 0 );
}

TEST_CASE( "Evolution test 4", "[Take Step function oscillator]" ) {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
    std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
    gameEvolution evolution(initial);
    evolution.CreateGridFromFile();
    evolution.TakeStep();
    auto vec = evolution.ReturnVec();

    //A dead cell with exactly three live neighbours should become a live cell
    REQUIRE(vec[2][1] == 'o');

    //A live cell with two live neighbours should stay alive
    REQUIRE(vec[2][2] == 'o');

    //A live cell with three live neighbours should stay alive
    REQUIRE(vec[7][1] == 'o');
    
    //A live cell with less than two live neighbours should die.
    REQUIRE(vec[2][0] == '-');

    //A live cell with more than three live neighbours should die.
    REQUIRE(vec[5][9] == '-');
}

TEST_CASE( "Evolution test 5", "[Take Step function glider]" ) {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/glider.txt";
    std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
    gameEvolution evolution(initial);
    evolution.CreateGridFromFile();
    evolution.TakeStep();
    auto vec = evolution.ReturnVec();

    //A dead cell with exactly three live neighbours should become a live cell
    REQUIRE(vec[1][1] == 'o');

    //A live cell with two live neighbours should stay alive
    REQUIRE(vec[3][2] == 'o');

    //A live cell with three live neighbours should stay alive
    REQUIRE(vec[3][1] == 'o');
    
    //A live cell with less than two live neighbours should die.
    REQUIRE(vec[1][2] == '-');
}
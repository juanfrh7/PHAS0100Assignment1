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

TEST_CASE( "Data Structure test 1", "[cololumns, rows and random cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = (row-1)*(col-1);
  DataStructure initial(row, col);

  REQUIRE( initial.ReturnRows() == row );
  REQUIRE( initial.ReturnColumns() == col );
  REQUIRE( initial.ReturnCells() <=  cells );
}

TEST_CASE( "Data Structure test 2", "[Set/Get cell content function]" ) {
  int col = 10;
  int row = 10;

  DataStructure initial(row, col);
  initial.Create2DGrid();

  initial.SetCellContent(5, 5, 'o');
  REQUIRE( initial.GetCellContent(5, 5) == 'o' );

  initial.SetCellContent(5, 5, '-');
  REQUIRE( initial.GetCellContent(5, 5) == '-' );
}


TEST_CASE( "Data Structure test 3", "[columns, rows and cell constructor]" ) {
  int col = 5;
  int row = 5;
  int cells = 10;
  DataStructure initial(row, col, cells);

  REQUIRE( initial.ReturnRows() == row );
  REQUIRE( initial.ReturnColumns() == col );
  REQUIRE( initial.ReturnCells() == cells );
}

TEST_CASE( "Data Structure test 4", "[columns and rows from path]" ) {

  std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
  DataStructure initial(path);

  REQUIRE( initial.ReturnRows() == 12 );
  REQUIRE( initial.ReturnColumns() == 12 );
}

TEST_CASE( "Data Structure test 5", "[Count alive neighbour cells function]" ) {

  std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
  DataStructure initial(path);

  //Check at the centre of the grid with alive cells
  int x = initial.CountAliveNeighbourCell(2, 1);

  //Check at a corner with no alive cells
  int y = initial.CountAliveNeighbourCell(0, 0);

  //Check at a border with alive cells
  int z = initial.CountAliveNeighbourCell(11, 3);

  REQUIRE( x == 3 );
  REQUIRE( y == 0 );
  REQUIRE( z == 2 );
}

TEST_CASE( "Evolution test 1", "[Take Step function]" ) {
    std::string path = "/workspaces/PHAS0100Assignment1/Testing/Data/oscillators.txt";
    std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
    gameEvolution evolution(initial);
    evolution.CreateGridFromFile();
    evolution.TakeStep();
    auto vec = evolution.ReturnVec();

    //A dead cell with exactly three live neighbours should become a live cell
    REQUIRE(vec[1][1] == '-');

    //A live cell with two or three live neighbours should stay alive
    REQUIRE(vec[2][2] == 'o');
    
    //A live cell with less than two live neighbours should die.
    REQUIRE(vec[2][0] == '-');

}
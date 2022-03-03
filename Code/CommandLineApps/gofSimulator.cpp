/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golMyFunctions.h>
#include <golExceptionMacro.h>
#include <iostream>
#include "DataStructure.h"
#include "gameEvolution.h"
#include <memory>
#include <utility>    
#include <vector>    
#include <string>
#include <thread>
#include <chrono>
#include <cstring>

/*
This command line allow the user to choose between the following two options:
  1: specifying a text file input or
  2: starting with random cell contents for the initial conditions.

The app also has an argument to control the number of generations to simulate.
 */

int main(int argc, char* argv[])
{
    // Check the number of parameters

    //only running executable
    if (argc == 1) {
      std::cerr << "In order to use the gofSimulator command line, pick between the next options:" << std::endl;
      std::cerr << "  1) "<< argv[0] << " row column cells iterations" << std::endl;
      std::cerr << "  2) " << argv[0] << " row column cells" << std::endl;
      std::cerr << "  3) "<< argv[0] << " filepath.txt" << std::endl;
      std::cerr << "You should specify in the correct order the number of columns, rows, alive cells, iterations and filepath " << std::endl;
    }

    //define the help argument
    if (argc == 2 && (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0)) {
      std::cout << "In order to use the gofSimulator command line, pick between the next options:" << std::endl;
      std::cout << "  1) "<< argv[0] << " row column cells iterations" << std::endl;
      std::cout << "  2) " << argv[0] << " row column cells" << std::endl;
      std::cout << "  3) "<< argv[0] << " filepath.txt" << std::endl;
      std::cout << "You should specify in the correct order the number of columns, rows, alive cells, iterations and filepath" << std::endl;
    }

    //defines and evolves a grid given a filepath
    if (argc == 3) {

      //convert commmand line arguments to correct types
      long arg = strtol(argv[2], NULL, 10);

      //define the system
      std::string path = argv[1];
      std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
      gameEvolution evolution(initial);
      evolution.CreateGridFromFile();

      //evolve and print the grid for each iteration
      for(int i = 0; i < arg; ++i){
        std::cout << "\n" << std::endl;
        std::cout << "Step " << i << std::endl;
        evolution.PrintGrid();
        evolution.TakeStep();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
      }
    }

    //defines and prints a grid
    if (argc == 4) {

      //convert commmand line arguments to correct types
      long arg1 = strtol(argv[1], NULL, 10);
      long arg2 = strtol(argv[2], NULL, 10);
      long arg3 = strtol(argv[3], NULL, 10);

      //define and print the system
      DataStructure initial(arg1, arg2, arg3);
      initial.Create2DGrid();
      initial.SetRandomlyAlive();
      initial.PrintGrid();
    }

    //defines and evolves a grid given the dimensions, alive cells and iterations
    if (argc == 5) {

      //convert commmand line arguments to correct types
      long arg1 = strtol(argv[1], NULL, 10);
      long arg2 = strtol(argv[2], NULL, 10);
      long arg3 = strtol(argv[3], NULL, 10);
      long arg4 = strtol(argv[4], NULL, 10);

      //define the system
      std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(arg1, arg2, arg3);
      gameEvolution evolution(initial);
      evolution.CreateGrid();

      //evolve the system and print it 
      for(int i = 0; i < arg4; ++i){
        std::cout << "\n" << std::endl;
        std::cout << "Step " << i << std::endl;
        evolution.PrintGrid();
        evolution.TakeStep();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    }
    return 0;
}

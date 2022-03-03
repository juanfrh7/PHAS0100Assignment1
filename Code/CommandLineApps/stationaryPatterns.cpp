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
#include <ctime>
#include <vector>    
#include <random>
#include<cstdlib>
#include <cstring>

/*
This command line allow the user to control the number of alive cells, the grid size and the
number of iterations for each configuration. The command line tries out different random initial 
conditions and for each, run the user specified number of calls.
The program prints original and final gridif there is a repetitive pattern throught its evolution.
 */

int main(int argc, char* argv[])
{
    // Check the number of parameters

    //only running executable
    if (argc == 1) {
      std::cerr << "In order to use the stationaryPatterns command line, you should specify:" << std::endl;
      std::cerr << argv[0] << " row column max_cells iterations states" << std::endl;
    }

    //define the help argument
    if (argc == 2 && (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0)) {
        std::cerr << "In order to use the stationaryPatterns command line, you should specify:" << std::endl;
        std::cerr << argv[0] << " row column max_cells iterations states" << std::endl;
    }

    //define and evolve various systems
    //print only the ones with a repetitive pattern
    if (argc == 6) {
      
      //convert commmand line arguments to correct types
      long arg1 = strtol(argv[1], NULL, 10);
      long arg2 = strtol(argv[2], NULL, 10);
      long arg3 = strtol(argv[3], NULL, 10);
      long arg4 = strtol(argv[4], NULL, 10);
      long arg5 = strtol(argv[5], NULL, 10);

      srand(time(0));

      for(int j; j< arg5; ++j){

        //create random number of cells, with cell_max as upper limit
        int cell = rand() % arg3;

        //define the system
        std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(arg1, arg2, cell);
        gameEvolution evolution(initial);
        evolution.CreateGrid();
        auto original = evolution.ReturnVec();

        //evolve it and check for patterns
        for(int i = 0; i < arg4; ++i){
          auto x = evolution.ReturnVec();
          evolution.TakeStep();
          auto y = evolution.ReturnVec();
          std::vector<std::vector<char>> vec(arg1, std::vector<char> (arg2, '-'));

          //if the evolved system is equal to an empty grid, dont print and skip to the next iteration
          if(y == vec){
              break;
              }
          
          //if the evolved system is equal to the previous system, print original and evolved system
          if(x == y){
            std::cout << "\n" << std::endl;
            std::cout << "State " << j << " with " << cell << " alive cells at iteration 0 " << std::endl;
            evolution.PrintOriginalGrid();
            std::cout << "\n" << std::endl;
            std::cout << "State " << j << " has a pattern at iteration " << i + 1 << std::endl;
            evolution.PrintGrid();
            std::cout << "\n" << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            break;
            }
          }
        }
      }
  return 0;
}

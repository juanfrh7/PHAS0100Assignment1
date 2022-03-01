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

// Example, header-only library, included in project for simplicity's sake.
#include <Eigen/Dense>
#include <unsupported/Eigen/NonLinearOptimization>

/**
 * \brief Demo file to check that includes and library linkage is correct.
 */
int main(int argc, char* argv[])
{
    // Check the number of parameters
    if (argc == 1) {
      std::cerr << "In order to use the stationaryPatterns command line, you should specify:" << std::endl;
      std::cerr << argv[0] << " row column max_cells iterations states" << std::endl;
    }

    if (argc == 2 && (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0)) {
        std::cerr << "In order to use the stationaryPatterns command line, you should specify:" << std::endl;
        std::cerr << argv[0] << " row column max_cells iterations states" << std::endl;
    }
    if (argc == 6) {
        long arg1 = strtol(argv[1], NULL, 10);
        long arg2 = strtol(argv[2], NULL, 10);
        long arg3 = strtol(argv[3], NULL, 10);
        long arg4 = strtol(argv[4], NULL, 10);
        long arg5 = strtol(argv[5], NULL, 10);

        srand(time(0));

        for(int j; j< arg5; ++j){
          int cell = rand() % arg3;
          std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(arg1, arg2, cell);
          gameEvolution evolution(initial);
          evolution.CreateGrid();
          auto original = evolution.ReturnVec();
          for(int i = 0; i < arg4; ++i){
            auto x = evolution.ReturnVec();
            evolution.TakeStep();
            auto y = evolution.ReturnVec();
            std::vector<std::vector<char>> vec(arg1, std::vector<char> (arg2, '-'));
            if(y == vec){
                break;
                }
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

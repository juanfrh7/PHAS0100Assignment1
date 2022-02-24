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
      std::cerr << "In order to use the command line, pick between the next options:" << std::endl;
      std::cerr << argv[0] << " row column cells iterations states" << std::endl;
    }
    if (argc == 6) {
        long arg1 = strtol(argv[1], NULL, 10);
        long arg2 = strtol(argv[2], NULL, 10);
        long arg3 = strtol(argv[3], NULL, 10);
        long arg4 = strtol(argv[4], NULL, 10);
        long arg5 = strtol(argv[5], NULL, 10);

        std::cout << arg5 << std::endl;
        for(int j; j< arg5; ++j){
          std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(arg1, arg2, arg3);
          gameEvolution evolution(initial);
          evolution.CreateGrid();
          std::cout << "State " << j << " at iteration 0 " << std::endl;
          evolution.PrintGrid();
          for(int i = 0; i < arg4; ++i){
            auto x = evolution.ReturnVec();
            evolution.TakeStep();
            auto y = evolution.ReturnVec();
            if(x == y){
              std::vector<std::vector<char>> vec(arg2, std::vector<char> (arg3, '-'));
              if(y == vec){
                std::cout << "State " << j << " has no pattern " << std::endl;
                break;
              }
              else{
              std::cout << "State " << j << " has a pattern at iteration " << i + 1 << std::endl;
              evolution.PrintGrid();
              break;
          }
        }
      }
    }
  }
  return 0;
}

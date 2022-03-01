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
      std::cerr << argv[0] << " row column cells iterations" << std::endl;
      std::cerr << "or" << std::endl;
      std::cerr << argv[0] << " filepath.txt" << std::endl;
    }
    if (argc == 3) {
      std::string path = argv[1];
      std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(path);
      gameEvolution evolution(initial);
      evolution.CreateGridFromFile();
      long arg = strtol(argv[2], NULL, 10);
      for(int i = 0; i < arg; ++i){
        std::cout << "Step " << i << std::endl;
        evolution.PrintGrid();
        evolution.TakeStep();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
      }
    }
    if (argc == 5) {
        long arg1 = strtol(argv[1], NULL, 10);
        long arg2 = strtol(argv[2], NULL, 10);
        long arg3 = strtol(argv[3], NULL, 10);
        long arg4 = strtol(argv[4], NULL, 10);
        std::shared_ptr<DataStructure> initial = std::make_shared<DataStructure>(arg1, arg2, arg3);
        gameEvolution evolution(initial);
        evolution.CreateGrid();
        for(int i = 0; i < arg4; ++i){
          std::cout << "Step " << i << std::endl;
          evolution.PrintGrid();
          evolution.TakeStep();
          std::this_thread::sleep_for(std::chrono::milliseconds(200));
      }
    }
    return 0;
}

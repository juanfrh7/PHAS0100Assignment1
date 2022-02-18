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
#include <memory>
#include <utility>    

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
      std::cerr << argv[0] << " row column cells" << std::endl;
      std::cerr << "or" << std::endl;
      std::cerr << argv[0] << " filepath.txt" << std::endl;
    }
    if (argc == 2) {
        DataStructure initial(argv[1]);
        initial.PrintGrid();
    }
    if (argc == 4) {
      int ia1 = atoi(argv[1]);
      int ia2 = atoi(argv[2]);
      int ia3 = atoi(argv[3]); 
      DataStructure initial(ia1, ia2, ia3);
      initial.Create2DGrid();
      initial.SetRandomlyAlive
      initial.PrintGrid();
    }
    return 0;
}

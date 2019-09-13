/******************************************************************************
* Assignment:  Homework #1
* Lab Section: 11883
* Description: This program is used to calculate speed up given specific cores/infinite cores, 
* runtime given specifc cores/infinite cores, along with runtime improvement difference. The calculations 
* are based upon the provided runtime value, percent of program that can be parallelized, and number of 
* cores proived by the user Amdahl.
*
* Programmers: Oluwatosin Ogunjobi oogunjob@purdue.edu
******************************************************************************/
#include <stdio.h>
#include <math.h>

int main ()
{
  double runtime_insert; //the runtime provided by the user
  double runtime; //the runtime calculated by the program given cores
  double percent; //the percent parallelized provided by the user
  double percent_p; //the percent coverted to decimal format for program
  int cores; //the number of cores provided by the user
  double speedup; //the speedup value calculated by the program given cores
  double speedup_inf; //the speedup value calculated by the program with infinite cores
  double runtime_inf; //the runtime value calculated by the program with infinite cores
  double imprve_diff; //the improvement difference between runtime_inf and runtime
  
//Asks the user to enter the runtime  
  printf("Enter the runtime of the program (seconds) -> ");
  scanf("%lf" , &runtime_insert);
//Asks the user to enter the percent that can be parallelized
  printf("Enter the percent of the program that can be parallelized -> ");
  scanf("%lf" , &percent);
//Asks the user to the enter the number of cores
  printf("Enter the number of cores -> ");
  scanf("%d" , &cores);

//Space Divider between inputs and outputs
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

//Outputs runtime
  printf("\nBase runtime: %.3f seconds", runtime_insert);

//Calculates the Amdahl's speedup value
  percent_p = percent / 100;
  speedup = pow(((1 - percent_p) + (percent_p / cores)),-1); 
//Outputs Amdahl's speedup
  printf("\nAmdahl's speedup with %d cores: %.3f", cores, speedup);

//Calculates the runtime given cores
  runtime = ((1 - percent_p) + (percent_p / cores)) * runtime_insert;
//Outputs the runtime
  printf("\nRuntime with %d cores: %.3f seconds", cores, runtime);

//Calculates speedup with infinite cores
  speedup_inf = pow(((1 - percent_p)),-1);
//Outputs Amdahl's speedup with infinite cores
  printf("\nAmdahl's speedup with infinite cores: %.3f", speedup_inf);

//Calculates runtime with infinite cores 
  runtime_inf = runtime_insert / (1 / (1 - percent_p) ) ;
//Outputs runtime with infinite cores
  printf("\nRuntime with infinite cores: %.3f seconds", runtime_inf);

//Calculates runtime difference
  imprve_diff = runtime - runtime_inf;
//Outputs runtime difference
  printf("\nRuntime improvement difference: %.3f seconds", imprve_diff);
  
//Space Divider between inputs and outputs
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  return 0;
}

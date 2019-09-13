/******************************************************************************
 * Assignment:  Homework #02
 * Lab Section: Tuesday, 9:30, SC 179
 * Description: This program is designed to print the results of three different calculations based on which 
 * calculation the user chooses along with the size of data provided and coefficients.
 * Programmers: Oluwatosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
  //Local Declarations
  //Algorithm Complexity Options (Algorithm One)
  double linear_time_one; //variable linear time calculation (Algorithm One)
  double logarithmic_time_one; //variable logarithmic time calculation (Algorithm One)
  double exponential_time_one; //variable for exponential calculation (Algorithm One)

  //Algorithm Complexity Options (Algorithm Two)
  double linear_time_two; //variable linear time calculation (Algorithm Two)
  double logarithmic_time_two; //variable logarithmic time calculation (Algorithm Two)
  double exponential_time_two; //variable for exponential calculation (Algorithm Two)

  //Variables Provided by the User
  double size_data; //size of data provided by the user
  int input_one; //user choice for the first complexity option to be performed
  int input_two; //user choice for the second complexity option to be performed
  double coefficient_one; //coefficient for the first algorithm
  double coefficient_two; //coefficient for the second algorithm
  
  //Different Factors (First Algorithm)
  int factor_one_first; //Variable for a factor of 1 when Complexity Option is 1 for First Algorithm
  int factor_two_first; //Variable for a factor of 1 when Complexity Option is 2 for First Algorithm
  int factor_three_first; //Variable for a factor of 1 when Complexity Option is 3 for First Algorithm
  
  //Different Factors (Second Algorithm)
  int factor_one_second; //Variable for a factor of 1 when Complexity Option is 1 for Second Algorithm
  int factor_two_second; //Variable for a factor of 1 when Complexity Option is 2 for Second Algorithm
  int factor_three_second; //Variable for a factor of 1 when Complexity Option is 3 for Second Algorithm
  
  //Results For Algorithm One and Algorithm Two Times
  double algorithmtime_one; //variable for the calculation of algorithm one time
  double algorithmtime_two; //variable for the calculation of algorithm two time
  
  int faster_algorithm; //displays the faster runtime between algorithm one and algorithm two
  
  double time_difference; //calculates the difference in time between algorithim one and algorithim two
  double correct_time_difference; //finds absolute value of time difference in case initial runtime is a negative value

  //Program Name
  printf("-=- Algorithm Complexity Options -=-\n");
  
  //Displays Complexity Options Used in Program
  printf("\n1. Linear time [n]\n");
  printf("2. Logarithmic time [nlog(n)]\n");
  printf("3. Exponential time [n^2]\n");

  //Asks User to Enter Size of Data Set for Program to Run
  printf("\nEnter the size of the data set to sort -> ");
  scanf("%lf", &size_data);

  //Asks User to Choose Complexity Option #1
  printf("Select complexity option #1 -> ");
  scanf("%d", &input_one);

  //Asks User to Enter Coefficient of Algorithm #1
  printf("Enter the coefficient of algorithm #1 -> ");
  scanf("%lf", &coefficient_one);

  //Asks User to Choose Enter Complexity Option #2
  printf("Select complexity option #2 -> ");
  scanf("%d", &input_two);

  //Asks User to Enter Coefficient of Algorithm #2
  printf("Enter the coefficient of algorithm #2 -> ");
  scanf("%lf", &coefficient_two);

  //Calculations to Create the Factors Equal to 1 (First Algorithm)
  factor_one_first = (input_one / pow(input_one,2)); 
  factor_two_first = (((input_one % 2) - 1) * -1);
  factor_three_first = (input_one / 3);

  //Calculations to Create the Factors Equal to 1 (Second Algorithm)
  factor_one_second = (input_two / pow(input_two,2));
  factor_two_second = (((input_two % 2) - 1) * -1);
  factor_three_second = (input_two / 3);

  //Different Calculations (Algorithm One)
  linear_time_one = (coefficient_one * size_data); //Finds Linear Time (Algorithm 1)
  logarithmic_time_one = (size_data * coefficient_one) * log2(size_data); //Finds Logarithmic Time (Algorithm 1)
  exponential_time_one = (coefficient_one) * (pow(size_data,2)); //Finds Exponential Time (Algorithm 1)

  //Different Calculations (Algorithm Two)
  linear_time_two = (coefficient_two * size_data); //Finds Linear Time (Algorithm Two)
  logarithmic_time_two = (size_data * coefficient_two) * log2(size_data); //Finds Logarithmic Time (Algorithm Two)
  exponential_time_two = (coefficient_two) * (pow(size_data,2)); //Finds Exponential Time (Algorithm Two)

  algorithmtime_one = (linear_time_one * factor_one_first) + (logarithmic_time_one * factor_two_first) + (exponential_time_one * factor_three_first);
  algorithmtime_two = (linear_time_two * factor_one_second) + (logarithmic_time_two * factor_two_second) + (exponential_time_two * factor_three_second);

  //Displays Algorithm Times for Algorithm One and Two
  printf("\nTime for algorithm #1 in seconds: %.3lf\n", algorithmtime_one);
  printf("Time for algorithm #2 in seconds: %.3lf\n", algorithmtime_two);

  //Finds the Faster Algorithm
  faster_algorithm = (algorithmtime_one / algorithmtime_two) + 1;
  printf("Faster algorithm #: %d\n", faster_algorithm);

  //Finds the Time Difference
  time_difference = algorithmtime_one - algorithmtime_two;
  correct_time_difference = sqrt(pow(time_difference,2));
  printf("Time difference (seconds): %.3lf", correct_time_difference);

  return 0;
}

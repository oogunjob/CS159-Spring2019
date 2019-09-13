/******************************************************************************
 * Assignment:  Homework #06
 * Lab Section: Tuesday, 9:30 AM, SC 179
 * Description: This program accepts several integers from the user and calucates the average and mean deviation while also printing the range
 * Programmers: Tosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#define SIZE 20

void getIntegers(int integer[]); //Gets the integers from the user
void printIntegers(int integer[]); //Lists the given integers with commas in between each number
float printAverage(int integer[]); //Prints the mean of the data and returns the mean to main
void printMeanDeviation(int integer[], float average); //Prints the mean deviation of the data set
void printRange(int integer[]); //Prints the range of the data set

int main(void)
{
  int num[SIZE]; //Stores the integers given by the user
  float mean; //Average of the data set

  getIntegers(num); //Retrieves storage of the integers from the user

  printIntegers(num); //Prints out the integers 

  mean = printAverage(num); //Finds the value of the mean

  printMeanDeviation(num, mean); //Finds the value of the mean deviation

  printRange(num); //Prints out the range from the data set

  return 0;
}

/******************************************************************************
 * Function:    printIntegers
 * Description: Prints out the numbers of the array with commas in between each one
 * Parameters:  integer, int, the array that stores the integers given by the user
 * Return:      void
 ******************************************************************************/
void printIntegers(int integer[])
{
  int count; //Keeps track of number of times the loop happens

  printf("Data set as entered: ");

  for (count = 0; count < SIZE - 1; count++) //Prints out the contents of the array except for the last number
    printf("%d, ", integer[count]);

  printf("%d", integer[SIZE - 1]); //Prints out the last number of the array

  return;
}

/******************************************************************************
 * Function:    printAverage
 * Description: Calculates the average of the given data sets and prints it out
 * Parameters:  integer, int, the array that stores the integers given by the user
 * Return:      average, float, the average of the integers
 ******************************************************************************/
float printAverage(int integer[])
{
  int count; //Keeps track of number of times the loop happens
  float sum; //The total of all the numbers in the array
  float average; //The sum of the array divided by the number of integers in the array

  sum = 0;

  for (count = 0; count < SIZE; count++) //Calculate the sum of the all the numbers array
    sum += integer[count];

  average = sum / SIZE; //Calcuates the average of the array
  printf("\nMean: %.2f\n", average); //Prints out the mean

  return average;
}

/******************************************************************************
 * Function:    printMeanDeviation
 * Description: Calucates the mean deviation of the data set and displays the value
 * Parameters:  integer, int, the array that stores the integers given by the user
 *              average, float, the mean of the data set
 * Return:      void
 ******************************************************************************/
void printMeanDeviation(int integer[], float average)
{
  int count; //keeps track of number of times the loop happens
  float summation; //Sum of all numbers in the array subtracted by the average and added together
  float meanDeviation; //The value of how far all values are from the middle

  summation = 0;

  for (count = 0; count < SIZE; count++) //calculates the summation of all the numbers in the array
    summation += (fabs(integer[count] - average));

  meanDeviation = summation / SIZE; //calculates the mean deviation by dividing summation by the number of integers in the array
  printf("Mean Deviation: %.2f\n", meanDeviation); //prints mean deviation

  return;
}

/******************************************************************************
 * Function:    printRange
 * Description: Displays the smallest and largest numbers in the data set of all integers
 * Parameters:  integer, int, the array that stores the integers given by the user
 * Return:      void
 ******************************************************************************/
void printRange(int integer[])
{
  int smallest; //the smallest number in the data set
  int largest; //the largest integer in the data set
  int count; //keeps track of number of times the loop happens

  smallest = integer[0]; //assings 'smallest' as the first number in the data set
  largest = smallest; //assings 'largest' as the first number in the data set

  for (count = 0; count < SIZE; count++) //determines which value will be assigned to 'smallest' and 'largest'
  {
    if (integer[count] < smallest)
    {
      smallest = integer[count];
    }

    if (integer[count] > largest)
    {
      largest = integer[count];
    }
  }

  printf("Range of values: %d, %d", smallest, largest); //Prints out the range

  return; 
}

/******************************************************************************
 * Function:    getIntegers
 * Description: Retrieves the integers from the user
 * Parameters:  integer, int, the array that stores the integers given by the user
 * Return:      void
 ******************************************************************************/
void getIntegers(int integer[])
{
  int count; //keeps track of the number of times a number is being stored

  printf("Enter 20 integer values -> ");
  for (count = 0; count < SIZE; count++) //Retrieves integers from the user
    scanf("%d", &integer[count]);

  printf("\n"); //Create space between input and output of program

  return;
}

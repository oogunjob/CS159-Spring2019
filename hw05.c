/******************************************************************************
 * Assignment:  Homework #05
 * Lab Section: Tuesday, 9:30 AM, SC 179
 * Description: This program gets a desired number from the user and calculates how many attempts it took to get the number or the seed value that was required to acheive it
 * Programmers: Tosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void displayOptions(); //Shows the user the options to select from
int getOption(); //Gets the option from the user
int getSeedValue(); //Gets the seed value from the user
int getDesiredNumber(); //Gets the desired number from the user
int optionEvaluator(int option, int seed, int number, int amount); //Decides wheter the option is '1' or '2' and sends to the appropriate function
int optionOne(int seed, int number, int count); //finds the seed value that was able to generate the desired number first
int optionTwo(int seed, int number, int count); //finds the count of number generations needed to get desired number
void printResults(int option, int startSeed, int desiredValue, int amount); //Prints the results based on the choice and values recorded in program

int main()
{
  int option; //option selected by the user to run
  int seed; //starting seed value given by the user
  int desired_num; //desired number that the user wants to find
  int amount; //starting value that holds the value of the seed needed or count of loops in program

  amount = 0;

  displayOptions(); //Shows the user the options that can be selected from

  option = getOption(); //Gives a value to option
  seed = getSeedValue(); //Gives a value to seed
  desired_num = getDesiredNumber(); //Gives value to desired number

  amount = optionEvaluator(option, seed, desired_num, amount); //Finds the value of either seed or count of number generations depending on the choice 

  printResults(option, seed, desired_num, amount); //Displays the results requested based on the choice of the user

  return 0;
}

/******************************************************************************
 * Function:    displayOptions
 * Description: Displays the options that the user can choose from in the program
 * Parameters:  none
 * Return:      void
 ******************************************************************************/
void displayOptions()
{
  printf("Random Number Testing Options\n");
  printf("%d. Find a seed\n",1);
  printf("%d. Find a number\n",2);

  return;
}

/******************************************************************************
 * Function:    getOption
 * Description: Prompts the user to enter the option and validates it to ensure it is within acceptable range (Borrowed from Professor Alan Bunning)
 * Parameters:  none
 * Return:      int, the number being returned as the option
 ******************************************************************************/
int getOption()
{
  int num; //the variable that will serve as the option

  do //validates that the option entered is either '1' or '2'
  {
    printf("Enter option -> "); //asks user to enter the option
    scanf("%d", &num);

    if (num < 1 || num > 2)
    {
      printf("\nError - Invalid option! Please try again!\n\n"); //prints error message is value is not within certain range
    }
  } while (num < 1 || num > 2);

  return num;
}

/******************************************************************************
 * Function:    getSeedValue
 * Description: Prompts the user to enter the seed value and validates it to ensure it is within acceptable range (Borrowed from Profes
 sor Alan Bunning)
 * Parameters:  none
 * Return:      int, the number being returned as the seed
 ******************************************************************************/
int getSeedValue()
{
  int num; //the variable that will serve as the seed

  do //validates that the seed entered is between '1' and '100000'
  {
    printf("Enter starting seed value -> "); //asks user to enter the seed value
    scanf("%d", &num);

    if (num < 1 || num > 100000)
    {
      printf("\nError - Enter a value from 1 to 100000\n\n"); //prints error message is value is not within certain range
    }
  } while (num < 1 || num > 100000);

  return num;
}

/******************************************************************************
 * Function:    getDesiredNumber
 * Description: Prompts the user to enter the desired number
 * Parameters:  none
 * Return:      int, the desired number from the user being returned
 ******************************************************************************/
int getDesiredNumber()
{
  int num; //the variable that will serve as the desired number

  do //validates that the integer entered is between '0' and '100000'
  {
    printf("Enter desired integer number -> "); //asks user for the desired integer
    scanf("%d", &num);

    if (num < 0 || num > 100000)
    {
      printf("\nError - Enter a value from 0 to 100000\n\n"); //prints error message is value is not within certain range
    }
  } while (num < 0 || num > 100000);

  return num;
}

/******************************************************************************
 * Function:    optionEvaluator
 * Description: Evaluates whether the option from the user was a '1' or '2' and sends to the appropriate function to return amount
 * Parameters:  option, int, the option provided by the user
 *              seed, int, the seed value provided by the user
 *			    number, int, the desired number that the user wants
 *			    amount, int, the count or seed value depending on which function the seed and desired number are sent to
 * Return:      int, the amount that is either the seed value that generated the desired number or the count of number generations made
 ******************************************************************************/
int optionEvaluator(int option, int seed, int number, int amount)
{

  if (option == 1) //sends amount to optionOne function if the user selected '1'
  {
    amount = optionOne(seed, number, amount);
  }

  if (option == 2) //sends amount to optionTwo function if the user selected '2'
  {
    amount = optionTwo(seed, number, amount);
  }

  return amount;

}

/******************************************************************************
 * Function:    optionOne
 * Description: Runs srand operation with seed and finds the seed value that was able to generate the desired number first through incrementation
 * Parameters:  seed, int, the seed value that was provided by the user
 *              number, int, the desired number that the user wants
 *			    count, int, the a count of times a random number in generated
 * Return:      int, the new seed that gave you the generated integer
 ******************************************************************************/
int optionOne(int seed, int number, int count)
{
  int value; //the generated random number
  int range; //range of possible numbers that can be selected from in the program

  range = 100000 + 1;

  do //loops srand and increments seed and count until random number is the same as the desired integer
  {
    srand(seed);
    value = rand() % range;
    count++;
    seed++;
  } while (value != number);

  return (seed - 1);  

}

/******************************************************************************
 * Function:    optionTwo
 * Description: Runs srand operation once with seed and counts the number of times a random number in generated and returns that value
 * Parameters:  seed, int, the seed value that was provided by the user
 *              number, int, the desired number that the user wants
 *			    count, int, the a count of times a random number in generated
 * Return:      int, the count of times that the loop had to run until it reached desired integer
 ******************************************************************************/
int optionTwo(int seed, int number, int count)
{
  int value; //the generated random number
  int range; //range of possible numbers that can be selected from in the program

  range = 100000 + 1;

  srand(seed);

  do //loops random number generation and increments seed and count until random number is the same as the desired integer
  {
    value = (rand() % range);
    count++;
    seed++;
  } while (value != number);

  return count;  

}

/******************************************************************************
 * Function:    printResults
 * Description: displays the results of either Option 1 or Option 2 depending on what the user wants 
 * Parameters:  choice, int, the choice that was provided by the user
 *              startSeed, int, the orignial seed value that was provided by the user at the beginning of the program
 *              desired_value, int, the desired number that the user wanted
 *              amount, int, either the seed value that generated the desired number first or count of random numbers generated based on what the choice was
 * Return:      void
 ******************************************************************************/
void printResults(int choice, int startSeed, int desired_value, int amount)
{
  printf("\nGiven starting seed [%d] and desired number [%d]", startSeed, desired_value); //prints the starting seed and desired integer that the user initially selected

  switch(choice)
  {
    case 1: printf("\nSeed that generates desired number first: %d", amount); //if the choice was '1', prints the seed that generated random number first
            break;
    case 2: printf("\nCount of number generations until desired found: %d", amount); //if the choice was '2', prints the count of number generations until the desired integer was found
            break;
  }

  return;

}

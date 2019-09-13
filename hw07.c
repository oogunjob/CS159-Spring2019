/******************************************************************************
 * Assignment:  Homework #07 
 * Lab Section: Tues, 9:30, SC179
 * Description: This program allows a user to enter intergers into an array and request how many numbers they wish to be sorted. The program will then sort 
 *              them and return final state of array.
 * Programmers: Tosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>

#define SIZE 25

int getIntegers(int array[]); //retrives the integers from the user
int getElements(int array[], int quantity); //retrieves the elements to be sorted by user
void firstSort(int array[], int quantity, int value); //sorts the first set of elements in array
void secondSort(int array[], int quantity, int value); //sorts the final set of elements in array
int determineTruth_One(int array[], int quantity, int value); //determines if the first set is already sorted
void sortDetermination_One(int value); //states the first set is already sorted
int determineTruth_Two(int array[], int quantity, int value); //determines if the final set is already sorted
void sortDetermination_Two(int value); //states the final set is already sorted
void printArray(int array[], int quantity); //prints the final state of the array

int main()
{
  int num[SIZE]; //the array that holds the integers
  int length; //the length of the array given by the user
  int sortValue; //the number of elements that need to be sorted
  int truth; //value reveals if the array is sorted or not

  length = getIntegers(num); //determines what the length of the array will be
  sortValue = getElements(num, length); //determines how many values the user wants to sort

  truth = determineTruth_One(num, length, sortValue); //will determine if the array is sorted or not
  if(truth == 1) //sends the first part of array to be sorted or will return message back to user stating 'already sorted'
    sortDetermination_One(sortValue);
  else
    firstSort(num, length, sortValue);

  truth = determineTruth_Two(num, length, sortValue); //will determine if the array is sorted or not
  if(truth == 1) //sends the second part of array to be sorted or will return message back to user stating 'already sorted'
    sortDetermination_Two(sortValue); 
  else
    secondSort(num, length, sortValue);

  printArray(num, length); //prints the final array in sorted order

  return 0;
}

/******************************************************************************
 * Function:    getIntegers (Borrowed from Lab 11)
 * Description: Retrieves the integers from the user
 * Parameters:  array[], int, the array that stores the integers given by the user
 * Return:      int, count, the size of the data
 ******************************************************************************/
int getIntegers(int array[])
{
  int count; //keeps track of the number of times a number is being stored

  count = 0;

  printf("Enter data set -> "); //Asks the user for the integers to enter

  do //allows user to enter amount of integers
  {
    scanf("%d", &array[count]);
    count++;
  } while (array[count - 1] != -1 && count < SIZE);

  if (array[count - 1] == -1)
    --count;

  return count;
}

/******************************************************************************
 * Function:    getElements
 * Description: Asks the users for the amount of elements they want sorted
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 * Return:      int, the number of elements that the user would like sorted
 ******************************************************************************/
int getElements(int array[], int quantity)
{
  int elements; //the number of integers the user wants sorted

  do //gets the elements that the users wants to sort while checking if less than length and greater than 0
  {
    printf("Enter number of elements to sort -> "); //asks user to enter the option
    scanf("%d", &elements);

    if (elements > quantity)
    {
      printf("\nError! Maximum number to sort is %d\n\n", quantity); //error message
    }

    if (elements <= 0)
    {
      printf("\nError! Positive values only!\n\n"); //error message
    }
  }while (elements > quantity || elements <= 0);

  return elements;       
}

/******************************************************************************
 * Function:    firstSort (Borrowed from Professor Alan Bunning)
 * Description: This function sorts the first set of numbers based on the elements provided by the user
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 *				value, int, the amount of elements that user wants to sort
 * Return:      void
 ******************************************************************************/
void firstSort(int array[], int quantity, int value)
{
  int count; //keeps track of the iteration of loops
  int placeholder; //holds the place of the current variable being sorted
  int temporary; //value assigned from placeholder to sort next number

  for (count = 0; count < value; count++) //sorts the first set of the value requested
  {
    temporary = array[count];
    placeholder = count - 1;

    while (temporary < array[placeholder] && placeholder >= 0)
    {
      array[placeholder + 1] = array[placeholder];
      placeholder--;
    }
    array[placeholder + 1] = temporary;
  }

  printf("\nStatus of first %d elements: ", value);
  for (count = 0; count < value; count++)
    printf("%d ", array[count]); //prints out the first sorted set 

  return;
}

/******************************************************************************
 * Function:    secondSort (Borrowed from Professor Alan Bunning)
 * Description: This function sorts the second set of numbers based on the elements provided by the user
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 *				value, int, the amount of elements that user wants to sort
 * Return:      void
 ******************************************************************************/
void secondSort(int array[], int quantity, int value)
{
  int placeholder; //holds the place of the current variable being sorted
  int temporary; //value assigned from placeholder to sort next number
  int counter; //starts array at second set depending on the value given by user

  for (counter = quantity - value + 1; counter < quantity; counter++) //sorts the first set of the value requested
  {
    temporary = array[counter];
    placeholder = counter - 1;

    while (temporary < array[placeholder] && placeholder >= (quantity - value))
    {
      array[placeholder + 1] = array[placeholder];
      placeholder--;
    }
    array[placeholder + 1] = temporary;
  }

  printf("\nStatus of final %d elements: ", value);
  for (counter = quantity - value; counter < quantity; counter++)
    printf("%d ", array[counter]); //prints out the first sorted set 

  return;    
}

/******************************************************************************
 * Function:    determineTruth_One
 * Description: Decides wheter or not the first set is sorted in ascending order or not and returns truth based on such
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 *				value, int, the amount of elements that user wants to sort
 * Return:      int, num which will either be a '1' representing already sorted or '0' meaning need for sort
 ******************************************************************************/
int determineTruth_One(int array[], int quantity, int value)
{
  int count; //keeps track of the iteration of loops done
  int num; //value determines if the array is sorted or not

  num = 1;
  count = 0;

  while(count < value - 1) //checks that previous number in array is less than the next number
  {
    if(array[count] > array[count + 1])
    {
      num = 0;
      count = value + 1;
    }
    else
      count++;
  }

  return num;
}

/******************************************************************************
 * Function:    determineTruth_Two
 * Description: Decides wheter or not the second set is sorted in ascending order or not and returns truth based on such
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 *				value, int, the amount of elements that user wants to sort
 * Return:      int, num which will either be a '1' representing already sorted or '0' meaning need for sort
 ******************************************************************************/
int determineTruth_Two(int array[], int quantity, int value)
{
  int count; //keeps track of the iteration of loops done
  int num; //value determines if the array is sorted or not
  int start; //where the array starts from

  num = 1;
  count = 0;
  start = quantity - value;

  while(count < value - 1) //checks that previous number in array is less than the next number
  {
    if(array[start + count] > array[start + count + 1])
    {
      num = 0;
      count = value + 1;
    }

    else
      count++;
  }

  return num;
}

/******************************************************************************
 * Function:    sortDetermination_One
 * Description: Prints that the first set of numbers are already sorted if so
 * Parameters:  value, int, the number of elements that user wanted sorted
 * Return:      void
 ******************************************************************************/
void sortDetermination_One(int value)
{

  printf("\nStatus of first %d elements: already sorted", value);

  return;
}

/******************************************************************************
 * Function:    sortDetermination_Two
 * Description: Prints that the second set of numbers are already sorted if so
 * Parameters:  value, int, the number of elements that user wanted sorted
 * Return:      void
 ******************************************************************************/
void sortDetermination_Two(int value)
{

  printf("\nStatus of final %d elements: already sorted", value);

  return;
}

/******************************************************************************
 * Function:    printArray
 * Description: Prints the final configuration of the array after sorts have been made
 * Parameters:  array[], int, the array that stores the integers that need to be sorted
 *              quantity, int, the amount of integers that are currently in the array
 * Return:      void
 ******************************************************************************/
void printArray(int array[], int quantity)
{
  int count; //keeps track of the interation of loops done

  printf("\nFinal array configuration: ");

  for (count = 0; count < quantity; count++)
    printf("%d ", array[count]);

  printf("\n");

  return;
}

/******************************************************************************
 * Assignment:  Homework #04 
 * Lab Section: Tues, 9:30, SC179
 * Description: This program allows the user to enter three characters to select their games and a seed for the random number
 * generator. It then simulates the five spins. displays the results of each game, and prints the user's final score.
 * Programmers: Tosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Function Declarations
void displayChoices(); //Displays choices for user to select from 
int getChoices(char *choice1, char *choice2, char *choice3); //Retrieves the choices from the user
int Randomizer(int); //Creates a random value based on seed number
void displayLandings(int spot1, int spot2, int spot3, int spot4, int spot5); //Displays the five random numbers (landing spots)
int scoreOperator(char, int, int, int, int, int); //evaluates what the score should be based on the choice and landing spots
int colorOperator(char, int, int, int, int, int); //Assigns point value if choice was a color
int numOperator(char, int, int, int, int, int); //Assigns point value if choice was Even or Odd
int halfOperator(char, int, int, int, int, int); //Assigns point value if choice was Higher Half or Lower Half
int dozenOperator(char, int, int, int, int, int); //Assigns point value if choice was 1st dozen, 2nd dozen, or 3rd dozen
void displayScoreBoard(); //Displays the scoreboard
void displayScore(char,int, int); //Displays the scores for each game
void displayTotal(int, int, int); //Displays the total amount of points from the game

int main(void)
{
  //Local Declarations
  char choice1; //The first choice selected by the user
  char choice2; //The second choice selected by the user
  char choice3; //The third choice selected by the user

  int seedvalue; //The seed value provided by the user
  int num1; //First landing spot based on seed value
  int num2; //Second landing spot based on seed value
  int num3; //Third landing spot based on seed value
  int num4; //Fourth landing spot based on seed value
  int num5; //Fifth landing spot based on seed value

  int score1; //Score given based on first choice and landing spots
  int score2; //Score given based on second choice and landing spots
  int score3; //Score given based on third choice and landing spots

  displayChoices(); //Displays the options of the game

  seedvalue = getChoices(&choice1, &choice2, &choice3); //Gets the seed value and choices from the user

  num1 = Randomizer(seedvalue); //Creates random number based on seed
  num2 = rand() % 37;
  num3 = rand() % 37;
  num4 = rand() % 37;
  num5 = rand() % 37;

  displayLandings(num1, num2, num3, num4, num5); //Displays the landing spots based on the seed value

  score1 = scoreOperator(choice1, num1, num2, num3, num4, num5); //Gets the amount of points based on the first choice
  score2 = scoreOperator(choice2, num1, num2, num3, num4, num5); //Gets the amount of points based on the second choice
  score3 = scoreOperator(choice3, num1, num2, num3, num4, num5); //Gets the amount of points based on the third choice

  displayScoreBoard(); //Shows the scoreboard to the user
  displayScore(choice1, 1, score1); //Shows the score to the user (First Game)
  displayScore(choice2, 2, score2); //Shows the score to the user (Second Game)
  displayScore(choice3, 3, score3); //Shows the score to the user (Third Game)
  displayTotal(score1, score2, score3); //Shows the total points to the user

  return 0;
}

/******************************************************************************
 * Function:    displayChoices
 * Description: The function displays the choices the user can select from in the game
 * Parameters:  none
 * Return:      void
 ******************************************************************************/
void displayChoices()
{
  printf("Possible Choices\n"); //Shows the possible choices user can select from along with point values

  printf("\n'1', '2', or '3' for the 1st, 2nd, or 3rd Dozen %d Points\n", 2);
  printf("'R' (Red)  or 'B' (Black) %23d point\n", 1);
  printf("'E' (Even) or 'O' (Odd) %25d point\n", 1);
  printf("'L' (Low)  or 'H' (High) %24d point\n", 1);
  printf("-=-=-=-\n");

  return;
}

/******************************************************************************
 * Function:    getChoices
 * Description: Gets the choices and seed value back from the user and sends them back to main
 * Parameters:  choice1, char, The first game selection chosen by the user
 *              choice2, char, The second game selection chosen by the user
 *				choice3, char, The third game selection chosen by the user
 * Return:      int, the seedvalue is return directly to main function
 ******************************************************************************/
int getChoices(char *choice1, char *choice2, char *choice3)
{
  int seedvalue; //the seedvalue provided by the user
  char value1; //first game choice
  char value2; //second game choice
  char value3; //third game choice

  printf("Enter three choices -> ");
  scanf("%c %c %c", &value1, &value2, &value3); //Gets the three choices from the users

  printf("Enter the seed -> ");
  scanf("%d",&seedvalue); //Gets the seed value

  *choice1 = value1; //Passes choice 1 to main function
  *choice2 = value2; //Passes choice 2 to main function
  *choice3 = value3; //Passes choice 3 to main function

  printf("-=-=-=-");

  return seedvalue; //Returns seed value to main
}

/******************************************************************************
 * Function:    Randomizer
 * Description: This function creates a random number given a seed value (Borrowed from Professor Alan Bunning)
 * Parameters:  SeedVal, int, initial seed value that is given by the user
 * Return:	    int, the random number generated by the program
 ******************************************************************************/
int Randomizer(int SeedVal)
{

  int range; //range of options possible
  int num; //random number produced by program

  srand(SeedVal); //seeds the randomizer
  range = 36 + 1;
  num = rand() % range; 

  return num; //Returns random number back to main
}

/******************************************************************************
 * Function:    displayLandings
 * Description: This function displays the landing spots based on the random numbers
 * Parameters:  spot1, int, the first location spot
 *				spot2, int, the second location spot
 *				spot3, int, the third location spot
 *				spot4, int, the fourth location spot
 *              spot5, int, the fifth location spot
 * Return:      void
 ******************************************************************************/
void displayLandings(int spot1, int spot2, int spot3, int spot4, int spot5)
{
  printf("\nThe Ball Landed On: %d %d %d %d %d", spot1, spot2, spot3, spot4, spot5); //Displays landing spots

  return;
}

/******************************************************************************
 * Function:    scoreOperator
 * Description: This function decides on what the score should be by sending choice and landing spots to other functions in program
 * Parameters:  char, choice, the choice that was provided by the user
 *				int, land1, the first landing spot
 *				int, land2, the second landing spot
 *				int, land3, the third landing spot
 *				int, land4, the fourth landing spot
 *				int, land5, the fifth landing spot
 * Return:      int, the score based on whatever game and choice was selected by the user
 ******************************************************************************/
int scoreOperator(char choice, int land1, int land2, int land3, int land4, int land5)
{
  int score; //the score based on the choice of the game

  if(choice == 'R' || choice == 'B') 
    score = colorOperator(choice, land1, land2, land3, land4, land5); //finds score if the choice was 'R' or 'B' runs this function
  else if (choice == 'E' || choice == 'O')
    score = numOperator(choice, land1, land2, land3, land4, land5); //finds score if the choice was 'E' or 'O' runs this function
  else if (choice == 'L' || choice == 'H')
    score = halfOperator(choice, land1, land2, land3, land4, land5); //finds score if the choice was 'L' or 'H' runs this function
  else if (choice == '1' || choice == '2' || choice == '3')
    score = dozenOperator(choice, land1, land2, land3, land4, land5); //finds score if the choice was '1' , '2', or '3' runs this function

  return score; //returns the score back to main
}

/******************************************************************************
 * Function:    colorOperator
 * Description: This functions assings the value of the score if the option 'R' or 'B' was selected
 * Parameters:  char, choice, the choice that was provided by the user
 *				int, land1, the first landing spot
 *				int, land2, the second landing spot
 *				int, land3, the third landing spot
 *				int, land4, the fourth landing spot
 *				int, land5, the fifth landing spot
 * Return:      int, the score based on how many points were earned
 ******************************************************************************/
int colorOperator(char choice, int land1, int land2, int land3, int land4, int land5) 
{
  int value; //the point value
  value = 0;

  if (choice == 'R') //adds to the score if the choice was 'R' and fell on a certain number
  {
    if (land1 == 1 || land1 == 3 || land1 == 5 || land1 == 7 || land1 == 9 || land1 == 12 || land1 == 14 || land1 == 16 || land1 == 18 || land1 == 19 || land1 == 21 || land1 == 23 || land1 == 25 || land1 == 27 || land1 == 30 || land1 == 32 || land1 == 34 || land1 == 36)
      value++;
    if (land2 == 1 || land2 == 3 || land2 == 5 || land2 == 7 || land2 == 9 || land2 == 12 || land2 == 14 || land2 == 16 || land2 == 18 || land2 == 19 || land2 == 21 || land2 == 23 || land2 == 25 || land2 == 27 || land2 == 30 || land2 == 32 || land2 == 34 || land2 == 36)
      value++;
    if (land3 == 1 || land3 == 3 || land3 == 5 || land3 == 7 || land3 == 9 || land3 == 12 || land3 == 14 || land3 == 16 || land3 == 18 || land3 == 19 || land3 == 21 || land3 == 23 || land3 == 25 || land3 == 27 || land3 == 30 || land3 == 32 || land3 == 34 || land3 == 36)
      value++;
    if (land4 == 1 || land4 == 3 || land4 == 5 || land4 == 7 || land4 == 9 || land4 == 12 || land4 == 14 || land4 == 16 || land4 == 18 || land4 == 19 || land4 == 21 || land4 == 23 || land4 == 25 || land4 == 27 || land4 == 30 || land4 == 32 || land4 == 34 || land4 == 36)
      value++;
    if (land5 == 1 || land5 == 3 || land5 == 5 || land5 == 7 || land5 == 9 || land5 == 12 || land5 == 14 || land5 == 16 || land5 == 18 || land5 == 19 || land5 == 21 || land5 == 23 || land5 == 25 || land5 == 27 || land5 == 30 || land5 == 32 || land5 == 34 || land5 == 36)
      value++;
  }

  else if (choice == 'B') //adds to the score if the choice was 'B' and fell on a certain number
  {
    if (land1 == 6 || land1 == 4 || land1 == 4 || land1 == 6 || land1 == 8 || land1 == 10 || land1 == 11 || land1 == 13 || land1 == 15 || land1 == 17 || land1 == 20 || land1 == 22 || land1 == 24 || land1 == 26 || land1 == 28 || land1 == 29 || land1 == 31 || land1 == 33 || land1 == 35)
      value++;
    if (land2 == 2 || land2 == 4 || land2 == 4 || land2 == 6 || land2 == 8 || land2 == 10 || land2 == 11 || land2 == 13 || land2 == 15 || land2 == 17 || land2 == 20 || land2 == 22 || land2 == 24 || land2 == 26 || land2 == 28 || land2 == 29 || land2 == 31 || land2 == 33 || land2 == 35)
      value++;
    if (land3 == 2 || land3 == 4 || land3 == 4 || land3 == 6 || land3 == 8 || land3 == 10 || land3 == 11 || land3 == 13 || land3 == 15 || land3 == 17 || land3 == 20 || land3 == 22 || land3 == 24 || land3 == 26 || land3 == 28 || land3 == 29 || land3 == 31 || land3 == 33 || land3 == 35)
      value++;
    if (land4 == 2 || land4 == 4 || land4 == 4 || land4 == 6 || land4 == 8 || land4 == 10 || land4 == 11 || land4 == 13 || land4 == 15 || land4 == 17 || land4 == 20 || land4 == 22 || land4 == 24 || land4 == 26 || land4 == 28 || land4 == 29 || land4 == 31 || land4 == 33 || land4 == 35)
      value++;
    if (land5 == 2 || land5 == 4 || land5 == 4 || land5 == 6 || land5 == 8 || land5 == 10 || land5 == 11 || land5 == 13 || land5 == 15 || land5 == 17 || land5 == 20 || land5 == 22 || land5 == 24 || land5 == 26 || land5 == 28 || land5 == 29 || land5 == 31 || land5 == 33 || land5 == 35)
      value++;
  }

  return value; //returns score back to scoreOperator
}

/******************************************************************************
 * Function:    numOperator
 * Description: This functions assings the value of the score if the option 'E' or 'O' was selected
 * Parameters:  char, choice, the choice that was provided by the user
 *				int, land1, the first landing spot
 *				int, land2, the second landing spot
 *				int, land3, the third landing spot
 *				int, land4, the fourth landing spot
 *				int, land5, the fifth landing spot
 * Return:      int, the score based on how many points were earned
 ******************************************************************************/
int numOperator(char choice, int land1, int land2, int land3, int land4, int land5)
{
  int value; //the point value
  value = 0;

  if (choice == 'E') //adds to score if the choice was 'E' and the landing spot was an even number
  {
    if (land1 % 2 == 0 && land1 > 0) //Evalutes if the landing spot is even
      value++;
    if (land2 % 2 == 0 && land2 > 0)
      value++;
    if (land3 % 2 == 0 && land3 > 0)
      value++;
    if (land4 % 2 == 0 && land4 > 0)
      value++;
    if (land5 % 2 == 0 && land5 > 0)
      value++;
  }

  else if (choice == 'O') //adds to score if the choice was 'O' and the landing spot was an odd number
  {
    if (land1 % 2 != 0 && land1 > 0) //Evalutes if the landing spot is odd
      value++;
    if (land2 % 2 != 0 && land2 > 0)
      value++;
    if (land3 % 2 != 0 && land3 > 0)
      value++;
    if (land4 % 2 != 0 && land4 > 0)
      value++;
    if (land5 % 2 != 0 && land5 > 0)
      value++;
  }

  return value; //returns score back to scoreOperator
}

/******************************************************************************
 * Function:    halfOperator
 * Description: This functions assings the value of the score if the option 'L' or 'H' was selected
 * Parameters:  char, choice, the choice that was provided by the user
 *				int, land1, the first landing spot
 *				int, land2, the second landing spot
 *				int, land3, the third landing spot
 *				int, land4, the fourth landing spot
 *				int, land5, the fifth landing spot
 * Return:      int, the score based on how many points were earned
 ******************************************************************************/
int halfOperator (char choice, int land1, int land2, int land3, int land4, int land5)
{
  int value; //the point value
  value = 0;

  if (choice == 'L') //adds to score if the choice was 'L' and the landing spot was between 1 and 18
  {
    if (land1 >= 1 && land1 <= 18) //Evalutes if the landing spot is between 1 and 18
      value++;
    if (land2 >= 1 && land2 <= 18)
      value++;
    if (land3 >= 1 && land3 <= 18)
      value++;
    if (land4 >= 1 && land4 <= 18)
      value++;
    if (land5 >= 1 && land5 <= 18)
      value++;
  }

  else if (choice == 'H') //adds to score if the choice was 'L' and the landing spot was between 19 and 36
  {
    if (land1 >= 19 && land1 <= 36) //Evalutes if the landing spot is between 19 and 36
      value++;
    if (land2 >= 19 && land2 <= 36)
      value++;
    if (land3 >= 19 && land3 <= 36)
      value++;
    if (land4 >= 19 && land4 <= 36)
      value++;
    if (land5 >= 19 && land5 <= 36)
      value++;
  }

  return value; //returns score back to scoreOperator
}

/******************************************************************************
 * Function:    dozenOperator
 * Description: This functions assings the value of the score if the option '1', '2', or '3' was selected
 * Parameters:  char, choice, the choice that was provided by the user
 *				int, land1, the first landing spot
 *				int, land2, the second landing spot
 *				int, land3, the third landing spot
 *				int, land4, the fourth landing spot
 *				int, land5, the fifth landing spot
 * Return:      int, the score based on how many points were earned
 ******************************************************************************/
int dozenOperator (char choice, int land1, int land2, int land3, int land4, int land5)
{
  int value; //the point value
  value = 0;

  if (choice == '1') //adds to score if the choice was '1' and the landing spot was between 1 and 12
  {
    if (land1 >= 1 && land1 <= 12) //Evalutes if the landing spot is between 1 and 12
      value += 2;
    if (land2 >= 1 && land2 <= 12)
      value += 2;
    if (land3 >= 1 && land3 <= 12)
      value += 2;
    if (land4 >= 1 && land4 <= 12)
      value += 2;
    if (land5 >= 1 && land5 <= 12)
      value += 2;
  }

  if (choice == '2') //adds to score if the choice was '2' and the landing spot was between 13 and 24
  {
    if (land1 >= 13 && land1 <= 24) //Evalutes if the landing spot is between 13 and 24
      value += 2;
    if (land2 >= 13 && land2 <= 24)
      value += 2;
    if (land3 >= 13 && land3 <= 24)
      value += 2;
    if (land4 >= 13 && land4 <= 24)
      value += 2;
    if (land5 >= 13 && land5 <= 24)
      value += 2;
  }

  if (choice == '3') //adds to score if the choice was '3' and the landing spot was between 25 and 36
  {
    if (land1 >= 25 && land1 <= 36) //Evalutes if the landing spot is between 25 and 36
      value += 2;
    if (land2 >= 25 && land2 <= 36)
      value += 2;
    if (land3 >= 25 && land3 <= 36)
      value += 2;
    if (land4 >= 25 && land4 <= 36)
      value += 2;
    if (land5 >= 25 && land5 <= 36)
      value += 2;
  }

  return value; //returns score back to scoreOperator
}

/******************************************************************************
 * Function:    displayScoreBoard
 * Description: Displays the score board header that says the name of the game and the score
 * Parameters:  none
 * Return:      void
 ******************************************************************************/
void displayScoreBoard()
{
  printf("\n-=-=-=-\n"); 
  printf("Game           Score"); //Shows the score board of the game

  return;
}

/******************************************************************************
 * Function:    displayScore
 * Description: Function decides the name of the game to display along with the score of the respective game
 * Parameters:  choice, char, the game that was selected by the user
 *              num, int, the order of which game was chosen
 *				score, int, the score based on the points earned by the given game
 * Return:      void
 ******************************************************************************/
void displayScore (char choice, int num, int score)
{  
  switch (choice) //Decides which game to display based on the choice and the points earned
  {
    case 'R': printf("\n%d: Red %11d", num, score);
              break;
    case 'B': printf("\n%d: Black %9d",num,  score);
              break;
    case 'E': printf("\n%d: Even %10d", num, score);
              break;
    case 'O': printf("\n%d: Odd %11d", num, score);
              break;
    case 'L': printf("\n%d: Low %11d", num, score);
              break;
    case 'H': printf("\n%d: High %10d", num, score);
              break;
    case '1': printf("\n%d: 1st dozen %5d", num, score);
              break;
    case '2': printf("\n%d: 2nd dozen %5d", num, score);
              break;
    case '3': printf("\n%d: 3rd dozen %5d", num, score);
  }

  return;
}

/******************************************************************************
 * Function:    displayTotal
 * Description: Displays the total score of the scores of the games combined
 * Parameters:  score1, int, score from the first game
 *              score2, int, score from the second game
 *				score3, int, score from the third game
 * Return:      void
 ******************************************************************************/
void displayTotal (int score1, int score2, int score3)
{
  printf("\nTotal Score: %5d", score1 + score2 + score3);

  return;
}

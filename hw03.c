/******************************************************************************
 * Assignment:  Homework #03
 * Lab Section: Tuesday, 9:30, SC 179
 * Description: This program takes in an intial radius and calculates the circumference, surface area, and volume of it along with half and one fourth of the inital radius. 
 * Programmers: Tosin Ogunjobi oogunjob@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

//Function Declarations
double getRadius(); //gets the Radius from the User
double cutRadius(double num); //splits the radius inserted in half
double calculateCircumference(double circ); //calculates the circumference with a given radius
double calculateSurfaceArea(double area); //calculates the surface area with a given radius
double calculateVolume(double volume); //calculates the volume with a given radius
void printOutputs(int trial, double radius); //displays the ouputs for all circumference, surface area, and volume calculations
void printTotals(double volume, double area); //displays the ouputs for all total volume and surface area for all three radii

int main(void)
{
  //Local Declarations
  double radius; //Variable for the initial radius given and stored by the User
  double radius_two; //Varaible for the second radius calculated by cutRadius function
  double radius_three; //Variable for the third radius calculated by cutRadius function
  double totalVolume; //Variable for the sum of all volumes of spheres
  double totalSurfaceArea; //Variable for the sum of all surface areas of spheres

  radius = getRadius();
  printOutputs(1, radius); //Prints calculations for first radius

  radius_two = cutRadius(radius);
  printOutputs(2, radius_two); //Prints calculations for second radius

  radius_three = cutRadius(radius_two); 
  printOutputs(3, radius_three); //Prints calculations for third radius

  totalVolume = calculateVolume(radius) + calculateVolume(radius_two) + calculateVolume(radius_three); //adds up the volume of all three radii

  totalSurfaceArea = calculateSurfaceArea(radius) + calculateSurfaceArea(radius_two) + calculateSurfaceArea(radius_three); //adds up the surface area of all three radii

  printTotals(totalVolume, totalSurfaceArea); //Prints the totals for volume and surface area

  return 0;
}

/******************************************************************************
 * Function:    getRadius
 * Description: Gets the radius from the user
 * Parameters:  none
 * Return:      double - initial radius used for program
 ******************************************************************************/
double getRadius()
{
  double radius_input; //Varaible for radius given by the user

  //gets the radius to be used throughout the program
  printf("Please enter the value of the largest radius -> ");
  scanf("%lf", &radius_input);
  printf("\n");

  return radius_input;
}

/******************************************************************************
 * Function:    cutRadius
 * Description: Splits the radius inserted in half
 * Parameters:  num, double, the radius given
 * Return:      double - radius given returned in half
 ******************************************************************************/
double cutRadius(double num)
{
  return num * 0.5;
}

/******************************************************************************
 * Function:    calculateCircumference
 * Description: Calculates the circumference given the radius
 * Parameters:  circ, double, the circumference that will be calculated
 * Return:      double - circumference based on the radius
 ******************************************************************************/
double calculateCircumference(double circ)
{
  return 2 * M_PI * circ;
}

/******************************************************************************
 * Function:    calculateSurfaceArea
 * Description: Calculates the surface area given the radius
 * Parameters:  area, double, the area that will be calculated
 * Return:      double - surface area based on the radius
 ******************************************************************************/
double calculateSurfaceArea(double area)
{
  return 4 * M_PI * pow(area,2);
}

/******************************************************************************
 * Function:    calculateVolume
 * Description: Calculates the volume given the radius
 * Parameters:  volume, double, the calculated volume 
 * Return:      double - volume based on the radius
 ******************************************************************************/
double calculateVolume(double volume)
{
  return (4.0 / 3) * M_PI * pow(volume,3);
}

/******************************************************************************
 * Function:    printOutputs
 * Description: Prints the outputs of circumference, surface area, and volume of the sphere given radius to send to different functions
 * Parameters:  trial, int, displays which trial has been run
 *              radius, double, the given radius from program 
 * Return:      void
 ******************************************************************************/
void printOutputs(int trial, double radius)
{
  printf("Radius #%d is: %15.2lf", trial, radius);
  printf("\nCircumference #%d is: %8.2lf", trial, calculateCircumference(radius));
  printf("\nSurface Area #%d is: %9.2lf", trial, calculateSurfaceArea(radius));
  printf("\nVolume #%d is: %15.2lf\n", trial, calculateVolume(radius));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;
}

/******************************************************************************
 * Function:    printTotals
 * Description: Displays the total volume and surface area of all the spheres combined
 * Parameters:  volume, double, and sum of all volumes of the speheres
 *              area, double, and sum of all surface area of the speheres
 * Return:      void
 ******************************************************************************/
void printTotals(double volume, double area)
{
  printf("Total Volume: %15.2lf\n", volume);
  printf("Total Surface Area: %9.2lf\n", area);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;
}

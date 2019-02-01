#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <string>
#include "coordinates.h"
using namespace std;

//      valid file check
//----------------------------------
bool checkIfValid(string file);

bool checkIfFileExist(string file);

bool checkForEmpty(string file);

bool checkForCharacters(string file);

bool checkForMultipleLines(string file);

bool checkForUneven(string file);
//-----------------------------------

void setCoords(coordinate * coordinateArray, string file);

string getType(coordinate * coordinateArray, int mountOfVertices);

int getAmountOfCoordinates(string file);

bool checkForDuplicates(coordinate * coordinateArray, int amountOfVertices);






#endif
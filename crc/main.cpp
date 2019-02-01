#include <iostream>
#include <fstream>
#include <string>
#include "../include/declarations.h"
#include "../include/shape.h"
#include "../include/coordinates.h"
#include "../include/point.h"
#include "../include/line.h"
#include "../include/triangle.h"
#include "../include/polygon.h"
using namespace std;

int main(int argc, const char * argv[])
{
    if (argc != 2){
        cout << "you need one input file" << endl;
        exit(EXIT_FAILURE);
    }

    string str;
    bool isValidFile;
    ifstream myFile;

    isValidFile = checkIfValid(argv[1]);

    if (isValidFile != true)
    {
        cout << "error: invalid file" << endl;
        exit(EXIT_FAILURE);
    }

    int amountOfVertices = getAmountOfCoordinates(argv[1]);

    coordinate * coordArray = new coordinate[amountOfVertices];

    setCoords(coordArray, argv[1]);

    if (checkForDuplicates(coordArray, amountOfVertices) == true){
        cout << "error: duplicate coordinates. " << endl;
        exit(EXIT_FAILURE);
    }

    string type = getType(coordArray, amountOfVertices);

    
    if (type == "point"){
        point fig(amountOfVertices, coordArray);
        cout << "figure type: " << fig.getType() << endl;
        cout << "area: " << fig.area() << endl;
    }
    else if (type == "line"){
        line fig(amountOfVertices, coordArray);
        cout << "figure type: " << fig.getType() << endl;
        cout << "area: " << fig.area() << endl;
    }
    else if (type == "triangle"){
        triangle fig(amountOfVertices, coordArray);
        cout << "figure type: " << fig.getType() << endl;
        cout << "area: " << fig.area() << endl;
    }
    else if (type == "polygon"){
        polygon fig(amountOfVertices, coordArray);
        cout << "figure type: " << fig.getType() << endl;
        cout << "area: " << fig.area() << endl;
    }
    else{
        cout << "error: \"type\" @ main.cpp.r67 " << endl;
    }


    delete[] coordArray;


    

    return 0;
}



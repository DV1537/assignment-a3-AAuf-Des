#include "./shape.h"

class line: public shape{
    public:
    line(int amountOfVertices, coordinate * coordinateArray);

    string getType();
    double area();
    double circumreference();
    coordinate position();
    bool isConvex();
    int distance();
    ~line();
};

line::line(int amountOfVertices, coordinate * coordinateArray){
    coords = new coordinate[amountOfVertices];

    for(int i = 0; i < amountOfVertices; i++){
        coords[i].x = coordinateArray[i].x;
        coords[i].y = coordinateArray[i].y;
    }

    for(int i = 0; i < amountOfVertices; i++){
        coords[i].x = coordinateArray[i].x;
        coords[i].y = coordinateArray[i].y;
    }

    for(int i = 0; i < amountOfVertices; i++){
            centerCoord.x += coords[i].x;
            centerCoord.y += coords[i].y;
    }

    centerCoord.x /= amountOfVertices;

    centerCoord.y /= amountOfVertices;
}

line::~line(){
    delete [] coords;
}


string line::getType(){
    type = "line";
    return type;
}

double line::area(){
    return -1;
}

double line::circumreference(){
    return 0;
}

coordinate line::position(){
    return centerCoord;
}

bool line::isConvex(){
    return false;
}

int line::distance(){
    return 1;

    // not done
}

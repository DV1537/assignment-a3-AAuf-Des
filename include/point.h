#include "./shape.h"

class point: public shape{
    public:
    point(int amountOfVertices, coordinate * coordinateArray);

    string getType();
    double area();
    double circumreference();
    coordinate position();
    bool isConvex();
    int distance();
    ~point();
};

point::~point(){
    delete[] coords;
}

point::point(int amountOfVertices, coordinate * coordinateArray){
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

string point::getType(){
    type = "point";
    return type;
}

double point::area(){
    return -1;
}

double point::circumreference(){
    return 0;
}

coordinate point::position(){
    return centerCoord;
}

bool point::isConvex(){
    return false;
}

int point::distance(){
    return 0;
}

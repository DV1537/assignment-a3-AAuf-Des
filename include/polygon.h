#include "./shape.h"

class polygon: public shape{
    public:
    polygon(int amountOfVertices, coordinate * coordinateArray);

    string getType();
    double area();
    double circumreference();
    coordinate position();
    bool isConvex();
    int distance();
    ~polygon();
};

polygon::polygon(int amountOfVertices, coordinate * coordinateArray){
    coords = new coordinate[amountOfVertices];
    sides = new double[amountOfVertices];

    coordSize = amountOfVertices;

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


polygon::~polygon(){
    delete [] coords;
    delete [] sides;
    
}

string polygon::getType(){
    type = "polygon";

    return type;
}

double polygon::area(){
    double total = 0;
    double area = 0;

    int j = coordSize - 1;

    for(int i = 0; i < coordSize; i++){
        total += (coords[j].x + coords[i].x ) * (coords[j].y - coords[i].y);
        j = i;
    }

    area = abs(total/2);

    return area;
}


double polygon::circumreference(){
    double circumreference = 0;

    for(int i = 0; i < coordSize; i++){
        if (i != coordSize - 1){
            sides[i] = sqrt(pow(coords[i].x - coords[i+1].x , 2) + pow(coords[i].y - coords[i+1].y, 2));
        }

        else{
            sides[i] = sqrt(pow(coords[i].x - coords[0].x , 2) + pow(coords[i].y - coords[0].y, 2));
        }        
    }

    for(int i = 0; i < coordSize; i++){
        circumreference = circumreference + sides[i];
    }

    return circumreference;
}

coordinate polygon::position(){
    return centerCoord;
}

bool polygon::isConvex(){
    int s = coordSize - 2;
    double *coordinateDirection = new double[s];
    double dot[4] = {0};

    for (int l = 0; l < s; l++)
    {
        dot[0] = coords[l+1].x - coords[l].x;
        dot[1] = coords[l+1].y - coords[l].y;
        
        dot[2] = coords[l+2].x - coords[l+1].x;
        dot[3] = coords[l+2].y - coords[l+1].y;
        
        coordinateDirection[l] = dot[0] * dot[3] - dot[1] * dot[2];
    }

    bool positive = false;
    bool negative = false;

    for (int l = 0; l < s; l++)
    {
        if (coordinateDirection[l] > 0){
            positive = true;
        }
        else{
            negative = true;
        }
    }

    delete [] coordinateDirection;

    if (positive && negative){
        return false;
    }
    else{
        return true;
    }
}

int polygon::distance(){
    return 0;
}
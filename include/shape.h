#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <cmath>
#include "coordinates.h"
using namespace std;


class shape{
    public:
    virtual string getType() = 0;
    virtual double area() = 0;
    virtual double circumreference() = 0;
    virtual coordinate position() = 0;
    virtual bool isConvex() = 0;
    virtual int distance() = 0;


    protected:
    coordinate * coords;
    double * sides;
    coordinate centerCoord;
    string type;
    int coordSize;
}; 





#endif
#include <iostream>
#include <cmath>
#define int long long
using namespace std;

const double PI = 2 * asin(1.0); 

struct StructCoordinates{
    double x;
    double y;
};

struct StructPolygon{
    int sidesNum;
    double sideLength;
    double area;
    double perimeter;
    StructCoordinates pointCoordinates;
}RegularPolygon;

void input_polygon();
void inf_delete();
double calculate_area(double sideLength, double sidesNum);
double calculate_perimeter(double sideLength, double sidesNum);
double *find_coordinates();

signed main()
{
    return 0;
}

void input_polygon(){
    cout << "Give me sides number: ";
    cin >> RegularPolygon.sidesNum;
    while(RegularPolygon.sidesNum < 3){
        cout << "Wrong number, it can't be lower than 3, try again, please: " << endl;
        cin >> RegularPolygon.sidesNum;
    }
    cout << endl << "Give me side length: ";
    cin >> RegularPolygon.sideLength;
    while(RegularPolygon.sideLength <= 0){
        cout << "Wrong length, please, try again: ";
        cin >> RegularPolygon.sideLength;
    }
    RegularPolygon.perimeter = calculate_perimeter(RegularPolygon.sideLength, RegularPolygon.sidesNum);
    RegularPolygon.area = calculate_area(RegularPolygon.sideLength, RegularPolygon.sidesNum);
}

double calculate_perimeter(double sideLength, int sidesNum){
    return (sideLength * sidesNum);
}

double calculate_area(double sideLength, int sidesNum){
    if(sidesNum == 3){
        return (pow(sideLength, 2) * sqrt(3) / 4);
    }
    if(sidesNum == 4){
        return (pow(sideLength, 2));
    }
    return (pow(sideLength, 2) * sidesNum / (4 * tan(PI/sidesNum)));
}


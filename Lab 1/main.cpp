#include <iostream>
#include <cmath>
#define int long long
using namespace std;

const double PI = 2 * asin(1.0); 

struct StructPolygon{
    int sidesNum;
    double sideLength;
    double area;
    double perimeter;
    double pointCoordinates;
}RightPolygon;

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
    cin >> RightPolygon.sidesNum;
    while(RightPolygon.sidesNum < 3){
        cout << "Wrong number, it can't be lower than 3, try again, please: " << endl;
        cin >> RightPolygon.sidesNum;
    }
    cout << endl << "Give me side length: ";
    cin >> RightPolygon.sideLength;
    while(RightPolygon.sideLength <= 0){
        cout << "Wrong length, please, try again: ";
        cin >> RightPolygon.sideLength;
    }
    RightPolygon.perimeter = calculate_perimeter(RightPolygon.sideLength, RightPolygon.sidesNum);
    RightPolygon.area = calculate_area(RightPolygon.sideLength, RightPolygon.sidesNum);
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

#include <iostream>
#include <cmath> //to work with area & coordinates
#include <limits> //to check input
#include <string> //to use gets()
#define int long long
using namespace std;

const double PI = 2 * asin(1.0);

struct StructCoordinates{
    double x;
    double y;
};

signed main()
{
    int sidesNum = 6;
    double x1 = 50, y1 = 50, sideLength = 12;
    
    StructCoordinates *coordinates = new StructCoordinates[sidesNum];
    
    double R = sideLength / (2 * sin(PI / sidesNum));
    double x0 = x1 - R * cos(sqrt(x1 * x1 + y1 * y1) / x1), y0 = y1 - R * sin(sqrt(x1 * x1 + y1 * y1) / y1);
    double centerAngle = 2 * PI / sidesNum;
    double angle = atan2((x1 - x0), (y1 - y0));
    
    cout << "x0 = " << x0 << endl << "y0 = " << y0 << endl;
    cout << "R = " << R << endl;
    
    coordinates[0].x = x1;
    coordinates[0].y = y1;
    
    for (int i = 1; i < sidesNum; i++)
    {
        coordinates[i].x = x0 + sideLength * cos(angle + i * centerAngle);
        coordinates[i].y = y0 + sideLength * sin(angle + i * centerAngle);
    }
    
    for (int i = 0; i < sidesNum; i++) {
        cout << "[" << coordinates[i].x << ", " << coordinates[i].y << "]" << endl;
    }
    
    return 0;
}

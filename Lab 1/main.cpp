#include <iostream>
#include <cmath> //to work with area & coordinates
#include <limits> //to check input
#include <cstdio> //to use gets()
#include <string>
#define int long long
using namespace std;

const double PI = 2 * asin(1.0);
int polygonsNum = 1;

struct StructCoordinates{
    double vertexCoordinates[2];
};

struct StructPolygon{
    int sidesNum;
    double sideLength;
    double area;
    double perimeter;
    StructCoordinates pointCoordinates;
}RegularPolygon;

void input_polygon(StructPolygon &RegularPolygon);
void inf_delete();
double calculate_area(const double sideLength, const int sidesNum);
double calculate_perimeter(const double sideLength, const int sidesNum);
double *find_coordinates(StructPolygon &RegularPolygon);
StructPolygon *rewrite_inf(StructPolygon *allPolygons, int polygonsNum);
void input_and_exit_checking(string &str);
void draw_menu();

signed main(){
    string temp_str;
    StructPolygon *allPolygons = new StructPolygon[1];
    do{
        input_and_exit_checking(temp_str);
    }while(true);
    delete [] allPolygons;
    return 0;
}

void input_polygon(StructPolygon &RegularPolygon){
    cout << "Give me sides number: ";
    cin >> RegularPolygon.sidesNum;
    while(cin.fail() || RegularPolygon.sidesNum < 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It should be a number which can not be lower 3, try again, please: ";
        cin >> RegularPolygon.sidesNum;
    }

    cout << endl << "Give me side length: ";
    cin >> RegularPolygon.sideLength;
    while(cin.fail() || RegularPolygon.sideLength <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It should be a number which should be above 0, try again, please: ";
        cin >> RegularPolygon.sideLength;
    }
    RegularPolygon.perimeter = calculate_perimeter(RegularPolygon.sideLength, RegularPolygon.sidesNum);
    RegularPolygon.area = calculate_area(RegularPolygon.sideLength, RegularPolygon.sidesNum);
}

double calculate_perimeter(const double sideLength, const int sidesNum){
    return (sideLength * sidesNum);
}

double calculate_area(const double sideLength, const int sidesNum){
    if(sidesNum == 3){
        return (pow(sideLength, 2) * sqrt(3) / 4);
    }
    if(sidesNum == 4){
        return (pow(sideLength, 2));
    }
    return (pow(sideLength, 2) * sidesNum / (4 * tan(PI/sidesNum)));
}

/*double *find_coordinates(StructPolygon &RegularPolygon){

}*/

StructPolygon *rewrite_inf(StructPolygon *allPolygons, const int polygonsNum){
    StructPolygon *newAllPolygons = new StructPolygon[polygonsNum + 1];
    for(int i = 0; i < polygonsNum; ++i){
        newAllPolygons[i] = allPolygons[i];
    }
    delete [] allPolygons;
    return (newAllPolygons);
}

void exit_checking(string &str){
    cin >> str;
    cout << "Would you lke to continue?";
    if(str == "exit" || str == "Exit"){
        cout << "Are you sure you'd like to ext?";
        str = "";
        cin >> str;
        if(str == "Yes" || str == "yes" || str == "yep" || str == "Yep"){
            exit(0);
        }
    }
    else{
        cout << "OK, let's write a new polygon." << endl;
    }
}

void draw_menu(){

}

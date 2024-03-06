#include <iostream>
#include <cmath> //to work with area & coordinates
#include <limits> //to check input
#include <cstdio> //to use gets()
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
    StructCoordinates coordinates;
}RegularPolygon;

void input_polygon(StructPolygon &RegularPolygon);
double calculate_area(const double sideLength, const int sidesNum);
double calculate_perimeter(const double sideLength, const int sidesNum);
double *find_coordinates(StructPolygon &RegularPolygon);
StructPolygon *add_polygon(StructPolygon *allPolygons, int &polygonsNum);
StructPolygon *delete_polygon(StructPolygon *allPolygons, int &polygonsNum);
void polygons_output(StructPolygon *allPolygons, const int polygonsNum);
void exit_checking();
void clear_console();
void draw_menu();
void user_input(StructPolygon *allPolygons, int &polygonsNum);
//add checking deleting and may be adding, realise choosing a number of polygon to delete, main, work with coordinates
//max area, max perimeter, return into menu

signed main(){
    int polygonsNum = 0;
    StructPolygon *allPolygons = new StructPolygon[polygonsNum];
    do{
        draw_menu();
        user_input(allPolygons, polygonsNum);
    }while(true);
    delete [] allPolygons;
    return 0;
}

//add coordinates writing
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
    clear_console();
}

void polygons_output(StructPolygon *allPolygons, const int polygonsNum){
    if(polygonsNum == 0){
        cout << "You have no polygons to output" << endl;
    }
    for(int i = 0; i < polygonsNum; ++i){
        cout << "Polygon " << i + 1 << ", sides number: " << allPolygons[i].sidesNum << ", side length: " <<
            allPolygons[i].sideLength << ", vertex coordinates: ";
        //ещё нужен вывод координат
        /*for(int j = 0; j < allPolygons[i].sidesNum; ++j){

        }*/
        cout << "; area: " << allPolygons[i].area << "; perimeter: " << allPolygons[i].perimeter << endl;
    }
    cout << endl;
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

StructPolygon *add_polygon(StructPolygon *allPolygons, int &polygonsNum){
    ++polygonsNum;
    StructPolygon *newAllPolygons = new StructPolygon[polygonsNum];
    for(int i = 0; i < polygonsNum; ++i){
        newAllPolygons[i] = allPolygons[i];
    }
    StructPolygon newPolygon;
    input_polygon(newPolygon);
    newAllPolygons[polygonsNum - 1] = newPolygon;
    delete [] allPolygons;
    return (newAllPolygons);
}

StructPolygon *delete_polygon(StructPolygon *allPolygons, int &polygonsNum){
    if(polygonsNum == 0){
        cout << "You have no polygons to delete" << endl;
        cout << endl;
        return(allPolygons);
    }
    cout << "Give me a number of the polygon you'd like to delete" << endl;
    int index;
    cin >> index;
    while(index < 0 || index > polygonsNum){
        cout << "Input index can not be less than 1 or more than polygons number (" << polygonsNum << ")" << endl;
        cin >> index;
        --index;
    }
    --polygonsNum;
    StructPolygon *newAllPolygons = new StructPolygon[polygonsNum];
    for(int i = 0; i < index; ++i){
        newAllPolygons[i] = allPolygons[i];
    }
    for(int i = 0; i > index && i < polygonsNum; ++i){
        newAllPolygons[i] = allPolygons[i];
    }
    delete [] allPolygons;
    return (newAllPolygons);
}

void exit_checking(){
    int flag;
    cout << "Are you sure you'd like to exit? Wrte 1, if yes, else 2" << endl;
    while(flag != 1 || flag != 2){
        cin >> flag;
        if(flag == 1){
            exit(0);
        }
        else if(flag == 2){
                clear_console();
            cout << "OK, let's write a new polygon." << endl;
            break;
        }
        else{
            cout << "Error input, you should write 1, if you'd like to exit, or 2, if you'd like to continue." << endl;
        }
    }
}

void clear_console(){
    int num = 100;
    for(int i = 0; i < num; ++i){
        cout << endl;
    }
}

void draw_menu(){
    cout << "Choose one of this variants and give me a number: " << endl;
    cout << "1. Write a new polygon" << endl;
    cout << "2. Show information about polygons" << endl;
    cout << "3. Delete polygon" << endl;
    cout << "4. Exit" << endl;
}

void user_input(StructPolygon *allPolygons, int &polygonsNum){
    int number;
    cin >> number;
    clear_console();
    switch(number){
    case 1:
        add_polygon(allPolygons, polygonsNum);
        break;
    case 2:
        polygons_output(allPolygons, polygonsNum);
        break;
    case 3:
        delete_polygon(allPolygons, polygonsNum);
        break;
    case 4:
        exit_checking();
        break;
    default:
        cout << "Wrong input, try again, please";
    }
}

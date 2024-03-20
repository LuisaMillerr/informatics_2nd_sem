#include <iostream>
#include <cmath> //to work with area & coordinates
#include <limits> //to check input
#include <cstdio> //to use gets()
#define int long long

using namespace std;

const double PI = 2 * asin(1.0);
int polygonsNum = 0;

struct StructCoordinates{
    double x;
    double y;
};

struct StructPolygon{
    int sidesNum;
    double sideLength;
    double area;
    double perimeter;
    StructCoordinates *vertexCoordinates;
}RegularPolygon;

void input_polygon(StructPolygon &RegularPolygon);
double calculate_area(const double sideLength, const int sidesNum);
double calculate_perimeter(const double sideLength, const int sidesNum);
double *find_coordinates(StructPolygon &RegularPolygon);
StructPolygon *add_polygon(StructPolygon *allPolygons);
StructPolygon *delete_polygon(StructPolygon *allPolygons);
void polygons_output(StructPolygon *allPolygons, const int polygonsNum);
void exit_checking();
void clear_console();
void draw_menu();
void user_input(StructPolygon *allPolygons);
void find_max_data(StructPolygon *allPolygons, const int polygonsNum, int choice = 1);
void draw_menu2();
void analyse(StructPolygon *allPolygons, const int polygonsNum);

signed main(){
    clear_console();
    StructPolygon *allPolygons = new StructPolygon[polygonsNum];
    do{
        draw_menu();
        int number;
        cin >> number;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "It should be an integer number from 1 to 5" << endl;
            cin >> number;
        }
        clear_console();
        switch(number){
        case 1:
            allPolygons = add_polygon(allPolygons);
            clear_console();
            break;
        case 2:
            polygons_output(allPolygons, polygonsNum);
            break;
        case 3:
            allPolygons = delete_polygon(allPolygons);
            clear_console();
            break;
        case 4:
            analyse(allPolygons, polygonsNum);
            break;
        case 5:
            exit_checking();
            break;
        default:
            cout << "Wrong input, try again, please" << endl;
        }
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

    cout << "Give me side length: ";
    cin >> RegularPolygon.sideLength;
    while(cin.fail() || RegularPolygon.sideLength <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It should be a number which should be above 0, try again, please: ";
        cin >> RegularPolygon.sideLength;
    }

    find_coordinates(RegularPolygon);

    RegularPolygon.perimeter = calculate_perimeter(RegularPolygon.sideLength, RegularPolygon.sidesNum);
    RegularPolygon.area = calculate_area(RegularPolygon.sideLength, RegularPolygon.sidesNum);
}

void polygons_output(StructPolygon *allPolygons, const int polygonsNum){
    if(polygonsNum == 0){
        cout << "You have no polygons to output" << endl;
    }
    for(int i = 0; i < polygonsNum; ++i){
        //double x = allPolygons[i].vertexCoordinates[0].x, y = allPolygons[i].vertexCoordinates[0].y;
        cout << "Polygon " << i + 1 << ", sides number: " << allPolygons[i].sidesNum << ", side length: " <<
            allPolygons[i].sideLength << ", vertex coordinates: ";
//        for(int j = 0; j < allPolygons[i].sidesNum; ++j){
//            cout << "[" << x << ", " << y << "] ";
//        }
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

double *find_coordinates(StructPolygon &RegularPolygon){
    RegularPolygon.vertexCoordinates = new StructCoordinates[RegularPolygon.sidesNum];
    double R = RegularPolygon.sideLength / (2 * sin(PI / RegularPolygon.sidesNum)); //радиус описанной окружности

    cout << "Give me coordinates of the vertex furthest from the origin: " << endl;
    cout << "x: ";
    cin >> RegularPolygon.vertexCoordinates[0].x;
    cout << "y: ";
    cin >> RegularPolygon.vertexCoordinates[0].y;
    double x1 = RegularPolygon.vertexCoordinates[0].x, y1 = RegularPolygon.vertexCoordinates[0].y;

    double R0 = sqrt(x1 * x1 + y1 * y1); //расстояние до начала координат

    while(cin.fail() || R0 < R){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It should be a double numbers and sqrt(x * x + y * y) can't be less than " << R << ", try again, please" << endl;
        cout << "x: ";
        cin >> x1;
        cout << "y: ";
        cin >> y1;
        R0 = sqrt(x1 * x1 + y1 * y1);
    }

    double x0 = x1 - R * (x1 / R0), y0 = y1 - R * (y1 / R0); //координаты центра

    for(int i = 1; i < RegularPolygon.sidesNum; ++i){
        double x = RegularPolygon.vertexCoordinates[i].x, y = RegularPolygon.vertexCoordinates[i].y;
        //x =
    }
}

StructPolygon *add_polygon(StructPolygon *allPolygons){
    ++polygonsNum;
    StructPolygon *newAllPolygons = new StructPolygon [polygonsNum];
    for(int i = 0; i < polygonsNum - 1; ++i){
        newAllPolygons[i] = allPolygons[i];
    }
    StructPolygon tempPolygon;
    input_polygon(tempPolygon);
    newAllPolygons[polygonsNum - 1] = tempPolygon;
    delete [] allPolygons;
    return newAllPolygons;
}

StructPolygon *delete_polygon(StructPolygon *allPolygons){
    if(polygonsNum == 0){
        cout << "You have no polygons to delete" << endl;
        cout << endl;
        return(allPolygons);
    }
    cout << "Give me a number of the polygon you'd like to delete" << endl;
    int index;
    cin >> index;
    while(cin.fail() || index < 0 || index > polygonsNum) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input index should be an integer number and it can not be less than 1 or more than polygons number (" << polygonsNum << ")" << endl;
        cin >> index;
    }
    --index;
    --polygonsNum;
    StructPolygon *newAllPolygons = new StructPolygon[polygonsNum];

    for(int i = 0; i < polygonsNum; ++ i){
        if(i < index){
            newAllPolygons[i] = allPolygons[i];
            continue;
        }
        ++index;
        newAllPolygons[i]  = allPolygons[index];
    }

    polygons_output(newAllPolygons, polygonsNum);

    delete [] allPolygons;
    return (newAllPolygons);
}

void exit_checking(){
    int flag;
    cout << "Are you sure you'd like to exit? Write 1, if yes, else 2." << endl;
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
    cout << "4. Analyze data" << endl;
    cout << "5. Exit" << endl;
}

void find_max_data(StructPolygon *allPolygons, const int polygonsNum, int choice){
    if(polygonsNum == 0){
        cout << "You have no polygons to analyze" << endl;
        return;
    }
    double max_area = 0; double max_peremeter = 0;
    if(choice == 1){
        for(int i = 0; i < polygonsNum; ++i){
            if(allPolygons[i].area > max_area){
                max_area = allPolygons[i].area;
            }
        }
        cout << "The data you were interested in: " << max_area << endl;
        return;
    }
    for(int i = 0; i < polygonsNum; ++i){
        if(allPolygons[i].perimeter > max_peremeter){
            max_peremeter = allPolygons[i].perimeter;
        }
    }
    cout << "The data you were interested in: " << max_peremeter << endl;
}

void draw_menu2(){
    cout << "Choose one of this variants and give me a number: " << endl;
    cout << "1. Find max area" << endl;
    cout << "2. Find max perimeter" << endl;
    cout << "3. Return to the menu" << endl;
}

void analyse(StructPolygon *allPolygons, const int polygonsNum){
    while(true){
        draw_menu2();
        int choice;
        cin >> choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "It should be an integer number from 1 to 3" << endl;
            cin >> choice;
        }
        if(choice == 3){
            clear_console();
            return;
        }
        switch(choice){
        case 1:
            clear_console();
            find_max_data(allPolygons, polygonsNum, 1);
            break;
        case 2:
            clear_console();
            find_max_data(allPolygons, polygonsNum, 2);
            break;
        default:
            "Wrong input, try again, please. It should be an integer number from 1 to 3";
            break;
        }
    }
}

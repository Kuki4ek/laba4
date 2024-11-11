#define _CRT_SECURE_NO_WARNINGS
#include "Libs/vechicle.h"
#include "Libs/file_proccessor.h"
#include "Libs/parser.h"
#include "Libs/register_vehicles.h"
#include "Libs/other_functions.h"
#include <iostream>
#include <string>
#include <locale>
#define FILENAME "vehicles.txt"
#define MAX_VEHICLE_COUNT 32

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    RegisterVehicles Vehicles(MAX_VEHICLE_COUNT);
    while (true) {
        int operation = 0;
        cout << "Меню\nВыберите операцию:\n1-Ввод данных с клавиатуры\n2-Ввод в файл\n3-Вывод из файла\n4-Вывод данных на экран\n5-Выполнить задания\n6-Выход" << endl;
        cout << ">";
        cin >> operation;
        int count = 0;
        
        switch (operation)
        {
        case 1:
            Vehicles.SetList(UserInput(&count, MAX_VEHICLE_COUNT));
            break;
        case 2:
            Vehicles.WriteToFile(FILENAME);
            break;
        case 3:
            Vehicles.ReadFromFile(FILENAME);
            break;
        case 4:
            Vehicles.DisplayAll();
            break;
        case 5:
            Vehicles.Task1();
            Vehicles.Task2();
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Ошибка" << endl;
            break;
        }
    }
    return 0;
}

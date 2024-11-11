#include "other_functions.h"
#include <iostream>
Vehicle* UserInput(int* countIn, int MaxCount) {
    int count = 0;
    cout << "Введите колличество записей" << endl;
    while (true) {
        cin >> count;
        if (count > MaxCount) {
            cout << "Ошибка, попробуйте снова: ";
        }
        else {
            break;
        }
    }
    *countIn = count;
    cin.ignore();
    Vehicle* v = new Vehicle[count];
    for (int i = 0; i < count; i++) {
        string buff;
        std::cout << "Введите данные для автомобиля " << (i + 1) << ":\n";
        std::cout << "Владелец: ";
        getline(std::cin, buff);
        v[i].setVehicleName(buff);
        std::cout << "Регистрационный номер: ";
        getline(std::cin, buff);
        v[i].setVehicleRegNumber(buff);
        std::cout << "Тип: ";
        getline(std::cin, buff);
        v[i].setVehicleType(buff);
        std::cout << "Марка: ";
        getline(std::cin, buff);
        v[i].setVehicleBrand(buff);
        std::cout << "Объем (л): ";
        getline(std::cin, buff);
        v[i].setVehicleVolume(stof(buff));
        std::cout << "Мощность (л.с.): ";
        getline(std::cin, buff);
        v[i].setVehiclePower(stof(buff));
        std::cout << "Дата последнего техосмотра: ";
        getline(std::cin, buff);
        v[i].setVehicleLastTo(buff);
        std::cout << "Пробег (км): ";
        getline(std::cin, buff);
        v[i].setVehicleMileage(stof(buff));
        std::cout << "Данные автомобиля " << (i + 1) << " успешно сохранены!\n\n";
    }
    return v;
}
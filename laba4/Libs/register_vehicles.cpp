#include "register_vehicles.h"
#include "file_proccessor.h"
#include "parser.h"
#include "other_functions.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#define INDENTATION 8
using namespace std;
RegisterVehicles::RegisterVehicles(int max_v) {
	max_num_vehicles = max_v;
	list = new Vehicle[max_num_vehicles];
	num_vehicles = 0;
}
RegisterVehicles::~RegisterVehicles() {
	max_num_vehicles = 0;
	delete[] list;
	num_vehicles = 0;
}
int RegisterVehicles::AddVehicle(Vehicle v) {
	/*
		0 - ЛИМИТ ПРИВЫШЕН
		1 - Всё ок
	*/
	int flag;
	if (num_vehicles < max_num_vehicles) {
		list[num_vehicles] = v;
		num_vehicles++;
		flag = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}
void RegisterVehicles::ReadFromFile(string filename) {
	string data = "";
	string* dataArr;
	string delimeter = "---\n";
	int count = 0;
	data = FileProccessor::ReadFile(filename);
	dataArr = Parser::Split(data, delimeter, count);
	for (int i = 0; i < count; i++) {
		list[i] = Parser::ParseStringToVechicle(dataArr[i]);
	}
}
void RegisterVehicles::WriteToFile(string filename) {
	list = UserInput(&num_vehicles, max_num_vehicles);
	string resultStr = "";
	string delimeter = "---\n";
	for (int i = 0; i < num_vehicles; ++i) {
		resultStr += list[i].toString();
		if (i < num_vehicles - 1) {
			resultStr += delimeter;
		}
	}
	FileProccessor::WriteFile(resultStr, filename);
}
void RegisterVehicles::DisplayAll() {
	/*if (num_vehicles == 0) {
		cout << "Записей нет, сначала считайте из файла или введите с клавиатуры!" << endl;
		return; 
	}*/
	cout << "Записей " << num_vehicles << "/" << max_num_vehicles << ".";
	cout << "Владелец" << "Номер" << "Тип" << "Марка" << "Объём двигателя" << "Мощность" << "Последнее ТО" << "Пробег" << endl;
	for (int i = 0; i < num_vehicles; i++) {
		cout << setw(INDENTATION) << i
			<< setw(INDENTATION) << list[i].getVehicleName()
			<< setw(INDENTATION) << list[i].getVehicleRegNumber()
			<< setw(INDENTATION) << list[i].getVehicleType()
			<< setw(INDENTATION) << list[i].getVehicleBrand()
			<< setw(INDENTATION) << list[i].getVehicleVolume()
			<< setw(INDENTATION) << list[i].getVehiclePower()
			<< setw(INDENTATION) << list[i].getVehicleLastTo()
			<< setw(INDENTATION) << list[i].getVehicleMileage()
			<< endl;
	}
}
void RegisterVehicles::DisplayById(int id_vehicle){
	if (id_vehicle >= num_vehicles) {
		cout << "Выход за допустимые значения. Допустимые значения: [0; " << num_vehicles - 1 << "]." << endl;
		exit(1);
	}
	else
	{
		cout << "Владелец" << "Номер" << "Тип" << "Марка" << "Объём двигателя" << "Мощность" << "Последнее ТО" << "Пробег" << endl;
		cout << setw(INDENTATION) << id_vehicle
			<< setw(INDENTATION) << list[id_vehicle].getVehicleName()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleRegNumber()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleType()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleBrand()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleVolume()
			<< setw(INDENTATION) << list[id_vehicle].getVehiclePower()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleLastTo()
			<< setw(INDENTATION) << list[id_vehicle].getVehicleMileage()
			<< endl;

	}
}
void RegisterVehicles::DeleteVehicleById(int id_vehicle) {
	if (id_vehicle >= num_vehicles) {
		cout << "Выход за допустимые значения. Допустимые значения: [0; " << num_vehicles - 1 << "]." << endl;
		exit(1);
	}
	else {
		for (int i = id_vehicle; i < num_vehicles-1; i++) {
			list[i] = list[i + 1];
		}
		Vehicle v;
		list[num_vehicles] = v;
		num_vehicles--;
	}
}
void RegisterVehicles::SetList(Vehicle* v) {
	list = v;
}
Vehicle* RegisterVehicles::GetList() {
	return list;
}
void RegisterVehicles::Task1() {
	bool flag = false;
	for (int i = 0; i < num_vehicles; i++) {
		if (list[i].task_1()) {
			if (!flag) {
				cout << "Номера автомобилей с пробегом свыше 100тыс. КМ" << endl;
				cout << setw(INDENTATION) << "id" << setw(INDENTATION) << "Регистрационный номер" << endl;
			}
			flag = true;
			cout << setw(INDENTATION) << i << setw(INDENTATION) << list[i].getVehicleRegNumber();
		}
	}
	if (!flag) cout << "Автомобилей с пробегом свыше 100тыс. КМ нет." << endl;
}
void RegisterVehicles::Task2() {
	bool flag = false;
	for (int i = 0; i < num_vehicles; i++) {
		if (list[i].task_2()) {
			if (!flag) {
				cout << "Фамилии владельцев, автомобили которых проходили ТО в течение последнего месяца" << endl;
				cout << setw(INDENTATION) << "id" << setw(INDENTATION) << "Фамилия" << endl;
			}
			flag = true;
			cout << setw(INDENTATION) << i << setw(INDENTATION) << list[i].getVehicleName();
		}
	}
	if (!flag) cout << "Автомобилей которые проходили ТО в течение последнего месяца нет." << endl;
}
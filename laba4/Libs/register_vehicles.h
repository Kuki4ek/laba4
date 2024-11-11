#ifndef REGISTER_VEHICLES_H
#define REGISTER_VEHICLES_H
#include "vechicle.h"
#include <string>
using namespace std;

class RegisterVehicles {
private:
	int max_num_vehicles;
	int num_vehicles;
	Vehicle *list;
public:
	RegisterVehicles(int max_v);
	~RegisterVehicles();
	int AddVehicle(Vehicle v);
	void ReadFromFile(string filename);
	void WriteToFile(string filename);
	void DisplayAll();
	void DisplayById(int id_vehicle);
	void DeleteVehicleById(int id_vehicle);
	void SetList(Vehicle* v);
	Vehicle* GetList();
	void Task1();
	void Task2();
};


#endif

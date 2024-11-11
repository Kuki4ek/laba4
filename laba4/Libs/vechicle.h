#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;
class Vehicle {
    private:
        string owner;
        string reg_number;
        string type;
        string brand;
        float volume;
        float power;
        string last_to;
        float mileage;
    public:
        Vehicle();
        ~Vehicle();
        string getVehicleName();
        string getVehicleType();
        string getVehicleBrand();
        float getVehicleVolume();
        float getVehiclePower();
        string getVehicleLastTo();
        float getVehicleMileage();
        string getVehicleRegNumber();
        void setVehicleName(string name);
        void setVehicleRegNumber(string reg_number);
        void setVehicleType(string type);
        void setVehicleBrand(string brand);
        void setVehicleVolume(float volume);
        void setVehiclePower(float power);
        void setVehicleLastTo(string last_to);
        void setVehicleMileage(float mileage);
        int* getFormatedDate(); //Не используется
        bool task_1();
        bool task_2();
        string toString();
};

#endif

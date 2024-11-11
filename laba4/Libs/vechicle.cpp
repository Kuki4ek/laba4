#include "vechicle.h"
#define TODAY "05.11.2024"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
Vehicle::Vehicle() {
    owner = "";
    reg_number = "";
    type = "";
    brand = "";
    volume = 0.0f;
    power = 0.0f;
    last_to = "";
    mileage = 0.0f;
}
Vehicle::~Vehicle() {
    owner = "";
    reg_number = "";
    type = "";
    brand = "";
    volume = 0.0f;
    power = 0.0f;
    last_to = "";
    mileage = 0.0f;
}

string Vehicle::getVehicleName()
{
    return this->owner;
}
string Vehicle::getVehicleRegNumber()
{
    return this->reg_number;
}
string Vehicle::getVehicleType()
{
    return this->type;
}
string Vehicle::getVehicleBrand()
{
    return this->brand;
}
float Vehicle::getVehicleVolume()
{
    return this->volume;
}
float Vehicle::getVehiclePower()
{
    return this->power;
}
string Vehicle::getVehicleLastTo()
{
    return this->last_to;
}
float Vehicle::getVehicleMileage()
{
    return this->mileage;
}
void Vehicle::setVehicleName(string name)
{
    this->owner = name;
}
void Vehicle::setVehicleType(string type)
{
    this->type = type;
}
void Vehicle::setVehicleBrand(string brand)
{
    this->brand = brand;
}
void Vehicle::setVehicleVolume(float volume)
{
    this->volume = volume;
}
void Vehicle::setVehiclePower(float power)
{
    this->power = power;
}
void Vehicle::setVehicleLastTo(string last_to)
{
    this->last_to = last_to;
}
void Vehicle::setVehicleRegNumber(string reg_number)
{
    this->reg_number = reg_number;
}
void Vehicle::setVehicleMileage(float mileage)
{
    this->mileage = mileage;
}
//Ќе используетс€
int* Vehicle::getFormatedDate()
{
    int* dates = new int[3];
    dates[0] = stoi(last_to.substr(0, last_to.find_first_of(".")));
    dates[1] = stoi(last_to.substr(last_to.find_first_of(".") + 1, last_to.find_last_of(".") - 1));
    dates[2] = stoi(last_to.substr(last_to.find_last_of(".") + 1, last_to.length()));
    return dates;
}
bool Vehicle::task_1()
{
    if (this->mileage>100000) {
        return true;
    }
    else {
        return false;
    }
}
//Ѕлок работы с датой -----------------------------------------------------
string format_to_date_string(int DD, int MM, int YYYY) {
    char buff[100];
    sprintf_s(buff, "%02d.%02d.%04d", DD, MM, YYYY);
    string buffAsStdStr = buff;
    return buffAsStdStr;
}
string mm_minus_data(string data) {
    int DD, MM, YYYY;
    sscanf_s(data.c_str(), "%d.%d.%d", &DD, &MM, &YYYY);

    if (MM == 1) {
        MM = 12;
        YYYY -= 1;
    }
    else {
        MM -= 1;
    }
    data.erase();
    data.append(format_to_date_string(DD, MM, YYYY));

    return data;
}
int comparing_data(string data1, string data2) {
    int DD1, MM1, YYYY1, DD2, MM2, YYYY2, flag;
    flag = 0;

    /*
    flag == 0 - даты равны
    flag == 1 - перва€ дата больше
    flag == 2 - втора€ дата больше
    */

    sscanf_s(data1.c_str(), "%d.%d.%d", &DD1, &MM1, &YYYY1);
    sscanf_s(data2.c_str(), "%d.%d.%d", &DD2, &MM2, &YYYY2);
    if (YYYY1 == YYYY2 && MM1 == MM2 && DD1 == DD2) {
        flag = 0;
    }
    else
    {
        if (YYYY1 > YYYY2) {
            flag = 1;
        }
        else
        {
            if (YYYY1 == YYYY2 && MM1 > MM2) {
                flag = 1;
            }
            else {
                if (YYYY1 == YYYY2 && MM1 == MM2 && DD1 > DD2) {
                    flag = 1;
                }
                else
                {
                    flag = 2;
                }
            }
        }
    }
    return flag;
}
//-------------------------------------------------------------------------
bool Vehicle::task_2() {
    //TODAY
    
    if (comparing_data(last_to, mm_minus_data(TODAY)) <= 1) {
        return true;
    }
    else {
        return false;
    }
}
string Vehicle::toString()
{
    return
        this->owner + "\n" +
        this->reg_number + "\n" +
        this->type + "\n" +
        this->brand + "\n" +
        to_string(this->volume) + "\n" +
        to_string(this->power) + "\n" +
        this->last_to + "\n" +
        to_string(this->mileage) + "\n";
}

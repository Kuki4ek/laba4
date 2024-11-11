#include "vechicle.h"
#include "parser.h"
#include <string>

using namespace std;
Vehicle Parser::ParseStringToVechicle(string data){

    Vehicle vehicle;
    vehicle.setVehicleName(data.substr(0, data.find_first_of('\n')));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleRegNumber(data.substr(0, data.find_first_of('\n')));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleType(data.substr(0, data.find_first_of('\n')));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleBrand(data.substr(0, data.find_first_of('\n')));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleVolume(stof(data.substr(0, data.find_first_of('\n'))));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehiclePower(stof(data.substr(0, data.find_first_of('\n'))));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleLastTo(data.substr(0, data.find_first_of('\n')));
    data.erase(0, data.find_first_of('\n') + 1);
    vehicle.setVehicleMileage(stof(data.substr(0, data.find_first_of('\n'))));
    return vehicle;
}
string* Parser::Split(const string &str, const string &delimiter, int &count) {
    count = 0;
    size_t pos = 0;
    size_t delim_len = delimiter.length();

    while ((pos = str.find(delimiter, pos)) != string::npos) {
        count++;
        pos += delim_len;
    }
    count++;

    auto *tokens = new string[count];

    size_t start = 0;
    size_t end = 0;
    int index = 0;

    while ((end = str.find(delimiter, start)) != string::npos) {
        tokens[index++] = str.substr(start, end - start);
        start = end + delim_len;
    }

    tokens[index] = str.substr(start);

    return tokens;
}

#ifndef PARSER_H
#define PARSER_H
#include "vechicle.h"
#include <string>
using namespace std;
class Parser
{
    public:
        static Vehicle ParseStringToVechicle(string data);
        static string* Split(const string &str, const string &delimiter, int &count);
};

#endif

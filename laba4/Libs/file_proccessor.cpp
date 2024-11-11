#include "file_proccessor.h"
#include <iostream>
#include <fstream>
using namespace std;
string FileProccessor::ReadFile(string path)
{
    string line;
    string data;
    ifstream myfile(path.data());
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            data += line+= "\n";
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    return data;
}

void FileProccessor::WriteFile(string data, string path)
{
    ofstream outfile(path.data(), ios::trunc);
    outfile << data;
    outfile.close();
}


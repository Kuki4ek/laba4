#ifndef FILE_PROCCESOR_H
#define FILE_PROCCESOR_H
#include <string>
using namespace std;
class FileProccessor
{
    public:
        static string ReadFile(string path);
        static void WriteFile(string data, string path);
};

#endif

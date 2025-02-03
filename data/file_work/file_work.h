#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <fstream>
using namespace std;

template<typename T>
class FileWork
{
private:
    string file_name;
public:
    FileWork(const char *file_name)
    {
        this->file_name = file_name;
    }
    bool save_class(T &obj)
    {
        ofstream file(file_name, ios::binary);
        if (!file.is_open())
            return false;
        file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
        file.close();
        return true;
    }
};
#endif // FILE_WORK_H

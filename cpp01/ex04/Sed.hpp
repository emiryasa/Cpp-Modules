#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Sed {
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        std::string line;
        int creat_file();
    public:
        Sed(std::string filename, std::string s1, std::string s2);
        int replace();
        ~Sed();
};

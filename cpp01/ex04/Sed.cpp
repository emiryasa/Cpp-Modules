#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2)
         : filename(filename), s1(s1), s2(s2) {}

Sed::~Sed() {}

int Sed::creat_file()
{
    std::fstream fs;
    fs.open((this->filename + ".replace").c_str(), std::ios::out);
    if (fs.fail())
        return std::cerr << this->filename << ".replace could not create" << std::endl, 1;
    size_t len = this->line.length();
    size_t check = 0;
    for (size_t i = 0; i < len; i++)
    {
        check = this->line.find(this->s1, i);
        if (check != std::string::npos && check == i)
        {
            fs << this->s2;
            i += this->s1.length() - 1;
        }
        else
            fs << this->line[i];
    }
    fs.close();
    return 0;
}

int Sed::replace()
{
    char c;
    std::fstream fs;
    fs.open(this->filename.c_str(), std::ios::in);
    if (fs.fail())
        return std::cerr << this->filename << " could not open" << std::endl, 1;
    while (!fs.eof() && fs >> std::noskipws >> c)
        this->line += c;
    fs.close();
    return (this->creat_file());
}

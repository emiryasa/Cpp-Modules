#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_data {
    std::string s1;
    int n;
    std::string s2;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(Serializer &copy);
        Serializer &operator=(Serializer &src);

    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
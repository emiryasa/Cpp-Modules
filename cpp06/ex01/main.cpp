#include "Serializer.hpp"

int main() {
    Data *data = new Data;
    uintptr_t raw;

    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";
    
    raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    
    std::cout << "data2->s1: " << data2->s1 << std::endl;
    std::cout << "data2->n: " << data2->n << std::endl;
    std::cout << "data2->s2: " << data2->s2 << std::endl;

    delete data;
    
    return 0;
}

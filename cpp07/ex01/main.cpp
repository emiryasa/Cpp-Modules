#include "iter.hpp"

void printIndex(int &num)
{
    static int index = 0;
    std::cout << "Value at index " << index << ": "<< num << std::endl;
    index++;
}

void charToInt(char &c)
{
    std::cout << "Cast value of '" << c << "': " << static_cast<int>(c) << std::endl;
}

int main( void )
{
    int arr[] = {1, 3, 8, 4};
    char arr1[] = {'c', 'd', 'a'};
    ::iter(arr, 4, printIndex);
    ::iter(arr1, 3, charToInt);
    return 0;
}

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    std::list<int> list;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(2);
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << "Found element: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Element not found" << std::endl;
    }
    list.push_back(13);
    try 
    {
        std::list<int>::iterator it = easyfind(list, 2);
        std::cout << "Found element: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Element not found" << std::endl;
    }
    return 0;
};

#include "PmergeMe.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) 
{
    if (this != &src)
    {
        _vec = src.getVec();
        _deque = src.getDeque();
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getVec() const {
    return _vec;
}

std::deque<int> PmergeMe::getDeque() const {
    return _deque;
}

void PmergeMe::setVec(std::vector<int> vec) {
    _vec = vec;
}

void PmergeMe::setDeque(std::deque<int> deque) {
    _deque = deque;
}

std::vector<std::string> PmergeMe::split(std::string str)
{
    std::vector<std::string> res;
    std::stringstream ss(str);
    std::string token;

    while (ss >> token)
        res.push_back(token);

    return res;
}

bool PmergeMe::isValidNumber(std::string str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    return true;
}

void PmergeMe::parseArgs(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::vector<std::string> token = split(av[i]);

        for (std::vector<std::string>::iterator it = token.begin(); it != token.end(); ++it)
        {
            if (isValidNumber(*it)) {
                int num = std::atoi(it->c_str());
                _vec.push_back(num);
                _deque.push_back(num);
            } else {
                throw std::invalid_argument("Error");
            }
        }
    }
    if (_vec.size() == 1) {
        throw std::invalid_argument("Error");
    }
}

template <typename T>
void PmergeMe::merge(T &container, const T &left, const T &right)
{
    size_t i = 0, j = 0, k = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            container[k++] = left[i++];
        } else {
            container[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        container[k++] = left[i++];
    }

    while (j < right.size()) {
        container[k++] = right[j++];
    }
}

template <typename T>
void PmergeMe::fordJhanson(T &container)
{
    size_t n = container.size();

    if (n <= 1) {
        return;
    }

    T left(container.begin(), container.begin() + n / 2);
    T right(container.begin() + n / 2, container.end());

    fordJhanson(left);
    fordJhanson(right);

    merge(container, left, right);
}

template <typename T>
void PmergeMe::printContainer(T& container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::getOutput(int ac, char **av)
{
    struct timeval start, end;
    try {
        parseArgs(ac, av);
        std::cout << "Before: ";
        printContainer(_vec);
        gettimeofday(&start, NULL);
        fordJhanson(_vec);
        gettimeofday(&end, NULL);
        std::cout << "After:  ";
        printContainer(_vec);
        long vec_seconds = end.tv_sec - start.tv_sec;
        long vec_microseconds = end.tv_usec - start.tv_usec;
        double vec_elapsed = vec_seconds * 1e6 + vec_microseconds;
        std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " <<
        std::fixed << std::setprecision(5) << vec_elapsed << " us" << std::endl;

        gettimeofday(&start, NULL);
        fordJhanson(_deque);
        gettimeofday(&end, NULL);
        long list_seconds = end.tv_sec - start.tv_sec;
        long list_microseconds = end.tv_usec - start.tv_usec;
        double list_elapsed = list_seconds * 1e6 + list_microseconds;
        std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : "
        << std::fixed << std::setprecision(5) << list_elapsed << " us" << std::endl;

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        void getOutput(int ac, char **av);
        void parseArgs(int ac, char **av);
        std::vector<std::string> split(std::string token);
        bool isValidNumber(std::string token);
        void sort();

        template <typename T>
        void fordJhanson(T &container);

        template <typename T>
        void merge(T &container, const T &left, const T &right);

        template <typename T>
        void printContainer(T &container);
};

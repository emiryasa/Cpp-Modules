#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange {
    private:
        std::string _file;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &file);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange &operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

};

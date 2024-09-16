#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) 
{
    *this = src;
}

BitcoinExchange::BitcoinExchange(const std::string &file): _file(file) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{

}

BitcoinExchange::~BitcoinExchange() {}


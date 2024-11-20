#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) 
{
    *this = src;
}

BitcoinExchange::BitcoinExchange(const std::string &file): _file(file) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        _data = src._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::processLine(const std::string& line) const
{
    std::stringstream ss(line);
    std::string date;
    double value;

    if (std::getline(ss, date, '|') && ss >> value)
    {
        date = trimLine(date);
        if (isValidDate(date) && isValidValue(value))
        {
            double price = getPrice(date);
            std::cout << date << " => " << value << " = " << value * price << std::endl;
        }
    }
    else
        std::cerr << "Error: bad input => " << line << std::endl;
}

bool    BitcoinExchange::isValidDate(const std::string& date) const
{
    std::stringstream ss(date);
    int year, month, day;
    char sep1, sep2;

    if (!(ss >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-' || date.size() != 10) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (date > _data.rbegin()->first || date < _data.begin()->first) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    return true;
}

bool    BitcoinExchange::isValidValue(double value) const
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void    BitcoinExchange::setData()
{
    std::ifstream fs;
    fs.open("data.csv");
    if (!fs.is_open())
        throw CouldNotOpenFileException();
    std::string line;
    std::string date;
    double price;
    while (std::getline(fs, line)) {
        std::stringstream ss(line);
        if (std::getline(ss, date, ',') && ss >> price) {
            _data[date] = price;
        }
    }

    fs.close();
}

void    BitcoinExchange::getBitcoinExchange()
{
    setData();
    std::ifstream fs;
    fs.open(_file.c_str());
    if (!fs.is_open())
        throw CouldNotOpenFileException();

    std::string line;
    std::getline(fs, line);
    while(std::getline(fs, line))
        processLine(line);
    
    fs.close();
}

double    BitcoinExchange::getPrice(const std::string& date) const
{
    std::map<std::string, double>::const_iterator closest_it = _data.end();
    for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
    {
        if (it->first == date)
            return it->second;

        if (it->first < date)
            closest_it = it;
    }

    if (closest_it != _data.end())
        return closest_it->second;

    return 0;
}

std::string BitcoinExchange::trimLine(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
    return "Error: could not open file.";
}

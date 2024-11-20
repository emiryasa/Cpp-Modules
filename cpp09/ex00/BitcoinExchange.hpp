#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange {
    private:
        const std::string _file;
        std::map<std::string, double> _data;

        std::string trimLine(const std::string& line) const; 
        void    processLine(const std::string& line) const;
        bool    isValidDate(const std::string& line) const;
        bool    isValidValue(double value) const;
        double    getPrice(const std::string& date) const;
        void    setData();

        class CouldNotOpenFileException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &file);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange &operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void getBitcoinExchange();

};

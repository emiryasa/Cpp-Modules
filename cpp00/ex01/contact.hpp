#pragma once

#include <iostream>
#include <string>

class  Contact{
    private:
        std::string name;
        std::string surname;
        std::string tel;
        std::string nickname;
        std::string secret;
    public:
        void set_name(std::string name);
        void set_surname(std::string surname);
        void set_tel(std::string tel);
        void set_nickname(std::string nickname);
        void set_secret(std::string secret);
        std::string get_name();
        std::string get_surname();
        std::string get_tel();
        std::string get_nickname();
        std::string get_secret();
        void print_user(int i);
        void print_with_details();
};

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string second_name;
        std::string nick_name;
        std::string phone_number;
        std::string dark_secret;
    public:
        void add(std::string input, int n);
        void search(int n, int action);
};

#endif
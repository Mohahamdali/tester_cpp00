#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
    private:
    Contact contact[8];
    public:
        int choose(std::string input, int n, char c);
        int i;
};

#endif
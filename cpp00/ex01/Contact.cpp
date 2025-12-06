#include "Contact.hpp"

void limited_print(std::string str, int length)
{
    int i = -1;
    int print_line = 10 - length;

    if (print_line >= 0)
    {
        while (print_line--)
            std::cout << ' ';
        std::cout << str;
    }
    else
    {
        while (++i < 9)
            std::cout << str[i];
        std::cout << '.';
    }
    std::cout << '|';
}

void    Contact::search(int n, int action)
{
    if (!action)
    {
        std::cout << "|         " << n + 1 << "|";
        limited_print(first_name, first_name.length());
        limited_print(second_name, second_name.length());
        limited_print(nick_name, nick_name.length());
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\n==== contact Information ====" << std::endl;
        std::cout << "First Name:   [" << first_name << ']' << std::endl;
        std::cout << "Second Name:  [" << second_name << ']' << std::endl;
        std::cout << "NickName:     [" << nick_name << ']' << std::endl;
        std::cout << "Phone Number: [" << phone_number << ']' << std::endl;
        std::cout << "Dark Secret:  [" << dark_secret << ']' << std::endl;
        std::cout << "=============================" << std::endl;
    }

}

void    Contact::add(std::string input, int n)
{
    switch (n)
    { 
        case 1:
            first_name = input;
            break;
        case 2:
            second_name = input;
            break;
        case 3:
            nick_name = input;
            break;
        case 4:
            phone_number = input;
            break;
        case 5:
            dark_secret = input;
            break;
        default:
            break;
    }
}

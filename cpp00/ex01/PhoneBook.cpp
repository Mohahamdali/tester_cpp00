
#include "PhoneBook.hpp"
#include <stdio.h>

int is_ft(std::string str, char action)
{
    int i = 0;
    int nsp = 0;
    if (action == 'P')
    {
        while(str[i])
        {
            if (!isprint(str[i]))
                return 2;
            if (!nsp && !isspace(str[i]))
                nsp = 1;
            i++;
        }
    }
    else if (action == 'D')
    {
        while(str[i])
        {
            if (!isdigit(str[i]))
                return 1;
            i++;
        }
    }
    if (!nsp)
        return 1;
    return 0;
}

int PhoneBook::choose(std::string input, int n, char c)
{
    int i = -1;
    int num = 0;
    static int sequence;
    static int save;
    std::string str;

    if (save < sequence)
        save = sequence;
    if (c == 'A')
    {
        if (sequence == 8)
            sequence = 0;
        contact[sequence].add(input, n);
        if (n == 5)
        {
            // printf("SEQ:%d - SAVE%d\n", sequence, save);
            sequence++;
        }
    }
    else if (c == 'S')
    {
        std::cout << "\n+-------------------------------------------+" << std::endl;
        std::cout << "|               Contacts List               |" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "|Contact Nu|First Name|SecondName| NickName |" << std::endl;
        while (++i < save)
            contact[i].search(i, 0);
        std::cout << "+-------------------------------------------+" << std::endl;
        if (!save)
            return(std::cout << "Your Contact List is empty!\n" << std::endl, 0);
        std::cout << "\nEnter the contact number: ";
        getline(std::cin, str);
        if (std::cin.eof())
            return 1;
        num = atoi(str.c_str());
        if (str.length() > 1 || num < 1 || num > 8 || num > save)
            return (std::cout << "Error: enter a valid contact number." << std::endl, 0);
        contact[num - 1].search(num, 1);
    }
    return 0;
}

int push_to_enter(std::string input, PhoneBook *pb, int n)
{
    int action = 0;

    getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    action = is_ft(input, 'P');
    if (action || !input.compare(""))
    {
        if (action == 1 || !action)
            std::cout << "Error: fields cannot be empty." << std::endl;
        else if (action == 2)
            std::cout << "Error: Non-printable characters are not allowed." << std::endl;
        return (1);
    }
    pb->choose(input, n, 'A');
    return 0;
}

int main()
{
    std::string name;
    std::string str;
    PhoneBook pb;
    int sq = 0;

    while (1)
    {
        std::cout << "Choose a command [ ADD | SEARCH | EXIT ]: ";
        getline(std::cin, name);
        if (std::cin.eof())
            break ;
        if (!name.compare("ADD"))
        {
            std::cout << "first name: ";
            if (push_to_enter(str, &pb, 1))
                continue;
            std::cout << "second name: ";
            if (push_to_enter(str, &pb, 2))
                continue;
            std::cout << "nick name: ";
            if (push_to_enter(str, &pb, 3))
                continue;
            std::cout << "phone number: ";
            if (push_to_enter(str, &pb, 4))
                continue;
            std::cout << "dark secret: ";
            if (push_to_enter(str, &pb, 6))
                continue;
            sq++;
        }
        else if (!name.compare("SEARCH"))
        {
            if (pb.choose(str, 0, 'S'))
                break ;
        }
        else if (!name.compare("EXIT"))
            return 0;
    }
    std::cout << std::endl;
}

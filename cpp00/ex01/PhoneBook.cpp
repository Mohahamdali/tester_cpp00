/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:40 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/27 16:01:21 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


std::string truncut(std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}


void PhoneBook::add_contact (std::string &fullname,std::string &number,std::string &nickname,\
    std::string &secret_field, std::string &last_name)
{
    int index = contact_count % 8;
    contacts[index].set_fullname_and_number(std::string(fullname), std::string(number),\
        std::string(nickname),std::string(secret_field), last_name);
    if (contact_count < 8)
      contact_count++;
    
 }

 void PhoneBook::search_contact()
 {
    if (contact_count == 0)
    {
        std::cout << "\033[1;31mNo contacts to display.\033[0m\n";
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
          << std::setw(10) << "First Name" << "|"
          << std::setw(10) << "Last Name" << "|"
          << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contact_count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncut(contacts[i].get_name()) << "|"
                  << std::setw(10) << truncut(contacts[i].get_last_name()) << "|"
                  << std::setw(10) << truncut(contacts[i].get_nick()) << std::endl;
    }
    int index;
    while (true)
    {
        std::cout << "Enter index of contact to view: ";
        std::string line;
        if (!(std::getline(std::cin, line)))
            break;
        if (line.empty())
        {
            std::cout << "Invalid input! Must enter a number.\n";
            continue;
        }
        bool valid = true;
        for (size_t i = 0; i < line.size();i++)
        {
            char c = line[i];
            if (!isdigit(c))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            std::cout << "Invalid input! Must enter a number.\n";
            continue;
        }
        std::stringstream ss(line);
        ss >> index;
        if (index < 0 || index >= contact_count)
        {
            std::cout << "Index out of range! Try again.\n";
            continue;
        }
        contacts[index].print();
        break;
    }
 }

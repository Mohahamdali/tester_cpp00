/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:46 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/27 15:11:47 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

bool is_printable_string(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isprint(str[i]))
			return false;
	}
	return true;
}

bool is_number(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}


int main()
{
	PhoneBook phone;
	std::string prompt;

	std::cout << "\033[1;32m*--WELCOME TO IPHONIX--*\033[0m" << std::endl;
	std::cout << "\033[1;36mAvailable commands:\033[0m\n";
	std::cout << "  \033[1;32mADD\033[0m    - Add a new contact to the phone book\n";
	std::cout << "  \033[1;33mSEARCH\033[0m - Search and display contacts\n";
	std::cout << "  \033[1;31mEXIT\033[0m   - Exit the program\n";
	std::string name, last_name, number, nickname, secret_filed;
	while (true)
	{
		std::cout << "\033[1;36mPlease enter command: \033[0m";
		if (!std::getline(std::cin, prompt))
		{
			std::cout << "\nExiting IPHONIX...\n";
			break;
		}
		if (prompt == "ADD")
		{
			while (true)
			{
				std::cout << "Enter name: ";
				if (!std::getline(std::cin, name))
				{
					std::cout << "\nExiting IPHONIX...\n";
					return 0;
				}
				if (name.empty())
					std::cout << "Name is not valid! Try again.\n";
				else if (!is_printable_string(name))
					std::cout << "Input contains non-printable characters! Try again.\n";
				else
					break;
			}
			while (true)
			{
				std::cout << "Enter last name: ";
				if (!std::getline(std::cin, last_name))
				{
					std::cout << "\nExiting IPHONIX...\n";
					return 0;
				}
				if (last_name.empty())
					std::cout << "Last name is not valid! Try again.\n";
				else if (!is_printable_string(last_name))
					std::cout << "Input contains non-printable characters! Try again.\n";
				else
					break;
			}
			while (true)
			{
				std::cout << "Enter number: ";
				if (!std::getline(std::cin, number))
				{
					std::cout << "\nExiting IPHONIX...\n";
					return 0;
				}
				if (number.empty())
					std::cout << "Number is not valid! Try again.\n";
				else if (!is_printable_string(number))
					std::cout << "Input contains non-printable characters! Try again.\n";
				else if (!is_number(number))
					std::cout << "Number must contain digits only! Try again.\n";
				else
					break;
			}
			while (true)
			{
				std::cout << "Enter nickname: ";
				if (!std::getline(std::cin, nickname))
				{
					std::cout << "\nExiting IPHONIX...\n";
					return 0;
				}
				if (nickname.empty())
					std::cout << "Nickname is not valid! Try again.\n";
				else if (!is_printable_string(nickname))
					std::cout << "Input contains non-printable characters! Try again.\n";
				else
					break;
			}
			while (true)
			{
				std::cout << "Enter darkest secret: ";
				if (!std::getline(std::cin, secret_filed))
				{
					std::cout << "\nExiting IPHONIX...\n";
					return 0;
				}
				if (secret_filed.empty())
					std::cout << "Secret cannot be empty! Try again.\n";
				else if (!is_printable_string(secret_filed))
					std::cout << "Input contains non-printable characters! Try again.\n";
				else
					break;
			}
			phone.add_contact(name, number, nickname, secret_filed, last_name);
		}
		else if (prompt == "SEARCH")
			phone.search_contact();
		else if (prompt == "EXIT")
		{
			std::cout << "\nExiting IPHONIX...\n";
			break;
		}
		else
			std::cout << "\n\033[1;31mPlease enter a valid command!!\033[0m" << std::endl;
	}
}

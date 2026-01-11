/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:35 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/29 14:48:27 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
  private:
    Contact contacts[8];
    int contact_count;

  public:
    PhoneBook();
    void add_contact(const std::string &fullname,
                     const std::string &number,
                     const std::string &nickname,
                     const std::string &secret_field,
                     const std::string &last_name);
    void search_contact();
};

std::string truncut(const std::string&);

#endif

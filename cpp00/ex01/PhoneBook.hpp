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
    int next_ind;

  public:
    PhoneBook();
    void add_contact(std::string &fullname,
                     std::string &number,
                     std::string &nickname,
                     std::string &secret_field,
                     std::string &last_name);
    void search_contact();
};

std::string truncut(const std::string&);

#endif

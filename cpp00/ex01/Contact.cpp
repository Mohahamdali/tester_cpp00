/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:54 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/27 15:15:25 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void Contact::print()
{
    std:: cout  << "Name: " << name << std:: endl  << "last_name: "  << last_name << std::endl << "number: " << number << std:: endl \
        << "Nickanme: " << nickname << std:: endl << "Secret fieled: " << darkest_secret << std:: endl; 
}

void Contact::set_fullname_and_number (const std::string &name1,const std::string &num,const std::string &nick, \
    const std::string &secret, const std::string &last_name1)
{
    name = name1;
    last_name = last_name1;
    number = num;
    nickname = nick;
    darkest_secret = secret;
}

 std::string Contact::get_name()
 {
    return (name);
 }

 std::string Contact::get_last_name ()
 {
    return  (last_name);
 }

 std::string Contact::get_nick ()
 {
    return (nickname);
 }

 std::string Contact::get_number()
 {
    return (number);
 }

 std::string Contact::get_secret ()
 {
    return (darkest_secret);
 }

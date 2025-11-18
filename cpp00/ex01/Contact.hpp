/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:51 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/27 15:15:41 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact {
private:
    std::string name;
    std::string last_name;
    std::string number;
    std::string nickname;
    std::string darkest_secret;

public:
    void set_fullname_and_number(const std::string &name1,
                                 const std::string &num,
                                 const std::string &nick,
                                 const std::string &secret,
                                 const std::string &last_name1);
    void print();
    std::string get_name();
    std::string get_last_name();
    std::string get_number();
    std::string get_nick();
    std::string get_secret();
};

#endif

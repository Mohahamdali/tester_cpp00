/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:11:59 by mhamdali          #+#    #+#             */
/*   Updated: 2025/10/27 15:12:00 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>


int main (int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m\n";
        return 1;
    }
    for (int i = 1; av[i] ; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            std:: cout << (char)toupper(av[i][j]);
        }
    }
    std:: cout << std::endl;
}
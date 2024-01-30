/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/11 14:56:10 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    (void) argv;
    if (argc == 1)
    {
        std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
        return (1);
    }

    
    
    
    prog 4 5 6 argc = 4
    
    
    
    
    
    for (int i = 0; i < argc; i += 2)
    {
        std::pair <int, int> temp(atoi(argv[i + 1]), atoi(argv[i + 2]));
    }
    return (0);
}
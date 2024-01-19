/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:34 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/09 13:04:35 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(std::string const& dataBase)
{
    std::ifstream input_file(database);
	if (!input_file.is_open())
	{
    	std::cout << "Could not open the file - '" << argv[1] << "'" << std::endl;
    	return (1);
  	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& toCopy)
{

}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& toAffect)
{

}
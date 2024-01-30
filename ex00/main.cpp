/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:17 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/15 16:41:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./btc inputFile.txt" << std::endl;
	std::string db = "data.csv";
	BitcoinExchange btc(db);
	std::string inF = argv[1];
	btc.showRes(inF);
	std::map<time_t, float> m = btc.getMap();

	/*for ( std::map<time_t, float>::const_iterator itMap = m.begin() ; itMap != m.end() ; ++itMap )
	{
		std::cout << itMap->first << " -> " << itMap->second << std::endl;

	}*/


	
	BitcoinExchange btc2(btc);
	std::cout << &btc.getMap() << std::endl;
	std::cout << &btc2.getMap() << std::endl;
	BitcoinExchange btc3;
	btc3 = btc;
	std::cout << &btc.getMap() << std::endl;
	std::cout << &btc3.getMap() << std::endl;

	return (0);
}

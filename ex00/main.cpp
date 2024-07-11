/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:17 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/11 14:29:04 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error: ./btc inputFile.txt");
		std::string db = "data.csv";
		BitcoinExchange btc(db);
		std::string inF = argv[1];
		btc.showRes(inF);
		std::map<time_t, float> m = btc.getMap();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*
	BitcoinExchange btc2(btc);
	std::cout << &btc.getMap() << std::endl;
	std::cout << &btc2.getMap() << std::endl;
	BitcoinExchange btc3;
	btc3 = btc;
	std::cout << &btc.getMap() << std::endl;
	std::cout << &btc3.getMap() << std::endl;*/

	return (0);
}

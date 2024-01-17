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

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./btc inputFile.txt" << std::endl;

	std::ifstream input_file(argv[1]);
	if (!input_file.is_open())
	{
    	std::cout << "Could not open the file - '" << argv[1] << "'" << std::endl;
    	return (1);
  	}
	std::stringstream test;
	test << input_file.rdbuf();
	std::string record;
	float numeric_value = 0.f;
	while (std::getline(test, record))
	{
		std::stringstream line(record);
		std::string key;
		std::string value;
		std::getline(line, key, '|');

		std::stringstream ss_key;
		ss_key << key;
		std::string date;
		std::getline(ss_key, date, '-');
		std::cout << "date: " << date << std::endl;




		std::getline(line, value, '\n');
		std::stringstream ss_stream(value);
		ss_stream >> numeric_value;
		if (numeric_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		if (numeric_value > 1000)
			std::cout << "Error: too large a number" << std::endl;
		else
			std::cout << numeric_value << std::endl;

	}
	return (0);
}

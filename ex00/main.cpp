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
#include <ctime>
#include <cstdlib>
#include <map>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./btc inputFile.txt" << std::endl;

	std::ifstream input_file("test.txt");
	if (!input_file.is_open())
	{
    	std::cout << "Could not open the file - '" << argv[1] << "'" << std::endl;
    	return (1);
  	}
	std::stringstream test;
	test << input_file.rdbuf();
	std::string record;
	float numeric_value = 0.f;
	std::map<time_t, float> m;

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
		
		int num_year;
		struct tm test_date;
		num_year = std::atoi(date.c_str());
		test_date.tm_year = num_year - 1900;

		std::getline(ss_key, date, '-');
		int num_month = std::atoi(date.c_str());
		test_date.tm_mon = num_month - 1;

		std::getline(ss_key, date, '-');
		int num_day = std::atoi(date.c_str());
		test_date.tm_mday = num_day;
		
		struct tm copy;
		bzero( &copy, sizeof( copy ) );
		copy.tm_year = test_date.tm_year;
		copy.tm_mon = test_date.tm_mon;
		copy.tm_mday = test_date.tm_mday;

		time_t coco = mktime(&test_date);
		if ( coco == -1 || copy.tm_year != test_date.tm_year || copy.tm_mon != test_date.tm_mon
	        || copy.tm_mday != test_date.tm_mday )
	{
		std::cout << "Probleme: " << num_year << "-" << num_month << "-" << num_day << std::endl;
		if (coco == -1)
			std::cout << "coco\n";
		std::cout << test_date.tm_year << " et " << copy.tm_year << std::endl;
		std::cout << test_date.tm_mon << " et " << copy.tm_mon << std::endl;
		std::cout << test_date.tm_mday << " et " << copy.tm_mday<< std::endl;
	}



		std::getline(line, value, '\n');
		std::stringstream ss_stream(value);
		ss_stream >> numeric_value;
		if (numeric_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (numeric_value > 1000)
			std::cout << "Error: too large a number" << std::endl;
		else
			m.insert(std::pair<time_t, float>(coco, numeric_value));


	}
	for ( std::map<time_t, float>::const_iterator itMap = m.begin() ; itMap != m.end() ; ++itMap )
	{
		std::cout << itMap->first << " -> " << itMap->second << std::endl;

	}
	return (0);
}

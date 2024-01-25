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

BitcoinExchange::BitcoinExchange(BitcoinExchange const& toCopy)
	: btc_map(toCopy.btc_map)
{

}


BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& toAffect)
{
	if (this != &toAffect)
		btc_map = toAffect.btc_map;
	return (*this);
}

static time_t getKey(std::string& key)
{
	std::stringstream ss_key;
	ss_key << key;
	std::string date;
	std::getline(ss_key, date, '-');
		
	int num_year;
	struct tm test_date;
	bzero(&test_date, sizeof( test_date));
	num_year = std::atoi(date.c_str());
	test_date.tm_year = num_year - 1900;

	std::getline(ss_key, date, '-');
	int num_month = std::atoi(date.c_str());
	test_date.tm_mon = num_month - 1;

	std::getline(ss_key, date, '-');
	int num_day = std::atoi(date.c_str());
	test_date.tm_mday = num_day;
		
	struct tm copy;
	bzero(&copy, sizeof( copy ));
	copy.tm_year = test_date.tm_year;
	copy.tm_mon = test_date.tm_mon;
	copy.tm_mday = test_date.tm_mday;

	time_t coco = mktime(&test_date);
	if ( coco == -1 || copy.tm_year != test_date.tm_year || copy.tm_mon != test_date.tm_mon
	    || copy.tm_mday != test_date.tm_mday )
		throw(std::invalid_argument(std::string("Bad Date")));
	return (coco);
}

static float getValue(std::string const& value)
{
	double numeric_value;
	std::stringstream ss_stream(value);
	ss_stream >> numeric_value;
	
	if (numeric_value >= FLT_MAX * -1 && numeric_value <= FLT_MAX)
		return (numeric_value);
	throw(std::out_of_range(std::string("Overflow")));
}

void BitcoinExchange::fillMap(std::stringstream& db_ss)
{
	std::string record;
	std::string key;
	std::string value;
	float true_value;
	time_t true_key;

	while (std::getline(db_ss, record))
	{
		std::stringstream line(record);
		std::getline(line, key, '|');
		std::getline(line, value, '\n');

		try
		{
			true_key = getKey(key);
			true_value = getValue(value);
			btc_map.insert(std::pair<time_t, float>(true_key, true_value));
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

std::map<time_t, float>& BitcoinExchange::getMap()
{
	return (btc_map);
}

BitcoinExchange::BitcoinExchange(std::string& dataBase)
{
    std::ifstream db_file(dataBase.c_str());
	if (!db_file.is_open())
	{
    	std::cout << "Could not open the file - '" << dataBase << "'" << std::endl;
  	}
	std::stringstream db_ss;
	db_ss << db_file.rdbuf();
	fillMap(db_ss);
	
}

float BitcoinExchange::getExchangeRate(time_t& key)
{
	struct tm *m = NULL;
	m = localtime(&key);

	std::cout << "Day: " << m->tm_mday << std::endl;
	std::cout << "month " << m->tm_mon << std::endl;
	while (btc_map.find(key) == btc_map.end())
	{
		if (m->tm_mday > 1)
		{
			--m->tm_mday;
			std::cout << "Day: " << m->tm_mday << std::endl;
		}
		else if (m->tm_mon > 0)
		{
			m->tm_mday = 29;
		//	std::cout << "month " << m->tm_mon << std::endl;
			--m->tm_mon;
		//	std::cout << "month " << m->tm_mon << std::endl;
		}
		else
		{
			m->tm_mon = 11;
		//	std::cout << "year " << m->tm_year << std::endl;
			--m->tm_year;
		}
		//std::cout << "Day: " << m->tm_mday << std::endl;
		key = mktime(m);
		//std::cout << "Day: " << m->tm_mday << std::endl;
	}
	return (btc_map[key]);
}

void BitcoinExchange::showRes(std::string& inputFile)
{
	std::ifstream if_file(inputFile.c_str());
	if (!if_file.is_open())
	{
    	std::cout << "Could not open the file - '" << inputFile << "'" << std::endl;
  	}
	std::stringstream if_ss;
	if_ss << if_file.rdbuf();

	std::string record;
	std::string key;
	std::string value;
	float true_value;
	time_t true_key;

	while (std::getline(if_ss, record))
	{
		std::stringstream line(record);
		std::getline(line, key, '|');
		std::getline(line, value, '\n');
		try
		{
			true_key = getKey(key);
			true_value = getValue(value);
			std::cout << true_value * getExchangeRate(true_key) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
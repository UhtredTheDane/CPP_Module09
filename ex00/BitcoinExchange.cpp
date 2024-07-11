/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:34 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/11 14:32:07 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(std::string& dataBase)
{
	std::ifstream db_file(dataBase.c_str());
	if (!db_file.is_open())
		throw std::invalid_argument("Could not open the file - '" + dataBase + "'");
	std::stringstream db_ss;
	db_ss << db_file.rdbuf();
	fillMap(db_ss);
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

	struct tm test_date;
	bzero(&test_date, sizeof( test_date));
	std::string str_year = date.c_str();
	int num_year = std::atoi(date.c_str());
	test_date.tm_year = num_year - 1900;

	std::getline(ss_key, date, '-');
	std::string str_month = date.c_str();
	int num_month = std::atoi(date.c_str());
	test_date.tm_mon = num_month - 1;

	std::getline(ss_key, date, '-');
	std::string str_day = date.c_str();
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
		throw(std::invalid_argument(std::string("Bad Input => " + str_year + "-" + str_month + "-" + str_day)));
	return (coco);
}

static float getValue(std::string const& value)
{
	double numeric_value;
	std::stringstream ss_stream(value);
	ss_stream >> numeric_value;

	if (numeric_value < 0)
		throw(std::out_of_range("Not a positive number"));
	if (numeric_value > INT_MAX)
		throw(std::out_of_range(std::string("too large number")));
	return (numeric_value);
}

void BitcoinExchange::fillMap(std::stringstream& db_ss)
{
	std::string record;
	std::string key;
	std::string value;
	float true_value;
	time_t true_key;
	std::getline(db_ss, record);

	while (std::getline(db_ss, record))
	{
		std::stringstream line(record);
		std::getline(line, key, ',');
		std::getline(line, value, '\n');
		try
		{
			true_key = getKey(key);
			true_value = getValue(value);
			btc_map.insert(std::pair<time_t, float>(true_key, true_value));
		}
		catch(std::exception &e)
		{
			std::cout << "Error in csv file: " << e.what() << std::endl;
		}
	}
}

std::map<time_t, float>& BitcoinExchange::getMap()
{
	return (btc_map);
}

time_t &test(struct tm& tc, time_t& key)
{
	struct tm copy;
	bzero(&copy, sizeof(copy));
	copy.tm_year = tc.tm_year;
	copy.tm_mon = tc.tm_mon;
	copy.tm_mday = tc.tm_mday;
	key = mktime(&tc);
	while (key == -1 || copy.tm_year != tc.tm_year || copy.tm_mon != tc.tm_mon
			|| copy.tm_mday != tc.tm_mday )
	{
		tc.tm_year = copy.tm_year;
		tc.tm_mon = copy.tm_mon;
		tc.tm_mday = copy.tm_mday - 1;
		copy.tm_mday = tc.tm_mday;
		key = mktime(&tc);
	}
	return (key);
}

float BitcoinExchange::getExchangeRate(time_t& key)
{
	struct tm *m = NULL;
	m = localtime(&key);
	struct tm tc;
	bzero(&tc, sizeof(tc));

	tc.tm_mday = m->tm_mday;
	tc.tm_mon = m->tm_mon;
	tc.tm_year = m->tm_year;
	while (btc_map.find(key) == btc_map.end())
	{
		if (tc.tm_mday > 1)
		{
			--tc.tm_mday;
		}
		else if (tc.tm_mon > 0)
		{
			tc.tm_mday = 31;
			--tc.tm_mon;
		}
		else
		{
			tc.tm_mday = 31;
			tc.tm_mon = 11;
			--tc.tm_year;
		}
		key = test(tc, key);
	}
	return (btc_map[key]);
}

void BitcoinExchange::showRes(std::string& inputFile)
{
	std::ifstream if_file(inputFile.c_str());
	if (!if_file.is_open())
		throw std::invalid_argument("Could not open the file - '" + inputFile + "'");
	std::stringstream if_ss;
	if_ss << if_file.rdbuf();

	std::string record;
	std::string key;
	std::string value;
	float true_value;
	time_t true_key;

	std::getline(if_ss, record);
	while (std::getline(if_ss, record))
	{
		std::stringstream line(record);
		std::getline(line, key, '|');
		std::getline(line, value, '\n');
		try
		{
			true_key = getKey(key);
			true_value = getValue(value);
			std::cout << key << "=>" << value << " = " << true_value * getExchangeRate(true_key) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

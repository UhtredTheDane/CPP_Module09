/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:42 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/09 13:04:43 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cfloat>
# include <exception>
# include <string.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <map>
# include <string>
# include <climits>

class BitcoinExchange
{
    public:

        BitcoinExchange(std::string& dataBase);
        BitcoinExchange(BitcoinExchange const& toCopy);
        ~BitcoinExchange(void);
        BitcoinExchange& operator=(BitcoinExchange const& toAffect);
        void showRes(std::string& inputFile);
        std::map<time_t, float>& getMap();
        BitcoinExchange(void);

    private:
        
        std::map<time_t, float> btc_map;
        float getExchangeRate(time_t& key);
        void fillMap(std::stringstream& db_ss);

};
#endif
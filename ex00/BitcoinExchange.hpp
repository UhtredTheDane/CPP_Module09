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

class BitcoinExchange
{
    public:

        BitcoinExchange(std::string const& dataBase);
        BitcoinExchange(BitcoinExchange const& toCopy);
        ~BitcoinExchange(void);
        BitcoinExchange& operator=(BitcoinExchange const& toAffect);

    private:

        BitcoinExchange(void);

};
#endif;
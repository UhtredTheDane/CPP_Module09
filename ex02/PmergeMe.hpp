/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:44 by agengemb          #+#    #+#             */
/*   Updated: 2024/06/17 17:27:06 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <utility>
# include <cstdlib>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(PmergeMe const& toCopy);
        PmergeMe& operator=(PmergeMe const& toAffect);
        ~PmergeMe(void);

        std::vector<std::pair<int, int> > vec;

    
};
#endif


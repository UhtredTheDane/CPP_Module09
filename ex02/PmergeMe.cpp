/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:31 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/09 14:09:32 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(PmergeMe const& toCopy)
{
    (void) toCopy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& toAffect)
{
	if (this != &toAffect)
	{

    }
	return (*this);
}


PmergeMe::~PmergeMe(void)
{

}

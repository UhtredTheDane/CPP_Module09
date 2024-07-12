/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/12 15:49:06 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	clock_t start;
	PmergeMe first;
	double clock_per_us;
	double timeVector;
	double timeList;

	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
		return (1);
	}
	clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000000;

	try
	{
		start = clock();
		first.runMergeInsertVector(argv + 1, argc - 1);
		timeVector = (clock() - start) / clock_per_us;
		first.showFinalVector();

		start = clock();
		first.runMergeInsertList(argv + 1, argc - 1);
		timeList = (clock() - start) / clock_per_us;
		first.showFinalList();

		std::cout << "Before: ";
		for (int i = 0; i < argc - 1; ++i)
			std::cout << argv[i + 1] << " ";
		std::cout << std::endl;
		std::cout << "After: ";
		std::list<int> sortContainer = first.getSortedList();
		for (std::list<int>::iterator it = sortContainer.begin(); it != sortContainer.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeVector << " us" << std::endl; 
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << timeList << " us" << std::endl; 
	}
	catch (std::exception& e)
	{}
	return (0);
}

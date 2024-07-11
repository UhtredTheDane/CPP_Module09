/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/11 23:12:55 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	clock_t start;
	clock_t end;

	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
		return (1);
	}
	PmergeMe first(argv + 1, argc - 1);
	start = clock();
	first.runMergeInsert();
	end = clock();
	first.showFinalVector();
	double clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000000;
	double timeVector = (end - start) / clock_per_us;
	start = clock();
	first.runMergeInsertList();
	end = clock();
	first.showFinalList();
	double timeList = (end - start) / clock_per_us;
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
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/05 19:36:11 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	clock_t start;
	clock_t end;

	(void) argv;
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
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	std::cout << "sa a pris " << (end - start) / clock_per_ms << " ms !\n";
	start = clock();
	first.runMergeInsertList();
	end = clock();
	first.showFinalList();
	clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	std::cout << "sa a pris " << (end - start) / clock_per_ms << " ms !\n";
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
	return (0);
}
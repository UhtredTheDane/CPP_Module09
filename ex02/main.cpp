/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/06/17 17:58:39 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge(std::vector<std::pair<int, int> >& vec, int deb, int mid, int end) 
{
	int LSize, RSize, LIndex, RIndex;

	LSize = mid - deb + 1;
	RSize = end - mid;
	LIndex = 0;
	RIndex = 0;
	std::vector<std::pair<int, int> > LVec(vec.begin() + deb, vec.begin() + mid + 1);

	std::cout << "LVec: ";
	for (std::vector<std::pair<int, int> >::iterator it = LVec.begin(); it != LVec.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;

	std::cout << "RVec: ";
	std::vector<std::pair<int, int> > RVec(vec.begin() + mid + 1, vec.begin() + end + 1);
	for (std::vector<std::pair<int, int> >::iterator it = RVec.begin(); it != RVec.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;

	for (int i = deb; i < end + 1; ++i)
	{
		if (RIndex == RSize)
		{
			vec[i] = LVec[LIndex];
			++LIndex;
		}
		else if(LIndex == LSize)
		{
			vec[i] = RVec[RIndex];
			++RIndex;
		}
		else if(LVec[LIndex] > RVec[RIndex])
		{
			vec[i] = RVec[RIndex];
			++RIndex;
		}
		else
		{
			vec[i] = LVec[LIndex];
			++LIndex;
		}
	}
}


void sort(std::vector<std::pair<int, int> >& vec, int deb, int end)
{
	int mid;
	if (end - deb >= 1)
	{
		mid = (end + deb) / 2;
		sort(vec, deb, mid);
		sort(vec, mid + 1, end);
		merge(vec, deb, mid, end);
	}
}

void insert2(std::vector<int> vecFinal, std::vector<int> test)
{
	int n = VecFinal.size();
	while (n !)
}

void insert(std::vector<int> vecToInsert, int debToInsert, int endToInsert)
{
	std::vector<int> test;

	for (int i = endToInsert; i >= debToInsert; ++i)
		test.push_back(vecToInsert[i]);
	insert2();
	int n = VecFinal.size();
	while (n !)
}

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
		return (1);
	}

	std::vector<std::pair<int, int> > vec;
	int a;
	int b;
	int i;
	for (i = 0; i + 1 < argc - 1; i += 2)
	{
		a = atoi(argv[i + 1]);
		b = atoi(argv[i + 2]);
		if (a < b)
		{
			vec.push_back(std::pair<int, int>(b, a));
		}
		else
		{
			vec.push_back(std::pair<int, int>(a, b));
		}	
	}
	/*
	if (i < argc - 1)
	{
		a = atoi(argv[i + 1]);
		vec.push_back(a);
	}*/
	
	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
	std::cout << "size " << vec.size() - 1 << std::endl;
	sort(vec, 0, vec.size() - 1);

	std::vector<int> vecFinal;
	std::vector<int> toInsert;
	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (it == vec.begin())
			vecFinal.push_back(it->second);
		else
			toInsert.push_back(it->second);
		vecFinal.push_back(it->first);
	}


	int temp_size;
	int size = 2;
	int indexMaxToInsert;

	int nbInsert = toInsert.size();
	
	int old_size = 0;
	int size = 2;

	int debToInsert = 2;
	int endToInsert = debToInsert + size - 1
	//while (nbInsert != 0)
	//{

		for (int i = endToInsert; i >= debToInsert; ++i)
		{

			int nbToInsert = toInsert[i];
			int n = i;
			int old_n = n;
			n /= 2;
			while (old_n - n > 1)
			{
				if (nbToInsert > vecFinal[n])
				
			}
			n /= 2;

		}


		debToInsert += size;
		endToInsert = debToInsert + size - 1





	/*int n = VecFinal.size();
	while (n !)
		temp_size = size;
		nbInsert -= size;
		size += old_size;
		old_size = temp_size;
	}*/


	/*
	int j = 4;


	int size;
	while (toInsert.size() > 0)
	{
		size = p2 - old_size;
		for (int i = size - 1; i >= 0; ++i)
		{
			int numtoinsert = toInsert[i];
			--j;
			
		}

		j += size;

	}*/
	
	for (std::vector<int>::iterator it = toInsert.begin(); it != toInsert.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}

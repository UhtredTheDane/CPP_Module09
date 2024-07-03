/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:08 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/03 19:45:01 by agengemb         ###   ########.fr       */
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


	std::vector<std::pair<int, int> > RVec(vec.begin() + mid + 1, vec.begin() + end + 1);

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
/*
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
*/
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
	int nbInsert = toInsert.size();
	int size = 2;
	int old_size = 0;
	int endToInsert = 3;
	int debToInsert = 2;
	while (nbInsert > 0)
	{

		int interDeb = 0;
		int interEnd = endToInsert; //non inclus
		for (int i = endToInsert; i >= debToInsert; ++i)
		{

			
			
			//int interDeb = 0;
			//int interEnd = i; //non inclus
			int nbToInsert = toInsert[i - size];
			int n = interEnd - interDeb;
			while (n > 1)
			{
				n /= 2;
				if (nbToInsert > vecFinal[n])
					interDeb = n + 1;
				else
					interEnd = n;
				n = interEnd - interDeb;
				if (n == 1)
				{
					if (nbToInsert >  vecFinal[interDeb])
					{
						vecFinal.insert(vecFinal.begin() + interDeb + 1, nbToInsert);
					}
					else
					{
						vecFinal.insert(vecFinal.begin() + interDeb, nbToInsert);
						++interEnd;
					}
				}
			}
			--nbToInsert;






		}
		size += old_size;
		endToInsert += size;
		debToInsert += size

	}
/*
	int temp_size;
	int size = 2;
	int indexMaxToInsert;

	int nbInsert = toInsert.size();
	

	int debToInsert = 2;
	int endToInsert = debToInsert + size - 1
	//while (nbInsert != 0)
	//{

	


		debToInsert += size;
		endToInsert = debToInsert + size - 1*/





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
	
	for (std::vector<int>::iterator it = vecFinal.begin(); it != vecFinal.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}

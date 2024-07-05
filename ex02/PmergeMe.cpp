/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:31 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/05 21:54:19 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(char **numbersToSort, int size)
{
	int a;
	int b;
	int i;
	popo = size;
	for (i = 0; i + 1 < size; i += 2)
	{
		a = atoi(numbersToSort[i]);
		b = atoi(numbersToSort[i + 1]);
		if (a < b)
		{
			vecToSort.push_back(std::pair<int, int>(b, a));
		}
		else
		{
			vecToSort.push_back(std::pair<int, int>(a, b));
		}	
	}
	isOdd = false;
	if (i < size)
	{
		isOdd = true;
		lonelyElement = atoi(numbersToSort[i]);
	}
	for (std::vector<std::pair<int, int> >::iterator it = vecToSort.begin(); it != vecToSort.end(); ++it)
	{
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::merge(std::vector<std::pair<int, int> >& vec, int deb, int mid, int end) 
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

void PmergeMe::sort(std::vector<std::pair<int, int> >& vec, int deb, int end)
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
bool checkMergeSort(std::vector<int> atester, int size)
{
	if (atester.size() != (long unsigned int) size)
		return (false);
	for (int i = 0; (long unsigned int)i < atester.size() - 1; ++i)
	{
		if (atester[i] > atester[i + 1])
			return (false);
	}
	return (true);
}

void PmergeMe::runMergeInsert()
{
	sort(vecToSort, 0, vecToSort.size() - 1);
	std::vector<int> vecFinal;
	std::vector<int> toInsert;
	for (std::vector<std::pair<int, int> >::iterator it = vecToSort.begin(); it != vecToSort.end(); ++it)
	{
		if (it == vecToSort.begin())
			vecFinal.push_back(it->second);
		else
			toInsert.push_back(it->second);
		vecFinal.push_back(it->first);
	}
	if (isOdd)
		toInsert.push_back(lonelyElement);
	int nbInsert = toInsert.size();
	int size = 2;
	int old_size = 0;
	int temp_size;
	int endToInsert = 3;
	int nbInsertAfter = 0;
	while (nbInsert > 0)
	{	
		int nb = 0;
		for (int i = endToInsert; i >= endToInsert - size + 1; --i)
		{
			if ((long unsigned int)i-2 < toInsert.size())
			{
				int nbToInsert = toInsert[i - 2];
				int index = i + nb + nbInsertAfter;
				int interDeb = 0;
				int interEnd = index - 1;
				while (interEnd - interDeb > 0)
				{
					int n = (interEnd - interDeb + 1) / 2;
					if (nbToInsert > vecFinal[n + interDeb])
					{
						if (n + interDeb + 1 > interEnd)
						{
							++nb;
							vecFinal.insert(vecFinal.begin() + interEnd + 1, nbToInsert);
						}
						interDeb = n + interDeb + 1;
					}
					else
						interEnd = n + interDeb - 1;

					if (interEnd - interDeb == 0)
					{
						if (nbToInsert >  vecFinal[interDeb])
						{
							if (interDeb + 1 != index)
								++nb;
vecFinal.insert(vecFinal.begin() + interDeb + 1, nbToInsert);
						}
						else
						{
							vecFinal.insert(vecFinal.begin() + interDeb, nbToInsert);
							++nb;
						}

					}
				}
			}
			--nbInsert;
		}
		nbInsertAfter += size;
		temp_size = size;
		size += old_size;
		old_size = temp_size;
		endToInsert += size;
		
	}
	for (std::vector<int>::iterator it = vecFinal.begin(); it != vecFinal.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	if (checkMergeSort(vecFinal, popo))
		std::cout << "sa marche !\n";
	else
		std::cout << "nnnnooooonnnnn !\n";
		
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

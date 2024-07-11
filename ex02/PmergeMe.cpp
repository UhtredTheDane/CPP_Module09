/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:31 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/12 01:38:06 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	
}

std::list<int> PmergeMe::getSortedList(void)
{
	return (listFinal);
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

void PmergeMe::merge(std::list<std::pair<int, int> >& vec, int deb, int mid, int end)
{
	int LSize, RSize, LIndex, RIndex;

	LSize = mid - deb + 1;
	RSize = end - mid;
	LIndex = 0;
	RIndex = 0;

	std::list<std::pair<int, int> >::iterator itBegin = vec.begin();
	std::list<std::pair<int, int> >::iterator itEnd = vec.begin();
	std::advance(itBegin, deb);
	std::advance(itEnd, mid + 1);
	std::list<std::pair<int, int> > LVec(itBegin, itEnd);
	itBegin = vec.begin();
	itEnd = vec.begin();
	std::advance(itBegin, + mid + 1);
	std::advance(itEnd, end + 1);
	std::list<std::pair<int, int> > RVec(itBegin, itEnd);
	for (int i = deb; i < end + 1; ++i)
	{
		std::list<std::pair<int, int> >::iterator itVec = vec.begin();
		std::list<std::pair<int, int> >::iterator itR = RVec.begin();
		std::list<std::pair<int, int> >::iterator itL = LVec.begin();
		std::advance(itVec, i);
		std::advance(itR, RIndex);
		std::advance(itL, LIndex);
		if (RIndex == RSize)
		{
			*itVec = *itL;
			++LIndex;
		}
		else if(LIndex == LSize)
		{
			*itVec = *itR;
			++RIndex;
		}
		else if(*itL > *itR)
		{
			*itVec = *itR;
			++RIndex;
		}
		else
		{
			*itVec = *itL;
			++LIndex;
		}
	}
}

template <typename T>
void PmergeMe::sort(T& vec, int deb, int end)
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

bool PmergeMe::checkMergeSortVector()
{
	if (vecFinal.size() != (long unsigned int) elementsNb)
		return (false);
	for (int i = 0; (long unsigned int)i < vecFinal.size() - 1; ++i)
	{
		if (vecFinal[i] > vecFinal[i + 1])
			return (false);
	}
	return (true);
}

bool PmergeMe::checkMergeSortList()
{
	if (listFinal.size() != (long unsigned int) elementsNb)
		return (false);
	std::list<int>::iterator itEnd = listFinal.end();
	std::advance(itEnd, -1);
	for (std::list<int>::iterator it = listFinal.begin(); it != itEnd;)
	{
		if (*it > *(++it))
			return (false);
	}
	return (true);
}

void PmergeMe::fillVectors(void)
{
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
}

void PmergeMe::dichotomyInsert(int index, int nbInsertAfter, int& nb)
{
	int nbToInsert = toInsert[index - 2];
	int interDeb = 0;
	int interEnd =  index + nb + nbInsertAfter - 1;
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
				if (interDeb + 1 != index + nb + nbInsertAfter)
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

void PmergeMe::insertElems(int& nbInsert, int nbInsertAfter, int endToInsert, int groupSize)
{
	int nb = 0;
	for (int i = endToInsert; i >= endToInsert - groupSize + 1; --i)
	{
		if ((long unsigned int) i-2 < toInsert.size())
		{
			dichotomyInsert(i, nbInsertAfter, nb);
			--nbInsert;
		}
	}
}

void PmergeMe::makeVecToSort(char **numbersToSort, int size)
{
	int a;
	int b;
	int i;

	elementsNb = size;
	isOdd = false;
	for (i = 0; i + 1 < size; i += 2)
	{
		a = atoi(numbersToSort[i]);
		b = atoi(numbersToSort[i + 1]);
		if (a < b)
			vecToSort.push_back(std::pair<int, int>(b, a));
		else
			vecToSort.push_back(std::pair<int, int>(a, b));
	}
	if (i < size)
	{
		isOdd = true;
		lonelyElement = atoi(numbersToSort[i]);
	}
}

void PmergeMe::runMergeInsert(char **numbersToSort, int size)
{
	makeVecToSort(numbersToSort, size);
	sort(vecToSort, 0, vecToSort.size() - 1);
	fillVectors();
	int nbInsert = toInsert.size();
	int groupSize = 2;
	int old_size = 0;
	int temp_size;
	int endToInsert = 3;
	int nbInsertAfter = 0;
	while (nbInsert > 0)
	{	
		insertElems(nbInsert, nbInsertAfter, endToInsert, groupSize);
		nbInsertAfter += groupSize;
		temp_size = groupSize;
		groupSize += old_size;
		old_size = temp_size;
		endToInsert += groupSize;
	}
}

void PmergeMe::fillList(void)
{
	for (std::list<std::pair<int, int> >::iterator it = listToSort.begin(); it != listToSort.end(); ++it)
	{
		if (it == listToSort.begin())
			listFinal.push_back(it->second);
		else
			listToInsert.push_back(it->second);
		listFinal.push_back(it->first);
	}
	if (isOdd)
		listToInsert.push_back(lonelyElement);
}

void PmergeMe::insertElemsList(int& nbInsert, int nbInsertAfter, int endToInsert, int groupSize)
{
	int nb = 0;
	for (int i = endToInsert; i >= endToInsert - groupSize + 1; --i)
	{
		if ((long unsigned int) i-2 < listToInsert.size())
		{
			dichotomyInsertList(i, nbInsertAfter, nb);
			--nbInsert;
		}
	}
}

void PmergeMe::dichotomyInsertList(int index, int nbInsertAfter, int& nb)
{
	std::list<int>::iterator it = listToInsert.begin();
	std::advance(it, index - 2);
	int nbToInsert = *it;
	int interDeb = 0;
	int interEnd =  index + nb + nbInsertAfter - 1;
	while (interEnd - interDeb > 0)
	{
		int n = (interEnd - interDeb + 1) / 2;
		it = listFinal.begin();
		std::advance(it, n + interDeb);
		if (nbToInsert > *it)
		{
			if (n + interDeb + 1 > interEnd)
			{
				++nb;
				it = listFinal.begin();
				std::advance(it, interEnd + 1);
				listFinal.insert(it, nbToInsert);
			}
			interDeb = n + interDeb + 1;
		}
		else
			interEnd = n + interDeb - 1;
		if (interEnd - interDeb == 0)
		{
			it = listFinal.begin();
			std::advance(it, interDeb);
			if (nbToInsert >  *it)
			{
				if (interDeb + 1 != index + nb + nbInsertAfter)
					++nb;
				listFinal.insert(++it, nbToInsert);
			}
			else
			{
				listFinal.insert(it, nbToInsert);
				++nb;
			}
		}
	}
}

void PmergeMe::makeListToSort(char **numbersToSort, int size)
{
	int a;
	int b;
	int i;

	elementsNb = size;
	isOdd = false;
	for (i = 0; i + 1 < size; i += 2)
	{
		a = atoi(numbersToSort[i]);
		b = atoi(numbersToSort[i + 1]);
		if (a < b)
			listToSort.push_back(std::pair<int, int>(b, a));
		else
			listToSort.push_back(std::pair<int, int>(a, b));
	}
	if (i < size)
	{
		isOdd = true;
		lonelyElement = atoi(numbersToSort[i]);
	}
}

void PmergeMe::runMergeInsertList(char **numbersToSort, int size)
{
	makeListToSort(numbersToSort, size);
	sort(listToSort, 0, listToSort.size() - 1);
	fillList();
	
	
	int nbInsert = listToInsert.size();
	int groupSize = 2;
	int old_size = 0;
	int temp_size;
	int endToInsert = 3;
	int nbInsertAfter = 0;
	while (nbInsert > 0)
	{	
		insertElemsList(nbInsert, nbInsertAfter, endToInsert, groupSize);
		nbInsertAfter += groupSize;
		temp_size = groupSize;
		groupSize += old_size;
		old_size = temp_size;
		endToInsert += groupSize;
	}
}

void PmergeMe::showFinalList()
{
	std::cout << "final list:\n";
	for (std::list<int>::iterator it = listFinal.begin(); it != listFinal.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	if (checkMergeSortList())
		std::cout << "sa marche !\n";
	else
		std::cout << "nnnnooooonnnnn !\n";
}

void PmergeMe::showFinalVector()
{
	std::cout << "final vector:\n";
	for (std::vector<int>::iterator it = vecFinal.begin(); it != vecFinal.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	if (checkMergeSortVector())
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

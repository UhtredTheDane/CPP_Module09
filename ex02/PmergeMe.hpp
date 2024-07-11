/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:44 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/12 01:36:54 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iterator>
# include <iostream>
# include <utility>
# include <cstdlib>
# include <ctime>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(PmergeMe const& toCopy);
        PmergeMe& operator=(PmergeMe const& toAffect);
        ~PmergeMe(void);
	void runMergeInsert(char **numbersToSort, int size);    
        void runMergeInsertList(char **numbersToSort, int size);
        bool checkMergeSortVector();
        void showFinalVector();
        bool checkMergeSortList();
        void showFinalList();
        std::list<int> getSortedList(void);

    private:
        void merge(std::vector<std::pair<int, int> >& vec, int deb, int mid, int end);
        void merge(std::list<std::pair<int, int> >& vec, int deb, int mid, int end);
        template <typename T>
        void sort(T& vec, int deb, int end);

        std::vector<std::pair<int, int> > vecToSort;
        std::vector<int> vecFinal;
	    std::vector<int> toInsert;

        std::list<std::pair<int, int> > listToSort;
        std::list<int> listFinal;
	    std::list<int> listToInsert;

        int lonelyElement;
        bool isOdd;
        int elementsNb;
       
        void makeVecToSort(char **numbersToSort, int size);
        void fillVectors(void);
        void insertElems(int& nbInsert, int nbInsertAfter, int endToInsert, int groupSize);
        void dichotomyInsert(int index, int nbInsertAfter, int& nb);

        void makeListToSort(char **numbersToSort, int size);
        void fillList(void);
        void insertElemsList(int& nbInsert, int nbInsertAfter, int endToInsert, int groupSize);
        void dichotomyInsertList(int index, int nbInsertAfter, int& nb);

};
#endif


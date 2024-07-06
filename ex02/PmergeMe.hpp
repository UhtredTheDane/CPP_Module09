/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:44 by agengemb          #+#    #+#             */
/*   Updated: 2024/07/05 19:34:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <utility>
# include <cstdlib>
# include <ctime>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(char **numbersToSort, int size);
        PmergeMe(PmergeMe const& toCopy);
        PmergeMe& operator=(PmergeMe const& toAffect);
        ~PmergeMe(void);
	void runMergeInsert();    

    private:
        std::vector<std::pair<int, int> > vecToSort;
        std::vector<int> vecFinal;
	    std::vector<int> toInsert;

        int lonelyElement;
        bool isOdd;
        int popo;//size

	    void merge(std::vector<std::pair<int, int> >& vec, int deb, int mid, int end);
        void sort(std::vector<std::pair<int, int> >& vec, int deb, int end);
        void fillVectors(void);
        void insertElems(int& nbInsert, int nbInsertAfter, int endToInsert, int groupSize);
        void dichotomyInsert(int index, int nbInsertAfter, int& nb);
};
#endif


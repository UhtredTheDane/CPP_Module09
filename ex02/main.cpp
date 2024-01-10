/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:24 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/10 17:51:36 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./RPN mathematical expression" << std::endl;
	std::string temp(argv[1]);
	std::stringstream test(temp);
	char mot;
	std::stack<int> mstack;
	
	while (!test.eof())
	{
		test >> mot;
		if (mot >= '0' && mot <= '9')
		{
			int cooc = mot - '0';
			std::cout << cooc << std::endl;
			mstack.push(cooc);
		}
		else
		{
			int a = mstack.top();
			mstack.pop();
			int b = mstack.top();
			mstack.pop();
			switch (mot)
			{
				case '+': mstack.push(a + b);
						break;
				default: mstack.push(a * b);
			}
			std::cout << mstack.top() << std::endl;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:08:54 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/09 14:08:56 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{

}

static void  trim_space(std::string& test)
{
	int i = 0;
	while (test.c_str()[i] != '\0')
	{
		if (test.c_str()[i] == ' ')
			test.erase(i, 1);
		else
			++i;
	}

}

void RPN::resolve(char c)
{
    int b;
    int a;
    
    b = mstack.top();
	mstack.pop();
	a = mstack.top();
	mstack.pop();
	switch (c)
	{
		case '+': mstack.push(a + b);
				break;
        case '-': mstack.push(a - b);
                break;
        case '/': mstack.push(a / b);
                break;
        default: mstack.push(a * b);
	}
}

RPN::RPN(std::string& input)
{
    int i;
    const char *temp;
    
    trim_space(input);
    i = 0;	
	temp = input.c_str();
	while (temp[i] != '\0')
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			mstack.push(temp[i] - '0');
        else if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/')
            resolve(temp[i]);
		else
            throw(std::invalid_argument(std::string("Error")));
		++i;
	}
}

RPN::RPN(RPN const& toCopy)
    : mstack(toCopy.mstack)
{

}

RPN const& RPN::operator=(RPN const& toAffect)
{
    if (this != &toAffect)
    {
        mstack = toAffect.mstack;
    }
    return (*this);
}

RPN::~RPN(void)
{

}

int RPN::getRes(void)
{
    return (mstack.top());
}

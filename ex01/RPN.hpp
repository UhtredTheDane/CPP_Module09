/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:03 by agengemb          #+#    #+#             */
/*   Updated: 2024/01/09 14:09:05 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>

class RPN
{
    private:
        std::stack<int> mstack;
        RPN(void);
        void    resolve(char c);

    public:
        RPN(std::string& input);
        RPN(RPN const& toCopy);
        RPN const& operator=(RPN const& toAffect);
        ~RPN(void);
        int getRes(void);
};

#endif
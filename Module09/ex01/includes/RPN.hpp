/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:04:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/21 12:14:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <stack>
# include <queue>
# include <sstream>

class RPN
{
    private:
        std::queue<int> queue;
        int _a;
        int _b;
        int doOperation(const std::string& s);
    public:
        RPN();
        ~RPN();
        RPN(const RPN& cpy);

        RPN& operator=(RPN src);

        void run(std::string input);
};

#endif

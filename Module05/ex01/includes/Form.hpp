/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/11 19:59:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int _grade_sign;
	const int _grade_execute;
	bool _signed;
public:
	Form();
	~Form();
	Form(const Form& cpy);

	Form& operator=(const Form& src);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
		
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

const std::string _name getName();
const int _grade_sign getGradeSign();
const int _grade_execute getGradeExecute;
bool _signed getSigned;

#endif
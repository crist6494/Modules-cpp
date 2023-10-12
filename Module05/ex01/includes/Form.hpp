/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 11:12:49 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeExecute;
	const int _gradeSign;
public:
	Form();
	Form(std::string name, int gradeExecute, int gradeSign);
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
	bool getSigned() const;
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif
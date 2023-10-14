/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 19:00:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExecute;
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExecute);
	virtual ~AForm();
	AForm(const AForm& cpy);

	AForm& operator=(const AForm& src);

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

	void beSigned(const Bureaucrat& bc);

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif
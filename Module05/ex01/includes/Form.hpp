/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/11 12:02:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int grade_sign;
	const int grade_execute;
	bool _signed;
public:
	Form::Form();
	Form::~Form();
};



#endif
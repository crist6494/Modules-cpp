/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:07:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 20:14:49 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, int grade);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		
};

#endif
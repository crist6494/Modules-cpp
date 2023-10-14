/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:16:59 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:27:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class  RobotomyRequestForm : public AForm
{
	public:
		 RobotomyRequestForm();
		 RobotomyRequestForm(std::string target);
		 RobotomyRequestForm(const  RobotomyRequestForm& cpy);
		~ RobotomyRequestForm();
		 RobotomyRequestForm& operator=(const  RobotomyRequestForm& src);
};

#endif
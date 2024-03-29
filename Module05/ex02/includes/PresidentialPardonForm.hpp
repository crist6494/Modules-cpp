/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:36:22 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 20:13:40 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class  PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const  PresidentialPardonForm& cpy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const  PresidentialPardonForm& src);

		std::string getTarget() const;
		
		void execute(const Bureaucrat& executor) const;
};

#endif
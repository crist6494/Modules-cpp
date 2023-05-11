/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:52:04 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

class AMateria
{
	protected:
		std::string _type;
	public:
	AMateria(std::string const & type);
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& src);
	AMateria& operator=(const AMateria& src)

	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
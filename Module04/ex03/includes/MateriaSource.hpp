/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:10:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/18 14:44:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <typeinfo>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& src);

		MateriaSource& operator=(const MateriaSource& src);
		
		AMateria* createMateria(std::string const & type);
		void learnMateria(AMateria*);
};

#endif
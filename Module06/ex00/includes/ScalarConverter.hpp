/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:42:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:43:55 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& cpy);
    ScalarConverter& operator=(const ScalarConverter& src);
};

#pragma endif
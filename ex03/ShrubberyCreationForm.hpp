/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:07:09 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{

	private:

		std::string	_target;

		/*	Assignment operator	*/
		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &src_object );

	public:

		/*	Canonical form	*/
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &src_object );
		~ShrubberyCreationForm( void );

		/*	Method	*/
		void					execute( Bureaucrat const &executor ) const;

};

#endif
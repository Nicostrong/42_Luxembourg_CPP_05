/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:54:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/22 11:12:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class	Intern
{
	private:

		struct	FormType
		{
			std::string	name;
			AForm		*(*create)( std::string target );
		};
	
		static AForm	*createShrubbery( std::string target );
		static AForm	*createRobotomy( std::string target );
		static AForm	*createPresidential( std::string target );

	public:

		/*	Canonical form	*/
		Intern( void );
		Intern(const Intern &src);
		~Intern( void );

		Intern	&operator=(const Intern &src);

		/*	Method	*/
		AForm	*makeForm(std::string formName, std::string target);

};

#endif
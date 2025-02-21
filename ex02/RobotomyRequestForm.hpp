/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 15:36:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm : public	AForm
{

	private:

		std::string	_target;

		/*	Assignment operator	*/
		RobotomyRequestForm	&operator=( RobotomyRequestForm const &src_object );

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &src_object );
		~RobotomyRequestForm( void );

		/*	Method	*/
		void				execute( Bureaucrat const &executor ) const;

};

#endif

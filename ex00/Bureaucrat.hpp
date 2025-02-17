/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/17 20:18:06 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat
{

		private:

			std::string const	_name;
			int					_grade;
		
		public:

			Bureaucrat( std::string const name, int grade );
			Bureaucrat( Bureaucrat const &src_object );
			~Bureaucrat( void );

			Bureaucrat		&operator=( Bureaucrat const &src_object );

			/*	Getter	*/
			std::string		getName( void ) const;
			int				getGrade( void ) const;

			/*	Methode	*/
			void			incGrade( void );
			void			decGrade( void );

			/*	class Exception	*/
			class			GradeTooHightException : public std::exception
			{

				public:

					const char* what() const throw();
			
			};

			class			GradeTooLowException : public std::exception
			{

				public:

					const char* what() const throw();
			
			};
};

std::ostream				&operator<<( std::ostream &out, Bureaucrat const &src_object); 

#endif

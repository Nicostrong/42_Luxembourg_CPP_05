/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:30:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"

class	AForm;

class	Bureaucrat
{

		private:

			std::string const	_name;
			int					_grade;
		
		public:

			/*	Canonical form	*/
			Bureaucrat( std::string const name, int grade );
			Bureaucrat( Bureaucrat const &src_object );
			~Bureaucrat( void );

			Bureaucrat	&operator=( Bureaucrat const &src_object );

			/*	Getter	*/
			std::string	getName( void ) const;
			int			getGrade( void ) const;

			/*	Methode	*/
			void		incGrade( void );
			void		decGrade( void );
			void		signForm( AForm &form ) const;
			void		executeForm( AForm const &form ) const;

			/*	class Exception	*/
			class	GradeTooHighException : public std::exception
			{

				public:

					const char	*what() const throw();
			
			};

			class	GradeTooLowException : public std::exception
			{

				public:

					const char	*what() const throw();
			
			};
};

std::ostream	&operator<<( std::ostream &out, Bureaucrat const &src_object); 

#endif

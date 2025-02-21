/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:09:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 15:03:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class	Bureaucrat;

class	AForm
{
	private:

		std::string	_name;
		bool		_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExecute;

		/*	Assignment forbidden	*/
		AForm 			&operator=( AForm const &src_object );

	public:

		/*	Canonical form	*/
		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExecute );
		AForm( const AForm &src_object );
		virtual ~AForm( void );

		/*	Getter	*/
		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		int				getGradeToSign( void ) const;
		int				getGradeToExecute( void ) const;
		
		/*	Method	*/
		void			beSigned( Bureaucrat const &bureaucrat );
		virtual void	execute( Bureaucrat const &executor ) const = 0;

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

		class	FormNotSignedException : public std::exception
		{

			public:

				const char	*what() const throw();
		
		};

};

std::ostream	&operator<<( std::ostream &out, AForm const &src_object); 

#endif
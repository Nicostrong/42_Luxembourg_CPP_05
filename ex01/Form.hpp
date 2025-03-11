/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:09:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 12:17:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class	Bureaucrat;

class	Form
{
	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		/*	Assignment forbidden	*/
		Form &operator=( Form const &src_object );

	public:

		/*	Canonical form	*/
		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExecute );
		Form( const Form &src_object );
		~Form( void );

		/*	Getter	*/
		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		int				getGradeToSign( void ) const;
		int				getGradeToExecute( void ) const;
		
		/*	Method	*/
		void			beSigned( Bureaucrat const &bureaucrat );

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

std::ostream	&operator<<( std::ostream &out, Form const &src_object); 

#endif
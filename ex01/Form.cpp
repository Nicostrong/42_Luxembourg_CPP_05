/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:09:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 12:17:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Constructor with parameter
 */
Form::Form( void ) :	_name("default"), \
						_isSigned(false), \
						_gradeToSign(1), \
						_gradeToExecute(1)
{
	std::cout	<< "Default Form constructor with name "
				<< _name
				<< " and with grade to sign "
				<< _gradeToSign
				<< " and with grade to execute "
				<< _gradeToExecute
				<< " called." 
				<< std::endl;
	return ;
}

/*
 *	Constructor with parameter
 */
Form::Form(	std::string name, \
			int gradeToSign, \
			int gradeToExecute) :	_name(name), \
									_isSigned(false), \
									_gradeToSign(gradeToSign), \
									_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout	<< "Form constructor with name " << _name
				<< " and with grade to sign " << _gradeToSign
				<< " and with grade to execute " << _gradeToExecute
				<< " called." 
				<< std::endl;
	return ;
}

/*
 *	Copy constructor
 */
Form::Form( Form const &src_object ) :	_name(src_object._name), \
										_isSigned(src_object._isSigned), \
										_gradeToSign(src_object._gradeToSign), \
										_gradeToExecute(src_object._gradeToExecute)
{
	std::cout	<< "Form copy constructor with name " << this->_name
				<< " and with grade to sign " << this->_gradeToSign
				<< " and with grade to execute " << this->_gradeToExecute
				<< " called."
				<< std::endl;
	return ;
}

/*
 *	Destructor
 */
Form::~Form( void )
{
	std::cout << "Form with name " << this->_name << " is destructed." << std::endl;
	return ;
}

/*******************************************************************************
 *								GETTER										   *
 ******************************************************************************/

/*
 *	getName
 */
std::string		Form::getName( void ) const
{
	return (this->_name);
}

/*
 *	getIsSigned
 */
bool			Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

/*
 *	getGradeToSign
 */
int				Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

/*
 *	getGradeToExecute
 */
int				Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

/*
 *	beSigned
 */
void			Form::beSigned( Bureaucrat const &bureaucrat )
{
	if (this->_isSigned)
	{
		std::cout << "the form is Already signed !" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
	return ;
}	

/*******************************************************************************
 *								EXCEPTION 									   *
 ******************************************************************************/

/*
 *	Exception GradeTooHighException	
 */
const char		*Form::GradeTooHighException::what() const throw()
{
	return  (RED"Grade too high !"RESET);
}

/*
 *	Exeception GradeTooLowException
 */
const char		*Form::GradeTooLowException::what() const throw()
{
	return  ("Grade too low !");
}

/*******************************************************************************
 *								OUTSTREAM									   *
 ******************************************************************************/

/*
 *	output stream operator
 */
std::ostream	&operator<<(std::ostream &out, Form const &src_object)
{
	out	<< "The form with the name " << src_object.getName()
		<< (src_object.getIsSigned() ? " is signed" : " is not signed")
		<< ", with grade to sign " << src_object.getGradeToSign()
		<< " and with grade to execute " << src_object.getGradeToExecute();
	return (out);
}
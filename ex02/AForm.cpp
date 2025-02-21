/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:09:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:39:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/


/*
 *	Constructor with parameter
 */
AForm::AForm( void ) :	_name("default"), \
						_isSigned(false), \
						_gradeToSign(1), \
						_gradeToExecute(1)
{
	std::cout	<< "Default AForm constructor with name " << _name
				<< " and with grade to sign " << _gradeToSign
				<< " and with grade to execute " << _gradeToExecute
				<< " called." << std::endl;
	return ;
}

/*
 *	Constructor with parameter
 */
AForm::AForm(	std::string name, \
			int gradeToSign, \
			int gradeToExecute) :	_name(name), \
									_isSigned(false), \
									_gradeToSign(gradeToSign), \
									_gradeToExecute(gradeToExecute)
{
	std::cout	<< "AForm constructor with name " << _name
				<< " and with grade to sign " << _gradeToSign
				<< " and with grade to execute " << _gradeToExecute
				<< " called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

/*
 *	Copy constructor
 */
AForm::AForm( AForm const &src_object ) :	_name(src_object._name), \
										_isSigned(src_object._isSigned), \
										_gradeToSign(src_object._gradeToSign), \
										_gradeToExecute(src_object._gradeToExecute)
{
	std::cout	<< "AForm copy constructor with name " << this->_name
				<< " and with grade to sign " << this->_gradeToSign
				<< " and with grade to execute " << this->_gradeToExecute
				<< " called." << std::endl;
	return ;
}

/*
 *	Destructor
 */
AForm::~AForm( void )
{
	std::cout	<< "AForm with name " << this->_name
				<< " is destructed." << std::endl;
	return ;
}

/*******************************************************************************
 *								GETTER										   *
 ******************************************************************************/

/*
 *	getName
 */
std::string		AForm::getName( void ) const
{
	return (this->_name);
}

/*
 *	getIsSigned
 */
bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

/*
 *	getGradeToSign
 */
int	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

/*
 *	getGradeToExecute
 */
int	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

/*
 *	beSigned
 */
void	AForm::beSigned( Bureaucrat const &bureaucrat )
{
	if (this->_isSigned)
	{
		std::cout	<< "The form with the name " << this->_name
					<< " is already signed." << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
	std::cout	<< "Bureaucrat " << bureaucrat.getName()
				<< " signs form " << this->getName()
				<< "." << std::endl;
	return ;
}	

/*******************************************************************************
 *								EXCEPTION 									   *
 ******************************************************************************/

/*
 *	Exception GradeTooHighException	
 */
const char		*AForm::GradeTooHighException::what() const throw()
{
	return  (RED"AForm Exception:\tGrade too high !"RESET);
}

/*
 *	Exeception GradeTooLowException
 */
const char		*AForm::GradeTooLowException::what() const throw()
{
	return  (RED"AForm Exception:\tGrade too low !"RESET);
}

/*
 *	Exception FormNotSignedException
 */
const char		*AForm::FormNotSignedException::what() const throw()
{
	return (RED"AForm Exception:\tForm not signed !"RESET);
}

/*******************************************************************************
 *								OUTSTREAM									   *
 ******************************************************************************/

/*
 *	output stream operator
 */
std::ostream	&operator<<(std::ostream &out, AForm const &src_object)
{
	out	<< "The form with the name " << src_object.getName()
		<< (src_object.getIsSigned() ? " is signed" : " is not signed")
		<< " and with grade to sign " << src_object.getGradeToSign()
		<< " and with grade to execute " << src_object.getGradeToExecute()
		<< "." << std::endl;
	return (out);
}
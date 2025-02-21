/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 16:06:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/


/*
 *	Constructor with parameter
 */
Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name)
{
	std::cout	<< "Bureaucrat constructor with name " << _name
				<< " and with grade " << grade
				<< " called."  << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}

/*
 *	Copy constructor
 */
Bureaucrat::Bureaucrat( Bureaucrat const & src_object ) :	_name(src_object._name), \
															_grade(src_object._grade)
{
	std::cout	<< "Bureaucrat copy constructor with name " << this->_name
				<< " and with grade " << this->_grade
				<< " called." << std::endl;
	return ;
}

/*
 *	Destructor
 */
Bureaucrat::~Bureaucrat( void )
{
	std::cout	<< "Bureaucrat with name " << this->_name
				<< " is destructed." << std::endl;
	return ;
}

/*
 *	Assignation operator
 */
Bureaucrat		&Bureaucrat::operator=( Bureaucrat const &src_object )
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &src_object)
	{
		this->_grade = src_object._grade;
		std::cout	<< "Bureaucrat with name " << this->_name
					<< " and with grade " << this->_grade
					<< " is created by assignment constructor." << std::endl;
	}
	return (*this);
}

/*******************************************************************************
 *								GETTER										   *
 ******************************************************************************/

/*
 *	getName
 */
std::string		Bureaucrat::getName( void ) const
{
	return (this->_name);
}

/*
 *	getGrade
 */
int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

/*
 *	incGrade
 */
void			Bureaucrat::incGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return ;
}

/*
 *	decGrade
 */
void			Bureaucrat::decGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return ;
}

/*******************************************************************************
 *								EXCEPTION 									   *
 ******************************************************************************/

/*
 *	Exception GradeTooHightException	
 */
const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return  (RED"Bureaucrat Exception:\tGrade too high !"RESET);
}

/*
 *	Exeception GradeTooLowException
 */
const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return  (RED"Bureaucrat Exception:\tGrade too low !"RESET);
}

/*******************************************************************************
 *								OUTSTREAM									   *
 ******************************************************************************/


/*
 *	output stream operator
 */
std::ostream	&operator<<( std::ostream &out, Bureaucrat const &src_object )
{
	out	<< src_object.getName()
		<< ", bureaucrat grade "
		<< src_object.getGrade();
	return (out);
}
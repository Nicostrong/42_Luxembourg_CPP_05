/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/17 20:19:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 *	Constructor with parameter
 */
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor with parameter called" << std::endl;
	if (grade < 1)
	throw Bureaucrat::GradeTooHightException();
	else if (grade > 150)
	throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}

/*
 *	Copy constructor
 */
Bureaucrat::Bureaucrat(Bureaucrat const & src_object) : _name(src_object._name), \
														_grade(src_object._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

/*
 *	Destructor
 */
Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

/*
 *	Assignation operator
 */
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src_object)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &src_object)
		this->_grade = src_object._grade;
	return (*this);
}

/*
 *	getName
 */
std::string	Bureaucrat::getName( void ) const
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

/*
 *	incGrade
 */
void	Bureaucrat::incGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHightException();
	else
		this->_grade--;
}

/*
 *	decGrade
 */
void	Bureaucrat::decGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

/*
 *	Exception GradeTooHightException	
 */
const char*	Bureaucrat::GradeTooHightException::what() const throw()
{
	return  ("Bureaucrat Exception :\n\tGrade too hight !");
}

/*
 *	Exeception GradeTooLowException
 */
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return  ("Bureaucrat Exception :\n\tGrade too low !");
}

/*
 *	output stream operator
 */
std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src_object)
{
	out	<< src_object.getName()
		<< ", bureaucrat grade "
		<< src_object.getGrade();
	return (out);
}
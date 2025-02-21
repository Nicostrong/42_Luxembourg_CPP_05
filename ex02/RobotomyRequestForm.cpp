/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:38:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Default constructor
 */
RobotomyRequestForm::RobotomyRequestForm( void ) \
						: AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
	std::srand(std::time(NULL));
	std::cout	<< "Default RobotomyRequestForm constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Constructor with papameter
 */
RobotomyRequestForm::RobotomyRequestForm( std::string target ) \
						: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
	std::cout	<< "RobotomyRequestForm constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Copy constructor
 */
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src_object ) \
						: AForm(src_object), _target(src_object._target)
{
	std::srand(std::time(NULL));
	std::cout	<< "RobotomyRequestForm copy constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout	<< "RobotomyRequestForm with name " << this->getName()
				<< " is destroyed." << std::endl;
	return ;
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "TIIIIIITTT... TUUUUTTT.... (robot noise)" << std::endl;
	if (std::rand() % 2)
	{
		std::cout	<< _target
					<< " has been robotomized successfully!"
					<< std::endl;
	}
	else
	{
		std::cout	<< "Robotomy failed on "
					<< _target
					<< "."
					<< std::endl;
	}
	return ;
}
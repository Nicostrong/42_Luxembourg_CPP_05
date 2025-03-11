/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:41:37 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 15:44:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Default constructor
 */
PresidentialPardonForm::PresidentialPardonForm( void ) \
						: AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout	<< "Default PresidentialPardontForm constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Constructor with papameter
 */
PresidentialPardonForm::PresidentialPardonForm( std::string target ) \
						: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout	<< "PresidentialPardontForm constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Copy constructor
 */
PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src_object ) \
						: AForm(src_object), _target(src_object._target)
{
	std::cout	<< "PresidentialPardontForm copy constructor with name " << this->getName()
				<< ", with grade to sign " << this->getGradeToSign()
				<< " and with grade to execute " << this->getGradeToExecute()
				<< " and with target " << this->_target
				<< " called." << std::endl;
	return ;
}

/*
 *	Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout	<< "PresidentialPardontForm with name " << this->getName()
				<< " is destroyed." << std::endl;
	return ;
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:05 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:38:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Default constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm( void ) \
						: AForm("Shrubbery", 145, 137), _target("default_target")
{
	std::cout	<< "Default ShrubberyCreationForm constructor with name "
				<< this->getName()
				<< ", with grade to sign "
				<< this->getGradeToSign()
				<< " and with grade to execute "
				<< this->getGradeToExecute()
				<< " and with target "
				<< this->_target
				<< " called." 
				<< std::endl;
	return ;
}

/*
 *	Constructor with papameter
 */
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) \
						: AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout	<< "ShrubberyCreationForm constructor with name "
				<< this->getName()
				<< ", with grade to sign "
				<< this->getGradeToSign()
				<< " and with grade to execute "
				<< this->getGradeToExecute()
				<< " and with target "
				<< this->_target
				<< " called." 
				<< std::endl;
	return ;
}

/*
 *	Copy constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src_object ) \
						: AForm(src_object), _target(src_object._target)
{
	std::cout	<< "ShrubberyCreationForm copy constructor with name "
				<< this->getName()
				<< ", with grade to sign "
				<< this->getGradeToSign()
				<< " and with grade to execute "
				<< this->getGradeToExecute()
				<< " and with target "
				<< this->_target
				<< " called." 
				<< std::endl;
	return ;
}

/*
 *	Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout	<< "ShrubberyCreationForm with name "
				<< this->getName()
				<< " is destroyed."
				<< std::endl;
	return ;
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream	outFile((_target + "_shrubbery").c_str());
	if (!outFile)
	{
		std::cerr << "Error: Unable to create " << _target << "_shrubbery file." << std::endl;
		return;
	}
	outFile <<	"       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\ \n";
	outFile.close();
	std::cout	<< "Shruberry created at " << _target << "_shrubbery." << std::endl;
	return ;
}
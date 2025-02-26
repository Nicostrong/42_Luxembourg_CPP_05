/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:54:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/26 07:52:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Default constructor
 */
Intern::Intern( void )
{
	std::cout	<< "Intern default constructor called." << std::endl;
	return ;
}

/*
 *	Copy constructor
 */
Intern::Intern( Intern const &src )
{
	std::cout	<< "Intern copy constructor called." << std::endl;
	*this = src;
	return ;
}

/*
 *	Destructor
 */
Intern::~Intern( void )
{
	std::cout	<< "Intern destructor called." << std::endl;
	return ;
}

/*
 *	Assignment constructor
 */
Intern	&Intern::operator=( Intern const &src )
{
	std::cout	<< "Intern assignment constructor called." << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/*******************************************************************************
 *							PRIVATE METHOD 									   *
 ******************************************************************************/

/*
 *	private method to create a Shrubbery form
 */
AForm*	Intern::createShrubbery( std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/*
 *	private method to create a Robotomy form
 */
AForm*	Intern::createRobotomy( std::string target )
{
	return (new RobotomyRequestForm(target));
}

/*
 *	private method to create a Presidential form
 */
AForm*	Intern::createPresidential( std::string target )
{
	return (new PresidentialPardonForm(target));
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

/*
 *	makeForm
 */
AForm	*Intern::makeForm( std::string formName, std::string target )
{
	FormType	forms[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};

	for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i].create(target));
		}
	}
	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return (NULL);
}
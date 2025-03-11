/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 16:41:33 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	AForm		*form1 = intern.makeForm("shrubbery creation", "Garden");
	AForm		*form2 = intern.makeForm("robotomy request", "Marvin");
	AForm		*form3 = intern.makeForm("presidential pardon", "Arthur Dent");
	AForm		*form4 = intern.makeForm("", "Unknown");
	AForm		*form5 = intern.makeForm("invalid form", "Nowhere");

	std::cout	<< BLUE
				<< "********** Execution **********"
				<< RESET
				<< std::endl;

	if (form1)
	{
		std::cout << GREEN;
		boss.signForm(*form1);
		boss.executeForm(*form1);
		std::cout << RESET;
		delete form1;
	}

	if (form2)
	{
		std::cout << YELLOW;
		boss.signForm(*form2);
		boss.executeForm(*form2);
		std::cout << RESET;
		delete form2;
	}

	if (form3)
	{
		std::cout << MAGENTA;
		boss.signForm(*form3);
		boss.executeForm(*form3);
		std::cout << RESET;
		delete form3;
	}

	std::cout << RED;
	if (!form4)
		std::cout << "Form 4 creation failed as expected (empty form name)." << std::endl;
	else
		delete form4;

	if (!form5)
		std::cout << "Form 5 creation failed as expected (invalid form name)." << std::endl;
	else
		delete form5;
	std::cout << RESET;

	std::cout	<< BLUE
				<< "********** Exception tests **********"
				<< RESET
				<< std::endl;
	
	Bureaucrat	lowRank("Lowrank", 150);
	AForm		*form6 = intern.makeForm("shrubbery creation", "Garden");
	AForm		*form7 = intern.makeForm("robotomy request", "Marvin");
	AForm		*form8 = intern.makeForm("presidential pardon", "Arthur Dent");

	if (form6)
	{
		try
		{
			std::cout << "lowRank try to sign form6" << std::endl;
			lowRank.signForm(*form6);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		delete form6;
	}
	if (form7)
	{
		try
		{
			std::cout << "lowRank try to sign form7" << std::endl;
			lowRank.signForm(*form7);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		delete form7;
	}
	if (form8)
	{
		try
		{
			std::cout << "lowRank try to sign form8" << std::endl;
			lowRank.signForm(*form8);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		delete form8;
	}

	std::cout	<< BLUE
				<< "********** Tests bad name forms **********"
				<< RESET
				<< std::endl;
	
	AForm		*form9 = intern.makeForm(" shrubbery creation", "Garden");
	AForm		*form10 = intern.makeForm("ROBOTOMY REQUEST", "Marvin");
	AForm		*form11 = intern.makeForm("presidential  pardon", "Arthur Dent");

	std::cout << RED;
	if (!form9)
		std::cout << "Form 9 creation failed as expected (empty form name)." << std::endl;
	if (!form10)
		std::cout << "Form 10 creation failed as expected (invalid form name)." << std::endl;
	if (!form11)
		std::cout << "Form 11 creation failed as expected (invalid form name)." << std::endl;
	std::cout << RESET;

	std::cout	<< BLUE
				<< "********** End of tests **********"
				<< RESET
				<< std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 18:51:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout	<< BLUE
					<< "********** Bureaucrats **********"
					<< RESET
					<< std::endl;

		Bureaucrat lowRank("LowRank", 150);
		Bureaucrat midRank("MidRank", 70);
		Bureaucrat highRank("HighRank", 1);
		Bureaucrat robotRank("RobotRank", 40);

		std::cout << lowRank << std::endl;
		std::cout << midRank << std::endl;
		std::cout << highRank << std::endl;
		std::cout << robotRank << std::endl;

		std::cout	<< BLUE
					<< "********** Forms **********"
					<< RESET
					<< std::endl;

		ShrubberyCreationForm shrubbery("Garden");
		RobotomyRequestForm robotomy("Marvin");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		std::cout	<< BLUE
					<< "********** Signing forms **********"
					<< RESET
					<< std::endl;

		std::cout << "error to signForm" << std::endl;
		lowRank.signForm(shrubbery);
		lowRank.signForm(robotomy);
		lowRank.signForm(pardon);

		std::cout << "correct try to signForm" << std::endl;
		midRank.signForm(shrubbery);
		midRank.signForm(robotomy);
		highRank.signForm(pardon);

		std::cout	<< BLUE
					<< "********** Executing forms **********"
					<< RESET
					<< std::endl;

		std::cout << "Error to executeForm" << std::endl;
		lowRank.executeForm(shrubbery);
		lowRank.executeForm(robotomy);
		lowRank.executeForm(pardon);

		std::cout << "executeForm correct" << std::endl;
		midRank.executeForm(shrubbery);
		
		std::cout << "executeForm correct but aleatory (50%)" << std::endl;
		std::cout << YELLOW;
		for (int i = 0; i < 10; ++i)
			robotRank.executeForm(robotomy);
		std::cout << RESET;

		std::cout << "executeForm error" << std::endl;
		midRank.executeForm(pardon);

		std::cout << "executeForm correct" << std::endl;
		highRank.executeForm(pardon);

		std::cout	<< BLUE
					<< "********** Exception Handling **********"
					<< RESET
					<< std::endl;

		try
		{
			std::cout << "Create PresidentialPardonForm with invalid grade to sign" << std::endl;
			PresidentialPardonForm invalidForm("Zaphod");
			Bureaucrat invalidBureaucrat("Invalid", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try
		{
			std::cout << "Form not signed" << std::endl;
			RobotomyRequestForm unsignedRobot("Unlucky");
			midRank.executeForm(unsignedRobot);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		std::cout	<< BLUE
					<< "********** Edge Cases **********"
					<< RESET
					<< std::endl;

		std::cout << "Try to sign again a signed form" << std::endl;
		highRank.signForm(pardon);

		std::cout << "Try to sign a signed form" << std::endl;
		midRank.signForm(shrubbery);

		std::cout << "\nCheck for file: Garden_shrubbery to verify ShrubberyCreationForm execution.\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Global Exception caught: " << e.what() << std::endl;
	}

	std::cout	<< BLUE
					<< "********** End of tests **********"
					<< RESET
					<< std::endl;

	return (0);
}
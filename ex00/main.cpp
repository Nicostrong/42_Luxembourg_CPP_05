/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 11:14:46 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testBureaucrat( const std::string &name, int grade )
{
	try
	{
		Bureaucrat	bureaucrat(name, grade);
		std::cout << bureaucrat << std::endl;

		std::cout << "Try to increase the grade ..." << std::endl;
		bureaucrat.incGrade();
		std::cout << "After incrementation: " << bureaucrat << std::endl;

		std::cout << "Try to decrease the grade .." << std::endl;
		bureaucrat.decGrade();
		std::cout << "After decrease: " << bureaucrat << std::endl;
		
		std::cout << "Try to decrease the grade .." << std::endl;
		bureaucrat.decGrade();
		std::cout << "After decrease: " << bureaucrat << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int		main( void )
{
	std::cout << "\t\t\t=== TEST BUREAUCRAT ===" << std::endl;

	std::cout	<< GREEN
				<< "\n\t\t--- Test Bureaucrat valid (Grade 75) ---"
				<< RESET
				<< std::endl
				<< std::endl;
	testBureaucrat("Alice", 75);

	std::cout	<< BLUE
				<< "\n\t\t--- Test Grade too hight (Grade 0) ---"
				<< RESET
				<< std::endl
				<< std::endl;
	testBureaucrat("Bob", 0);

	std::cout	<< BLUE
				<< "\n\t\t--- Test Grade too low (Grade 151) ---"
				<< RESET
				<< std::endl
				<< std::endl;
	testBureaucrat("Charlie", 151);

	std::cout	<< YELLOW
				<< "\n\t\t--- Test invalid decrease ---"
				<< RESET
				<< std::endl
				<< std::endl;
	testBureaucrat("Edward", 150);

	std::cout	<< YELLOW
				<< "\n\t\t--- Test invalid increase ---"
				<< RESET
				<< std::endl
				<< std::endl;
	testBureaucrat("Paul", 1);

	return (0);
}
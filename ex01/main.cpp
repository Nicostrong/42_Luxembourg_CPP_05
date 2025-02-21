/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/21 14:14:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout	<< BLUE
				<< "********** Test Bureaucrat constructor **********"
				<< RESET
				<< std::endl;
	/*	Grade ToLow	*/
	try
	{
		std::cout << "Trying to create a bureaucrat with a grade too low..." << std::endl;
		Bureaucrat b1("Alice", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Grade ToHigh	*/
	try
	{
		std::cout << "Trying to create a bureaucrat with a grade too high..." << std::endl;
		Bureaucrat b2("Tom", 152);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Grade OK	*/
	try
	{
		std::cout << "Creating a bureaucrat with a valid grade..." << std::endl;
		Bureaucrat b3("Barbara", 1);
		std::cout << b3 << std::endl;
		std::cout << "Incrementing grade..." << std::endl;
		b3.incGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating a bureaucrat with a valid grade..." << std::endl;
		Bureaucrat b4("Dave", 150);
		std::cout << b4 << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		b4.decGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout	<< BLUE
				<< "********** Test Form constructor **********"
				<< RESET
				<< std::endl;
	/*	Grade to sign to high	*/
	try
	{
		std::cout << "Trying to create a form with a grade to sign too high..." << std::endl;
		Form f1("Contract", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Grad to execute to low	*/
	try
	{
		std::cout << "Trying to create a form with a grade to execute too low..." << std::endl;
		Form f2("Agreement", 50, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Valid Form	*/
	try
	{
		std::cout << "Creating a form with valid grade..." << std::endl;
		Form f3("Invoice", 30, 40);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Impossible to assignment Form uncomment to check error in compilation	*/
	/*
	try
	{
		Form f4("Invoisse", 30, 40);
		Form f5("Invoice", 30, 40);
		f4 = f5;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}*/

	std::cout	<< BLUE
				<< "********** Test Form signing **********"
				<< RESET
				<< std::endl;
	/*	Not the good grade to sign the form	*/
	try
	{
		Bureaucrat signer("Eve", 50);
		Form form1("Purchase Order", 30, 40);
		std::cout << signer << std::endl;
		std::cout << form1 << std::endl;
		std::cout << "Trying to sign a form with a grade too low..." << std::endl;
		form1.beSigned(signer);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Good grade to sign and try to sign again	*/
	try
	{
		Bureaucrat signer2("Frank", 20);
		Form form2("Leave Request", 30, 40);
		std::cout << signer2 << std::endl;
		std::cout << form2 << std::endl;
		form2.beSigned(signer2);
		std::cout << form2 << std::endl;
		std::cout << "Trying to sign the already signed form again..." << std::endl;
		form2.beSigned(signer2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout	<< BLUE
				<< "********** Test Grade Manipulation **********"
				<< RESET
				<< std::endl;
	/*	Bad final grade to high	*/
	try
	{
		Bureaucrat b5("George", 2);
		std::cout << b5 << std::endl;
		std::cout << "Incrementing grade..." << std::endl;
		b5.incGrade();
		std::cout << b5 << std::endl;
		std::cout << "Incrementing grade..." << std::endl;
		b5.incGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	bad final grade to low	*/
	try
	{
		Bureaucrat b6("Helen", 149);
		std::cout << b6 << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		b6.decGrade();
		std::cout << b6 << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		b6.decGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
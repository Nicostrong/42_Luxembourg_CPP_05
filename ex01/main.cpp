/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:58:10 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/11 12:30:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main( void )
{
	std::cout	<< BLUE
				<< "********** Test Bureaucrat constructor **********"
				<< RESET
				<< std::endl;
	try
	{
		std::cout	<< "Trying to create a bureaucrat with a grade too low..." << std::endl;
		Bureaucrat	b1("Alice", 151);
		std::cout	<< b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Trying to create a bureaucrat with a grade too high..." << std::endl;
		Bureaucrat	b2("Tom", 0);
		std::cout	<< b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Creating a bureaucrat with a valid grade..." << std::endl;
		Bureaucrat	b3("Barbara", 1);
		std::cout	<< b3 << std::endl;
		std::cout	<< "Incrementing grade..." << std::endl;
		b3.incGrade();
		std::cout	<< b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Creating a bureaucrat with a valid grade..." << std::endl;
		Bureaucrat	b4("Dave", 150);
		std::cout	<< b4 << std::endl;
		std::cout	<< "Decrementing grade..." << std::endl;
		b4.decGrade();
		std::cout	<< b4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout	<< BLUE
				<< "********** Test Form constructor **********"
				<< RESET
				<< std::endl;
	try
	{
		std::cout	<< "Trying to create a form with a grade to sign too high..." << std::endl;
		Form		f1("Contract", 0, 50);
		std::cout	<< f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Trying to create a form with a grade to sign too low..." << std::endl;
		Form		f2("Contract", 200, 50);
		std::cout	<< f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Trying to create a form with a grade to execute too hight..." << std::endl;
		Form		f3("Agreement", 50, 151);
		std::cout	<< f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Trying to create a form with a grade to execute too low..." << std::endl;
		Form		f4("Agreement", 50, 151);
		std::cout	<< f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout	<< "Creating a form with valid grade..." << std::endl;
		Form		f5("Invoice", 30, 40);
		std::cout	<< f5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*	Impossible to assignment Form uncomment to check error in compilation	*/
	/*
	try
	{
		Form		f6("Invoisse", 30, 40);
		std::cout	<< f6 << std::endl;
		Form		f7("Invoice", 30, 40);
		std::cout	<< f7 << std::endl;
		f6 = f7;
		std::cout	<< f6 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	*/
	std::cout	<< BLUE
				<< "********** Test Form signing **********"
				<< RESET
				<< std::endl;
	try
	{
		Bureaucrat	signer("Eve", 50);
		Form		form1("Purchase Order", 30, 40);
		std::cout	<< signer << std::endl;
		std::cout	<< form1 << std::endl;
		std::cout	<< "Trying to sign a form with a grade too low..." << std::endl;
		form1.beSigned(signer);
		std::cout	<< form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	signer2("Frank", 20);
		Form		form2("Leave Request", 30, 40);
		std::cout	<< signer2 << std::endl;
		std::cout	<< form2 << std::endl;
		form2.beSigned(signer2);
		std::cout	<< form2 << std::endl;
		std::cout	<< "Trying to sign the already signed form again..." << std::endl;
		form2.beSigned(signer2);
		std::cout	<< form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout	<< BLUE
				<< "********** Test Grade Manipulation **********"
				<< RESET
				<< std::endl;
	try
	{
		Bureaucrat	b5("George", 2);
		std::cout	<< b5 << std::endl;
		std::cout	<< "Incrementing grade..." << std::endl;
		b5.incGrade();
		std::cout	<< b5 << std::endl;
		std::cout	<< "Incrementing grade..." << std::endl;
		b5.incGrade();
		std::cout	<< b5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b6("Helen", 149);
		std::cout	<< b6 << std::endl;
		std::cout	<< "Decrementing grade..." << std::endl;
		b6.decGrade();
		std::cout	<< b6 << std::endl;
		std::cout	<< "Decrementing grade..." << std::endl;
		b6.decGrade();
		std::cout	<< b6 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout	<< BLUE
				<< "********** Test Sign Form **********"
				<< RESET
				<< std::endl;
	Bureaucrat	alice("Alice", 50);
	Bureaucrat	bob("Bob", 20);
	Form		contract("Contract", 30, 40);

	std::cout	<< alice << std::endl;
	std::cout	<< bob << std::endl;
	std::cout	<< contract << std::endl;
	std::cout	<< "Alice can't sign the form..." << std::endl;
	alice.signForm(contract);
	std::cout	<< "Bob can sign the form..." << std::endl;
	bob.signForm(contract);
	std::cout	<< "Bob sign the form again..." << std::endl;
	bob.signForm(contract);

	return (0);
}
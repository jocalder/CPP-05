/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:41:02 by jocalder          #+#    #+#             */
/*   Updated: 2026/02/26 11:47:37 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "===== TEST 1: Creation OK =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		Form f("Contract", 50, 30);

		std::cout << a << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: Invalid Bureaucrat Grade =====" << std::endl;
	try
	{
		Bureaucrat bad("Bad", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: Invalid Form Grade =====" << std::endl;
	try
	{
		Form badForm("Illegal", 151, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: Successful Sign =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form permit("Permit", 10, 10);

		boss.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5: Failed Sign =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form secret("SecretForm", 10, 10);

		intern.signForm(secret);
		std::cout << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6: Increment / Decrement Limits =====" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		top.incrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Increment error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 150);
		low.decrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Decrement error: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 7: Copy and Assignment =====" << std::endl;
	try
	{
		Bureaucrat a("Original", 20);
		Bureaucrat b = a; // copy constructor

		std::cout << b << std::endl;

		Bureaucrat c("Other", 100);
		c = a; // assignment

		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== END OF TESTS =====" << std::endl;

	return 0;
}

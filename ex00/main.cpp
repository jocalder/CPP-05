/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:16:44 by jocalder          #+#    #+#             */
/*   Updated: 2026/02/17 12:04:18 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "VALID INCREMENT" << std::endl;
	try
	{
		Bureaucrat	a("Jon", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "VALID DECREMENT" << std::endl;
	try
	{
		Bureaucrat	b("Tim", 149);
		std::cout << b << std::endl;
		
		b.decrementGrade();
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "TOO HIGH IN CONSTRUCTOR" << std::endl;
	try
	{
		Bureaucrat	c("Anne", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "TOO LOW IN CONSTRUCTOR" << std::endl;
	try
	{
		Bureaucrat	d("Sara", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	
}
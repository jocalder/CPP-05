/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:09:39 by jocalder          #+#    #+#             */
/*   Updated: 2026/03/12 12:40:38 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
	AForm* form;

	try
	{
		std::cout << "Test 1: ShrubberyCreationForm." << std::endl;
		form = someRandomIntern.makeForm("shrubbery creation", "Shrub");
		if (form)
		{
			Bureaucrat Bob("bob", 1);
			Bob.signForm(*form);
		    Bob.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Test 2: RobotomyRequestForm." << std::endl;
		form = someRandomIntern.makeForm("robotomy request", "Robot");
		if (form)
		{
			Bureaucrat jon("jon", 1);
			jon.signForm(*form);
			jon.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
    
    try
	{
		std::cout << "Test 3: PresidentialPardonForm." << std::endl;
		form = someRandomIntern.makeForm("presidential pardon", "Presi");
		if (form)
		{
			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 4: Invalid form." << std::endl;

	form = someRandomIntern.makeForm("invalid form", "Nobody");
	if (form)
		delete form;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:01:46 by jocalder          #+#    #+#             */
/*   Updated: 2026/03/12 11:48:52 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm shrub("Shrub");
	RobotomyRequestForm robot("RObot");
	PresidentialPardonForm pardon("Presi");

	std::cout << "SIGN TESTS." << std::endl;
	intern.signForm(shrub);
	boss.signForm(shrub);

	std::cout << "EXECUTE TESTS." << std::endl;
	intern.executeForm(shrub);
	boss.executeForm(shrub);

	std::cout << "ROBOTOMY." << std::endl;
	boss.signForm(robot);
	boss.executeForm(robot);

	std::cout << "PRESIDENTIAL." << std::endl;
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}

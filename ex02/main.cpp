/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:01:46 by jocalder          #+#    #+#             */
/*   Updated: 2026/03/04 13:02:37 by jocalder         ###   ########.fr       */
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

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "\n--- SIGN TESTS ---\n";
	intern.signForm(shrub);
	boss.signForm(shrub);

	std::cout << "\n--- EXECUTE TESTS ---\n";
	intern.executeForm(shrub);
	boss.executeForm(shrub);

	std::cout << "\n--- ROBOTOMY ---\n";
	boss.signForm(robot);
	boss.executeForm(robot);

	std::cout << "\n--- PRESIDENTIAL ---\n";
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}

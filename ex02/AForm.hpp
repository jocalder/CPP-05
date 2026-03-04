/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:23 by jocalder          #+#    #+#             */
/*   Updated: 2026/03/04 13:09:17 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();
		
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat &b);
		void		execute(Bureaucrat const & executor) const;
		
		virtual void	executeAction() const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();	
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& f);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:59:03 by jocalder          #+#    #+#             */
/*   Updated: 2026/03/04 13:11:23 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const {return _name;}
bool		AForm::getSigned() const {return _signed;}
int			AForm::getGradeToSign() const {return _gradeToSign;}
int			AForm::getGradeToExecute() const {return _gradeToExecute;}

void		AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooHighException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{return "Grade too high!";}
const char*	AForm::GradeTooLowException::what() const throw()
{return "Grade too low!";}
const char*	AForm::FormNotSignedException::what() const throw()
{return "Form not signed!";}

std::ostream&	operator<<(std::ostream& out, const AForm& f)
{
	out << "Form " << f.getName()
	   << ", signed: " << f.getSigned()
	   << ", gradeToSign: " << f.getGradeToSign()
	   << ", gradeToExecute: " << f.getGradeToExecute();
	return out;
}
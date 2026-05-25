#include "../inc/   Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Name"), grade(75) {}

Bureaucrat::Bureaucrat(std::string const& newName, int newGrade) : name(newName)
{
    if (newGrade < 1)
        throw GradeTooHighException();
    if (newGrade > 150)
        throw GradeTooLowException();
    this->grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src){
        if (this->name != src.name)
            throw InvalidAssignment();
        this->grade = src.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const&    Bureaucrat::getName()const
{
    return this->name;
}

int Bureaucrat::getGrade()const
{
    return (this->grade);
}

void    Bureaucrat::promote(int degrees)
{
    if (this->grade - degrees < 1)
        throw GradeTooHighException();
    this->grade -= degrees;
}

void    Bureaucrat::demote(int degrees)
{
    if (this->grade + degrees > 150)
        throw GradeTooLowException();
    this->grade += degrees;
}

void    Bureaucrat::signForm(const Form& form)const
{
    bool success = form.beSigned(this);
    if (success){
        std::cout << this->name << " signed " << form.name;
    }
    else{
        std::cout << this->name << " couldn't sign " << form.name << " because his grade is too low." << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Bureaucrat::InvalidAssignment::what() const throw()
{
    return ("Invalid assignment. Bureaucrats have different names.");
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " ,bureaucrat grade: " << bureaucrat.getGrade() << "." << std::endl;
    return (out);
}
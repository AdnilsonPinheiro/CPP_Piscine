#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

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

void    Bureaucrat::signForm(AForm& form)const
{
    try{
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << this->name << " couldn't sign " << form.getName() << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

void    Bureaucrat::executeForm(AForm const& form)const
{
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
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
    out << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << "." << std::endl;
    return (out);
}
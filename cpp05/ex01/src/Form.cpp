#include "../inc/Form.hpp"

Form::Form() : name("Standard Form"), isSigned(false), signGrade(75), execGrade(75) {}

Form::Form(const std::string newName, const int newSignGrade, const int newExecGrade) : 
    name(newName),
    signGrade(newSignGrade),
    execGrade(newExecGrade)
{
    if (newSignGrade < 1 || newExecGrade < 1)
        throw GradeTooLowException();
    else if (newSignGrade > 150 || newExecGrade > 150)
        throw GradeTooHighException();
    this->isSigned = false;
}

Form::Form(const Form& src) :
    name(src.name),
    isSigned(false),
    signGrade(src.signGrade),
    execGrade(src.execGrade) {}

Form&   Form::operator=(const Form& src)
{
    if (this != &src){
        // this->name = src.name;
        this->isSigned = src.isSigned;
        // this->signGrade = src.signGrade;
        // this->execGrade = src.execGrade;
    }
    return (*this);
}

Form::~Form(){}

const std::string&  Form::getName()const    
{
    return (this->name);
}

bool    Form::sigStatus()const
{
    return (this->isSigned);
}

int   Form::getSignGrade()const
{
    return (this->signGrade);
}

int   Form::getExecGrade()const
{
    return (this->execGrade);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Error: grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Error: grade too low!");
}

std::ostream&   operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() << "\n\t" << "Signature Grade: " << form.getSignGrade() << "\n\t" << "Signature Status: " << form.sigStatus() << "\n\t" << "Execution Grade: " << form.getExecGrade() << std::endl;
    return (out);
}
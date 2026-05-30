#include "../inc/Form.hpp"

Form::Form() : name("Standard Form"), isSigned(false), signGrade(75), execGrade(75) {}

Form::Form(const std::string newName, const int newSignGrade, const int newExecGrade) : 
    name(newName),
    signGrade(newSignGrade),
    execGrade(newExecGrade)
{
    if (newSignGrade < 1 || newExecGrade < 1)
        throw GradeTooHighException();
    else if (newSignGrade > 150 || newExecGrade > 150)
        throw GradeTooLowException();
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
        if (this->name != src.name || this->signGrade != src.signGrade || this->execGrade != src.execGrade)
            throw InvalidCopyAssignmentException();
        this->isSigned = src.isSigned;
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

const char* Form::InvalidCopyAssignmentException::what() const throw()
{
    return ("Form Error: invalid assingment operator!");
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Error: grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Error: grade too low!");
}

std::ostream&   operator<<(std::ostream& out, const Form& Form)
{
    out << Form.getName() << "\n\t" << "Signature Grade: " << Form.getSignGrade() << "\n\t" << "Signature Status: " << Form.sigStatus() << "\n\t" << "Execution Grade: " << Form.getExecGrade() << std::endl;
    return (out);
}
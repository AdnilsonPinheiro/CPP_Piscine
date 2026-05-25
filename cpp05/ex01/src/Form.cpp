#include "../inc/Form.hpp"

Form::Form() : name("Standard Form"), isSigned(false), signGrade(75), execGrade(75) {}

Form::Form(const std::string newName, const int newSignGrade, const int newExecGrade) : 
    name(newName),
    isSigned(false),
    signGrade(newSignGrade),
    execGrade(newExecGrade) {}

Form::Form(const Form& src) :
    name(src.name);
    isSigned(false),
    signGrade(src.signGrade),
    execGrade(src.execGrade) {}

Form&   Form::operator=(const Form& src)
{
    if (this != &src){
        this->name = src.name;
        this->isSigned = src.isSigned;
        this->signGrade = src.signGrade;
        this->execGrade = src.execGrade;
    }
    return (this);
}

Form::~Form(){}

const std::string&  Form::getName()const    
{
    return (this->name);
}

bool    Form::isSigned()const
{
    return (this->isSigned);
}

const int   Form::getSignGrade()const
{
    return (this->signGrade);
}

const int   Form::getExecGrade()const
{
    return (this->execGrade);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.grade > this->grade)
        throw GradeTooHighException();
    this->isSigned = true;
}

std::ostream&   operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << this->name << "\n\t" << "Signature Grade: " << this->signGrade << "\n\t" << "Signature Status: " << this->isSigned << "\n\t" << "Execution Grade: " << this->execGrade << std::endl;
    return (out);
}
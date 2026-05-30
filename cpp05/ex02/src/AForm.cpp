#include "../inc/AForm.hpp"

AForm::AForm() : name("Standard AForm"), isSigned(false), signGrade(75), execGrade(75) {}

AForm::AForm(const std::string newName, const int newSignGrade, const int newExecGrade) : 
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

AForm::AForm(const AForm& src) :
    name(src.name),
    isSigned(false),
    signGrade(src.signGrade),
    execGrade(src.execGrade) {}

AForm&   AForm::operator=(const AForm& src)
{
    if (this != &src)
    {
        if (this->name != src.name || this->signGrade != src.signGrade || this->execGrade != src.execGrade)
            throw InvalidCopyAssignmentException();
        this->isSigned = src.isSigned;
    }
    return (*this);
}

AForm::~AForm(){}

const std::string&  AForm::getName()const    
{
    return (this->name);
}

bool    AForm::sigStatus()const
{
    return (this->isSigned);
}

int   AForm::getSignGrade()const
{
    return (this->signGrade);
}

int   AForm::getExecGrade()const
{
    return (this->execGrade);
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

void    AForm::execute(Bureaucrat const& executor)const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->execGrade)
        throw GradeTooLowException();
    this->executeAction();
}

const char* AForm::InvalidCopyAssignmentException::what() const throw()
{
    return ("AForm Error: invalid copy assignment!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm Error: form needs signing!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Error: grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Error: grade too low!");
}

std::ostream&   operator<<(std::ostream& out, const AForm& AForm)
{
    out << AForm.getName() << "\n\t" << "Signature Grade: " << AForm.getSignGrade() << "\n\t" << "Signature Status: " << AForm.sigStatus() << "\n\t" << "Execution Grade: " << AForm.getExecGrade() << std::endl;
    return (out);
}
#ifndef Form_HPP
# define Form_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           execGrade;
public:
    Form    ();
    Form    (const std::string newName, const int newSignGrade, const int newExecGrade);
    Form    (const Form& src);
    Form&   operator=(const Form& src);
    ~Form   ();

    const std::string&  getName()const;
    bool                sigStatus()const;
    int                 getSignGrade()const;
    int                 getExecGrade()const;

    void                beSigned(const Bureaucrat& bureaucrat);

    class InvalidCopyAssignmentException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& out, const Form& Form);

#endif
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           execGrade;
public:
    AForm    ();
    AForm    (const std::string newName, const int newSignGrade, const int newExecGrade);
    AForm    (const AForm& src);
    AForm&   operator=(const AForm& src);
    ~AForm   ();

    const std::string&  getName()const;
    bool                sigStatus()const;
    int                 getSignGrade()const;
    int                 getExecGrade()const;

    void                beSigned(const Bureaucrat& bureaucrat);

    virtual void    execute(Bureaucrat const& executor)const;
    virtual void    executeAction(void)const = 0;

    class InvalidCopyAssignmentException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception{
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

std::ostream&   operator<<(std::ostream& out, const AForm& AForm);

#endif
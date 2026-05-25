    #ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
private:
    const std::string   name;
    int grade;
public:
    Bureaucrat  ();
    Bureaucrat  (std::string const& newName, int grade);
    Bureaucrat  (const Bureaucrat& src);
    Bureaucrat&  operator=(const Bureaucrat& rhs);
    ~Bureaucrat ();

    std::string const&  getName()const;
    int                 getGrade()const;
    void                promote(int degrees);
    void                demote(int degrees);

    void                signForm(const Form& form)const;

    class   GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class   GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class   InvalidAssignment : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
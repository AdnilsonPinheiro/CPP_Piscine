#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>

class AForm;

class Intern
{
public:
	Intern	();
	Intern	(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern	();

	AForm* makeForm	(const std::string form, const std::string target)const;

	class UnknownFormException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
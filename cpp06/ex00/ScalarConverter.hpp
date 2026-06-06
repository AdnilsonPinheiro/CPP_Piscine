#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <sstream>

class ScalarConverter
{
public:
	static void convert(std::string& input);
private:
	std::string data;
	ScalarConverter();
	ScalarConverter(const std::string& input);
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();
};

#endif
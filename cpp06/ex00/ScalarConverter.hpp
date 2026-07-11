#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <climits>
# include <cstdlib>
# include <float.h>

enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	ERROR
};

class ScalarConverter
{
public:
	static void convert(const std::string& input);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();
};

#endif
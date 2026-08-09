#include "BitcoinExchange.hpp"

static void trim(std::string& str);

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchange_rates(other.exchange_rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchange_rates = other.exchange_rates;
	return (*this);
}

void BitcoinExchange::processInput(const std::string& input)
{
	std::ifstream filename(input);
	if (!filename.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string line;

	// checks if a first line exists and if it is in the appropriate form
	if (!std::getline(filename, line) || line != "date | value")
		throw std::runtime_error("Error: header must be \"date | value\"");

	while (std::getline(filename, line))
	{
		std::stringstream ss(line);
		std::string date, value;

		// passes the content of the line, up until the '|' character, to std::string date
		std::getline(ss, date, '|');
		// passes rest of the line to std::string value
		std::getline(ss, value);

		trim(date);
		trim(value);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	
}

static void trim(std::string& str)
{
	std::string result;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			result += str[i];
	}

	str = result;
}
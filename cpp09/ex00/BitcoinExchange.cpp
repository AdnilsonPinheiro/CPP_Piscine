#include "BitcoinExchange.hpp"

static void trim(std::string& str);

BitcoinExchange::BitcoinExchange()
{
	loadData("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchange_rates(other.exchange_rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchange_rates = other.exchange_rates;
	return (*this);
}

void BitcoinExchange::loadData(const char* filename)
{
	std::ifstream infile(filename, std::ifstream::in);

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open data.csv");

	std::string line;

	if (!std::getline(infile, line) || line != "date,exchange_rate")
		throw std::runtime_error("Error: header must be \"date,exchange_rate\"");

	while (std::getline(infile, line))
	{
		std::stringstream ss(line);
		std::string date, rate;

		std::getline(ss, date, ',');
		std::getline(ss, rate);

		if (!isValidDate(date))
			throw std::runtime_error("Error: Invalid date format at data.csv");

		double x_rate = isValidValue(rate);
		if (x_rate < 0)
			throw std::runtime_error("Error: Invalid exchange rate at data.csv");

		exchange_rates[date] = x_rate;
	}
	infile.close();
}

void BitcoinExchange::processInput(const char* input)
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
		std::string date, s_value;

		// passes the content of the line, up until the '|' character, to std::string date
		std::getline(ss, date, '|');
		// passes rest of the line to std::string s_value
		std::getline(ss, s_value);

		trim(date);
		trim(s_value);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = isValidValue(s_value);
		if (value < 0)
			continue;
		if (value > 1000.0)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		double rate = getRate(date);
		std::cout << date << " => " << value << " = " << rate * value << std::endl;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year	= atoi(date.substr(0, 4).c_str());
	int month	= atoi(date.substr(5, 7).c_str());
	int day		= atoi(date.substr(8, 10).c_str());

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[2] = 29;

	if (month < 1 || month > 12 || year < 1 || day < 1 || day > daysInMonth[month])
		return false;

	return true;
}

double BitcoinExchange::isValidValue(const std::string& s_value)
{
	std::stringstream ss(s_value);
	double value;

	ss >> value;

	// checks ss failed or if the errorstate flag is set
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: bad input => " << s_value << std::endl;
		return -1;
	}
	if (value < 0.0)
	{
		std::cerr << "Error: value not a positive number." << std::endl;
		return -2;
	}

	return value;
}

double BitcoinExchange::getRate(const std::string& date)
{
	std::map<std::string, double>::iterator it = exchange_rates.lower_bound(date);

	if (it != exchange_rates.end() && it->first == date)
		return it->second;
	if (it == exchange_rates.begin())
		return 0;
	--it;
	return it->second;
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
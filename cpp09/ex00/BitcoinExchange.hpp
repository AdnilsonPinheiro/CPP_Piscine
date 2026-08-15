#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

class BitcoinExchange
{
private:
	std::map<std::string, double>	exchange_rates;
	bool	isValidDate(const std::string& date);
	double	isValidValue(const std::string& s_value);
	double	getRate(const std::string& date);
	void	loadData(const char* filename);
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void processInput(const char* input);
};

#endif
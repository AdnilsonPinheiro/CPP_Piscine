#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float>	exchange_rates;
	bool isValidDate(const std::string& date);
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void processInput(const std::string& input);
};

#endif
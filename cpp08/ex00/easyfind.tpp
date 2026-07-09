#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <iostream>
# include <sstream>
# include <string>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
    {
        std::ostringstream oss;
        oss << value;
        std::string errorMsg = "ERROR: Value not found: " + oss.str();
        throw std::runtime_error(errorMsg);
    }
    return it;
}

#endif
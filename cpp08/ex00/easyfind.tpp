#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <typeinfo>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    if (typeid(typename T::value_type) == typeid(int))
    {
        typename T::const_iterator iter = std::find(container.begin(), container.end(), value);
        if (iter == container.end())
        {
            std::string errorMsg = "Container does not hold value " + std::to_string(value);
            throw std::runtime_error(errorMsg);
        }
        return (iter);
    }
    else
    {
        std::string errorMsg = "Error: Container is not of type <int>";
        throw std::runtime_error(errorMsg);
    }
}

#endif
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

# include "easyfind.tpp"
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 06:46:29 by aaycan            #+#    #+#             */
/*   Updated: 2026/11/01 06:46:29 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::runtime_error("easyfind: value not found"));
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int value)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::runtime_error("easyfind: value not found"));
	return (it);
}

#endif

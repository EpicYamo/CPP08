/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 07:01:36 by aaycan            #+#    #+#             */
/*   Updated: 2026/11/01 07:01:38 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _max(0) {}

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &other) : _max(other._max), _numbers(other._numbers) {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _max)
		throw (FullException());
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>			sorted(_numbers);
	std::vector<unsigned int>	values;
	std::vector<unsigned int>	gaps;

	if (_numbers.size() < 2)
		throw (NoSpanException());
	std::sort(sorted.begin(), sorted.end());
	values.assign(sorted.begin(), sorted.end());
	gaps.resize(values.size());
	std::adjacent_difference(values.begin(), values.end(), gaps.begin());
	return (*std::min_element(gaps.begin() + 1, gaps.end()));
}

unsigned int	Span::longestSpan(void) const
{
	unsigned int	smallest;
	unsigned int	largest;

	if (_numbers.size() < 2)
		throw (NoSpanException());
	smallest = static_cast<unsigned int>(*std::min_element(_numbers.begin(),
				_numbers.end()));
	largest = static_cast<unsigned int>(*std::max_element(_numbers.begin(),
				_numbers.end()));
	return (largest - smallest);
}

unsigned int	Span::size(void) const
{
	return (_numbers.size());
}

const char	*Span::FullException::what(void) const throw()
{
	return ("Span: no room left for another number");
}

const char	*Span::NoSpanException::what(void) const throw()
{
	return ("Span: at least two numbers are needed to find a span");
}

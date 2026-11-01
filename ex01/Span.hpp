/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 06:46:42 by aaycan            #+#    #+#             */
/*   Updated: 2026/11/01 06:46:46 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <exception>

class Span
{
	private:
		unsigned int		_max;
		std::vector<int>	_numbers;

	public:
		Span();
		explicit Span(unsigned int n);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		void			addNumber(int number);
		template <typename InputIterator>
		void			addNumbers(InputIterator begin, InputIterator end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		unsigned int	size(void) const;

		class FullException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

template <typename InputIterator>
void	Span::addNumbers(InputIterator begin, InputIterator end)
{
	if (static_cast<unsigned long>(std::distance(begin, end))
		> static_cast<unsigned long>(_max - _numbers.size()))
		throw (FullException());
	_numbers.insert(_numbers.end(), begin, end);
}

#endif

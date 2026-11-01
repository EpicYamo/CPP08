/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 06:46:36 by aaycan            #+#    #+#             */
/*   Updated: 2026/11/01 14:17:46 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iterator>
#include <string>

static void	subject_test(void);
static void	exception_tests(void);
static void	range_tests(void);
static void	copy_test(void);
static void	big_test(unsigned int amount);
static void	print_spans(const std::string &label, const Span &span);

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << "--- subject test ---" << std::endl;
	subject_test();
	std::cout << std::endl << "--- exceptions ---" << std::endl;
	exception_tests();
	std::cout << std::endl << "--- range insertion ---" << std::endl;
	range_tests();
	std::cout << std::endl << "--- big tests ---" << std::endl;
	big_test(10000);
	big_test(100000);
	return (0);
}

static void	subject_test(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	exception_tests(void)
{
	Span	empty(5);
	Span	one(5);
	Span	full(2);

	print_spans("empty span", empty);
	one.addNumber(42);
	print_spans("one number", one);
	full.addNumber(1);
	full.addNumber(2);
	try
	{
		full.addNumber(3);
		std::cout << "full span: no exception (wrong)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "full span: " << e.what() << std::endl;
	}
	full = Span(3);
	full.addNumber(INT_MIN);
	full.addNumber(INT_MAX);
	print_spans("INT_MIN and INT_MAX", full);
}

static void	range_tests(void)
{
	std::vector<int>			from_vector;
	std::list<int>				from_list;
	Span						span(8);
	std::list<int>::iterator	third;
	int							i;

	i = 0;
	while (i < 5)
	{
		from_vector.push_back(i * i);
		from_list.push_back(100 + i * 7);
		i++;
	}
	span.addNumbers(from_vector.begin(), from_vector.end());
	std::cout << "after vector {0, 1, 4, 9, 16}: size " << span.size()
		<< std::endl;
	try
	{
		span.addNumbers(from_list.begin(), from_list.end());
		std::cout << "list range: no exception (wrong)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "list range of 5 into 3 free slots: " << e.what()
			<< std::endl;
	}
	third = from_list.begin();
	std::advance(third, 3);
	span.addNumbers(from_list.begin(), third);
	print_spans("after 3 list values {100, 107, 114}", span);
	copy_test();
}

static void	copy_test(void)
{
	Span	original(3);
	Span	copy(original);
	Span	assigned;

	original.addNumber(10);
	original.addNumber(20);
	copy.addNumber(1);
	copy.addNumber(1000);
	assigned = original;
	assigned.addNumber(21);
	print_spans("original {10, 20}", original);
	print_spans("copy {1, 1000}", copy);
	print_spans("assigned {10, 20, 21}", assigned);
}

static void	big_test(unsigned int amount)
{
	std::vector<int>	numbers;
	Span				span(amount);
	unsigned int		i;

	i = 0;
	while (i < amount)
	{
		numbers.push_back(std::rand());
		i++;
	}
	span.addNumbers(numbers.begin(), numbers.end());
	std::cout << amount << " random numbers: ";
	print_spans("", span);
}

static void	print_spans(const std::string &label, const Span &span)
{
	std::cout << label;
	if (!label.empty())
		std::cout << ": ";
	try
	{
		unsigned int	shortest = span.shortestSpan();
		unsigned int	longest = span.longestSpan();

		std::cout << "shortest " << shortest << ", longest " << longest
			<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

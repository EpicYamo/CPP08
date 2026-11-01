/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:59:24 by aaycan            #+#    #+#             */
/*   Updated: 2026/11/01 14:59:25 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

static void	subject_test(void);
static void	list_test(void);
static void	iterator_tests(void);
static void	copy_test(void);
static void	vector_test(void);
template <typename T>
static void	print_all(const std::string &label, const T &container);

int	main(void)
{
	std::cout << "--- subject test (MutantStack) ---" << std::endl;
	subject_test();
	std::cout << std::endl << "--- same test with std::list ---" << std::endl;
	list_test();
	std::cout << std::endl << "--- iterators ---" << std::endl;
	iterator_tests();
	std::cout << std::endl << "--- copies ---" << std::endl;
	copy_test();
	std::cout << std::endl << "--- std::vector as underlying container ---"
		<< std::endl;
	vector_test();
	return (0);
}

static void	subject_test(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
	std::cout << "std::stack copy: size " << s.size() << ", top " << s.top()
		<< std::endl;
}

static void	list_test(void)
{
	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator	it = lst.begin();
	std::list<int>::iterator	ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	iterator_tests(void)
{
	MutantStack<int>					mstack;
	MutantStack<int>::iterator			found;
	MutantStack<int>::reverse_iterator	rit;
	int									i;

	i = 1;
	while (i <= 5)
	{
		mstack.push(i * 10);
		i++;
	}
	print_all("bottom to top", mstack);
	std::cout << "top to bottom (reverse):";
	rit = mstack.rbegin();
	while (rit != mstack.rend())
	{
		std::cout << " " << *rit;
		++rit;
	}
	std::cout << std::endl;
	found = std::find(mstack.begin(), mstack.end(), 30);
	if (found != mstack.end())
		*found = 333;
	print_all("after std::find(30) and write 333", mstack);
	std::cout << "top is still " << mstack.top() << std::endl;
	const MutantStack<int>	&ref = mstack;
	print_all("through const reference", ref);
}

static void	copy_test(void)
{
	MutantStack<int>	original;
	MutantStack<int>	assigned;

	original.push(1);
	original.push(2);
	original.push(3);
	MutantStack<int>	copy(original);
	assigned = original;
	copy.push(4);
	assigned.pop();
	print_all("original", original);
	print_all("copy + push(4)", copy);
	print_all("assigned + pop()", assigned);
}

static void	vector_test(void)
{
	MutantStack<std::string, std::vector<std::string> >	words;

	words.push("first");
	words.push("second");
	words.push("third");
	print_all("words", words);
	std::cout << "top: " << words.top() << ", size: " << words.size()
		<< std::endl;
	words.pop();
	print_all("after pop", words);
}

template <typename T>
static void	print_all(const std::string &label, const T &container)
{
	typename T::const_iterator	it;

	std::cout << label << ":";
	it = container.begin();
	while (it != container.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

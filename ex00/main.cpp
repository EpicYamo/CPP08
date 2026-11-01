#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

template <typename T>
static void	test_find(const std::string &label, const T &container, int value);

int	main(void)
{
	std::vector<int>		numbers;
	std::list<int>			linked;
	std::deque<int>			queue;
	const std::vector<int>	const_numbers(3, 7);
	int						i;

	i = 0;
	while (i < 10)
	{
		numbers.push_back(i * 10);
		linked.push_back(i * 3);
		queue.push_front(i);
		i++;
	}
	std::cout << "--- std::vector {0, 10, ..., 90} ---" << std::endl;
	test_find("find 40", numbers, 40);
	test_find("find 0", numbers, 0);
	test_find("find 99", numbers, 99);
	std::cout << std::endl << "--- std::list {0, 3, ..., 27} ---" << std::endl;
	test_find("find 27", linked, 27);
	test_find("find 5", linked, 5);
	std::cout << std::endl << "--- std::deque {9, 8, ..., 0} ---" << std::endl;
	test_find("find 9", queue, 9);
	test_find("find -1", queue, -1);
	std::cout << std::endl << "--- const std::vector {7, 7, 7} ---"
		<< std::endl;
	test_find("find 7", const_numbers, 7);
	test_find("find 8", const_numbers, 8);
	std::cout << std::endl << "--- modify through returned iterator ---"
		<< std::endl;
	*easyfind(numbers, 40) = 4242;
	test_find("find 4242", numbers, 4242);
	return (0);
}

template <typename T>
static void	test_find(const std::string &label, const T &container, int value)
{
	std::cout << label << ": ";
	try
	{
		typename T::const_iterator	it = easyfind(container, value);

		std::cout << "found " << *it << " at index "
			<< std::distance(container.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

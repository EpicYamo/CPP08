# CPP Module 08

Templated containers, iterators and algorithms: a generic search over STL containers, a span calculator built on `std::vector`, and an iterable `std::stack`.

> Part of the **42 school curriculum**. Built by **Arda Aycan**.

## Exercises

| Exercise | Binary | What it demonstrates |
| --- | --- | --- |
| `ex00` | `easyfind` | `easyfind` finds the first occurrence of an int in any sequence container with `std::find`, returns an iterator to it (a `const_iterator` for const containers) and throws an exception when the value is missing. |
| `ex01` | `span` | `Span` stores up to N ints, accepts them one by one or as a whole iterator range, and computes the shortest and longest span with `std::sort`, `std::adjacent_difference` and `std::min_element`/`std::max_element`; it is tested with 100,000 numbers. |
| `ex02` | `mutantstack` | `MutantStack` inherits `std::stack` and exposes the iterators of its protected underlying container, so the stack can be traversed forwards, backwards and with STL algorithms while still converting to a plain `std::stack`. |

## Build and run

Every exercise has its own Makefile and produces its own binary:

```bash
make -C ex02
./ex02/mutantstack
```

`make fclean -C <exercise>` removes the binary again.

## Notes

- C++98, `-Wall -Wextra -Werror`.
- Object files depend on the exercise headers, so changing a header-only template triggers a rebuild.
- `easyfind` is meant for sequence containers; associative containers have their own `find` member and store keys or key/value pairs instead of plain ints.
- `Span` returns spans as `unsigned int`, so the span between `INT_MIN` and `INT_MAX` (4294967295) fits without overflow.
- `MutantStack` keeps the declaration in `MutantStack.hpp` and the member definitions in `MutantStack.tpp`; its output matches the same test run on `std::list`.

## Author

**Arda Aycan** ([@EpicYamo](https://github.com/EpicYamo)).

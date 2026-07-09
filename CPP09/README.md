<i>This project has been created as part of the 42 curriculum by hlichten.</i>

<h1 align="center">
  CPP09
</h1>

<p align="center">
  <i>C++ Module CPP09 – 42 Common Core</i><br>
  <strong>Developed in C++ by <a href="https://github.com/Hyliah">@Hyliah</a></strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />
  <img src="https://img.shields.io/badge/Standard-C++98-blueviolet.svg" />
  <img src="https://img.shields.io/badge/Status-In Progress-violet" />
  <img src="https://img.shields.io/badge/School-42%20Lausanne-pink.svg" />
</p>

---

<h2>♦ Description ♦</h2>

CPP09 is the ninth C++ module of the 42 Common Core.

The goal of this project is to practice advanced use of the **STL containers**, improve data processing skills, and understand how to choose the correct data structure depending on the problem.

This module focuses on:

- Manipulating associative containers
- Parsing and validating input data
- Handling large amounts of data efficiently
- Applying algorithms with complexity constraints
- Understanding the differences between container behaviors

The project is divided into three independent exercises, each introducing a different algorithmic challenge.

---

<h2>♦ Project Overview ♦</h2>

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | BitcoinExchange | A program that reads historical Bitcoin prices and calculates exchange values from user input |
| ex01 | RPN | A Reverse Polish Notation calculator using a stack-based evaluation system |
| ex02 | PmergeMe | A sorting program implementing the Ford-Johnson merge-insertion algorithm |

---

<h2>♦ Exercise Details ♦</h2>

<h3>BitcoinExchange</h3>

This exercise introduces associative containers and file parsing.

Features:

- Reading Bitcoin price history from a CSV database
- Validating dates and values
- Searching the closest previous available date
- Using `std::map` for efficient lookup

Main concepts:

- File streams
- String parsing
- Exception handling
- Associative containers

---

<h3>RPN</h3>

This exercise implements a calculator using **Reverse Polish Notation**.

Example:
 8 9 + 2 * 7 /

The program evaluates expressions using a stack.

Main concepts:

- Stack manipulation
- Parsing expressions
- Operator handling
- Error management

---

<h3>PmergeMe</h3>

This exercise focuses on algorithmic optimization.

The goal is to sort a sequence of positive integers using the **Ford-Johnson merge-insertion algorithm**.

The program compares performances using:

- `std::vector`
- `std::list`

Main concepts:

- Algorithm complexity
- Recursive algorithms
- Container performance comparison
- Time measurement

---

<h2>♦ Technical Concepts ♦</h2>

This module covers:

- STL containers:
  - `map`
  - `stack`
  - `vector`
  - `deque`

- Iterators

- Algorithms and complexity analysis

- Parsing techniques

- Exception handling

- Canonical form:
  - Default constructor
  - Copy constructor
  - Assignment operator
  - Destructor

- Performance optimization

---

<h2>♦ Instructions ♦</h2>

### Compilation

Each exercise contains its own Makefile.

Compilation flags:

```bash
-Wall -Wextra -Werror -std=c++98
```

compile the project:
```bash
make
make re
make fclean
```

<h2>♦ Resources ♦</h2>

Useful documentation:

C++ Reference
https://en.cppreference.com/
C++ STL Documentation
https://cplusplus.com/reference/stl/
Art Of Computer Programming, Vol.3. Merge Insertion, Page 184
https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf

Peer learning is a major part of the 42 experience. Additional learning sources include:
42 Intra videos and exercises
Official C++ documentation (STL containers and algorithms)
Discussions with peers and tutors

<h3>AI Usage</h3>

They were used for:

Clarifying C++ concepts
Understanding STL behavior
Reviewing algorithms
Debugging small implementation issues
Improving documentation

<h2>♦ Personal Notes ♦</h2>

CPP - Homemade HelpCenter:

<a href="https://www.figma.com/board/YLwrD2ZJmG2QEYdvLQ85o0/CPP_help-center?node-id=0-1&t=rvW7b2dDy1z6ygfJ-1"> CPP HelpCenter </a>
<h2>♦ Author ♦</h2>

hlichten
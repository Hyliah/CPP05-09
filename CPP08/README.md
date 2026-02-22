<!-- README.md -->
<p>This project has been created as part of the 42 curriculum by hlichten.</p>

<h1 align="center">
  CPP08
</h1>

<p align="center">
  <i>C++ module CPP08 – 42 Common Core</i><br>
  <strong>Developed in C++ by <a href="https://github.com/Hyliah">@Hyliah</a></strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />
  <img src="https://img.shields.io/badge/Standard-C++98-blueviolet.svg" />
  <img src="https://img.shields.io/badge/Status-In Progress-violet" />
  <img src="https://img.shields.io/badge/School-42 Lausanne-pink.svg" />
</p>

---

<h2>♦ Objective / Description ♦</h2>

This module focuses on **C++ containers and algorithms**, including:

- Iterating through containers  
- Working with **STL containers** (`vector`, `list`, `deque`, `stack`)  
- Creating **custom container-like classes** (`Span`, `MutantStack`)  
- Applying **algorithmic thinking** with standard and custom structures  
- Handling exceptions and boundary cases  

The goal is to **practice STL concepts**, develop **iterable classes**, and manage **exceptions safely**.

---

<h2>♦ Concepts Covered ♦</h2>

- Standard Template Library (STL) containers: `vector`, `deque`, `list`, `stack`  
- Iterators and const_iterators  
- Exception handling for containers  
- Writing **generic functions** (`easyfind`)  
- Creating **custom iterable containers** (`MutantStack`)  
- Algorithmic complexity (O(n), O(n log n))  
- Deep copy, canonical form, and safe memory handling  

---

<h2>♦ Exercises ♦</h2>

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Easyfind | Implement a function template `easyfind` to search for an integer in any container; handle exceptions if not found |
| ex01 | Span | Implement a `Span` class that stores integers and can return the shortest and longest span; handle overflows and exceptions |
| ex02 | MutantStack | Implement a `MutantStack` class inheriting from `std::stack` that is **iterable** using standard iterators; mimic STL container behavior |

---

<h2>♦ Compilation & Execution ♦</h2>

All projects are compiled using a Makefile with flags:  
`-Wall -Wextra -Werror -std=c++98`

Example usage:

```bash
make
./easyfind
./span
./mutantstack
```

<h2>♦ Personal Notes ♦</h2> 

CPP - Homemade HelpCenter :
<a href="https://www.figma.com/board/YLwrD2ZJmG2QEYdvLQ85o0/CPP_help-center?node-id=0-1&t=rvW7b2dDy1z6ygfJ-1">CPP HelpCenter</a>


<h2>♦ Resources ♦</h2>

Peer learning is a major part of the 42 experience. Additional learning sources include:
42 Intra videos and exercises
Official C++ documentation (STL containers and algorithms)
Discussions with peers and tutors
AI tools were used only to clarify concepts and debug small issues, not to write the project code.

<h2>♦ Author ♦</h2>
hlichten

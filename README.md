<!-- README.md -->
<h1 align="center">
  CPP Modules – 42
</h1>

<p align="center">
  <i>C++ learning modules from CPP04 to CPP09, part of the 42 Common Core.</i><br>
  <strong>Developed in C++ by <a href="https://github.com/Hyliah">@Hyliah</a></strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />
  <img src="https://img.shields.io/badge/Standard-C++98-blueviolet.svg" />
  <img src="https://img.shields.io/badge/Status-In Progress-violet" />
  <img src="https://img.shields.io/badge/School-42 Lausanne-pink.svg" />
</p>

---

<h2 align="center">♦ Overview ♦</h2>

This repository contains my implementation of the **CPP05 to CPP09 modules** from the 42 C++ piscine.  
The goal of these projects is to progressively discover **object-oriented programming in C++**, while respecting strict constraints such as the **C++98 standard**, memory safety, and clean architecture.

Each module introduces new concepts and builds upon the previous ones.

---

<h2> ♦ Modules ♦</h2>

| Module | Main Concepts | Status |
|------|---------------|--------|
| CPP05 | Exceptions, abstract classes, inheritance, polymorphism | Waiting for evaluation |
| CPP06 | Type casting, reinterpret/static/dynamic cast, serialization | WIP |
| CPP07 | Templates, generic programming | ... |
| CPP08 | STL containers, iterators, algorithms | ... |
| CPP09 | Advanced STL, containers adaptors, algorithms, real use cases | ... |

---

<h2> ♦ Project Structure ♦</h2>

```
CPP05/
├── ex00/ # Bureaucrat : Bureaucrat class, exceptions & grade handling
├── ex01/ # FormUp : Form class, interaction with Bureaucrat
├── ex02/ # Form28B : Abstract forms & concrete implementations
├── ex03/ # CoffeeMaking : Function pointers
│
CPP06/
├── ex00/ # convert : Scalar type conversion
├── ex01/ # Serialization (uintptr_t)
├── ex02/ # Runtime type identification
│
CPP07/
├── ex00/ # Template functions
├── ex01/ # Iter template
├── ex02/ # Template array class
│
CPP08/
├── ex00/ # Easy find (STL algorithm)
├── ex01/ # Span (range and distance)
├── ex02/ # MutantStack (iterator on stack)
│
CPP09/
├── ex00/ # Bitcoin exchange (map & parsing)
├── ex01/ # Reverse Polish Notation
├── ex02/ # Merge-insert sort (Ford-Johnson)


```

Each folder contains:
- Source files (`.cpp`, `.hpp`)
- A module-specific `README.md`
- Exercises following the 42 subject guidelines

---

<h2> ♦ Compilation & Execution ♦</h2>

All projects are compiled using a Makefile compling with flags :
 -Wall -Wextra -Werror -std=c++98

All compilator gives tailored informations
exemple : 

```bash
make
./Bureaucrat  ready to use. 
./Bureaucrat
```

<h2> ♦ Coding Standards ♦</h2>

- C++98 compliant
- No memory leaks (checked with Valgrind)
- Clear separation between headers and sources
- Respect of the 42 Norm and subject constraints

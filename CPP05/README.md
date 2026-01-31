<!-- README.md -->
<p><i>This project has been created as part of the 42 curriculum by hlichten. </i></p>

<h1 align="center">
  CPP05
</h1>

<p align="center">
  <i>C++ module CPP05 – 42 Common Core</i><br>
  <strong>Developed in C++ by <a href="https://github.com/Hyliah">@Hyliah</a></strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />
  <img src="https://img.shields.io/badge/Standard-C++98-blueviolet.svg" />
  <img src="https://img.shields.io/badge/Status-In Progress-violet" />
  <img src="https://img.shields.io/badge/School-42 Lausanne-pink.svg" />
</p>

---

<h2>♦ Objective / Description♦</h2>

The goal of this module is to introduce and practice **exception handling** and reinforce knowledge of **inheritance, abstract classes, and operator (`<<`) overloading**.  
The idea is to implement a bureaucracy simulation with **forms, bureaucrats, and interns**.

---

<h2>♦ Concepts Covered ♦</h2>

- Exception handling (`try/catch`)
- Dynamic allocation (`new` / `delete`)
- Operator overloading (`operator<<`)
- Function pointers and simple factory pattern
- Classes, inheritance, and abstract classes

---

<h2>♦ Exercises ♦</h2>

| Exercise | Name | Description |
|--------|-------------|----------|
| ex00 | Mommy, when I grow up, I want to be a bureaucrat! | Introduction to `try/catch` and exception handling |
| ex01 | Form up, maggots! | Creation of complex class hierarchy to manage forms |
| ex02 | No, you need form 28B, not 28C... | implement abstract `AForm` and concrete forms, with signing and execution logic |
| ex03 | At least this beats coffee-making | CImplementation of Intern using function pointer table to dynamically create forms |

---

<h2> ♦ Compilation & Execution ♦</h2>

All projects are compiled using a Makefile compling with flags :
 -Wall -Wextra -Werror -std=c++98

All compilator gives tailored informations
exemple : 

```bash
make
./FormUp  ready to use.
./FormUp
```

---

<h2>♦ Personal Notes ♦</h2>

Exception classes are used to signal, propagate, and explain errors in C++.
They work with try, catch, and throw.
An exception thrown during a constructor aborts the object creation.
An exception thrown inside a member function does not undo previous changes.
Therefore, checks must always be done before modifying the object state.

<p>[Exception Classes]</p>
<img src="ASSETS/exception_classes.png" width="90%" alt="ex03 : Exception classes">

CPP - Homemade HelpCenter : 
<a href="https://www.figma.com/board/YLwrD2ZJmG2QEYdvLQ85o0/CPP_help-center?node-id=0-1&t=rvW7b2dDy1z6ygfJ-1">CPP HelpCenter</a>



---

<h2>♦ Ressorces ♦</h2>
Peer learning is a major part of the 42 experience.
Additional learning sources included:

- 42 Intra videos
- Official C++ documentation
- Discussions with peers

AI tools were used only to answer conceptual questions and help with debugging typos or logic issues,
not to generate the project code.

---

<h2>♦ Author ♦</h2>

42 login: hlichten

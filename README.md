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
|------|---------------|----------|
| CPP05 | ... | WIP |
| CPP06 | ... | ... |
| CPP07 | ... | ... |
| CPP08 | ... | ... |
| CPP09 | ... | ... |

---

<h2> ♦ Project Structure ♦</h2>

```
CPP00-04/
├── CPP05/              
│  ├── ex00/            # 
│  ├── ex01/            # 
│  ├── ex02/            # 
│
├── CPP06/              
│  ├── ex00/            # 
│  ├── ex01/            # 
│  ├── ex02/            # 
│  ├── ex03/            # 
│  ├── ex04/            # 
│  ├── ex05/            # 
│  ├── ex06/            # 
│
├── CPP07/              
│  ├── ex00/            # 
│  ├── ex01/            # 
│  ├── ex02/            # 
│  ├── ex03/            # 
│
├── CPP08/              
│  ├── ex00/            # 
│  ├── ex01/            # 
│  ├── ex02/            # 
│  ├── ex03/            # 
│
├── CPP09/              
│  ├── ex00/            # 
│  ├── ex01/            # 
│  ├── ex02/            # 
│  ├── ex03/            # 


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
./SedIsForLosers  ready to use. Enter a file and two occurences (S1 & S2)
./SedIsForLosers  file.txt "this" "that"
```



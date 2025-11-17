# Time of Sorting - C/C++ Procedural Programming Project

This repository contains a C/C++ project that measures the execution time of different sorting algorithms on integer arrays. The project demonstrates procedural programming techniques, memory management, and performance measurement in C/C++.

## Features

- Implements **7 sorting algorithms**:
  - Insertion Sort
  - Selection Sort
  - Bubble Sort
  - Mix Sort
  - Half Sort (binary insertion variant)
  - Heap Sort
  - Quick Sort
- Measures execution time for each sorting algorithm using `clock()` from `<time.h>`.
- Works with dynamically allocated arrays and demonstrates proper memory management.
- Modular design with separate files for sorting functions (`sorting.h` / `sortfortime.cpp`) and main program logic (`timeofsorting.cpp`).

## Project Structure

/timeofsorting  
│  
├── sorting.h # Header file with function declarations  
├── sortfortime.cpp # Implementation of sorting algorithms  
├── timeofsorting.cpp # Main program measuring sorting times  
├── timeofsorting.sln # Visual Studio solution file  
├── timeofsorting.vcxproj  
├── timeofsorting.vcxproj.filters  
└── README.md  

> **Note:** Generated build files, object files, and executables are excluded from the repository to keep it clean and professional.

## Usage

1. **Clone the repository:**

```bash
git clone https://github.com/AndKac600224/timeofsorting.git
cd timeofsorting
```
2. Build the project using Visual Studio or a C++ compiler of your choice.
3. Go to project and click *alt+f7* buttons, click *debugging* and set arguments to chosen number of integers (e.g. 50000). Then click *OK* and run the program.
    This will create a random array of 50000 (for instance - depends on your choice) integers and display the execution time for each sorting algorithm in a few seconds.

## Example Output
Sortowanie za pomoca InsertSort zajmie:
0.002345 seconds

Sortowanie za pomoca SelectionSort zajmie:
0.003210 seconds

## Learning Outcomes
* Solid understanding of procedural programming in C/C++.
* Practical experience with dynamic memory allocation and array manipulation.
* Familiarity with algorithm efficiency and performance measurement.
* Clean modular code with separation of declarations and implementations.


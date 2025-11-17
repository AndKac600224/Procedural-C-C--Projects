# Half-Insertion Sort in C/C++

This repository contains a C/C++ project demonstrating **Half-Insertion Sort**, a variant of the classical insertion sort algorithm that uses **binary search** to find the correct insertion position.  

It is written in a procedural style, suitable for learning sorting algorithms, dynamic memory handling, and basic C/C++ programming concepts.

## Project Overview

**Half-Insertion Sort** improves upon regular insertion sort by using a **binary search** to determine where to insert the next element instead of scanning linearly. This reduces the number of comparisons, while still moving elements to make room for insertion.

### Key Features

- Efficient insertion of elements using binary search.  
- Works on integer arrays of any size.  
- Demonstrates procedural programming and array manipulation in C/C++.  

## Files Structure

/HalfInsertionSort  
│  
├── HalfInsertion.cpp # Main program with half-insertion sort implementation  
└── README.md  

## Usage

Compile and run the program using any C/C++ compiler.
You can change the hardcoded array made for sorting by changing values of tab[] in *main()*

## How It Works?

The algorithm iterates through each element of the array starting from index 1.
* For each element, it uses binary search to find the correct position in the already sorted left part of the array.
* It shifts all larger elements one position to the right.
* Inserts the current element into its correct position.

### Time Complexity:
* Worst-case: O(n²) (due to shifting elements)
* Comparisons: O(n log n) (binary search)

## Learning Outcomes
* Understand binary search applied inside insertion sort.
* Practice array manipulation and element shifting.
* Learn to implement sorting algorithms in C/C++ in a procedural style.

# Mixed Sort in C/C++

This project is demonstrating **Mixed Sort**. 
It is a variation of the classic Bubble Sort that sorts the array in **both directions**—from left to right and right to left—making it slightly more efficient than standard Bubble Sort.

## Project Overview

**Mixed Sort** works by:

1. Moving the **largest numbers to the end** of the array (rightward pass).  
2. Moving the **smallest numbers to the beginning** of the array (leftward pass).  
3. Repeating these two passes until the array is completely sorted.

## Files Structure

/MixedSort  
│  
├── MixedSort.cpp # Main program with mixed sort implementation  
└── README.md  

## Usage

**Compile and run the program** using a C/C++ compiler
An array used for sorting is hardcoded, but change be easily changed in *main() by setting values for *tab[]**

## How It Works?
1. Start with the full array.
2. Perform a right-to-left pass:
  * Compare each element with its left neighbor.
  * Swap if the current element is smaller.
  * This moves the smallest numbers to the left.

3. Perform a left-to-right pass:
  * Compare each element with its left neighbor.
  * Swap if the current element is smaller.
  * This moves the largest numbers to the right.

4. Repeat until no swaps are needed.

### Time Complexity:
* Worst-case: O(n²)
* Best-case (almost sorted array): O(n)

## Learning Outcomes
* Understanding "both-directions" Bubble Sort logic.
* Practicing array manipulation and swapping in C/C++.


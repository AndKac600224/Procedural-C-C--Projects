# Knight's Tour - Backtracking Algorithm in C/C++

This repository contains a C/C++ project that solves the **Knight's Tour problem** using a backtracking algorithm. The program demonstrates procedural programming, dynamic memory management, and recursive problem solving.

## Project Overview

The Knight's Tour is a classic chess problem where a knight must visit every square on an `n x n` chessboard exactly once. This project:

- Implements a **backtracking algorithm** to find a valid tour.
- Supports chessboards of different sizes (configurable in the project).
- Tracks all moves, including attempted and valid ones.
- Demonstrates modular programming with separate files for logic (`ChessHorsem.cpp`) and headers (`ChessHorse.h`).

## Files Structure
/ChessHorse  
│  
├── ChessHorse.h # Header file with definitions and function prototypes  
├── ChessHorsem.cpp # Implementation of board creation, move validation, and backtracking  
├── chesshores-test.cpp # Main program executing the Knight's Tour  
└── README.md # this file  

## Features

- Recursive **backtracking algorithm** for exploring all possible knight moves.
- Supports **configurable board size** (via `CHESSBOARD_SIZE` macro in `ChessHorse.h`) - more than 6 needs more time to compile and may not be completed - depends on yours CPU.
- Proper **memory allocation and deallocation** for the chessboard.
- Displays the resulting chessboard with move numbers after a successful tour.
- Counts all moves attempted during the algorithm, including invalid backtracks.

## Usage

1. **Set the chessboard size** in `ChessHorse.h` (e.g., `#define CHESSBOARD_SIZE 5`).

2. **Build the project** using Visual Studio or a C++ compiler of your choice.

3. **Go to `Project -> Properties -> Debugging -> Command Arguments` and set the starting position of knight (note that indexing in C starts from 0 and it cannot exclude chessboard dimensions) e.g. `2 3`**

4. **Run the program**


## Example Output
0   17  2   19  4  
3   6   15  8   21
...
All moves: 1728

## Learning Outcomes
* Understanding of backtracking algorithms and recursion.
* Experience with dynamic memory allocation and 2D arrays in C/C++.
* Familiarity with debugging and tracking algorithmic execution.
* Modular code structure with clear separation of header files and implementation.

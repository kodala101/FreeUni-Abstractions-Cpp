# Abstractions-Cpp

A collection of Programming Abstractions C++ course assignments as part of the Computer Science curriculum at the Free University of Tbilisi (adapted from Stanford CS106B framework).

Note: starter code structures were provided by the university course staff. Core logic, game loops, dynamic data structures, and feature implementations were authored by me.

## Technologies & Tools

* **Language:** C++11
* **Libraries:** Stanford C++ Libraries (`Vector`, `Grid`, `Queue`, `Map`, `Set`, `Lexicon`, `PriorityQueue`, `GWindow`, `ibstream`, `obstream`, `TokenScanner`)
* **Core Concepts:** Abstract Data Types (ADTs), Functional & Memory Recursion, Backtracking, Graph Algorithms, Binary Trees, Bit Manipulation, Computational Complexity

---

## Assignment 1: Welcome to C++!

* **Part 1: Warmup** – Environment setup, debugging basic syntax errors, and generating a hash code.
* **Problem 1: Coin Flip Simulation** – Simulates coin tosses until three consecutive heads occur.
* **Problem 2: Pascal's Triangle** – Calculates combinations $c(n, k)$ recursively without loops or multiplication.
* **Problem 3: Numeric Conversions** – Implements recursive `stringToInt` and `intToString` functions without standard libraries or loops.
* **Problem 4: Flesch-Kincaid Readability** – Reads a text file using `TokenScanner` to calculate its grade-level readability score based on word, sentence, and syllable counts.

## Assignment 2: Fun with Collections

* **Problem 1: Word Ladders** – Finds the shortest word sequence between two words using a Breadth-First Search (BFS) algorithm with `Vector`, `Queue`, and `Lexicon` ADTs[cite: 1, 3].
* **Problem 2: Random Writer** – Builds an order-$k$ Markov model from an input text using a `Map<string, Vector<char>>` to generate 2000 characters of pseudo-random text[cite: 5, 6, 7].

## Assignment 3: Recursion!

* **Warm-up 0A: Karel Goes Home** – Solves pathfinding recursively to count valid shortest paths to the origin.
* **Warm-up 0B: Random Subsets** – Generates a random subset from a master set using recursion instead of loops.
* **Problem 1: Subsequences** – Recursively determines whether one string is a subsequence of another without using loops.
* **Problem 2: The Sierpinski Triangle** – Draws an order-$N$ fractal Sierpinski Triangle using `GWindow` and polar line operations.
* **Problem 3: Inverse Genetics** – Recursively finds and outputs all possible RNA strands that translate to a given protein sequence using a `Map<char, Set<string>>` codon map.
* **Problem 4: Universal Health Coverage** – Uses recursive backtracking to determine if a subset of hospital locations can fully cover a given set of cities within a set limit.

## Assignment 5: Boggle!

* **Human Player Search** – Implements recursive backtracking to validate player-entered words against a 2D letter grid, enforcing adjacency and single-use rules[cite: 1, 3, 4].
* **Computer Player Search** – Exhaustively searches the entire Boggle board using recursive backtracking and `Lexicon` prefix pruning (`containsPrefix`) to find all remaining valid words[cite: 1, 3, 4].

## Assignment 6: Huffman Encoding

* **Bit Streams & Types** – Utilizes `ibstream`/`obstream` for custom bit-level file I/O and defines custom `Node` structures handling regular characters and `PSEUDO_EOF`[cite: 1, 2, 3].
* **Frequency & Tree Construction** – Generates character frequency maps and builds optimized Huffman encoding trees using a priority queue (`pqueue.h`)[cite: 3].
* **Encoding & Decoding** – Converts file contents bit-by-bit using tree traversals for compression and decompression routines (`encodeFile`, `decodeFile`)[cite: 4].
* **Full File Compression** – Assembles complete file compression pipelines (`compress`, `decompress`) by combining tree operations with custom header management for table metadata[cite: 4].

## Assignment 7: Trailblazer

* **Step 1: Dijkstra's Algorithm** – Implements Dijkstra's algorithm using `TrailblazerPQueue` to find the shortest path across 2D grid terrains based on move and elevation costs[cite: 2, 3, 4].
* **Step 2: A* Search** – Extends the shortest-path algorithm to A* search using an admissible heuristic to optimize pathfinding speed[cite: 5, 6].
* **Step 3: Kruskal's Algorithm** – Uses Kruskal's algorithm on a grid graph to build minimum spanning trees that generate randomized 2D mazes[cite: 7, 8].

## Assignment 8: LeetCode Solutions

* Solve 10 Problems from Leetcode

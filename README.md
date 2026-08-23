# Freeuni Abstractions Cpp & Projects



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





with the structure and style of this text? keep everything else same:# FreeUni Java Basics & Projects



A collection of foundational Java assignments, interactive GUI applications, and algorithms completed as part of the Computer Science curriculum at the Free University of Tbilisi (adapted from Stanford CS106A framework).



> **Note:** starter code structures and graphical framework templates were provided by the university course staff. Core logic, game loops, dynamic data structures, and feature implementations were authored by me.



---



## 📁 Repository Structure



### 1. `Assignment1-Karel/`

* Basic algorithmic problem-solving, control flow, and spatial logic using Karel the Robot.

* Solutions for classic Karel challenges.



### 2. `Assignment2-SimpleJava/`

* **ACM Graphics:** Coordinate geometry, visual rendering, and custom layout drawing (`Pyramid`, `Target`, `HierarchyDiagram`).

* **Console Applications:** Mathematical algorithms, input validation, and control flow (`PythagoreanTheorem`, `FindMinMax`, `HailstoneSequence`).



### 3. `Assignment3-Breakout/`

* A complete implementation of the classic arcade game **Breakout**.

* **Key Features:** Real-time animation, collision detection algorithms, score tracking, dynamic paddle movement, and game-over state handling using the `acm.graphics` library.



### 4. `Assignment4-Hangman/`

* An interactive word-guessing game with both text-based and visual UI components.

* **Key Features:** String manipulation, random word selection, file I/O for reading dictionary files, dynamic canvas redrawing (`HangmanCanvas`), and remaining guess tracking.



### 5. `Assignment5-Yahtzee/`

* A multi-player implementation of the classic dice rolling game **Yahtzee**.

* **Key Features:** Array manipulation, score tracking categories, complex rule validation algorithms (Straights, Full House, Yahtzee), and user interaction flow.



### 6. `Assignment6-NameSurfer/`

* A visual database application to graph the popularity trends of US baby names over decades.

* **Key Features:** Parsing structured data files (`names-data.txt`), hash maps (`HashMap`), custom graphical plotting (`NameSurferGraph`), dynamic window resizing, and search GUI components.



### 7. `Assignment7-FacePamphlet/`

* A full-featured mini social network desktop application.

* **Key Features:** Custom object-oriented design (`FacePamphletProfile`), relational graph-like connections (friend networks), status updates, dynamic image loading, and inter-component GUI communication.



---



## 🛠️ Technologies & Tools

* **Language:** Java

* **Libraries:** Stanford ACM Java Framework (`acm.graphics`, `acm.program`, `acm.gui`)

* **Concepts:** Object-Oriented Programming (OOP), Data Structures (Lists, Maps), File I/O, Event-Driven Programming, GUI Design.

Abstractions-Cpp
A collection of Programming Abstractions C++ course assignments as part of the Computer Science curriculum at the Free University of Tbilisi (adapted from Stanford CS106B framework).

Note: starter code structures were provided by the university course staff. Core logic, game loops, dynamic data structures, and feature implementations were authored by me.

📁 Repository Structure
1. Assignment1-WelcomeToCpp/
Warmup exercises covering environment setup, basic syntax debugging, hash code generation, and a consecutive coin flip simulation.

Key Features: Calculating combinations c(n,k) recursively without loops or multiplication, recursive numeric conversions (stringToInt and intToString), and calculating Flesch-Kincaid Readability scores using file reading and TokenScanner.

2. Assignment2-FunWithCollections/
Practical applications utilizing core Abstract Data Types (ADTs) to solve complex problems.

Key Features: Finding the shortest path in Word Ladders using Breadth-First Search (BFS) with Vector, Queue, and Lexicon ADTs, and generating 2000 characters of pseudo-random text by building an order-k Markov model via a Map<string, Vector<char>>.

3. Assignment3-Recursion/
A comprehensive suite of problems utilizing functional recursion, memory recursion, and recursive backtracking.

Key Features: Recursive pathfinding (Karel Goes Home), loop-less subset generation and string subsequence checking, drawing order-N Sierpinski Triangles using GWindow, mapping inverse genetics via Map<char, Set<string>>, and solving the Universal Health Coverage problem.

5. Assignment5-Boggle/
A programmatic solver and validator for the Boggle word search game.

Key Features: Recursive backtracking to validate human player entries on a 2D letter grid with adjacency constraints, and exhaustive board searching for the computer player using Lexicon prefix pruning (containsPrefix).

6. Assignment6-HuffmanEncoding/
A complete file compression and decompression utility leveraging Huffman coding trees.

Key Features: Bit-level file I/O operations (ibstream/obstream), character frequency map generation, optimized tree construction via priority queues (pqueue.h), and custom header management for table metadata.

7. Assignment7-Trailblazer/
Implementations of foundational graph algorithms applied to 2D grid terrains and mazes.

Key Features: Shortest-path finding based on move and elevation costs using Dijkstra's algorithm and A* search (with an admissible heuristic), and generating randomized mazes by building minimum spanning trees with Kruskal's algorithm.

8. Assignment8-LeetCode/
General algorithmic problem-solving and optimization practice.

Key Features: Solutions for 10 problems from the LeetCode platform.

🛠️ Technologies & Tools
Language: C++11

Libraries: Stanford C++ Libraries (Vector, Grid, Queue, Map, Set, Lexicon, PriorityQueue, GWindow, ibstream, obstream, TokenScanner)

Concepts: Abstract Data Types (ADTs), Functional & Memory Recursion, Backtracking, Graph Algorithms, Binary Trees, Bit Manipulation, Computational Complexity

please give me it as a file to copy

Your Markdown file is ready

MD icon
Abstractions-Cpp-README
 MD 
Open
You can download the file using the link above to easily copy its contents. Let me know if you need any other adjustments!





Gemini is AI and can make mistakes.

Analyzing
# Abstractions-Cpp

A collection of Programming Abstractions C++ course assignments as part of the Computer Science curriculum at the Free University of Tbilisi (adapted from Stanford CS106B framework).

> **Note:** starter code structures were provided by the university course staff. Core logic, game loops, dynamic data structures, and feature implementations were authored by me.

---

## 📁 Repository Structure

### 1. `Assignment1-WelcomeToCpp/`
* Warmup exercises covering environment setup, basic syntax debugging, hash code generation, and a consecutive coin flip simulation.
* **Key Features:** Calculating combinations $c(n, k)$ recursively without loops or multiplication, recursive numeric conversions (`stringToInt` and `intToString`), and calculating Flesch-Kincaid Readability scores using file reading and `TokenScanner`.

### 2. `Assignment2-FunWithCollections/`
* Practical applications utilizing core Abstract Data Types (ADTs) to solve complex problems.
* **Key Features:** Finding the shortest path in Word Ladders using Breadth-First Search (BFS) with `Vector`, `Queue`, and `Lexicon` ADTs, and generating 2000 characters of pseudo-random text by building an order-$k$ Markov model via a `Map<string, Vector<char>>`.

### 3. `Assignment3-Recursion/`
* A comprehensive suite of problems utilizing functional recursion, memory recursion, and recursive backtracking.
* **Key Features:** Recursive pathfinding (Karel Goes Home), loop-less subset generation and string subsequence checking, drawing order-$N$ Sierpinski Triangles using `GWindow`, mapping inverse genetics via `Map<char, Set<string>>`, and solving the Universal Health Coverage problem.

### 5. `Assignment5-Boggle/`
* A programmatic solver and validator for the Boggle word search game.
* **Key Features:** Recursive backtracking to validate human player entries on a 2D letter grid with adjacency constraints, and exhaustive board searching for the computer player using `Lexicon` prefix pruning (`containsPrefix`).

### 6. `Assignment6-HuffmanEncoding/`
* A complete file compression and decompression utility leveraging Huffman coding trees.
* **Key Features:** Bit-level file I/O operations (`ibstream`/`obstream`), character frequency map generation, optimized tree construction via priority queues (`pqueue.h`), and custom header management for table metadata.

### 7. `Assignment7-Trailblazer/`
* Implementations of foundational graph algorithms applied to 2D grid terrains and mazes.
* **Key Features:** Shortest-path finding based on move and elevation costs using Dijkstra's algorithm and A* search (with an admissible heuristic), and generating randomized mazes by building minimum spanning trees with Kruskal's algorithm.

### 8. `Assignment8-LeetCode/`
* General algorithmic problem-solving and optimization practice.
* **Key Features:** Solutions for 10 problems from the LeetCode platform.

---

## 🛠️ Technologies & Tools
* **Language:** C++11
* **Libraries:** Stanford C++ Libraries (`Vector`, `Grid`, `Queue`, `Map`, `Set`, `Lexicon`, `PriorityQueue`, `GWindow`, `ibstream`, `obstream`, `TokenScanner`)
* **Concepts:** Abstract Data Types (ADTs), Functional & Memory Recursion, Backtracking, Graph Algorithms, Binary Trees, Bit Manipulation, Computational Complexity
Abstractions-Cpp-README.md
Displaying Abstractions-Cpp-README.md.

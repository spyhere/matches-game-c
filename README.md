# Matches-Game (C99 implementation)

[Solution in Go](https://github.com/spyhere/matches-game)

## Description

The solution written in C programming language for a task from [this lecture](https://www.youtube.com/watch?v=qaCsf7wOpRQ&t=4826s).
With this program you are playing against computer. First player is decided randomly.

## Rules

Given N amount of matches, first player is grabbing as much as he wants, but not all of them. The next player
can grab <= then (previous player grabbed * 2). They continue grabbing matches until all matches have been taken.
Player who had the last move wins.

At the end program should show the history of moves and display who has won.

For example:
```
Given 11 matches.
Moves: [4, 7]
Player2 wins!
```

## Usage

1. Clone the repo
2. Make sure you have [CMake](https://cmake.org/download/) installed
3. Build the project

```bash
cmake -S . -B build
cmake --build build
```
4. Run the application

```bash
./build/matches-game-c
```

### Example:
```
your@pc matches-game-c % ./build/matches-game-c
Enter your name: Eugene
Shuffle...
21 matches for this game. First move goes to Eugene
Available 20 matches (21 left). Your move: 5
Available 10 matches (16 left). ...Computer grabs 3
Available 6 matches (13 left). Your move: 3
Available 6 matches (10 left). ...Computer grabs 2
Available 4 matches (8 left). Your move: 2
Available 4 matches (6 left). ...Computer grabs 1
Available 2 matches (5 left). Your move: 1
Available 2 matches (4 left). ...Computer grabs 1
Available 2 matches (3 left). Your move: 2

Game over
Computer has won!
Initial amount of matches: 21
Moves:
Eugene 5(16) - Computer 3(13)
Eugene 3(10) - Computer 2(8)
Eugene 2(6) - Computer 1(5)
Eugene 1(4) - Computer 1(3)
Eugene 2(1) - Computer 1(0)
```


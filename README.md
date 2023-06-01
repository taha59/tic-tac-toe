# Tic Tac Toe Game

## Introduction
This is a simple Tic Tac Toe game implemented in C++. It allows you to play the game in multiplayer mode or against a computer opponent.

## Prerequisites
Make sure you have a C++ compiler installed on your system.

## How to Play
1. Clone this repository.
2. Compile the source code using the C++ compiler.
3. Run the executable file.
4. Choose the game mode:
   - Multiplayer: Play against another player.
   - Single Player: Play against the computer.

## Game Rules
- The game is played on a 3x3 grid.
- Players take turns marking a cell with their respective symbol (Player 1: O, Player 2/Computer: X).
- The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins the game.
- If all cells are filled and no player has won, the game ends in a tie.

## Code Structure
- The `tic_tac_toe` class represents the game and contains the game logic.
- The `display_board` function displays the current state of the game board.
- The `print_legal_m` function prints the legal moves available on the board.
- The `game_status` function checks the game status to determine if a player has won or the game has ended in a tie.
- The `multiplayer_mode` function allows two players to play against each other.
- The `single_player` function allows a player to play against the computer.
- The `main` function handles the game mode selection and initializes the game.

## Acknowledgments
Special thanks to [OpenAI](https://openai.com/) for providing the GPT-3.5 model used to generate this README.


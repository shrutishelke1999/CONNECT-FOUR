Project 1: CONNECT 4

My code has mainly three sections, in roughly the following order.

Section 1: Checks for wins
 - Checks for horizontal and vertical wins
 - Checks for wins diagonally up and diagonally down
 - Tells you if a game has been won
 - Returns the winner of the game


Section 2: Possible Moves
 - To add a move, it iterates over the given column and finds the first available spot. Returns false if column is full or invalid.
 - For AI moves:  it checks to see if the AI can win making a certain move, and does the move 
                  it checks to see if the other player can make a winning move and does that move instead as a defensive move
                 else generates a random possible move


Section 3: Main Function
 - Prints the board and asks users if they want to be player 1 or 2. 
 - Assigns X to Player 1 and O to Player 2
 - Asks users to pick valid column till a valid column is picked and move is recorded
 - Keeps track of all moves and no of moves
 - Declares winner or tie, and prints all the moves done in the game

All of the above sections have several helper functions. 
This code gives the user an opportunity to pick their player number and hence 'X' or 'O'.
The AI is able to pick and block winning moves
It checks for invalid input by the user.

Here is the link for my video : https://youtu.be/fMHHMn6m2JA 


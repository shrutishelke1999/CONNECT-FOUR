#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//checks for horizontal wins
char HorizontalWin(char board[6][7]){
  for(int i=0;i<6;i++){
    if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]==board[i][3]){
      if(board[i][0]=='X'){
       return 'X';
      }
      if(board[i][0]=='O'){
       return 'O';
      }
    }
    
    if(board[i][1]==board[i][2]&&board[i][2]==board[i][3]&&board[i][3]==board[i][4]){
      if(board[i][1]=='X'){
       return 'X';
      }
      if(board[i][1]=='O'){
       return 'O';
      }
    }
   
    if(board[i][2]==board[i][3]&&board[i][3]==board[i][4]&&board[i][4]==board[i][5]){
      if(board[i][2]=='X'){
       return 'X';
      }
      if(board[i][2]=='O'){
       return 'O';
      }
    }

    if(board[i][3]==board[i][4]&&board[i][4]==board[i][5]&&board[i][5]==board[i][6]){
      if(board[i][3]=='X'){
       return 'X';
      }
      if(board[i][3]=='O'){
       return 'O';
      }
    }
  }
     return '.';
}


//checks for vertical wins 
char VerticalWin(char board[6][7]){
  for(int i=0;i<7;i++){
    if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[2][i]==board[3][i]){
      if(board[0][i]=='X'){
       return 'X';
      }
      if(board[0][i]=='O'){
       return 'O';
      }
    }

    if(board[1][i]==board[2][i]&&board[2][i]==board[3][i]&&board[3][i]==board[4][i]){
      if(board[1][i]=='X'){
       return 'X';
      }
      if(board[1][i]=='O'){
       return 'O';
      }
    }

    if(board[2][i]==board[3][i]&&board[3][i]==board[4][i]&&board[4][i]==board[5][i]){
      if(board[2][i]=='X'){
       return 'X';
      }
      if(board[2][i]=='O'){
       return 'O';
      }
    }
  }
  return '.';
}


//checks for diagonal wins up to down
char DiagonalWin1(char board[6][7]){
  for(int i=0;i<4;i++){
    if(board[0][i]==board[1][i+1]&&board[1][i+1]==board[2][i+2]&&board[2][i+2]==board[3][i+3]){
      if(board[0][i]=='X'){
       return 'X';
      }
      if(board[0][i]=='O'){
       return 'O';
      }
    }

    if(board[1][i]==board[2][i+1]&&board[2][i+1]==board[3][i+2]&&board[3][i+2]==board[4][i+3]){
      if(board[1][i]=='X'){
       return 'X';
      }
      if(board[1][i]=='O'){
       return 'O';
      }
    }

    if(board[2][i]==board[3][i+1]&&board[3][i+1]==board[4][i+2]&&board[4][i+2]==board[5][i+3]){
     if(board[2][i]=='X'){
       return 'X';
      }
      if(board[2][i]=='O'){
       return 'O';
      }
    }
  }
  return '.';
}


//checks for diagonal wins down to up
char DiagonalWin2(char board[6][7]){
  for(int i=3;i<7;i++){
    if(board[0][i]==board[1][i-1]&&board[1][i-1]==board[2][i-2]&&board[2][i-2]==board[3][i-3]){
      if(board[0][i]=='X'){
       return 'X';
      }
      if(board[0][i]=='O'){
       return 'O';
      }
    }

    if(board[1][i]==board[2][i-1]&&board[2][i-1]==board[3][i-2]&&board[3][i-2]==board[4][i-3]){
      if(board[1][i]=='X'){
       return 'X';
      }
      if(board[1][i]=='O'){
       return 'O';
      }
    }

    if(board[2][i]==board[3][i-1]&&board[3][i-1]==board[4][i-2]&&board[4][i-2]==board[5][i-3]){
      if(board[2][i]=='X'){
       return 'X';
      }
      if(board[2][i]=='O'){
       return 'O';
      }
    }
  }

  return '.';
}


//prints  Game Board
void printBoard(char board[6][7]){
  //adds spaces between boards for more readable display
  for(int i=0;i<20;i++){
    printf("\n");
  }
  printf("   A  B  C  D  E  F  G");
  printf("\n");
  for(int i=0;i<6;i++){
    for(int j=0;j<8;j++){
      if(j==0){
        printf("%i ", 6-i);
       
      }
      else{
        printf(" %c ", board[i][j-1]);
      } 
    }
    printf("\n");
  }
}

//returns winner of the game
char Winner(char board[6][7]){
  if(HorizontalWin(board)!='.'){
    return HorizontalWin(board);
  }
  
  if(VerticalWin(board)!='.'){
    return VerticalWin(board);
  }

  if(DiagonalWin1(board)!='.'){
    return DiagonalWin1(board);
  }

  if(DiagonalWin2(board)!='.'){
    return DiagonalWin2(board);
  }
  return '.';
}

//checks if the game has been won
bool hasWon(char board[6][7]){
  return (Winner(board)!='.');
}

//converts column character into int for simplification of further code
int columnInt(char column){
  if(column=='A')return 0;
  if(column=='B')return 1;
  if(column=='C')return 2;
  if(column=='D')return 3;
  if(column=='E')return 4;
  if(column=='F')return 5;
  if(column=='G')return 6;
  return -1; 
}


//checks if specified column is full
bool isFull(char column, char board[6][7]){
  if(columnInt(column)==-1)return false;
  if(board[0][columnInt(column)]!='.')return true;
  return false;
 }

//adds a move to the column
bool addMove(char column, int playerNo, char board[6][7]){
  
  int columnNo = columnInt(column);
  char player = 'X';
  if(playerNo==2)player='O';
   
  if(columnNo==-1){
    return false;
  }
  
  if(isFull(column, board)==true){
    return false;
  }
  
 
  if(board[5][columnNo]=='.'){
    board[5][columnNo]=player;
    return true;
  }
  
  //iterates from the top to find position to add next move
  else {
    for(int i=0;i<5;i++){
      if(board[i][columnNo]=='.'&&board[i+1][columnNo]!='.'){
        board[i][columnNo]=player;
        return true;
      }
    }
    return false;
  }

} 

//Random integer generator, found online on geekforgeeks.org
int randomInt(int lower, int upper){
  return (rand() % (upper - lower + 1)) + lower;
}

char AIMove(char board[6][7], int AIplayerNo){

  char tempBoard[6][7];
  char AIplayer = 'X';
  char otherPlayer = 'O';
  int otherPlayerNo = 2;
  if(AIplayerNo==2){
    AIplayer='O';
    otherPlayer='X';
    otherPlayerNo=1;
  }

//does a move if it is the winning move for AI
for(int k=0;k<7;k++){
  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
      tempBoard[i][j]=board[i][j];
    }
  }
  if(addMove('A'+k, AIplayerNo, tempBoard)&&Winner(tempBoard)==AIplayer){
      addMove('A'+k, AIplayerNo, board);
      return 'A'+k;
  }
}

//does a defensive move by checking if it is a winning move for user
for(int k=0;k<7;k++){
  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
      tempBoard[i][j]=board[i][j];
    }
  }
    if(addMove('A'+k, otherPlayerNo, tempBoard)&&Winner(tempBoard)==otherPlayer){
      addMove('A'+k, AIplayerNo, board);
      return 'A'+k;
    }
}

//Else randomly picks a valid column using ASCII Table
for(int i=0;i<6;i++){
  for(int j=0;j<7;j++){
    tempBoard[i][j]=board[i][j];
  }
}

int randomNo=randomInt(65, 71);
  char c=randomNo;
   while(!addMove(c,AIplayerNo,tempBoard)){
     randomNo=randomInt(65, 71);
     c=randomNo;
   }
  addMove(c,AIplayerNo,board);
  return c;
}





int main(void) {
  char board[6][7];
  int playerNo;
  int AINo=2;
  char moves[42];
  int noofMoves=0;
  char playerMove;
  
  for(int i=0;i<6;i++){       //creates game board
    for(int j=0;j<7;j++){
      board[i][j]='.';
    }
  }

  printBoard(board);

  printf("Do you want to play first or second? Type 1 or 2 respectively\n");
  scanf("%i", &playerNo);
  if(playerNo==2)AINo=1;
 
  while(hasWon(board)==false&&noofMoves<42){
    
    if(AINo==1){
      moves[noofMoves]=AIMove(board,1);
      noofMoves++;
    }
   
    if(hasWon(board))break;
   
    printBoard(board);
    printf("Select a column for your next move between A to G\n");
    scanf(" %c", &playerMove);
   
    //checks to see if it is a valid move
    while(!addMove(playerMove,playerNo,board)){
      printf("Invalid column. Select another column between A to G for your next move\n");
      scanf(" %c", &playerMove);
    }
    
    moves[noofMoves]=playerMove;
    noofMoves++;
    
    if(AINo==2){
      moves[noofMoves]=AIMove(board,2);
      noofMoves++;
    }
  }
 
  printBoard(board);
  if(Winner(board)=='.'){
    printf("It is a tie!\n");
  }
 
  if(Winner(board)=='X'){
    printf("The winner is Player 1\n");
  }

  if(Winner(board)=='O'){
    printf("The winner is Player 2\n");
  }

  for(int i=0;i<noofMoves;i++){
   printf(" %c\n", moves[i]);
  }
}

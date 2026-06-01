#include<iostream>
#include<ctime>
// This Function draws the board
void DrawBoard(std::string board[3][3]){
for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        std::cout<<"    "<<"|_"<<board[i][j]<<"_|";
    }
    std::cout<<"\n";
}
// This function takes the player's move
}
void PlayerMove(std::string board[3][3]){
int Move;
std::cout<<"Enter index of the block you want to play on: ";
std::cin>>Move;

// The code below divdes the two digit number into single digits and stores it into a and b 
int a = Move/10;
int b = Move%10;

//The code below checks if the player has entered position that exists on the board
if(a<0 || a>2 || b<0 || b>2){
std::cout<<"Please enter a valid position the board\n";
PlayerMove(board);
return; // This return avoids a bug that happens due to function calls
}
//The code below checks if the position chosen by player is empty and then puts player's marker accordingly
if(board[a][b] != "X" && board[a][b] != "O"){
board[a][b] = "X";
}
//If postion chosen by player is not empty then function is called again recursively.
else{
    std::cout<<"Please enter a valid position the board\n";
    PlayerMove(board);
    return;
}
}


// This fucntion takes two random integers and puts them in boards[a][b] to get a random postion where the computer plays it's move.
void ComputerMOve(std::string board[3][3]){
int a = rand()%3;
int b = rand()%3;
//The code below checks if the position chosen by Computer is empty and then puts player's marker accordingly
if(board[a][b] != "X" && board[a][b] != "O"){
    board[a][b] = "O";
}
//If postion chosen by computer is not empty then function is called again recursively.
else{
    ComputerMOve(board);
}

}


bool CheckWiner(std::string board[3][3],std::string marker){

    // Winning conditoin for row

    /* This part of code blelow iterates the two dimensional array i.e. the board in row-wise order and if three consecutive
    elements in the row are equal to the same marker then it returns true boolean value*/
    int count;
    //The bigger for loop iterates over each row
for(int i = 0; i<3; i++){
    count = 0;
    // The smaller for loop iterates over each element in a row 
    for(int j = 0; j<3; j++){
        if(board[i][j] == marker ){
            count++;
        }
    }
    if(count == 3){
            return true;
        }
}

//Winning condition for columns

/* This part of code blelow iterates the two dimensional array i.e. the board in column-wise order and if three consecutive
    elements in the column are equal to the same marker then it returns true boolean value*/

// The bigger for loop iterates over columns
for(int i = 0; i<3; i++){
    count = 0;
    //The smaller for loop iterates over each element in the a column.
    for(int j = 0; j<3; j++){
        if(board[j][i] == marker ){
            count++;
        }
        
    }
    if(count == 3){
            return true;
        }
}

// Winning condition for Principal digonal
count = 0;
// This for loop checks if all diagonal elements are occupied by the same marker
for(int i = 0; i<3; i++){
      if(board[i][i] == marker ){
            count++;
        }
}
if(count == 3){
            return true;
        }

//winning condition for non-Principal digonal
count = 0;
 /* To check for the non-Principal digonal we see a patter the indeces of elmes are 02 ,11, 20
 here we can see a patter than one index is going form 0 t0 2 while other is going from 2 to 0
 so for 0 to 2 we simply run a for loop with i = 0 to i <3 and for other part we take an interger j 
 set it's intial value to 2 then decease it by 1 for each iteration of the loop*/
int j = 2;

for(int i = 0; i<3; i++){
    if(board[i][j] == marker ){
            count++;
        }
        j--;
}
// At last we check if all three elements of the non-principal digonal are equal and return true if they are 
if(count == 3){
            return true;
        }


return false;
}

bool CheckForDraw(std::string board[3][3]){
    // We are checking for winning condition after every move of player and computer so it the boards fils all the
    // 9 elments without either of them winning then it is a draw
    int count = 0;
for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        if(board[i][j] == "X" || board[i][j] == "O"){
            count++;
        }
    }
}
if(count == 9){
    return true;
}
else{
    return false;
}
}

int main(){

    std::string markerp = "X";


    std::string markerc = "O";

    srand(time(NULL));
    // This is the original board to play on with postions as strings
    std::string board[3][3] = {{"00","01","02"},
                              {"10","11","12"},
                              {"20","21","22"}};
        bool running = true;

        while(running){
        DrawBoard(board);// First this shows the player an empty board
        std::cout<<"\n";

        PlayerMove(board);// Player makes a move

        if(CheckWiner(board,markerp)){// We check if player has won after every move he makes if he has we break the loop
        DrawBoard(board);
        std::cout<<" \nYou have won the game";
        break;
        }

        if(CheckForDraw(board)){// As player is the one palying the first move he will also be the one palying the last move
        //and only the person playing the last move can make a draw So we check if it's a draw after each move of player
        DrawBoard(board);
        std::cout<<" \nIt is a draw";
        break;
        }


        ComputerMOve(board);//Computer makes a move

        if(CheckWiner(board,markerc)){// We check it computer has won after every move it makes and break the loop it it does.
        DrawBoard(board);
        std::cout<<" \nComputer won the game";
        break;
        }
        std::cout<<"\n";
        }
    }
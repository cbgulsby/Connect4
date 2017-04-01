#include <iostream>
using namespace std;

string playerChoice = "";
void print();
bool columnFull(int column);
bool gameOver();
void computerMove();
void playerMove();
int counter(int row, int column, char direction);
bool checkDiagonal(char color);
int lastMove;                        //lastmove = 1 -> computer; lastmove = 0 -> human;
char board[6][7];
bool check3();
                                     //computer moves: "x";
                                     //human moves: "o";
                                     
int main(){    
    for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++){
                    board[i][j] = '_';
            }
    }
    
    cout << "Welcome to Connect Four! Would you like to go first or second?" << endl;
    cin >> playerChoice;
    if (playerChoice == "first"){
            playerMove();
            lastMove = 0;
            print();
    }
    else if (playerChoice == "second"){
            computerMove();
            lastMove = 1;   
            print();
    }
    else {
        cout << "Invalid choice" << endl;
        return -1;
     }
     
    while(gameOver() != true){
        if(lastMove == 0){
             computerMove();
             lastMove = 1;  
             print();
        }
        else if(lastMove == 1){
             playerMove();
             lastMove = 0;
             print();
        }
    }
    if(gameOver() == true) {
        if(lastMove == 1) {
             cout << "The computer has won!!" << endl;   
        }
            
        else {   
            cout << "You have won!!" << endl;
        }
    }
      
}

void print(){
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            cout << " | " << board[i][j];
        }
        cout << " | " << endl;
    }
    cout << endl;
}
int counter (int row, int column, char direction){

int hmax = 6;
int vmax = 5;
int vmin = 0;
int hmin = 0;
int check = 1;
int check1 = 1;
int check2 = 1;
int counter = 1;
int value = 0;
char val = '_';
char val1 = '_';
char val2 = '_';
char tempval = '_';
        if (direction == 'v'){                                        //vertical
                while (counter != 4 &&  check != 0 && val != 'o'){
                        if (row + counter <= vmax){
                                val = board[row + counter][column];
                                if (val == 'x'){
                                        value++;
                                }
				if (val == 'o'){
					tempval = board[row + counter + 1][column];
					if (tempval == 'o'){
						tempval = board[row + counter + 2][column];
						if (tempval == 'o'){
							value = 90000;
							return value;
						}
					}
				}
                        }
                        else {
                                check = 0;
                        }
			counter++;
                }
                if (value == 3){                        //autowin
                        value = 100000;
                }
        }
        
        if (direction == 'h'){                                          //horizontal
              while (counter != 4 && (check1 != 0 || check2 != 0) && val1 != 'o' && val2 != 'o'){
                     if (val1 != 'o'){
                         if (column + counter <= hmax){
                            val1 = board[row][column + counter];
                            if (val1 == 'x'){
                               value++;
                             }
		             if (val1 == 'o' && column + counter + 1 <= hmax){
					tempval = board[row][column + counter + 1];
					if (tempval == 'o' && column + counter + 2 <= hmax){
					tempval = board[row][column + counter + 2];
					if (tempval == 'o'){
						value = 90000;
						return value;
					}
				}
				}
                             
                        }
                        else {
                            check1 = 0;
                        }
                     }
                     if (val2 != 'o'){
                         if (row - counter >= hmin){
                             val2 = board[row][column - counter];
                             if (val2 == 'x'){
                                 value++;
                              }
			     if (val2 == 'o' && column - counter - 1 >= hmin){
				tempval = board[row][column - counter - 1];
				if (tempval == 'o' && column - counter - 2 >= hmin){
					tempval = board[row][column - counter - 2];
				if (tempval == 'o'){
					value = 90000;
					return value;
				}
				}
				}
      
                        }
                        else {
                            check2 = 0;
                        }
                     }
                        counter++;
             }
                     if (value == 3){
                             value = 100000;
                     }
        }  
                        
        if (direction == 'r'){                          //right diagonal
            while (counter != 4 && (check1 != 0 || check2 != 0) && (val1 != 'o' || val2 != 'o')){
                    if (val1 != 'o' && check1 != 0){
                        if (column + counter <= hmax && row - counter >= vmin){
                            val1 = board[row - counter][column + counter];
                            if (val1 == 'x'){
                                    value++;
                             }
			if (val1 == 'o' && (column + counter + 1 <= hmax) && (row - counter - 1 >= vmin)){
				tempval = board[row - counter - 1][column + counter + 1];
				if (tempval == 'o' && (column + counter + 2 <= hmax) && (row - counter - 2 >= vmin)){
					tempval = board[row - counter - 2][column + counter + 2];
				if (tempval == 'o'){
					value = 90000;
					return value;
				}
				}
				}
			 
                         }
                         else {
                             check1 = 0;
                         }
                    }
                    if (val2 != 'o' && check2 != 0){
                        if (column - counter >= hmin && row + counter <= vmax){
                            val2 = board[row + counter][column - counter];
                            if (val2 == 'x'){
                                    value++;
                            }
			    if (val2 == 'o' && (column - counter - 1 >= hmin) && (row + counter + 1 <= vmax)){
				tempval = board[row + counter + 1][column - counter - 1];
				if (tempval == 'o' && (column - counter - 2 >= hmin) && (row + counter + 2 <= vmax)){
				tempval = board[row + counter + 2][column - counter - 2];
				if (tempval == 'o'){
					value = 90000;
				}
				}
				}  
                         }
                         else {
                             check2 = 0;
                         }
                    } 
                    counter++; 
            }
            if (value == 3){
                value = 100000;
            }
                          
        }
        if (direction == 'l'){                          //left diagonal
            while (counter != 4 && (check1 != 0 || check2 != 0) && (val1 != 'o' || val2 != 'o')){
                if (val1 != 'o' && check1 != 0){
                        if (column - counter >= hmin && row - counter >= vmin){
                            val1 = board[row - counter][column - counter];
                            if (val1 == 'x'){
                                    value++;
                            }
				if (val1 == 'o' && (column - counter - 1 >= hmin) && (row - counter - 1 >= vmin)){
					tempval = board[row - counter - 1][column - counter - 1];
					if (tempval == 'o' && (column - counter - 2 >= hmin) && (row - counter - 2 >= vmin)){
					tempval = board[row - counter - 2][column - counter - 2];
					if (tempval == 'o'){
						value = 90000;
					}
					}
					}
                        }
                        else {
                            check1 = 0;
                        }
               }
               if (val2 != 'o' && check2 != 0){
                       if (column + counter <= hmax && row + counter <= vmax){
                           val2 = board[row + counter][column + counter];
                           if (val2 == 'x'){
                               value++;
                           }
			   if (val2 == 'o' && (column + counter + 1 <= hmax) && (row + counter + 1) <= vmax){
				tempval = board[row + counter + 1][column + counter + 1];
				if (tempval == 'o' && (column + counter + 2 <= hmax) && (row + counter + 2) <= vmax){
				tempval = board[row + counter + 2][column + counter + 2];
				if (tempval == 'o'){
					value = 90000;
				}
				}
				}
				
                       }
                       else {
                           check2 = 0;
                       }
              }
              counter++;   
            }
            if (value == 3){
                value = 100000;
            }
        
        }
return value;
}    
void computerMove() {
int maxvalue = 0;
int vvalue;
int hvalue;
int rvalue;
int lvalue;
int placei;
int placej;
int ran = 0;
for (int j = 0; j < 7; j++){
        for (int i = 5; i > -1; i--){
                if (board[i][j] == '_'){
                        if (ran != 1){
                                placei = i;
                                placej = j;
                                ran = 1;
                        }
                        vvalue = counter(i, j, 'v');
                        hvalue = counter(i, j, 'h');
                        rvalue = counter(i, j, 'r');
                        lvalue = counter(i, j, 'l');
                        if (vvalue + hvalue + rvalue + lvalue == maxvalue){
                                if (j == 3){
					vvalue = vvalue + 4;
				}
				if (j == 2 || j == 4){
					vvalue = vvalue + 3;
				}
				if (j == 1 || j == 5){
					vvalue = vvalue + 2;
				}
				else {
					vvalue = vvalue + 1;
				}
				maxvalue = (vvalue + hvalue + rvalue + lvalue);
				placei = i;
				placej = j;
			}
			else if (vvalue + hvalue + rvalue + lvalue > maxvalue){
				maxvalue = (vvalue + hvalue + rvalue + lvalue);
                                placei = i;
                                placej = j;
                        }
                        i = 0;
                }
        }
}
int used = 0;

	board[placei][placej] = 'x';	
	used = 1;

//else {
//	if(check3()) return;
//}
//if (used != 1){
//	board[placei][placej] = 'x';
//}

return;
}

void playerMove(){
     int playerColumn;
     int i=5;
        cout << "Pick a column (0-6): ";
        cin >> playerColumn;                            // player's column choice
        if (columnFull(playerColumn) == true)
        {
                cout << "Column full, pick another column" <<  endl;
                playerMove();                           //repeats call for player move until vaild choice is made
        }
        while (board[i][playerColumn] != '_' && i>0) {
                i--;                                    //iterates through rows
        }
        board[i][playerColumn] = 'o';                //places players mark

}

bool checkDiagonal(char color){
    for(int i = 5; i>=0; i--){
        for (int j = 6; j>=0; j--){
            if(board[i][j] == color){
                if(board[i+1][j+1] == color){
                    if(board[i+2][j+2] == color){
                        if(board[i+3][j+3] == color){
                            return true;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i<6; i++){
        for (int j = 7; j>=0; j--){
            if(board[i][j] == color){
                if(board[i+1][j-1] == color){
                    if(board[i+2][j-2] == color){
                        if(board[i+3][j-3] == color){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool gameOver(){
    int count = 0;
    for (int i = 0; i<6; i++){ //check horizontally
        for(int j = 0; j<6; j++){
            if(((board[i][j]=='x')||(board[i][j]=='o'))&&(board[i][j] == board[i][j+1])) {
                count++;
                if(count == 3){ return true;}
            }
            else {
                count = 0;
            }     
        }
    } 
    count = 0;
    for (int j = 0; j<6; j++){ //check vertically
        for(int i = 0; i<5; i++){
            if(((board[i][j]=='x')||(board[i][j]=='o')) && (board[i][j] == board[i+1][j])) {
                count++;
                if(count == 3){return true;}
            }
            else {
                count = 0;
            }     
        }
    } 
    count = 0;
    if(checkDiagonal('x')==true) return true;
    if(checkDiagonal('o')==true) return true;
    return false;
}

bool columnFull(int column){                                        //tests if a given column is full or nah
       int full = 1;
       for (int i = 0; i < 6; i++){
          if (board[i][column] != 'x' || board[i][column] != 'o'){            //defaults to empty when '_'
                      full = 0;
          }
       } 
        if (full == 0){
            return false;
           }
         else {
             return true;
         } 
}

bool check3() {
    int count = 0;
    for (int i = 0; i<6; i++){ //check horizontally
        for(int j = 0; j<6; j++){
            if(((board[i][j]=='x')||(board[i][j]=='o'))&&(board[i][j] == board[i][j+1])) {
                count++;
                if(count == 2){
                    if(j<5 && board[i][j+2] == '_'){
                        if(i==6){board[i][j+2] = 'x'; return true;}
                        if(i==5 && board[6][j+2] != '_'){board[i][j+2] = 'x'; return true;}
                        if(i==4 && board[6][j+2] != '_' && board[5][j+2] != '_'){board[i][j+2] = 'x'; return true;}
                        if(i==3 && board[6][j+2] != '_' && board[5][j+2] != '_' && board[4][j+2] != '_'){board[i][j+2] = 'x'; return true;}
                        if(i==2 && board[6][j+2] != '_' && board[5][j+2] != '_' && board[4][j+2] != '_' && board[3][j+2]){board[i][j+2] = 'x'; return true;}
                        if(i==1 && board[6][j+2] != '_' && board[5][j+2] != '_' && board[4][j+2] != '_' && board[3][j+2] && board[2][j+2] != '_'){board[i][j+2] = 'x';
 return true;}
                        if(i==0 && board[6][j+2] != '_' && board[5][j+2] != '_' && board[4][j+2] != '_' && board[3][j+2] && board[2][j+2] != '_' && board[1][j+2] != '_'){board[i][j+2] = 'x'; return true;}
                    }
                    else if(j>1 && board[i][j-2] == '_'){
                        if(i==6){board[i][j-2] = 'x'; return true;}
                        if(i==5 && board[6][j-2] != '_'){board[i][j-2] = 'x'; return true;}
                        if(i==4 && board[6][j-2] != '_' && board[5][j-2] != '_'){board[i][j-2] = 'x'; return true;}
                        if(i==3 && board[6][j-2] != '_' && board[5][j-2] != '_' && board[4][j-2] != '_'){board[i][j-2] = 'x'; return true;}
                        if(i==2 && board[6][j-2] != '_' && board[5][j-2] != '_' && board[4][j-2] != '_' && board[3][j-2]){board[i][j-2] = 'x'; return true;}
                        if(i==1 && board[6][j-2] != '_' && board[5][j-2] != '_' && board[4][j-2] != '_' && board[3][j-2] && board[2][j-2] != '_'){board[i][j-2] = 'x';
 return true;}
                        if(i==0 && board[6][j-2] != '_' && board[5][j-2] != '_' && board[4][j-2] != '_' && board[3][j-2] && board[2][j-2] != '_' && board[1][j-2] != '_'){board[i][j-2] = 'x'; return true;}
                    }
                }
                
                   count = 0;
    for (int j = 0; j<6; j++){ //check vertically
        for(int i = 0; i<5; i++){
            if(((board[i][j]=='x')||(board[i][j]=='o')) && (board[i][j] == board[i+1][j])) {
                count++;
                if(count == 2){
                    if(i>1 && board[i-2][j] == '_'){
                        board[i-2][j] = 'x';
                        return true;
                    }
                }
            }
            else {
                count = 0;
            }
        }
    }
    for(int i = 3; i>=0; i--){ //check diagonally
        for (int j = 4; j>=0; j--){
            if(board[i][j] == 'x'){
                if(board[i+1][j+1] == 'x'){
                    if(board[i+2][j+2] == 'x'){
                        if(i<3 && j<4 && board[i+3][j+3] == '_'){
                            board[i+3][j+3] = 'x';
                        }
                        else if(i>1 && j>1 && board[i-2][j-2] == '_'){
                            board[i-2][j-2] = 'x';
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i<3; i++){
        for (int j = 6; j>=2; j--){
            if(board[i][j] == 'x'){
                if(board[i+1][j-1] == 'x'){
                    if(board[i+2][j-2] == 'x'){
                        if(i<3 && j>2 && board[i+3][j-3] == '_'){
                            board[i+3][j-3] = 'x';
                            return true;
                        }
                        else if(i>1 && j<5 && board[i-2][j+2] == '_'){
                            board[i-2][j+2] = 'x';
                            return true;
                        }
                    }
                }
            }
        }
    }
    for(int i = 3; i>=0; i--){ //check diagonally
        for (int j = 4; j>=0; j--){
            if(board[i][j] == 'o'){
                if(board[i+1][j+1] == 'o'){
                    if(board[i+2][j+2] == 'o'){
                        if(i<3 && j<4 && board[i+3][j+3] == '_'){
                            board[i+3][j+3] = 'x';
                        }
                        else if(i>1 && j>1 && board[i-2][j-2] == '_'){
                            board[i-2][j-2] = 'x';
                        }
                    }
                }
            }
        }
    }
        for(int i = 0; i<3; i++){
        for (int j = 6; j>=2; j--){
            if(board[i][j] == 'o'){
                if(board[i+1][j-1] == 'o'){
                    if(board[i+2][j-2] == 'o'){
                        if(i<3 && j>2 && board[i+3][j-3] == '_'){
                            board[i+3][j-3] = 'x';
                            return true;
                        }
                        else if(i>1 && j<5 && board[i-2][j+2] == '_'){
                            board[i-2][j+2] = 'x';
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
}}}             

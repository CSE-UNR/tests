#include <stdio.h>
#define FILENAME "field.txt"
#define FILENAME2 "scores.txt"
#define ROW 8
#define COLUMN 8
#define NAMEINDEX 30


int valid(int row, int column);
void getCell(int* rowsptr, int* columnsptr);
char uncoverCell(FILE* in, int row, int column, int userrow, int usercol, int answerboard[8][8], char realboard[8][8]);
char clearCell(FILE* in, int row, int column, int userrow, int usercol, int myboard[8][8], char realboard[8][8]);
char getMenuChoice();


void displayBoard(int row, int col, char Array[8][8]);
void getName(char names[NAMEINDEX], FILE* ptr2, int score);
void displayLeaderboard(FILE* ptr2);
char replayChoice();
void clearBoard(int row, int column, char Array[8][8]);
int checkBomb(int row, int column, char Array[8][8]);
int checkWin(int row, int column, char Array[8][8], int myboard[8][8]);


// test func
void test(char Array[8][8]) {
        printf("\n");
        for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++)
                        printf("%c, ", Array[i][j]);
                printf("\n"); 
        }
        printf("\n");
}


int main(){


        FILE* ptr = fopen(FILENAME, "r");
        FILE* ptr2 = fopen(FILENAME2, "a");


        int answerArray[ROW][COLUMN], rows = 0, columns = 0, validity, column, row, col, score;
        char choice, Array[8][8] = {'\0'}, names[NAMEINDEX], uncover, one, two, three, four, five, six, seven, eight, nine, restart = 'Y';


        //fix answerboard
        for(int rowindex = 0; rowindex < ROW; rowindex++){
                for(int colindex = 0; colindex < COLUMN; colindex++){
                        fscanf(ptr, "%d", &answerArray[rowindex][colindex]);
                }
        }


        if(ptr == NULL){
                printf("File can not open");
                return 0;
        }
        if(ptr2 == NULL){
                printf("File can not open");
                return 0;
        }
        do{
                int bombvalue = 0, winValue = 0, score = 0;
                while(bombvalue == 0 && winValue == 0){


                //test
                printf("\nANSWERARRAY:\n");
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++)
                                printf("%d, ", answerArray[i][j]);
                        printf("\n"); 
                }
                printf("\n");


                displayLeaderboard(ptr2);
                displayBoard(rows, columns, Array);
                
                do{
                        getCell(&rows, &columns);
                        validity = valid(rows, columns);
                }while(validity != 1);
                choice = getMenuChoice();
                switch(choice){
                        case 'M':
                                Array[rows-1][columns-1] = 'F';
                        break;
                        case 'U':
                                uncover = uncoverCell(ptr, ROW, COLUMN, rows, columns, answerArray, Array);
                                Array[rows-1][columns-1] = uncover;
                                bombvalue += checkBomb(rows, columns, Array);
                        break;
                        case 'C':
                                if(valid(rows-1, columns-1) == 1 && Array[rows-1-1][columns-1-1] != 'F'){
                                        one = clearCell(ptr, ROW, COLUMN, rows-1, columns-1, answerArray, Array);
                                        Array[rows-1-1][columns-1-1] = one;
                                        bombvalue += checkBomb(rows-1, columns-1, Array);
                                        
                                }
                                if(valid(rows-1, columns) == 1 && Array[rows-1][columns] != 'F'){
                                        two = clearCell(ptr, ROW, COLUMN, rows-1, columns, answerArray, Array);
                                        Array[rows-1-1][columns-1] = two;
                                        bombvalue += checkBomb(rows-1, columns, Array);
                                        
                                }
                                if(valid(rows-1, columns+1) == 1 && Array[rows-1][columns+1] != 'F'){
                                        three = clearCell(ptr, ROW, COLUMN, rows-1, columns+1, answerArray, Array);
                                        Array[rows-1-1][columns+1-1] = three;                                        
                                        bombvalue += checkBomb(rows-1, columns+1, Array);
                                }
                                if(valid(rows, columns-1) == 1 && Array[rows][columns-1] != 'F'){
                                        four = clearCell(ptr, ROW, COLUMN, rows, columns-1, answerArray, Array);
                                        Array[rows-1][columns-1-1] = four;
                                        bombvalue += checkBomb(rows, columns-1, Array);
                                }
                                if(valid(rows, columns) == 1 && Array[rows][columns] != 'F'){
                                        five = clearCell(ptr, ROW, COLUMN, rows, columns, answerArray, Array);
                                        Array[rows-1][columns-1] = five;
                                        bombvalue += checkBomb(rows, columns, Array);
                                }
                                if(valid(rows, columns+1) == 1 && Array[rows][columns+1] != 'F'){
                                        six = clearCell(ptr, ROW, COLUMN, rows, columns+1, answerArray, Array);
                                        Array[rows-1][columns+1-1] = six;
                                        bombvalue += checkBomb(rows, columns+1, Array);
                                }
                                if(valid(rows+1, columns-1) == 1 && Array[rows+1][columns-1] != 'F'){
                                        seven = clearCell(ptr, ROW, COLUMN, rows+1, columns-1, answerArray, Array);
                                        Array[rows+1-1][columns-1-1] = seven;
                                        bombvalue += checkBomb(rows+1, columns-1, Array);
                                }
                                if(valid(rows+1, columns) == 1 && Array[rows+1][columns] != 'F'){
                                        eight = clearCell(ptr, ROW, COLUMN, rows+1, columns, answerArray, Array);
                                        Array[rows+1-1][columns-1] = eight;
                                        bombvalue += checkBomb(rows+1, columns, Array);
                                }
                                if(valid(rows+1, columns+1) == 1 && Array[rows+1][columns+1] != 'F'){
                                        nine = clearCell(ptr, ROW, COLUMN, rows+1, columns+1, answerArray, Array);
                                        Array[rows+1-1][columns+1-1] = nine;
                                        bombvalue += checkBomb(rows+1, columns+1, Array);
                                }
                        break;
                        default:
                        break;
                }
                winValue = checkWin(ROW, COLUMN, Array, answerArray);
                if(winValue == 1){
                        score += 1;
                        getName(names, ptr2, score);
                        break;
                }
                //test
                printf("Bombvalue, winvalue: %d, %d\n", bombvalue, winValue);
                if (bombvalue != 0) {
                        printf("You lose :(\n");
                        break;
                }
        }
        bombvalue = 0;
        displayBoard(rows, columns, Array);
        restart = replayChoice();
        clearBoard(ROW, COLUMN, Array);
        } while(restart == 'Y');
        
        fclose(ptr);
        fclose(ptr2);
        
        return 0;
}


void displayBoard(int row, int col, char Array [8][8]){
        printf("    ");
        for(col = 0; col < 8; col++){
                printf("%d   ", col + 1);
            }
        printf("\n");
        printf("  ---------------------------------\n");
        for(row = 0; row < 8; row++){
                 printf("%d ", row + 1);
                for(col = 0; col < 8; col++){
                        printf("| ");
                        
                        switch(Array[row][col]){
                                case 'F':
                                case '1':
                                case '2':
                                case '3':
                                case 'X':
                                case '_':
                                        printf("%c ", Array [row][col]);
                                        break;
                                default:
                                        printf("  ");
                                        break;
                        
                        }
                 }
                printf("|");
                       printf("\n");
                printf("  ---------------------------------\n");
}
}




char getMenuChoice (){
        char choice;
        printf("(M)ark this cell with a bomb flag\n");
        printf("(U)ncover to reveal what’s in this cell\n");
        printf("(C)heck the surrounding cells\n");
        printf("Which move?: ");
        scanf(" %c", &choice);
        return choice;
}


        


int valid(int row, int column){


        if(row <= 8 && row >= 1){
                if(column <= 8 && column >= 1){
                        return 1;
                }
        }
        return 0;
}


void getCell(int* rowsptr, int* columnsptr){


        printf("Which cell? ");
        scanf("%d %d", rowsptr, columnsptr);
}


char uncoverCell(FILE* in, int row, int column, int userrow, int usercol, int answerboard[8][8], char realboard[8][8]){
        
        int rowindex = 0, colindex = 0;


        //for(rowindex = 0; rowindex < row; rowindex++){
        //        for(colindex = 0; colindex < column; colindex++){
        //                fscanf(in, "%d", &answerboard[rowindex][colindex]);
        //                //printf("%d,", answerboard[rowindex][colindex]);
        //        }
        //}
        
        switch(answerboard[userrow - 1][usercol - 1]){
                case 0:
                        return '_';
                break;
                case 1:
                        return '1';
                break;
                case 2:
                        return '2';
                break;
                case 3:
                        return '3';
                break;
                case 99:
                        return 'X';
                break;
                default:
                break;
        }
}


char clearCell(FILE* in, int row, int column, int userrow, int usercol, int answerboard[8][8], char realboard[8][8]){


        int rowindex = 0, colindex = 0;


        //for(rowindex = 0; rowindex < row; rowindex++){
        //        for(colindex = 0; colindex < column; colindex++){
        //                fscanf(in, "%d", &answerboard[rowindex][colindex]);
        //                //printf("%d,", answerboard[rowindex][colindex]);
        //        }
        //}
        if(realboard[userrow-1][usercol-1] == ‘F’){
                return ‘F’;
        }
        else if(valid(userrow, usercol) == 1){
                switch(answerboard[userrow-1][usercol-1]){
                case 0:
                        return '_';
                break;
                case 1:
                        return '1';
                break;
                case 2:
                        return '2';
                break;
                case 3:
                        return '3';
                break;
                case 99:
                        return 'X';
                break;
                default:
                break;
                }
        }
}


void getName(char names[NAMEINDEX], FILE* ptr2, int score){
        printf("Please enter your name: ");
        gets(names);
        fputs(names, ptr2);
}


void displayLeaderboard(FILE* ptr2){
        char str[500];
        fscanf(ptr2, "%s", str);
        printf("LEADERBOARD: \n");
        printf("%s", str);
} 


char replayChoice(){
        char choice;
        printf("Play again? (Y/N): ");
        scanf(" %c", &choice);
        return choice;
}


void clearBoard(int row, int column, char Array[8][8]){
        int rowindex, colindex;
                for(rowindex = 0; rowindex < row; rowindex++){
                        for(colindex = 0; colindex < column; colindex++){
                                Array[rowindex][colindex] = '\0';
                        }
                }
}


int checkBomb(int row, int column, char Array[8][8]){
        // test
        //printf("Selected row/col: %d, %d\n", row-1, column-1);
        //printf("Selected answer value: %d\n", Array[row-1][column-1]);
        if(Array[row-1][column-1] == ‘F’){
                return 0;
        }
else if(Array[row-1][column-1] == ‘X’){
                return 1;
        }
        else{
                return 0;
        }
}


int checkWin(int row, int column, char Array[8][8], int myboard[8][8]){
        int rowindex, colindex;
        for(rowindex = 0; rowindex < row; rowindex++){
                for(colindex = 0; colindex < column; colindex++){
                        if (Array[rowindex][colindex] == 'X')
                                return 0;
                        if ((Array[rowindex][colindex] == 0 || Array[rowindex][colindex] == 'F') && myboard[rowindex][colindex] != 99)
                                return 0;
                }
        }
        printf("Winner!\n");
        return 1;
}
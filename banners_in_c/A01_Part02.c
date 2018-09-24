//Assignment 1.
//Author: Bartosz Haza (SC15BH).
//University of Leeds.
//Module COMP 171101.

/*
As part of my assignment for the first part I will be required to write a program
that will convert normal text that can be inputted from the keyboard into
text banners.

The second part required me to write the text in both italics and bold letters, also
the  '&' character to be printed. The italics and bold letters should be easily
toggled between by using &I &i for italics and &B and &b for bold.

I will have a 3 dimensional array that will allow me to allocate the right amount
of space without wasting any, they will be then used to assign to the appropriate
input from the keyboard.

The use of loops will be used to print out the arrays, I want the program to always
keep running and only be killed when the "enter key" is used.
*/

//Includes the standard I/O header.
//Includes the string header.
#include <stdio.h>
#include <string.h>

//This will be the maximum allowance for the line input.
char line[200];

/*Two integar variables that will be used in the for loops to print out the elements of the array.
The string will go through the width of the array and the check will go along it.*/
int string;
int check;

//Specified array for the asterisks, this will be used to store all of the characters.
char main_array[200][7][6]= {

//Main array with all of the characters in asterisks.
{/*"A"*/ //Start of array list.
{"*****"},
{"*   *"},
{"*   *"},
{"*****"},
{"*   *"},
{"*   *"},
{"*   *"}
},

{/*"B"*/
{"**** "},
{"*   *"},
{"*   *"},
{"*****"},
{"*   *"},
{"*   *"},
{"**** "}
},

{/*"C"*/
{"*****"},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*****"}
},

{/*"D"*/
{"**** "},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"**** "}
},

{/*"E"*/
{"*****"},
{"*    "},
{"*    "},
{"*****"},
{"*    "},
{"*    "},
{"*****"}
},

{/*"F"*/
{"*****"},
{"*    "},
{"*    "},
{"*****"},
{"*    "},
{"*    "},
{"*    "}
},

{/*"G"*/
{"*****"},
{"*    "},
{"*    "},
{"* ***"},
{"*   *"},
{"*   *"},
{"*****"}
},

{/*"H"*/
{"*   *"},
{"*   *"},
{"*   *"},
{"*****"},
{"*   *"},
{"*   *"},
{"*   *"}
},

{/*"I"*/
{"*****"},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"*****"}
},

{/*"J"*/
{"*****"},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"***  "}
},

{/*"K"*/
{"*   *"},
{"*  * "},
{"* *  "},
{"**   "},
{"* *  "},
{"*  * "},
{"*   *"}
},

{/*"L"*/
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*****"}
},

{/*"M"*/
{" * * "},
{"* * *"},
{"* * *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"}
},

{/*"N"*/
{"*   *"},
{"**  *"},
{"**  *"},
{"* * *"},
{"* * *"},
{"*  **"},
{"*   *"}
},

{/*"O"*/
{" *** "},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"P"*/
{"**** "},
{"*   *"},
{"*   *"},
{"**** "},
{"*    "},
{"*    "},
{"*    "}
},

{/*"Q"*/
{"*****"},
{"*   *"},
{"*   *"},
{"*   *"},
{"* * *"},
{"*****"},
{"    *"}
},

{/*"R"*/
{"**** "},
{"*   *"},
{"*   *"},
{"**** "},
{"* *  "},
{"*  * "},
{"*   *"}
},

{/*"S"*/
{" ****"},
{"*    "},
{"*    "},
{" *** "},
{"    *"},
{"    *"},
{"**** "}
},

{/*"T"*/
{"*****"},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "}
},

{/*"U"*/
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"V"*/
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{" * * "},
{"  *  "}
},

{/*"W"*/
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"* * *"},
{"* * *"},
{" * * "}
},

{/*"X"*/
{"*   *"},
{"*   *"},
{" * * "},
{"  *  "},
{" * * "},
{"*   *"},
{"*   *"}
},

{/*"Y"*/
{"*   *"},
{"*   *"},
{" * * "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "}
},

{/*"Z"*/
{"*****"},
{"    *"},
{"   * "},
{"  *  "},
{" *   "},
{"*    "},
{"*****"}
},

{/*"a"*/
{"     "},
{"     "},
{" *** "},
{"*   *"},
{"*****"},
{"*   *"},
{"*   *"}
},

{/*"b"*/
{"     "},
{"     "},
{"*    "},
{"*    "},
{"**** "},
{"*   *"},
{" *** "}
},

{/*"c"*/
{"     "},
{"     "},
{" ****"},
{"*    "},
{"*    "},
{"*    "},
{" ****"}
},

{/*"d"*/
{"     "},
{"     "},
{"    *"},
{"    *"},
{" ****"},
{"*   *"},
{" ****"}
},

{/*"e"*/
{"     "},
{"     "},
{" *** "},
{"*   *"},
{"**** "},
{"*    "},
{" ****"}
},

{/*"f"*/
{"     "},
{"     "},
{" ****"},
{"*    "},
{"*****"},
{"*    "},
{"*    "}
},

{/*"g"*/
{"     "},
{"     "},
{" ****"},
{"*   *"},
{" ****"},
{"    *"},
{"**** "}
},

{/*"h"*/
{"     "},
{"     "},
{"*    "},
{"*    "},
{"**** "},
{"*   *"},
{"*   *"}
},

{/*"i"*/
{"     "},
{"     "},
{"  *  "},
{"     "},
{"  *  "},
{"  *  "},
{"*****"}
},

{/*"j"*/
{"    "},
{"    "},
{"  * "},
{"    "},
{"  * "},
{"  * "},
{"**  "}
},

{/*"k"*/
{"     "},
{"     "},
{"*   *"},
{"*  * "},
{"***  "},
{"*  * "},
{"*   *"}
},

{/*"l"*/
{"     "},
{"     "},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{" ****"}
},

{/*"m"*/
{"     "},
{"     "},
{" * * "},
{"* * *"},
{"*   *"},
{"*   *"},
{"*   *"}
},

{/*"n"*/
{"     "},
{"     "},
{"**** "},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"}
},

{/*"o"*/
{"     "},
{"     "},
{" *** "},
{"*   *"},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"p"*/
{"     "},
{"     "},
{"**** "},
{"*   *"},
{"**** "},
{"*    "},
{"*    "}
},

{/*"q"*/
{"     "},
{"     "},
{" ****"},
{"*   *"},
{" ****"},
{"    *"},
{"    *"}
},

{/*"r"*/
{"     "},
{"     "},
{" *** "},
{"*   *"},
{"*    "},
{"*    "},
{"*    "}
},

{/*"s"*/
{"     "},
{"     "},
{" ****"},
{"*    "},
{" *** "},
{"    *"},
{"**** "}
},

{/*"t"*/
{"     "},
{"     "},
{"  *  "},
{"*****"},
{"  *  "},
{"  *  "},
{"  ***"}
},

{/*"u"*/
{"     "},
{"     "},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"v"*/
{"     "},
{"     "},
{"*   *"},
{"*   *"},
{"*   *"},
{" * * "},
{"  *  "}
},

{/*"w"*/
{"     "},
{"     "},
{"*   *"},
{"*   *"},
{"*   *"},
{"* * *"},
{" * * "}
},

{/*"x"*/
{"     "},
{"     "},
{"*   *"},
{" * * "},
{"  *  "},
{" * * "},
{"*   *"}
},

{/*"y"*/
{"     "},
{"     "},
{"*   *"},
{" * * "},
{"  *  "},
{"  *  "},
{"**   "}
},

{/*"z"*/
{"     "},
{"     "},
{"*****"},
{"    *"},
{"  *  "},
{"*    "},
{"*****"}
},

{/*"One"*/
{"  *  "},
{" **  "},
{"* *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"*****"}
},

{/*"Two"*/
{"**** "},
{"    *"},
{"   * "},
{"  *  "},
{" *   "},
{"*    "},
{"*****"}
},

{/*"Three"*/
{"**** "},
{"    *"},
{"    *"},
{"**** "},
{"    *"},
{"    *"},
{"**** "}
},

{/*"Four"*/
{"   **"},
{"  * *"},
{" *  *"},
{"*****"},
{"   * "},
{"   * "},
{"   * "}
},

{/*"Five"*/
{"*****"},
{"*    "},
{"*    "},
{"**** "},
{"    *"},
{"    *"},
{"**** "}
},

{/*"Six"*/
{" ****"},
{"*    "},
{"*    "},
{"**** "},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"Seven"*/
{"*****"},
{"    *"},
{"    *"},
{"   * "},
{"  *  "},
{" *   "},
{"*    "}
},

{/*"Eight"*/
{" *** "},
{"*   *"},
{"*   *"},
{" *** "},
{"*   *"},
{"*   *"},
{" *** "}
},

{/*"Nine"*/
{" *** "},
{"*   *"},
{"*   *"},
{" ****"},
{"    *"},
{"    *"},
{"**** "}
},

{/*"Zero"*/
{"*****"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*   *"},
{"*****"}
},

{/*"Semi-colon"*/
{" **  "},
{" **  "},
{"     "},
{"     "},
{" **  "},
{" **  "},
{"*    "}
},

{/*"Question mark"*/
{" *** "},
{"*   *"},
{"    *"},
{"  *  "},
{"  *  "},
{"     "},
{"  *  "}
},

{/*"Exclamation Mark"*/
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"     "},
{"  *  "}
},

{/*"Colon"*/
{"     "},
{" **  "},
{" **  "},
{"     "},
{" **  "},
{" **  "},
{"     "}
},

{/*"Full-stop"*/
{"     "},
{"     "},
{"     "},
{"     "},
{"     "},
{" **  "},
{" **  "}
},

{/*"Comma"*/
{"     "},
{"     "},
{"     "},
{"     "},
{" **  "},
{" **  "},
{"*    "}
},

{/*"Space"*/
{"     "},
{"     "},
{"     "},
{"     "},
{"     "},
{"     "},
{"     "}
},

{/*Speech-mark*/
{"* *  "},
{"* *  "},
{"     "},
{"     "},
{"     "},
{"     "},
{"     "}
},

{/*Forward-slash*/
{"     "},
{"     "},
{"    *"},
{"   * "},
{"  *  "},
{" *   "},
{"*    "}
},

{/*Back-slash*/
{"     "},
{"     "},
{"*    "},
{" *   "},
{"  *  "},
{"   * "},
{"    *"}
},

{/*Dash*/
{"     "},
{"     "},
{"     "},
{"*****"},
{"     "},
{"     "},
{"     "}
},

{/*Plus*/
{"     "},
{"  *  "},
{"  *  "},
{"*****"},
{"  *  "},
{"  *  "},
{"     "}
},

{/*Under-score*/
{"     "},
{"     "},
{"     "},
{"     "},
{"     "},
{"     "},
{"*****"}
},

{/*Left-arrow*/
{"    *"},
{"   * "},
{" *   "},
{"*    "},
{" *   "},
{"   * "},
{"    *"}
},

{/*Right-arrow*/
{"*    "},
{"  *  "},
{"    *"},
{"    *"},
{"   * "},
{"  *  "},
{"*    "}
},

{/*Left-square-bracket*/
{"*****"},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*    "},
{"*****"}
},

{/*Right-square-bracket*/
{"*****"},
{"    *"},
{"    *"},
{"    *"},
{"    *"},
{"    *"},
{"*****"}
},

{/*Left-bracket*/
{"    *"},
{"  *  "},
{"*    "},
{"*    "},
{"*    "},
{"  *  "},
{"    *"}
},

{/*Right-bracket*/
{"*    "},
{"  *  "},
{"    *"},
{"    *"},
{"    *"},
{"  *  "},
{"*    "}
},

{/*Equals*/
{"     "},
{"     "},
{"*****"},
{"     "},
{"*****"},
{"     "},
{"     "}
},

{/*Upwards-arrow*/
{"  *  "},
{" * * "},
{"*   *"},
{"     "},
{"     "},
{"     "},
{"     "}
},

{/*Wavey-dash*/
{"     "},
{"     "},
{"     "},
{" *  *"},
{"*  * "},
{"     "},
{"     "}
},

{/*Vertical-line*/
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "},
{"  *  "}
},

{/*Left-Curly-brace*/
{"  * *"},
{" *   "},
{" *   "},
{"*    "},
{" *   "},
{" *   "},
{"  * *"}
},

{/*Right-Curly-brace*/
{"* *  "},
{"   * "},
{"   * "},
{"    *"},
{"   * "},
{"   * "},
{"* *  "}
},

{/*Hash-key*/
{"  * *"},
{" * * "},
{"*****"},
{"*****"},
{"* *  "},
{"* *  "},
{"     "}
},

{/*Divide-symbol*/
{"     "},
{"    *"},
{" * * "},
{"  *  "},
{" * * "},
{"*    "},
{"     "}
},

{/*Star*/
{"  *  "},
{"*****"},
{"* * *"},
{"     "},
{"     "},
{"     "},
{"     "}
},
};//End of array list.

char italics_array[10][7][7]= {
{/*Italics array*/
{"      \0"},
{"     \0 "},
{"    \0  "},
{"   \0   "},
{"  \0    "},
{" \0     "},
{"\0      "}
},

{
{"\0      "},
{" \0     "},
{"  \0    "},
{"   \0   "},
{"    \0  "},
{"     \0 "},
{"      \0"}
},
};//End of italics array.

int main ()
{//Start of main function.

  printf("Enter your personal banner: ");                                 //Start, prompt user to enter text.

/********************************************************************
 * The while loop will loop around my for and switch statements     *
 * so that when there is input it will loop back and allow the user *
 * to enter as many lines as they want, and terminate with the      *
 * \n known as the enter key.                                       *
 ********************************************************************/
    while (1){

    fgets(line, sizeof(line), stdin);                                     //This will read the keyboard input.
    printf("Size of line: [%lu]\n", strlen(line) -1);                     //This will print out the user input value.

/************************************************************************
 * If the line is equal to 1 it will terminate the while loops          *
 * the value 1 is the size of the string, 1 would be the null character *
 * that is stored at the end of the string.                             *
 ************************************************************************/
        if (strlen(line) <= 1){//Start of if loop.
        printf("Program Terminated!\n");                                  //Print out message to prompt user.
        break;                                                            //Program will terminate it loop statement is met.
        }//End of loop.

/************************************************************************************
 * for loop will loop through the array using string and check,                     *
 * when a character is entered for example, A then the switch statement has been    *
 * used to assign the input to the appropriate place of the array that contains the *
 * representation of the letter A.                                                  *
 ************************************************************************************/
    for (string = 0; string <= 6; string++){
        for (check = 0; line[check] != '\0'; check++){

          switch (line[check]) {
            case 'A':
            printf("%s ", main_array[0][string]);
            break;
            case 'B':
            printf("%s ", main_array[1][string]);
            break;
            case 'C':
            printf("%s ", main_array[2][string]);
            break;
            case 'D':
            printf("%s ", main_array[3][string]);
            break;
            case 'E':
            printf("%s ", main_array[4][string]);
            break;
            case 'F':
            printf("%s ", main_array[5][string]);
            break;
            case 'G':
            printf("%s ", main_array[6][string]);
            break;
            case 'H':
            printf("%s ", main_array[7][string]);
            break;
            case 'I':
            printf("%s ", main_array[8][string]);
            break;
            case 'J':
            printf("%s ", main_array[9][string]);
            break;
            case 'K':
            printf("%s ", main_array[10][string]);
            break;
            case 'L':
            printf("%s ", main_array[11][string]);
            break;
            case 'M':
            printf("%s ", main_array[12][string]);
            break;
            case 'N':
            printf("%s ", main_array[13][string]);
            break;
            case 'O':
            printf("%s ", main_array[14][string]);
            break;
            case 'P':
            printf("%s ", main_array[15][string]);
            break;
            case 'Q':
            printf("%s ", main_array[16][string]);
            break;
            case 'R':
            printf("%s ", main_array[17][string]);
            break;
            case 'S':
            printf("%s ", main_array[18][string]);
            break;
            case 'T':
            printf("%s ", main_array[19][string]);
            break;
            case 'U':
            printf("%s ", main_array[20][string]);
            break;
            case 'V':
            printf("%s ", main_array[21][string]);
            break;
            case 'W':
            printf("%s ", main_array[22][string]);
            break;
            case 'X':
            printf("%s ", main_array[23][string]);
            break;
            case 'Y':
            printf("%s ", main_array[24][string]);
            break;
            case 'Z':
            printf("%s ", main_array[25][string]);
            break;
            case 'a':
            printf("%s ", main_array[26][string]);
            break;
            case 'b':
            printf("%s ", main_array[27][string]);
            break;
            case 'c':
            printf("%s ", main_array[28][string]);
            break;
            case 'd':
            printf("%s ", main_array[29][string]);
            break;
            case 'e':
            printf("%s ", main_array[30][string]);
            break;
            case 'f':
            printf("%s ", main_array[31][string]);
            break;
            case 'g':
            printf("%s ", main_array[32][string]);
            break;
            case 'h':
            printf("%s ", main_array[33][string]);
            break;
            case 'i':
            printf("%s ", main_array[34][string]);
            break;
            case 'j':
            printf("%s ", main_array[35][string]);
            break;
            case 'k':
            printf("%s ", main_array[36][string]);
            break;
            case 'l':
            printf("%s ", main_array[37][string]);
            break;
            case 'm':
            printf("%s ", main_array[38][string]);
            break;
            case 'n':
            printf("%s ", main_array[39][string]);
            break;
            case 'o':
            printf("%s ", main_array[40][string]);
            break;
            case 'p':
            printf("%s ", main_array[41][string]);
            break;
            case 'q':
            printf("%s ", main_array[42][string]);
            break;
            case 'r':
            printf("%s ", main_array[43][string]);
            break;
            case 's':
            printf("%s ", main_array[44][string]);
            break;
            case 't':
            printf("%s ", main_array[45][string]);
            break;
            case 'u':
            printf("%s ", main_array[46][string]);
            break;
            case 'v':
            printf("%s ", main_array[47][string]);
            break;
            case 'w':
            printf("%s ", main_array[48][string]);
            break;
            case 'x':
            printf("%s ", main_array[49][string]);
            break;
            case 'y':
            printf("%s ", main_array[50][string]);
            break;
            case 'z':
            printf("%s ", main_array[51][string]);
            break;
            case '1':
            printf("%s ", main_array[52][string]);
            break;
            case '2':
            printf("%s ", main_array[53][string]);
            break;
            case '3':
            printf("%s ", main_array[54][string]);
            break;
            case '4':
            printf("%s ", main_array[55][string]);
            break;
            case '5':
            printf("%s ", main_array[56][string]);
            break;
            case '6':
            printf("%s ", main_array[57][string]);
            break;
            case '7':
            printf("%s ", main_array[58][string]);
            break;
            case '8':
            printf("%s ", main_array[59][string]);
            break;
            case '9':
            printf("%s ", main_array[60][string]);
            break;
            case '0':
            printf("%s ", main_array[61][string]);
            break;
            case ';':
            printf("%s ", main_array[62][string]);
            break;
            case '?':
            printf("%s ", main_array[63][string]);
            break;
            case '!':
            printf("%s ", main_array[64][string]);
            break;
            case ':':
            printf("%s ", main_array[65][string]);
            break;
            case '.':
            printf("%s ", main_array[66][string]);
            break;
            case ',':
            printf("%s ", main_array[67][string]);
            break;
            case ' ':
            printf("%s ", main_array[68][string]);
            break;
            case '"':
            printf("%s ", main_array[69][string]);
            break;
            case '/':
            printf("%s ", main_array[70][string]);
            break;
            case '\\':
            printf("%s ", main_array[71][string]);
            break;
            case '-':
            printf("%s ", main_array[72][string]);
            break;
            case '+':
            printf("%s ", main_array[73][string]);
            break;
            case '_':
            printf("%s ", main_array[74][string]);
            break;
            case '<':
            printf("%s ", main_array[75][string]);
            break;
            case '>':
            printf("%s ", main_array[76][string]);
            break;
            case '[':
            printf("%s ", main_array[77][string]);
            break;
            case ']':
            printf("%s ", main_array[78][string]);
            break;
            case '(':
            printf("%s ", main_array[79][string]);
            break;
            case ')':
            printf("%s ", main_array[80][string]);
            break;
            case '=':
            printf("%s ", main_array[81][string]);
            break;
            case '^':
            printf("%s ", main_array[82][string]);
            break;
            case '~':
            printf("%s ", main_array[83][string]);
            break;
            case '{':
            printf("%s ", main_array[85][string]);
            break;
            case '}':
            printf("%s ", main_array[86][string]);
            break;
            case '#':
            printf("%s ", main_array[87][string]);
            break;
            case '%':
            printf("%s ", main_array[88][string]);
            break;
            case '*':
            printf("%s ", main_array[89][string]);
            break;

/*****************************************************************************************
 * The case by default will be the "&" symbol and both lower and upper-case "i" will     *
 * be assigned to the end of it, but when capital "I" is entered it will print the first *
 * italics array that till indent the code after "&I" and then the code will be reversed *
 * to standard straight text when it's followed by a "&i".                               *
 *****************************************************************************************/
            case '&': //The case is "&".
              if (line[check+1] == 'I'){//Open if statement.
                printf("%s", italics_array[0][string]);                             //"I" will be added after the "&" symbol.
              check++;
              }//Close if statement.
              else if (line[check+1] == 'i'){//Open if statement.
                printf("%s", italics_array[1][string]);
              check++;

              }//Close if statement.
            };
        };
    printf("\n");//This will print each line of the array on a separate line.
    };
    printf("Enter another banner ");                                                //Prompt the user to enter more text.
    printf("or press (Enter) to terminate the program: ");                          //Prompt user on how to kill the program.
};

//The value 0 should be returned if and only if there are no errors.
  return (0);
}// End of main function.

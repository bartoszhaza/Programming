					/******************************************************************
					*           Procedural Programming [1711] Coursework 2            *
					*               Author: Bartosz Haza [200959739]                  *
					*                       Dr Hamish Carr                         	  *
				    *																  *
					*	In the following program I will be working with file input    *
					*		and output alongside conversion from Binary to ASCII.     *
					*******************************************************************/

#include <stdio.h> //Standard I/O header.
#include <string.h> //Standard string header.
#include <stdlib.h> //Standard library header.

unsigned char *buffer; //Buffer variable pointer.
char magicNumber[2]; //Magic number variable.
char commentLine[2]; //The comment line in the file.
int number; //This is the fourth line in the header "255"
int height; //One of the two numbers on line 3.
int width; //One of the two numbers on line 3.
int ConversionLine; //Variable that equals to height by width.
int i; //Condition variable for first for loop

//This is the usual main function.
int main(int argc, char *argv[])
{//Start of Part 1.
	FILE 	*input_file; //Input file pointer.

	FILE  	*output_file; //Input file pointer.

 	input_file = fopen(argv[1], "rb"); //Read the input file with fopen and read it as a binary.
	//output_file = fopen(argv[2], "w"); //Write output with fopen and the output will has the possibility of being written.
	
	//Command Line Parameters.         
	if (argc == 1){//Statement 1.
		printf("No arguments.%s\n", argv[0]); //If no arguments are entered it will return the message.
	}//End of statement 1.

	else if (argc > 3){//Statement 2.
		printf("Too many arguments have been entered.%s\n", argv[0]); //If too many arguments are entered it will print the following message.
	}//End of statement 2.

	else if (input_file == NULL){//Statement 3. 
		printf("The file does not exist.\n"); //The error message.
		return(-1); //Anything that is not 0 is an error so this will print an error.
	} //Statement 3.

	else if (argc == 2) {//Start of Part 2.
	fscanf(input_file, "%s", magicNumber); //This will read the magic number.

	fscanf(input_file, "%s", commentLine); //This will scan the comment line for the file that is entered in the second word.

	while(fgetc(input_file) != '\n'){//Start of Loop.
	//While the input_file is not equal to new line it will keep looping.
	}//End of loop.

	fscanf(input_file, "%d", &height); //The input will be scanned for the height variable.
	fscanf(input_file, "%d\n", &width); //The input will be scanned for the width.
	fscanf(input_file, "%d\n", &number); //The input will be scanned for the number.
	
	ConversionLine = height * width * sizeof(unsigned char); //Conversion for height and width.
	unsigned char *buffer = malloc(height * width * sizeof(unsigned char)); //Defenition of buffer.
	fread(buffer,sizeof(unsigned char), ConversionLine, input_file); //Fread will read the 

	printf("%s\n", magicNumber); //The magic number will be printed.
	printf("%s\n", commentLine); //The commentLine will be printed.
	printf("%d ", height); //The height and width will be printed on the same line.
    printf("%d\n", width); //The width will be printed.
	printf("%d\n", number); //The fourth line with the expected "255" value will be printed.
	
	for (i = 0; i < ConversionLine; i++){//Start of for loop 1
		printf("%d ", *(buffer+i)); //This will print the buffer for the binary or ascii file when it's entered, it will loop through incrementing by one.
	}//End of first for loop.

	fclose(input_file); //Closes the inpur file.
	//fclose(output_file); //Closes the output file.

	printf("\n"); //Will print a new line.

	return (0); //Return 0 if no erros are found.
}// End of Part 2. 

	else if (argc == 3){//Start of Part 3.
			output_file = fopen(argv[2], "w");

		fscanf(input_file, "%s", magicNumber); //This will read 
		fputs("P2\n",output_file); //This will make the magicNumber P2 which is used for binary and P5 is used for ASCII.

		fscanf(input_file, "%s", commentLine); //This will scan in the comment line from the file that is inputted.
		fprintf(output_file, "%s\n", commentLine); //This will print out the comment line for the output file.

		while(fgetc(input_file) != '\n'){//Start of Loop.
		//While the input_file is not equal to new line it will keep looping.
		}//End of loop.

		fscanf(input_file, "%d", &height); //The input will be scanned for the height variable.
		fscanf(input_file, "%d\n", &width); //The input will be scanned for the width.
		fprintf(output_file, "%d %d\n", height, width);
		fscanf(input_file, "%d\n", &number); //The input will be scanned for the number.
		fprintf(output_file, "%d\n", number);

		ConversionLine = height * width * sizeof(unsigned char); //Conversion for height and width.
		unsigned char *buffer = malloc(height * width * sizeof(unsigned char)); //Defenition of buffer.
		fread(buffer,sizeof(unsigned char), ConversionLine, input_file); //Fread will read the 

		printf("%s\n", magicNumber); //The magic number will be printed.
		printf("%s\n", commentLine); //The commentLine will be printed.
		printf("%d ", height); //The height and width will be printed on the same line.
    	printf("%d\n", width); //The width will be printed.
		printf("%d\n", number);
		for (i = 0; i < ConversionLine; i++){//Start of for loop 1
			printf("%d ", *(buffer+i)); //Buffer for the first file that is entered.
			fprintf(output_file, "%d ", *(buffer+i)); //Buffer the second file that is entered as one of the parameters.

		}
		fclose(output_file); //This will close the output file.
		printf("\n"); //Print new lines. 

		return (0); //Return 0 if there are no errors in the code.
	}//End of P2art 3.

}

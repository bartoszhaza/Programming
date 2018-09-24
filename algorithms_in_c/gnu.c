#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void gnuPlot(int* elementArray, int userInput){
	
	FILE *fp = fopen("algorithm.gnu", "w"); // write a new file .gnu
	int i; // incrementing variable
	fprintf(fp, "unset key\n");
	fprintf(fp, "set xlabel 'Array size'\n");
	fprintf(fp, "set ylabel 'Integer Value'\n");

	// this will set the graphs standard coordinates to 100 anything above
	// that will extend the graph automatically
	if(userInput < 100){
		userInput = userInput + 100;
	}
	fprintf(fp, "plot [0:%d][0:%d] 'algorithm.out' with lp\n", userInput, userInput);

	FILE *second_file = fopen("algorithm.out", "w"); // write the .out file that will be opened by gnu
	for(i=0; i<userInput; i++){
		fprintf(second_file, " %d %d\n", i, elementArray[i]);

	}
	fclose(fp); // close the file
	fclose(second_file); // close the file
	system("gnuplot -p -c 'algorithm.gnu'");
}
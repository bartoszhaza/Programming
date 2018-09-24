////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					    File: main.c				      //
//														  //
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char **argv){
	clock_t start, end; // function for start and end of timing
	double time_spent; // variable to store the time spent for the program to execture
	int *elementArray; // pointer to the array that will be holding the elements
	int i; // integer to loop through the loop to sort the numbers
	int userInput; // user input for the number of elements
	int choice; // the choice for which algorithm the user can choose
	while (1){
   		fgets(line, sizeof(line), stdin);                                     //This will read the keyboard input.
    	printf("Size of line: [%lu]\n", strlen(line) -1);                     //This will print out the user input value.
        	if (strlen(line) <= 1){//Start of if loop.
        	printf("Program Terminated!\n");                                  //Print out message to prompt user.
       		break;                                                            //Program will terminate it loop statement is met.
        }//End of loop.

	printf("Enter the size of the array: "); // user prompt
	scanf("%d", &userInput); // scan the user input
	elementArray = (int* )calloc(userInput, sizeof(int)); // allocate the same size for the array as the number of elements

	//////////////////////////////////////////////////////////////////
	//																//
	//	prompt for the user to choose which sorting algorithm he	//
	// 	would like to use to sort the numbers randomly generated	//
	//																//
	//////////////////////////////////////////////////////////////////
	printf("1) Quick sort\n");
	printf("2) Bubble sort\n");
	printf("3) Selection sort\n");
	printf("4) Insertion sort\n");
	printf("5) Multiple sorting Alhorithms\n");
	printf("Choose a sorting Algorithm: ");
	scanf("%d", &choice); // scan user input
	
	//////////////////////////////////////////////////////////////////
	//																//
	//	while the choice is not 1, 2 or 3 then the prompt			//
	//	along with an error message will be displayed with the		//
	//	possibility to re-enter a choice							//
	//																//
	//////////////////////////////////////////////////////////////////
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
		printf("Invalid Choice!\n");
		printf("Try again!\n");
		printf("1) Quick sort\n");
		printf("2) Bubble sort\n");
		printf("3) Selection sort\n");
		printf("4) Insertion sort\n");
		printf("5) Multiple sorting Alhorithms\n");
		printf("Choose a sorting Algorithms: ");
		scanf("%d", &choice); // scan user input
	}
	
	//////////////////////////////////////////////////////////////////
	//																//
	//	for each choice the same process will be carried out the	//
	//	only difference will be that a different sorting algorithm	//
	//	will be called												//
	//																//
	//////////////////////////////////////////////////////////////////	
	if(choice == 1){
		start = clock(); // start timer clock
		srand(time(NULL)); // random numbers
		for(i=0; i<userInput; i++){ // random numbers generated depending on the array size entered
			elementArray[i] = rand() %userInput + 1; // assign each array point a random number
		}
		mainQuickSort(elementArray, userInput); // quick sort called
		printf("Randomly generated sorted numbers: \n"); // message that numbers are generated
		for(i=0; i<userInput; i++){ 
			printf("Array[%d] = %d\n", i, elementArray[i]); // print the array and its elements
		}
		end = clock(); // stop counting the execution time
		time_spent = (double)(end - start) / CLOCKS_PER_SEC; // formula to work out the time
		printf("Time taken for quicksort [%f] seconds \n", time_spent); // print the results
		gnuPlot(elementArray, userInput); // plot the sorted graph 
	}

	else if(choice == 2){
		start = clock();
		srand(time(NULL));
		for(i=0; i<userInput; i++){
			elementArray[i] = rand() %userInput + 1;
		}
		bubbleSort(elementArray, userInput);
		printf("Randomly generated sorted numbers: \n");
		for(i=0; i<userInput; i++){
			printf("Array[%d] = %d\n", i, elementArray[i]);
		}
		end = clock();
		time_spent = (double)(end - start) / CLOCKS_PER_SEC;
		printf("Time taken for bubble sort [%f] seconds \n", time_spent);
		gnuPlot(elementArray, userInput);
	}

	else if(choice == 3){
		start = clock();
		srand(time(NULL));
		for(i=0; i<userInput; i++){
			elementArray[i] = rand() %userInput + 1;
		}
		selectionSort(elementArray, userInput);
		printf("Randomly generated sorted numbers: \n");
		for(i=0; i<userInput; i++){
			printf("Array[%d] = %d\n", i, elementArray[i]);
		}
		end = clock();
		time_spent = (double)(end - start) / CLOCKS_PER_SEC;
		printf("Time taken for selection sort [%f] seconds \n", time_spent);
		gnuPlot(elementArray, userInput);
	}

	else if(choice == 4){
		start = clock();
		srand(time(NULL));
		for(i=0; i<userInput; i++){
			elementArray[i] = rand() %userInput + 1;
		}
		insertionSort(elementArray, userInput);
		printf("Randomly generated sorted numbers: \n");
		for(i=0; i<userInput; i++){
			printf("Array[%d] = %d\n", i, elementArray[i]);
		}
		end = clock();
		time_spent = (double)(end - start) / CLOCKS_PER_SEC;
		printf("Time taken for insertion sort [%f] seconds \n", time_spent);
		gnuPlot(elementArray, userInput);
	}

	else if(choice == 5){
		int innerChoice;
		while(innerChoice != 1 && innerChoice != 2 && innerChoice != 3 && innerChoice != 4 && innerChoice != 5 && innerChoice != 5){
			printf("Choose which Algorithms to compare\n");
			printf("1) Quick sort and Bubble sort\n");
			printf("2) Quick sort and Insertion sort\n");
			printf("3) Quick sort and Selection sort\n");
			printf("4) Bubble sort and Selection sort\n");
			printf("5) Bubble sort and Insertion sort\n");
			printf("6) Insertion sort and Selection sort\n");
			printf("Choose a sorting Algorithms: ");
			scanf("%d", &innerChoice);
		}
		if(innerChoice == 1){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			mainQuickSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for quick sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			bubbleSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for bubble sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
		if(innerChoice == 2){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			mainQuickSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for quick sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			insertionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for insertion sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
		if(innerChoice == 3){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			mainQuickSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for quick sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			selectionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for selection sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
		if(innerChoice == 4){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			bubbleSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for bubble sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			selectionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for selection sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
		if(innerChoice == 5){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			bubbleSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for bubble sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			insertionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for insertion sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
		if(innerChoice == 6){
			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			insertionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for insertion sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);

			start = clock();
			srand(time(NULL));
			for(i=0; i<userInput; i++){
				elementArray[i] = rand() %userInput + 1;
			}
			selectionSort(elementArray, userInput);
			printf("Randomly generated sorted numbers: \n");
			for(i=0; i<userInput; i++){
				printf("Array[%d] = %d\n", i, elementArray[i]);
			}
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time taken for selection sort [%f] seconds \n", time_spent);
			gnuPlot(elementArray, userInput);
		}
	}

	free(elementArray); // free the array

	return 0; // return 0 if there are no problems, standard in each main
}
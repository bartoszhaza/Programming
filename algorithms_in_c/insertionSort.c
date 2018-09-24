////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					File: insertionSort.c				  //
//														  //
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

//////////////////////////////////////////////////////////////
//														 	//
//	insertion sort works in a way that at first the			//
//	first element would be shifted to the right it would	//
//	then be followed by other numbers in the sequence		//
//	if the number is lower than the previous one then the	//
//	previous number will be shifted to the left and so on	//
//														 	//
//////////////////////////////////////////////////////////////
void insertionSort(int *elementArray, int userInput){
	int i; // incrementing variable
	int x; // loop variable
	int temp; // variable to hold the array size

	for(i=1; i<=userInput; i++){ // i is assigned to 1 as we start with one element
		x = i; // assign x to i
		while(x>0 && elementArray[x] < elementArray[x-1]){
			temp = elementArray[x];
			elementArray[x] = elementArray[x-1];
			elementArray[x-1] = temp;
			x--;
		}
	}
}
////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					File: bubbleSort.c	       			  //
//														  //
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

///////////////////////////////////////////////////////////
//														 //
//	bubble sort works in a way where it compares two     //
//  values that are next to each other and if the        //
//  one on the left is larger than the one on the right  //
//  then the value will be moved to the right, this      //
//  would happen with each number and the process would  //
//  be repeated until the numbers are in order making    //
//  this the slowest out of the three sorting algorithms //
//  that I have chosen to implement						 //
//														 //
///////////////////////////////////////////////////////////
void bubbleSort(int *elementArray, int userInput){
	int x; // variable used for my for loops 
	int i; // variable used to store a value of a loop

	for(i=0; i<userInput; i++){ // loop through until i is less than the desired array size
		for(x=0; x<userInput; x++){ // loop through again as long as x is less than the user in
			if(elementArray[x]>elementArray[x+1]){
				int temp = elementArray[x+1]; // integer that holds the specified size of the array + 1
				elementArray[x+1] = elementArray[x]; // array size + 1 is equal to the array size
				elementArray[x] = temp; // assign the array size to variable temp
			}
		}
	}
}
////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					File: selectionSort.c				  //
//														  //
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

//////////////////////////////////////////////////////////////
//														 	//
//	selection sort works in a way that it splits the		//
//	integers into to tables, sorted and unsorted, the way	//
//	this algorithm sorts the numbers is by starting with the//	
//	first number in the unsorted list and making that the	//
//	new minimum and then it would go through the list		//
//	and everytime a number is smaller than the current it 	//
//	becomes the current number until there is no number		//
//	smaller than that current minimum number and then that	//
//	number would be placed at the start of the sorted list	//
//	this process is then repeated							//
//														 	//
//////////////////////////////////////////////////////////////
void selectionSort(int *elementArray, int userInput){
	int i; // incrementing variable
	int x; // loop variable
	int minimum_index;
	int temp; // variable to hold the array size

	for(i=0; i<userInput; i++){
		 minimum_index = i;
		for(x=i; x<userInput; x++){
			if(elementArray[minimum_index]>elementArray[x]){
				minimum_index = x;
			}

		}
		temp = elementArray[i];
		elementArray[i] = elementArray[minimum_index];
		elementArray[minimum_index] = temp;
	}
}
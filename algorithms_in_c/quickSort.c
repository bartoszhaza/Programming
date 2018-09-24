////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					File: quickSort.c				      //
//														  //
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

//////////////////////////////////////////////////////////////
//														 	//
//	quicksort works in a way that if starts of with			//
//	something called a pivot that will go through			//
//	each integer and compare it to itself and anything		//
//	that is greater than it will stay in its original		//
//	place and anything that is less will be but on the		//
//	other side of the wall, once there is nothing smaller	//
//	than the current pivot it will be placed between		//
//	the pivots smallest number and all other numbers that	//
//	are greater than it and another pivot will be chosen	//
//	and the process will be repeated						//
//														 	//
//////////////////////////////////////////////////////////////
void mainQuickSort(int *elementArray, int userInput){
	quickSort(elementArray, 0, userInput - 1);
}

void quickSort(int *elementArray, int first, int last){
	int pivot; // the pivot
	int x; // loop intege
	int temp; // temp e.g. integer to hold the array value
	int i; // loop integer

	if(first < last){ // if the first integer is lower than the last one
		pivot = first; // the pivot will be the assigned to the first number
		i = first; // i will be used as the first
		x = last; // x will be used as the last

		while(i < x){
			while(elementArray[i] <= elementArray[pivot] && i < last)
				i++; // i incremented if the array size i is less than or equal to the array size of the pivot and i is less than the last
			while(elementArray[x] > elementArray[pivot])
				x--; // decremented if the array size x is greater than array of pivot size
			if(i < x){
				temp = elementArray[i]; // assign the array size i to the temp variable
				elementArray[i] = elementArray[x]; // array size i is equal to array size x
				elementArray[x] = temp; // array size x is equal to the temp variable
			}
		}
		temp = elementArray[pivot]; // now assign the pivot to temp
		elementArray[pivot] = elementArray[x]; // pivot is equal to array x
		elementArray[x] = temp; // array x is equal to temp
		quickSort(elementArray, first, x - 1);
		quickSort(elementArray, x + 1, last);
	}
}
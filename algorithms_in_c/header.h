////////////////////////////////////////////////////////////
// 														  //
//					 Programming Proxect                  //
//			Sorting and benchmarking Algorithms	 	      //
//						 Coursework 2					  //
//				 Author: Bartosz Haza (SC15BH)		      //
//					   File: header.h					  //
//														  //
////////////////////////////////////////////////////////////

// in the header file each function that is in each .c
// file will be called and then compiled together 
// through the makefile
void mainQuickSort(int *elementArray, int userInput);
void quickSort(int *elementArray, int first, int last);
void bubbleSort(int *elementArray, int userInput);
void selectionSort(int *elementArray, int userInput);
void insertionSort(int *elementArray, int userInput);
void gnuPlot(int* elementArray, int userInput);

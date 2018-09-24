////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Bartosz Haza (200959739)						  //
//						Coursework 1 (Programming Project)					  //
//								Main file (.c)							      //
//																			  //
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structqNode.h"

// main procedure
int main(int argc, char **argv){
	Node *head = makeNode(0.0, 0.0, 0);	// create the head node: level 0
	makeChildren(head);	// split to level 1
	//destroyNode(head); // function called inside the main to destroy the nodes made
	makeChildren(head->child[2]);	// split one node to level 2

////////////////////////////////////////////////////////////////////////////////
//																	          //
//				The function here will be called to perform their			  //
//				task of writing the leaf, making the children etc.			  //
//																			  //
////////////////////////////////////////////////////////////////////////////////
	NodeList nList;
	init_list(&nList);
	leafList(head, &nList);
	increasePoint(&nList);
	leafList(head, &nList);
	writeLeaf(&nList);

	return 0; // return 0 if there are no errors found in the main
}

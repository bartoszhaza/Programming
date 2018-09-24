////////////////////////////////////////////////////////////////////////////////
//																																						//
//												Bartosz Haza (200959739)														//
//										Coursework 1 (Programming Project)											//
//                           Functions file (.c)                              //
//																																						//
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structqNode.h"

////////////////////////////////////////////////////////////////////////////////
//																																						//
//						Part 1 (Creating the Leaf Node List inside the QuadTree)				//
//									                                                          //
////////////////////////////////////////////////////////////////////////////////

// makeChildren function to make the children
void makeChildren(Node *parent){

  // parent data
  double x = parent->xy[0];
  double y = parent->xy[1];
  int level = parent->level;

  // child edge length
  double hChild = pow(2.0, - (level+1));

  // create children at level+1, 4 children will be created
  parent->child[0] = makeNode(x,y, level + 1);
  parent->child[1] = makeNode(x + hChild, y, level + 1);
  parent->child[2] = makeNode(x + hChild, y + hChild, level + 1);
  parent->child[3] = makeNode(x,y + hChild, level + 1);

  return;
}

// function to printout the node
void printOut(FILE *fp, Node *node){

  // node data
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

// open a file and prepare to write
void writeTree(Node *head)
  {
	FILE *fp = fopen("quad.out", "w+"); // write quad.out
	writeNode(fp,head); // writeNode fp which is the pointer to the FILE  and the head
	fclose(fp); // close the file
	return; // return function
}

// recursively search for leaf nodes
void writeNode(FILE *fp, Node *node){
	int i; // variable i for looping through the for statement

	if(node->child[0] == NULL)
		printOut(fp,node); // printOut fp and node if condition of if statement met
	else{ // otherwise
		for(i=0; i<4; ++i){ // for statements parameters
			writeNode(fp, node->child[i]); // writeNode, pointer fp node pointing to child[i] "i" being the variable incremented
		}
	}
	return; // return function
}

// function for destroying the node
void destroyNode(Node *node){
	int i; // variable to loop through

	if(node->child[0] == NULL) // if condition of if statement met
		free(node); // free node
	else{ // otherwise
		for(i=0; i<4; ++i){ // for the conditions of the statement
			destroyNode(node->child[i]); // destroy the node pointing to child[i] 'i' the variable incremented
		}
	}
	return; // return function
}

// function for making a new node
Node *makeNode(double x, double y, int level){
	int i; // variable to loop

	Node *node = (Node *)malloc(sizeof(Node));

	node->level = level; // node pointing to level is level

	node->xy[0] = x;
	node->xy[1] = y;

	for(i=0; i<4; ++i)
		node->child[i] = NULL;

	return node; // return node
}

////////////////////////////////////////////////////////////////////////////////

// function to initialise the list
void init_list(NodeList *list){
  list->first_leaf = NULL;
}

// function to add a node
void nodeAdd(Node *node, NodeList *list){
  node->next_leaf = list->first_leaf;
  list->first_leaf = node;
}

// function for the leafList
void leafList(Node *node, NodeList *list){
  int i = 0; // increment variable

  if(node->child[0] == NULL){
    nodeAdd(node, list);
  }
  else {
    for(i = 0; i < 4; ++i){
      leafList(node->child[i],list);
    }
  }
}

// write a new leaf function
void writeLeaf(NodeList *list){
	FILE *fp = fopen("quad.out", "w+"); // write file quad.out
	writeLeafNode(fp,list); //writeLeafNode with fp and list
	fclose(fp); // close file
	return; // returns the function
}

void writeLeafNode(FILE *fp, NodeList *list){
	int i; // variable to increment

  Node *walkNode = list->first_leaf;
  while(walkNode != NULL){
      printOut(fp,walkNode); // printOut fp and walkNode
      if(walkNode -> next_leaf == NULL)
      {
      }
  walkNode = walkNode -> next_leaf;
  }
}

////////////////////////////////////////////////////////////////////////////////
//																																						//
//											Part 2 (Growing the QuadTree)													//
//																																						//
////////////////////////////////////////////////////////////////////////////////
void increasePoint(NodeList *list){
  Node *walkNode = list -> first_leaf; // Node, pointer to walkNode is equal to the list that points to the firs_leaf
  
  // while the walkNode is not equal to NULL
  while(walkNode != NULL){
    makeChildren(walkNode); // make children in walkNode
    walkNode = walkNode -> next_leaf; // walkNode is equal to walkNode pointing to next_leaf
  }
}

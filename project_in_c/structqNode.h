////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Bartosz Haza (200959739)					  //
//							Coursework 1 (Programming Project)    			  //
//									Header file (.h)	  					  //
//																			  //
////////////////////////////////////////////////////////////////////////////////
struct qNode {

	// data structure definition
	// node data
	int level;
	double xy[2];
	struct qNode *child[4];
	struct qNode *next_leaf;

	};

	// data type definition
	typedef struct qNode Node;

////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Second structure list_node	   					  //
//																			  //
////////////////////////////////////////////////////////////////////////////////
struct list_node {
	Node *first_leaf;

};
	typedef struct list_node NodeList;
////////////////////////////////////////////////////////////////////////////////
//																			  //
//				Calling the functions from the file functions.c			      //
//																		      //
////////////////////////////////////////////////////////////////////////////////
void makeChildren(Node *parent);
void printOut(FILE *fp, Node *node);
void writeTree(Node *head);
void writeNode(FILE *fp, Node *node);
void destroyNode(Node *node);
Node *makeNode(double x, double y, int level);
void leafList(Node *node, NodeList *list);
void nodeAdd(Node *node, NodeList *list);
void init_list(NodeList *list);
void writeLeaf(NodeList *list);
void writeLeafNode(FILE *fp, NodeList *list);
void increasePoint(NodeList *list);

#ifndef bbtree_included       /* prevent multiple */
#define bbtree_included



/* Items in binary search tree */
typedef struct BSTItem_s{
  struct BSTItems_s *leftc;
  struct BSTItems_s *rightc;
  char *info;
 } BSTItem;

/* a list of BBItems */
typedef struct {
  BSTItem *head, *cur;
} BSTree;


/* Create a new List */
BSTree *bstAlloc();


/* Add element and key to element in BSTree */
void bstAdd(BSTree *bst, char *i);


/* Print Elements of tree */
void bstPrint(BSTItem *b);

/* remove an element from binary search tree)*/
void bstRemove(BSTree *bst, char *i);


/*Auxiliary to remove the element from a tree */
void removeAux(BSTree *bst, char *i);

/* Auxiliary to add various elements to a tree */
void addTwoc(BSTree *bst, BSTItem *b);

/* Write the names into a file */
void writeFiles(BSTree *bst);

/* Reading the names from a file into a tree */
void readFile(BSTree *bst);

/* Auxiliar to write file */
void writeAux(BSTItem *b, char *i);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bstree.h"

/*create a new tree */
BSTree *bstAlloc()
{
  BSTree *bst = (BSTree *)malloc(sizeof(BSTree));
  bst->head = bst->cur = 0;
 
  return bst;
}

/* Add an element to BSTree */
void bstAdd(BSTree *bst, char *i)
{

  BSTItem *treeN;
  char *icopy;
  BSTItem *b;
  int len;
  int cond;
  int loopExit = 0;
 

  treeN = bst->head;
  
  
  /* find length of namne */
  for(len=0; i[len]; len++)
    ;
  icopy = (char *)malloc(len+1);
  for(len = 0; i[len];len++)  /* copy chars */
    icopy[len] = i[len];
  icopy[len]=0;


 
  b = (BSTItem *)malloc(sizeof(BSTItem));
  b->info = icopy;
  b->leftc = b->rightc = 0;
  /* printf("Created new node \n");*/


  /* Check if tree is empty */
  if(!bst->head){
    bst -> head = b;
    return;
  }

  /*printf("Begin the loop. \n");*/
  while(!loopExit){
    cond=strcmp(icopy, treeN->info);
    /*printf("Comparing with %s\n", treeN->info);*/
    if (cond == 0 ){      /* Repeated value */
      /*printf("Repeated value.\n");*/
      loopExit++;
    }
    else if(cond<0){  /*Looking at the left */
      /* printf("Looking at the left. \n");*/
      if (!treeN->leftc){
	/* No left c add element there */
	treeN->leftc = b;
	loopExit++;
	/* printf("Added to left \n");*/
      }
      else {  /* Not a leaf */
	treeN=treeN->leftc;
	/* printf("Moving left \n");*/
      }}
    else{     /*Looking at the right element */
      if(!treeN->rightc){
	/* No right child add element there */
	treeN->rightc = b;
	loopExit++;
	/* printf("Added to the rigth \n");*/
      }
      else{ /*Not a leaf */
	treeN = treeN->rightc;
	/*printf("Moving to the right \n");*/
      }}}}
	
  
/* Print elements of tree */
void bstPrint(BSTItem *b){
  if (b){
    printf("%s \n", b->info);
    bstPrint(b->leftc);
    bstPrint(b->rightc);}
     }

/* Remove an element */
void bstRemove(BSTree *bst, char *i){
  BSTItem *treeN;
  char *icopy;
  int len;
  int cond;
  int loopExit = 0;
  BSTree *temp;
  treeN = bst->head;
  
  /* find length of namne */
  for(len=0; i[len]; len++)
    ;
  icopy = (char *)malloc(len+1);
  for(len = 0; i[len];len++)  /* copy chars */
    icopy[len] = i[len];
  icopy[len]=0;

  /* Check if tree is empty */
  if(!bst->head){
    /* printf("Empty tree \n");*/
    return;
  }

  /* printf("Begin the loop. \n");*/
  while(!loopExit){
    cond=strcmp(icopy, treeN->info);
    /* printf("Comparing with %s\n", treeN->info);*/
    if (cond == 0 ){      /* Found value */
      /* printf("They match!.\n");*/
      removeAux(bst, icopy);
      loopExit++;}
    else if (cond<0){ /* Looking to the  left  side */
      /* printf("Looking at the left \n");*/
      if (!treeN->leftc){  /* empty to the left */
	printf("Value is not found in tree. \n"); 
	loopExit++;
      }
      else {
	treeN = treeN->leftc;
	/* printf("Moving left \n");*/
      }}
    else {  /* Looking at the right side */
      /* printf("Looking at the right side. \n"); */
      if (!treeN->rightc) { /* Empty to the right */
	printf("Value is not found in tree. \n");
	loopExit++;
      }
      else {
	treeN = treeN->rightc;
	/* printf("Moving to the right. \n"); */
      }}}}
  

void removeAux(BSTree *bst, char *i){
  BSTItem *treeN;
  int cond;
  int loopExit = 0;
  BSTItem *temp;
  BSTItem *parent;
  int twoC = 0;
  treeN = bst->head;

  
  /*  printf("There is a value. \n"); */

  cond=strcmp(i, treeN->info);
  /* Check if the head for special case */
  /*printf("Checking the head \n"); */
  if(cond ==0){
    /* printf("It is in the head \n");*/
    /* Value is in the head */
     if(!treeN->leftc){
       /* printf("No left child \n");*/
      /* No left c */
      if (!treeN->rightc){
	/* printf("No left or right child \n");*/
	/* Special case head is leaf */
	bst->head = 0;
	loopExit++;
      }
      else{
	/* Tree only has a left child */
	bst->head = treeN->rightc;
	loopExit++;}}
    else if (!treeN ->rightc){
      /* Special case it is aleaf */
      bst->head = treeN->leftc;
      loopExit++;
    }
    else {
      temp = treeN->rightc;
      bst->head = treeN->leftc;
      loopExit++;
      twoC++;
    }}

  /* Saving the parent and setting the treeN to the correct side */
  parent = bst->head;
  if (cond<0){
    treeN= treeN->leftc;}
  else {
    treeN = treeN ->rightc;}
  /* printf("Begin loop %d\n", loopExit); */
  while(!loopExit){
    cond=strcmp(i, treeN->info);
    if (cond == 0){
      cond = strcmp(i, parent->info);  // find new cond for parent */
      /* printf("Refound value!\n"); */
      if(!treeN->leftc){
      /* No left c */
	if (!treeN->rightc){
	/* Special case its a leaf */
	  /* printf("It is a leaf\n");*/
	  if (cond < 0){
	    parent->leftc = 0;
	    loopExit++;
	    /* printf (" Clear left side of parent\n");}*/
	  }
	  else {
	    parent ->rightc = 0;
	    loopExit++;
	    /* printf (" Clear right side of parent \n");*/
	  }}
	else {
	  /* Deleted node only had a rigth child */
	  if (cond < 0 ){
	   parent->leftc = treeN->rightc;
	   loopExit++;
	   /*printf("Set right child of treeN to parent left. \n");*/
	  }
	  else {
	    parent->rightc = treeN->rightc;
	    loopExit++;
	    /* printf("Set right child of treeN to parent right. \n");*/
	  }}}
      else if(!treeN->rightc){
	/* Deleted node only had a left child */
	if (cond < 0 ){
	  parent->leftc = treeN -> leftc;
	  loopExit++;
	  /* printf("Set left child of treeN to parent left. \n");*/
}
	else {
	  parent->rightc = treeN -> leftc;
	  loopExit++;
	  /* printf("set rigth child of treeN to parent right. \n");*/
	    }}
      else {
	/* Found item has 2 children */
	twoC++;
	loopExit++;
	temp = treeN->rightc;
	if (cond <0){
	  parent->leftc = treeN->leftc;
	 }
	else {
	  parent->rightc = treeN->leftc;
	}}}
    else{ /* Have not found the correct location yet */
      if (cond < 0){
	cond = strcmp(i, parent->info);  // find new cond for parent */
	treeN = treeN ->leftc;
	if (cond < 0){
	  parent = parent ->leftc;}
	else{
	  parent = parent->rightc;}}
      else {
	cond = strcmp(i, parent->info);  // find new cond for parent */
	treeN = treeN ->rightc;
	if (cond < 0){
	  parent = parent -> leftc;}
	else {
	  parent = parent -> rightc;}}}}

  if (twoC){
    /* The element had two children */
    addTwoc(bst, temp);
  }}

 void addTwoc(BSTree *bst, BSTItem *b){
   /* Combines elements to a tree for those deletes that had two children */
   if (b){
     bstAdd(bst, b->info);
     addTwoc(bst, b->leftc);
     addTwoc(bst, b->rightc);
   }
 }

void readFile(BSTree *bst){
  /* Reading the names from a file */
  FILE *fp;
  char str[2000];
  char* filename = "names.txt";

  fp = fopen(filename, "r");
  if (fp == NULL){
    printf("Could not open file %s", filename);
    return;
  }
  while(fgets(str, 2000, fp)!= NULL){
    bstAdd(bst, str);
    printf("%s", str);}
  fclose(fp);
  return;
}

void writeFile(BSTree *bst){
  /* Writing tree names into a file */
  FILE *fp;
  BSTItem *b;
  char* filename = "names.txt";
  
  b= bst->head;
  fp = fopen (filename, "w");
  writeAux(filename, b);
  fclose(fp);
  return;
}

void writeAux(BSTItem *b, char*i){
  FILE *fp;
  fp = fopen(i, "w");
  if (b){
    fprintf(fp, b->info);
    writeAux(b->leftc, i);
    writeAux(b->rightc, i);
  }
  fclose(fp);
}

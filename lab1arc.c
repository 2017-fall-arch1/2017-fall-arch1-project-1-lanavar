#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
  char element;
  int choice;
  char buf[100];
  BSTree *bst = bstAlloc(); /* make an empty tree */



  while(choice!=9){
  
    printf("Please select the desired choice by entering the corresponding number. \n");
    printf("1. Add a new employee name. \n");
    printf("2. Remove an employee name. \n");
    printf("3. List all employee names. \n");
    printf("4. Enter to read the file. \n");
    printf("5. Enter to write the tree informaiton into the file.\n");
    printf("9. When done with program. \n");
    printf("Please enter your choice: ");
    if(fgets(buf, sizeof(buf), stdin))
      {
	choice = atoi(buf);
      }
    option(choice, bst);
  }

  printf("done\n");
    
   

  return 0;
}

void option(int x, BSTree *bst){
  /* method to decide what path to follow and whether the option displayed is valid */
  char *value = malloc(1204);
  printf("You chose: %d \n", x);
  switch (x){
  case 1: {
    printf("Please enter the name of the employee to add: ");
    fgets(value, 1024, stdin);
    bstAdd(bst, value);
    printf("%s entered into database.\n",value);
    break;
  }
  case 2:{
    printf("Please enter the name of the employee to delete: ");
    fgets(value, 1024, stdin);
    bstRemove(bst, value);
    printf("removed from data base.\n", value);
    break;
  }
  case 3:{
    printf("Here is the list of the employee names: ");
    bstPrint(bst->head);
    printf("\n");
    break;
  }
  case 4:{
    readFile(bst);
    printf("The information from the file has been saved. \n", value);
    break;
  }
  case 5:{
    write(bst);
    printf("New information has been writen into the file.\n");
    break;
  }
  case 9:{
    printf("Exiting program.");
    break;
      }
    
  default: {
    printf("You entered an invalid selection\n");
    break;
  }
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"


List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){
   List* list1 = malloc(sizeof(List));

   list1 -> head = NULL;
   list1 -> tail = NULL;
   list1 -> printData = printFunction;
   list1 -> deleteData = deleteFunction;
   list1 -> compare = compareFunction;

   return list1;

}


Node *initializeNode(void *data){
   Node *node1 = malloc(sizeof(Node));

   node1 -> data = data;
   node1 -> previous = NULL;
   node1 -> next = NULL;

   return node1;
}


void insertFront(List *list, void *toBeAdded){
   if (list == NULL){
   	return;
   }
   if (list->head == NULL){
      list->head = initializeNode(toBeAdded);
      list->tail = list->head;
      return;
   }
   
   Node *node = initializeNode(toBeAdded);
   node -> next = list->head;
   list->head->previous = node;
   list->head = node;
   while (node -> next != NULL){
      node = node->next;
   }
   list -> tail = node; 
}


void insertBack(List *list, void *toBeAdded){
   if (list == NULL){
          printf("why?\n");
   	return;
   }
   if (list->head == NULL){
     list->head = initializeNode(toBeAdded);
     list->tail = list->head;
      return;
   }

   Node *temp = list->head;
   while(temp->next != NULL){
      temp = temp->next;
   }

   Node *node = initializeNode(toBeAdded);
   node -> next =NULL;
   node -> previous = temp;
   temp->next = node;
   list -> tail = node;

}


void insertSorted(List *list, void *toBeAdded){
  /*if (list == NULL){
   	return;
   }
   if (list->head == NULL){
      list->head = initializeNode(toBeAdded);
      return;
   }

   Node *node = initializeNode(toBeAdded);
   Node *temp = list->head
   while(temp != NULL){
      if(compareData(toBeAdded,temp->data)!=0){
         temp = temp->next
      } else {
         node -> next = temp->next;
         node -> previous = temp;
         temp->next->previous = node;
         temp -> next = node;
      }
      }*/
   
}


void *getFromFront(List *list){
   if(list == NULL || list->head==NULL){
   	  return NULL;
   }

   return list->head->data;
}


void *getFromBack(List *list){
   if(list == NULL || list->head==NULL){
   	  return NULL;
   }

   return list->tail->data; 
}


void printBackwards(List *list){
   if (list == NULL || list->head == NULL){
      return;
   }

   Node *temp;
   if(list-> tail != NULL ){
      temp = list->tail;
   } 


   while(temp != NULL){
      list->printData(temp->data);
      temp = temp -> previous;
   }
   
}


void printForward(List *list){
   if (list== NULL){
      return;
   }

   Node *temp = list->head;

   while(temp != NULL){
      list->printData(temp->data);
      temp = temp->next;
   }

}


void deleteList(List *list){
   if (list == NULL){
      return;
   }

   while (list -> head != NULL){
      Node *temp = list->head;
      list->head = list->head->next;
      
      temp->next = NULL;
      temp->previous = NULL;
      list->deleteData(temp->data);
      free(temp);
   }
   free(list);
   list =NULL;
}


int deleteDataFromList(List *list, void *toBeDeleted){
  if(list==NULL || list->head == NULL || toBeDeleted == NULL){
      return 0;
   }

   Node *temp = list->head;

   while (temp!= NULL){
      if(temp->data == toBeDeleted){
	 if(temp == list->head){
            list->head = list->head->next;
	    if(list->head!=NULL){
		    list->head->previous = NULL;
            }
         }else if(temp == list->tail){
            if(temp->previous != NULL){
	       temp->previous->next = NULL;
	    }
	 } else {
            temp->previous->next = temp->next;
	    temp->next->previous = temp->previous;
	 }
	 list->deleteData(temp->data);
	 temp->next=NULL;
	 temp->previous=NULL;
	 free(temp);
      }
      temp = temp->next;
   }
   return 0;
}

/*
--------------------------------------------------------------------------------------------------
>Owner:              Sabyasachi Hazra
--------------------------------------------------------------------------------------------------
>Date of creation:   02/01/2024
--------------------------------------------------------------------------------------------------
>File name:          Singly-linked-list.c
--------------------------------------------------------------------------------------------------
>Topic name:         Singly linked list
--------------------------------------------------------------------------------------------------
>Description:        Singly linked list is a data structure in computer science. It is a linear 
                     collection of data elements whose order is not given by their physical 
                     placement in memory rather, each element points to the next. Each element is 
                     called a node. Each node holds a data and a pointer to save the address of 
                     the next node or point to it, except the last node which points to null. In 
                     case of singly linked list traversal is possible in only one direction.
--------------------------------------------------------------------------------------------------
*/

// Libraries and Header files
#include <stdio.h>
#include <stdlib.h>

// Structure definition of a node for singly linked list
typedef struct Node {
        int data;
        struct Node *linkNext;
} Node;

// Method prototypes and declarations
void insert(int pos);
void delete(int pos);
void display();

// Global variables
Node *head = NULL;
int c = 0;

// Method definitions
// Method: Singly-linked-list.insert
void insert(int pos) {
        Node *n = NULL, *temp;
        int i;
        n = (Node *) malloc(sizeof(Node));
        if(n == NULL) {
	        display();
	        printf("Memory allocation failed!\nPlease try again!\n");
	        return;
        }
        if(pos == 0) {
	        printf("Enter position: ");
	        scanf("%d", &pos);
        }
        if(pos >= 1 && pos <= c + 1) {
	        printf("Enter value: ");
	        scanf("%d", &n->data);
	        if(pos == 1) {
		        n->linkNext = head;
		        head = n;
	        } else {
		        temp = head;
		        for(i = 1; i < pos - 1; i++)
			        temp = temp->linkNext;
		        n->linkNext = temp->linkNext;
		        temp->linkNext = n;
	        }
	        c++;
	        display();
        } else {
	        display();
	        printf("Position not available!\n");
        }
}

//Method: Singly-linked-list.delete
void delete(int pos) {
        Node *temp1, *temp2;
        int i;
        if(head == NULL) {
	        display();
	        printf("Linked list Underflow!\n");
	        return;
        }
        if(pos == 0) {
	        printf("Enter position: ");
	        scanf("%d", &pos);
        }
        if(pos < 1 || pos > c) {
	        display();
	        printf("Position not available!\n");
	        return;
        }
        temp1 = head;
        if(pos == 1) {
	        head = head->linkNext;
	        c--;
	        display();
	        printf("Data deleted: %d\n", temp1->data);
	        free(temp1);
        } else {
	        temp2 = temp1;
	        for(i = 1; i < pos; i++) {
		        temp1 = temp2;
		        temp2 = temp2->linkNext;
	        }
	        temp1->linkNext = temp2->linkNext;
	        c--;
	        display();
	        printf("Data deleted: %d\n", temp2->data);
	        free(temp2);
        }
}

// Method: Singly-linked-list.display
void display() {
        Node *n = head;
        system("cls||clear");
        if(n != NULL) {
	        printf("Linked list data:\nHEAD -> ");
	        while(n != NULL) {
		        printf("|%d| -> ", n->data);
		        n = n->linkNext;
	        }
	        printf("TAIL\n");
        }
        printf("Node count: %d\n\n", c);
}

// Method: Singly-linked-list.main
int main() {
        int ch1, ch2;
        system("cls||clear");
        printf("NOTE: THIS IS A BASIC SINGLY LINKED LIST PROGRAM. ANY DATA ENTERED INTO THE PROGRAM WHILE EXECUTION, WILL BE STORED IN THE PRIMARY MEMORY AND WILL BE DELETED AS SOON AS THE PROGRAM TERMINATES.\n\n");
        while(1) {
	        printf("MAIN MENU:\n[1] -> Insert data\n[2] -> Delete data\n[0] -> Exit\n\n> ");
	        scanf("%d", &ch1);
	        switch(ch1) {
		        case 0:
			        display();
			        printf("Press \"ENTER\" to clear screen and exit!");
			        getchar();
			        if(getchar() == '\n' || getchar() != '\n')
				        system("cls||clear");
			        free(head);
			        return 0;
		        case 1:
			        display();
			        while(1) {
				        printf("INSERT DATA:\n[1] -> Insert at beginning\n[2] -> Insert at end\n[3] -> Insert at custom position\n[0] -> Go back to main menu\n\n> ");
				        scanf("%d", &ch2);
				        if(ch2 == 0) {
					        display();
					        break;
				        }
				        switch(ch2) {
					        case 1:
						        insert(1);
						        break;
					        case 2:
						        insert(c + 1);
						        break;
					        case 3:
						        insert(0);
						        break;
					        default:
						        display();
						        printf("Wrong choice!\nPlease try again!\n");
				        }
			        }
			        break;
		        case 2:
			        display();
			        while(1) {
				        printf("DELETE DATA:\n[1] -> Delete first node\n[2] -> Delete last node\n[3] -> Delete node from custom position\n[0] -> Go back to main menu\n\n> ");
				        scanf("%d", &ch2);
				        if(ch2 == 0) {
					        display();
					        break;
				        }
				        switch(ch2) {
					        case 1:
						        delete(1);
						        break;
					        case 2:
						        delete(c);
						        break;
					        case 3:
						        delete(0);
						        break;
					        default:
						        display();
						        printf("Wrong choice!\nPlease try again!\n");
				        }
			        }
			        break;
		        default:
			        display();
			        printf("Wrong choice!\nPlease try again!\n");
	        }
        }
}


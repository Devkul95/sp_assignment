#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000

typedef struct Node{

	char *d;
	struct Node *nxt;
}Node;


Node *create_node(const char *line){
	
	Node *newNode = (Node *)malloc(sizeof(Node));
	if(newNode !=NULL){
		newNode->d=strdup(line);
		newNode->nxt=NULL;
	}
	return newNode;
}

void freeLL(Node *head){

	while(head!=NULL){

		Node *temp=head;
		head=head->nxt;
		free(temp->d);
		free(temp);
	}
}

int main(int arg, char *args[]){

	if(arg!=2){
		printf("\n you have not entered the input line n", args[0]);
		return 1;
	}

	int n=atoi(args[1]);

	if(n<=0){
		printf("\ninvalid line number input");
	       	return 1;
	}

	char line[MAX_LINE_LENGTH];
	Node *head=NULL;
	Node *tail=NULL;
	int count=0;

	printf("\nenter the input lines: ");	
	while(fgets(line,sizeof(line), stdin)!=NULL){
		
		Node *n1 = create_node(line);
		if(n1 ==NULL){
			printf("\nerror in memory allocation");
			freeLL(head);
			return 1;
		}

		if(count==0){
			head=n1;
			tail=n1;
		}else {
			tail->nxt=n1;
			tail=n1;
		}
		
		count++;

		if(count>n){
			Node *temp=head;
			head=head->nxt;
			free(temp->d);
			free(temp);
			count--;
		}
	}

	printf("\nlast %d lines are: ",(count<n)?count:n);
	Node *curr=head;
	while(curr!=NULL){
		printf("%s",curr->d);
		curr=curr->nxt;
	}

	freeLL(head);
	return 0;
}
		


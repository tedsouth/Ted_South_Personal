//Author: Ted South
//Date: 8/20/18

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size= 10;
int selection;

typedef struct phonebook{
	char firstName[80];
	char lastName[80];
	char phoneNum[80];
}pb;

void addContact(pb *);
void deleteContact(pb *);
void showContents(pb *);

FILE *pEdit;
FILE *pScan;

//Main function
int main(void)
{
	
	size=0;
	pb *phonebook;
	phonebook = (pb*) malloc(sizeof (pb)*100);
 	
 	int a=0;
 	
 	if (phonebook ==NULL)
		 {
		 	printf("Error. Exiting Program\n\n");
			 return 1;	
			} 
	else{}
		
 	do{
 		printf("______________________________\n");
 		printf("Phonebook Menu\n\n");
 		printf("(1)Add Contact\n");
 		printf("(2)Delete Contact\n");
 		printf("(3)Show all entered contacts\n");
 		printf("What would you like to do? ");
 		scanf("%d", &selection);
 		
 		if (selection==1)
		 {
		 	addContact(phonebook);
		 }
		 
		 if (selection == 2)
		 {
		 	deleteContact(phonebook);
		 }
		 
		 if (selection == 3)
		 {
		 	showContents(phonebook);
		 }
		 
	}while (a<=4);		//Will always loop
	
}

//Function to add contacts
void addContact(pb *phonebook){
	
		pEdit = fopen("phonebook.dat", "a");
		if (pEdit == NULL )
		{
			printf("\nError. Exiting Program\n\n");
			return;
		}
		
		else
			{
			
			size++;
			realloc(phonebook, sizeof(pb));
			
			printf("\nEnter the  first name: ");
			scanf("%s", phonebook[size-1].firstName);
			printf("\nEnter the  last name: ");
			scanf("%s", phonebook[size-1].lastName);
			printf("\nPhone #: ");
			scanf("%s", phonebook[size-1].phoneNum);
		
			printf("\nContact added to phonebook.\n");
			
			fprintf(pEdit, "%s\t%s\t%s\n", phonebook[size-1].firstName, phonebook[size-1].lastName, phonebook[size-1].phoneNum);
			fclose(pEdit);
			
			}
}

//Function to delete a contact
void deleteContact(pb *phonebook){
	int x = 0;
	int y = 0;
	char deleteFirst[80];
	char deleteLast[80];
	
	printf("\nSearch for name in your contacts: \n");
	printf("First name: ");
	scanf("%s", deleteFirst);
	printf("Last name: ");
	scanf("%s", deleteLast);
	
	for (x=0; x<size;x++)		//Will search through memory for matching names
	{
		if (strcmp(deleteFirst, phonebook[x].firstName)==0)
		{
			if (strcmp(deleteLast, phonebook[x].lastName)==0)
			{
				for (y=x; y<(size-1);y++)
				{
					strcpy(phonebook[y].firstName,phonebook[y+1].firstName);
					strcpy(phonebook[y].lastName,phonebook[y+1].lastName);
					strcpy(phonebook[y].phoneNum,phonebook[y+1].phoneNum);
				}
				
				printf("\n\nContact Deleted.\n\n");
				size--;
				return;
			}
		}
	}

		printf("\n\nContact not found. Try again.\n\n"); //In case of no match
	
}

//Prints out contents input into the phonebook
void showContents(pb *phonebook){
	
	int x = 0;
	
	if(size>0)
	{
		printf("\nEntered Contacts:\n\n");
		pScan = fopen("phonebook.dat", "r");
		if (pScan == NULL)
		{
			printf("Error. Exiting program");
			return;
		}
		else
		{			
			for ( x=0; x < size ; x++ )
			{
				printf("%s %s\t", phonebook[x].firstName, phonebook[x].lastName);
				printf("%s\n\n\n", phonebook[x].phoneNum);
			}
		}
		fclose(pScan);
	}
	else if (size==0)
	{
		printf("You currently have no contacts.\n\n");
	}

}


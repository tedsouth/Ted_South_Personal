//Author: Ted South
//Date: 8/20/2018

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Input values for +,-,*,/
float first, second, answer = 0;

//Input values for intteger only functions
int intAmount, intOne, intTwo, intAns, selection, nextNum;
int i,factor,num,x, n=0;

//Initialization of operation menu and functions
void options();
void add();
void subtract();
void multiply();
void divide();
void primeTest();
int factorial();
int power();
void fib();
void goodBye();

//Functions for the menu and each operation
void options(){
	printf("Calculator Menu:\n");
	printf("(1) Addition\n");
	printf("(2) Subtraction\n");
	printf("(3) Multiplication\n");
	printf("(4) Division\n");
	printf("(5) Modulus (Integers Only)\n");
	printf("(6) Test if Prime (Integers Only)\n");
	printf("(7) Factorial (Integers Only)\n");
	printf("(8) Power\n");
	printf("(9) Fibonacci Sequence\n");
	printf("(0) Exit\n\n");
	printf("\nPlease select a function using its corresponding number. ");
	scanf("%d", &selection);
	
}

void add(){
		printf("\nEnter the first number: ");
		scanf("%f", &first);
		printf("\nEnter the second number: ");
		scanf("%f", &second);
		
		answer = (first+second);
		printf("\n%.2f + %.2f = %.2f\n_________________________________________\n\n\n", first, second, answer);
}

void subtract(){
		printf("\nEnter the first number: ");
		scanf("%f", &first);
		printf("\nEnter the second number: ");
		scanf("%f", &second);
		
		answer = (first-second);
		printf("\n%.2f - %.2f = %.2f\n_________________________________________\n\n\n", first, second, answer);
}

void multiply() {

		printf("\nEnter the first number: ");
		scanf("%f", &first);
		printf("\nEnter the second number: ");
		scanf("%f", &second);
		
		answer = (first*second);
		printf("\n%.2f * %.2f = %.2f\n_________________________________________\n\n\n", first, second, answer);
}

void divide(){

		printf("\nEnter the first number: ");
		scanf("%f", &first);
		printf("\nEnter the second number: ");
		scanf("%f", &second);
		
		answer = (first/second);
		printf("\n%.2f / %.2f = %.2f\n_________________________________________\n\n\n", first, second, answer);
}

void modulus(){
		printf("\nEnter the first number: ");
		scanf("%d", &intOne);
		printf("\nEnter the second number: ");
		scanf("%d", &intTwo);
		
		intAns = (intOne % intTwo);
		
		printf("\nThe remainder of %d / %d = %d\n_________________________________________\n\n\n", intOne, intTwo, intAns);
}

void primeTest(){
	printf("\nEnter the number to be tested: ");
		scanf("%d", &n);
		for(i=2; i<=n-1; i++) {
			if (n%i==0) {
				printf("%d is not a prime number: %d * %d = %d\n_________________________________________\n\n\n", n,n/i,i,n);
				 
				break;
			}
	}
		if (i==n)
		printf("%d is a prime number: \n_________________________________________\n\n\n", n);
			
}

int factorial(){
	int i, factor=1,num;
	
	printf("\nEnter a positive integer to get the factorial : ");
	scanf("%d", &num);
	
	for(i=1;1<=num;i++){
	
		factor=num*i;
		printf("\nThe factorial of %d is:  %d\n_________________________________________\n\n\n",num,factor);
		return 0;
		}
		
}

int power(){
		printf("\nEnter the base number: ");
		scanf("%d", &intOne);
		printf("\nEnter the exponent value: ");
		scanf("%d", &intTwo);
	
		int intAns=1;
			
		for(i=0; i<intTwo; i++){
			intAns= intAns*intOne;
		}
			
		printf("%d to the %d power is %d.\n_________________________________________\n\n\n",intOne,intTwo,intAns);
	
}

void fib(){
	int i, intOne=0, intTwo=1;
	printf("Enter the number of terms for the sequence: ");
	scanf("%d", &intAmount);
	
	printf("Fibonacci series: ");
	
	for(i=1; i<=intAmount; i++){
		printf("%d ", intOne);
		nextNum = intOne + intTwo;
		intOne=intTwo;
		intTwo = nextNum;
	}
	printf("\n_________________________________________\n\n\n");
}

void goodBye(){
	printf("\nGood Bye!\n___________________________________________\n\n");
}

//Main function using a switch case, each given case has a function
int main(){
	
	int x = 1;
	
	do {	
		options();
	
		switch(selection)	
			{	
			case 1: add();
				break;
					
			case 2: subtract();
				break;
				
			case 3: multiply();
				break;
				
			case 4: divide();
				break;	
				
			case 5: modulus();
				break;
			
			case 6: primeTest();
				break;
			
			case 7: factorial();
				break;
			
			case 8: power();
				break;
			
			case 9: fib();
				break;
				
			case 0: goodBye();
				break;		
			
		}return 0;
	} while (x=1);
			
}




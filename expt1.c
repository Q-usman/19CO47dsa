/*
 Name: QURESHI MOHAMMED USMAN MOHD JAVED
 Roll no.: 19CO47
 COURSE: DATA STRUCTURE LAB.

Experiment No 1: Implement Menu driven program for factorial, fibonacci and palindrome using functions.

*/
#include<stdio.h>
#include<stdlib.h>

int main()
   {
	   while(1)
	  { 
	   int menu;
	   printf("\nMenu\n\n1.Factorial\n2.Fibonacci\n3.Palindrome\n4.Exit \n\nSelect the number::");
	   scanf ("%d",&menu);
	   int n,number;

int factorial(int n);
int fibonacci(int n);
int palindrome(int n);
	   
	  
	   switch(menu)   /*allows us to execute one code block among many alternatives.*/
	   {
		   case 1:
		   printf("\n\tFACTORIAL\n");
		   printf("\nEnter the number:: ");
		   scanf("%d",&n);
		   number=factorial(n);
		   printf("\nThe factorial of %d is %d\n\n",n,number);
		   printf("\n\n");
		   break;
		   
		   case 2:
		   printf("\n\tFIBONACCI\n");
		   printf("\nEnter the range:: ");
		   scanf("%d",&n);
		   fibonacci(n);
		   printf("\n\n");
		   break;
		   
		   case 3:
		   printf("\n\tPALINDROME\n");
		   printf("\nEnter the number:: ");
		   scanf("%d",&n);
		   palindrome(n);
		   printf("\n\n");
		   break;
		   
		   case 4:exit(0);
		   break;
		   
		   default:printf("\nIncorrect input\n\n");
		   
	   }
	}

return 0;

   }


int factorial(int n)
	{
		int i,fact=1;

		for(i=1;i<=n;i++)
		{
		fact=fact*i;
		}
		
return fact;
	}


int fibonacci(int n)
	{
		int a=0,b=1,c;
		printf("\n%d   %d   " ,a,b);

		for(c=0;c<n-2;c++)
		{
			c=a+b;
			if(c<n)
			{printf("%d   ",c);}
			a=b;
			b=c;
		}
		
return 0;
	}


int palindrome(int n)
	{
		int temp,rem=0,x;
	
		temp=n;
	
	
		while(n>0)      
		{
			x=n%10;
			rem=rem*10+x;
			n=n/10;
		}
	
	if(temp==rem)
	{printf("\n%d is a palindrome\n\n",temp);}
	else
	{printf("\n%d is not a palindrome\n\n",temp);}
	
return 0;
	}

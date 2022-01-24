/*
Name: QURESHI MOHAMMED USMAN MOHD JAVED
 Roll no.: 19CO47
 COURSE: DATA STRUCTURE LAB.

Experiment No 2: Implementation of stack using arrays.
     
     
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
  { 
    int data[MAX];
    int top;
  }s;
  
void initialize(struct stack *s)
  {
   s->top=-1;
  }
   
int isEmpty(struct stack *s)
 {
  if(s->top==-1)
    return 1;
  else
    return 0;
       
 }
int isFull(struct stack *s)
  {
  if(s->top==MAX-1)
        return 1;
  else 
        return 0;
   }
   
  void push(struct stack *s,int d)
   {
   if(isFull(s))
    printf("Stack Overflow");
     
   else
      {
      s->top++;
      s->data[s->top]=d;
      printf("Inserted Successfully!");
      }
   }
   

 void pop(struct stack *s,int d)
  {
  if(s->top==-1)
    printf("Stack Underflow");
    
   else
   {
   d=s->data[s->top];
   s->top--;
   printf("Poped element is %d",d);
    }
  }
  
  
void peek(struct stack *s)
   {
     if(isEmpty(s))
     printf("Stack Underflow");
     
   else
     {
  int d=s->data[s->top];
   printf("Peak Element is\t%d",d);
      
     }
   }
   

void display(struct stack *s)
{  
	int i;
  if(isEmpty(s))
   printf("Stack Underflow");
   
   else
     {
      for(i=s->top;i>=0;i--)
       {
         printf("%d\n",s->data[i]);
    
        }
	 }
}

 
int main()
{
 int a,d;
 initialize(&s);
 
 printf("\t\t\t\tMENU PROGRAM");
 while(1)
 {
	 
 printf("\n\nOperations:");
 printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n\nEnter your choice: ");
 scanf("%d",&a);
     switch(a)
     {
     case 1:
     printf("Enter the data for push: ");
     scanf("%d",&d);
     push(&s,d);	 
     break;
     
     case 2:
       pop(&s,d);
       break;
     
     
     case 3:
        peek(&s);
        break;
        
     case 4:
        display(&s);
        break;
        
     case 5:
        exit(0);
        
     default:
         printf("Invalid choice!!");
     
     } 
 }
 return 0;
}

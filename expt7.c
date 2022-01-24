/*
 Name: QURESHI MOHAMMED USMAN MOHD JAVED
 Roll no.: 19CO47
 COURSE: DATA STRUCTURE LAB.

  Experiment No 7:Implementation of singly linked list.

  THEORY:
		Singly Linked List:- In Singly Linked List, every node is made up of two parts:
				1. Data and 2. Next
			Data parts contains the actual element while next part contains address of next node
			It is a one way traversing list, which means we can traverse only in forward direction
			We cannot traverse in backward direction
			The first node is called head node	 
*/

#include<stdio.h>
#include<stdlib.h>
struct SLL
{
int data;
struct SLL *nxt;
};
struct SLL *insertAtEnd(struct SLL *h,int d)
{
	struct SLL *p,*tmp;
	p=(struct SLL *)malloc(sizeof(struct SLL));
	if(p==NULL)
	 {
		 printf("\nNot Enough Memory to allocate");
		 return h;
     }
    
    p->data=d;
    p->nxt=NULL;
     if(h==NULL)
      h=p; 
      
    else
     {
		 tmp=h;
		 while(tmp->nxt!=NULL)
		  {
			  tmp=tmp->nxt;
		  }
		  tmp->nxt=p;
		  p->nxt=NULL;
	  }
	 
    return h;
      
}



struct SLL *insertAtStart(struct SLL *h,int d)
{
	struct SLL *p;
	p=(struct SLL *)malloc(sizeof(struct SLL));
	p->data=d;
    p->nxt=NULL;
    h=p;
    return h;
}



struct SLL *insertAfter(struct SLL *h,int key,int d)
{
	struct SLL *p,*tmp;
	p=(struct SLL *)malloc(sizeof(struct SLL));
	p->data=d;
    p->nxt=NULL;
    if(h==NULL)
      h=p; 
      else
     {
		 tmp=h;
		 while(tmp!=NULL  &&  tmp->data!=key)
			tmp=tmp->nxt;
		if(tmp!=NULL)
		 {
			 p->nxt=tmp->nxt;
			 tmp->nxt=p;
		  }
		else
		 {
			 printf("\n\tGiven Node %d Does not Exists in Linked List ::",key);
			 free(p);
	     }
	 }
return h;
}



struct SLL *removeLast(struct SLL *h)
{
	struct SLL *tmp,*prev;
	tmp=h;
	 if(h!=NULL)
	  {
		  if(h->nxt!=NULL)
		   {
			  while(tmp->nxt!=NULL)
		       { 
				   prev=tmp;
				   tmp=tmp->nxt;
			   }
			 prev->nxt=NULL;
		   }
		  else
		   {
			   h=NULL;
			   free(tmp);
		   }
		}
	  else 
	   printf("\nLL is empty");  
return h;       
}




struct SLL *removeFirst(struct SLL *h)
{
	struct SLL *tmp;
	tmp=h;
    if(h!=NULL)
	  {
		  h=h->nxt;
		  free(tmp);
	  }
	 else
	   printf("\nLL is empty");
return h;
}



struct SLL *removeAfter(struct SLL *h,int key)
{
	struct SLL *tmp,*p;	   
	tmp=h;
	if(h!=NULL)
	 {
		 while(tmp!=NULL  &&  tmp->data!=key)
			tmp=tmp->nxt;
		if(tmp!=NULL)
		 {
			 if(tmp->nxt!=NULL)
		      {
				p=tmp->nxt;
				tmp->nxt=p->nxt;  
				p->nxt=NULL;
				free(p);
			  }
			 else
			  printf("\nGiven Node is the Last Node"); 
		
	     }	  
	    else 
	     printf("\nGiven key does not exists");  
	  }
	 else  
	  printf("\nLL is empty");       
return h;
}



void display(struct SLL *h)
{
	struct SLL *tmp;
	tmp=h;
	if(h!=NULL)
	 {
		 printf("\n\n\t\tLL Contents.....\n\t");
		 while(tmp!=NULL)
		  {
			  printf("%d-> ",tmp->data);
			  tmp=tmp->nxt;
		  }
		 printf("NULL"); 
	 }
	else
	 printf("\nLL is empty");
}





int main()
{
	struct SLL *head;
	int ch,d,k;
	head=NULL;
	while(1)
	 {
		 printf("\n\n\n\t\t\tMENU");
		 printf("\n1.Insert\n2.Insert after.\n3.Remove.\n4.Remove After.\n5.Display.\n6.Exit");
		 printf("\n\tEnter your choice ::");
		 scanf("%d",&ch);
		 switch(ch)
		  {
			  case 1:
			   printf("\n\tEnter data ::");
			   scanf("%d",&d);
			   head=insertAtEnd(head,d);
			   break;
			   
			  case 2:
			   printf("\n\tEnter data ::");
			   scanf("%d",&d);
			   printf("\n\tEnter key data ::");
			   scanf("%d",&k);
			   head=insertAfter(head,k,d);
			   break;
			   
			  case 3:
			   head=removeFirst(head);
			   break;
			   
			  case 4:
			   printf("\n\tEnter Key ::");
			   scanf("%d",&d);
			   head=removeAfter(head,d);
		       break;
		       
		      case 5:
		       display(head);
		       break;
		       
		      case 6:
		       return 0;
		       break;
		       
		       
		      default:
		       printf("\n\n\n\t\tPlease Enter correct choice ::");
		 }
     }
return 0;
}

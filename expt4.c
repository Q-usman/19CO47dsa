/*
 Name: QURESHI MOHAMMED USMAN MOHD JAVED
 Roll no.: 19CO47
 COURSE: DATA STRUCTURE LAB.

Experiment No 4: Evaluation of Postfix expression.


*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

struct stack
{
int data[MAX];
int top;
};

int empty(struct stack *s)
{
	return (s->top==-1)?1:0;
}

void push(struct stack *s,int ele)
{
	if (s->top < MAX-1)
	s->data[++s->top]=ele;
	else
	printf("\nSTACK OVERFLOW");
}

int pop(struct stack *s)
{
	if(!empty(s))
	return s->data[s->top--];
	else
	return (int)-1;
}

int eval(char *expr)
{
char c;
int i,res,op2;
struct stack st;
st.top=-1;
for(i=0;expr[i]!='\0';i++)
 { 
	 c=expr[i];
	 switch(c)
		{
			case '+':
			op2=pop(&st);
			res=pop(&st)+op2;
			push(&st,res);
			break;
			
			case '-':
			op2=pop(&st);
			res=pop(&st)-op2;
			push(&st,res);
			break;
			
			case '*':
			op2=pop(&st);
			res=pop(&st)*op2;
			push(&st,res);
			break;
			
			case '/':
			op2=pop(&st);
			res=pop(&st)/op2;
			push(&st,res);
			break;
			
			case '%':
			op2=pop(&st);
			res=pop(&st)%op2;
			push(&st,res);
			break;
			
			
			case '$':
			op2=pop(&st);
			res=pow(pop(&st),op2);
			push(&st,res);
			break;
			
			case 'e':
			exit(0);
			break;
			
			default:    //operand
			push(&st,c-'0');
			
		}
 }
 return pop(&st);	
}

int main()
{
	while(1)
	{
	char *postfix;
		int res;
		postfix=(char*)malloc(1);
		printf("\nEnter postfix Expression: ");
		scanf("%s",postfix);
		res=eval(postfix);
		printf("\n Evalution to Postfix Expression is : %d\n",res);
		printf("\nEnter e for exit\n");
	}
}



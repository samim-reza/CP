#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];

int isFull ()
{
  return top == MAX - 1;
}

int isEmpty ()
{
  return top == -1;
}

void push (char item)
{
  if (isFull ())
    return;
  top++;
  stack[top] = item;
}

int pop ()
{
  if (isEmpty ())
    return INT_MIN;
  
  return stack[top--];
}

int peek ()
{
  if (isEmpty ())
    return INT_MIN;
  return stack[top];
}

int checkIfOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

int getPostfix (char *expression, char *postfix)
{
  int i, j;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      
      if (checkIfOperand (expression[i]))
	postfix[++j] = expression[i];

      else if (expression[i] == '(')
	push (expression[i]);
 
      else if (expression[i] == ')')
	{
	  while (!isEmpty (stack) && peek (stack) != '(')
	    postfix[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != '(')
	    return -1;		             
	  else
	    pop (stack);
	}
      else			
	{
	  while (!isEmpty (stack)
		 && precedence (expression[i]) <= precedence (peek (stack)))
	    postfix[++j] = pop (stack);
	  push (expression[i]);
	}

    }


  while (!isEmpty (stack))
    postfix[++j] = pop (stack);

  postfix[++j] = '\0';

}

void reverse (char *exp)
{

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}

void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

void InfixtoPrefix (char *exp)
{

  int size = strlen (exp);

  reverse (exp);

  brackets (exp);

  char postfix[MAX];
  getPostfix (exp, postfix);

  reverse (postfix);
  strcpy(exp, postfix);
}

void InfixtoPostfix (char *exp)
{
  int size = strlen (exp);
 
  getPostfix (exp, exp);
}

int main ()
{
  printf ("Enter the infix expression: ");

  char expression[MAX];
  fgets(expression, MAX, stdin);
  expression[strcspn(expression, "\n")] = '\0';

  char prefix[MAX];
  strcpy(prefix, expression);
  InfixtoPrefix (prefix);

  printf ("The prefix is: %s\n", prefix);

  char postfix[MAX];
  strcpy(postfix, expression);
  InfixtoPostfix (postfix);

  printf ("The postfix is: %s\n", postfix);

  return 0;
}

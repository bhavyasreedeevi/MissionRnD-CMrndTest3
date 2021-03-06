/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>;
#include <stdio.h>

//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
int pop(struct Stack* stack)
{
	if (!isEmpty(stack))
			return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

/*
Helper Functions are optional to write 
*/
//Helper Functions Start
int isOperator(char *data){
	if (data==NULL)
		return 0;
	else
	{
		int n = *data - '0';

		if (n == '*' || n == '+' || n == '-')
		{
			return 1;
		}
		else
			return 0;
	}
}
int isOperand(char *data){
	if (data==NULL)
		return 0;
	else
	{
		if (!isOperator(data))
		{
			return(1);
		}
	}
}
int getOperand(char *data){
	//converts data string to an integer "123" => 123
	if (data == NULL)
		return 0;
	else
		return(atoi(data));
}

//Helper Functions end
void inorder(struct enode *root){
	if (root == NULL)
		return;
	inorder(root->left);
	{
		if (isOperand(root->data))
			push(stack, exp[i] - '0');
	}
	inorder(root->right);
}
struct Stack* stack = createStack(strlen(exp));

int solve_tree(struct enode *root){
	if (root==NULL)
		return -1;
	else
	{
		inorder(root);
	}
}


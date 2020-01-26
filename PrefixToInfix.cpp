#include<iostream>
#include<string>
using namespace std;

string stack[50];
int top = -1;

void push(char ch)
{
	//cout << "\nTop : " << top;
	top++;
	stack[top] = ch;
	//cout << "\nTop incremented : "<<top;
}
int isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return 1;
	}
	return 0;
}



int main()
{
	char expression[40];
	char temp[40];
	string op, op1;
	cout << "\nEnter the Expression : ";
	cin >> temp;
	strcpy_s(expression,sizeof(expression),temp);
	_strrev(expression);
	//cout << expression<<endl;
	cout << "------------------------------------------------------------"<<endl;

	int len = strlen(expression);
	for (int i = 0; i < len; i++)
	{
		if (isOperator(expression[i]))
		{
			//cout << "\nTop in op: " << top;
			op = stack[top];
			top--;
			op1 = stack[top];
			stack[top] = '(' + op + expression[i] + op1 + ')';
		}
		else
			push(expression[i]);
	}

	cout << "\nPrefix to Infix is : " << stack[top];
	system("pause");
	return 0;

}
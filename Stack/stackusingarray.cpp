#include <iostream>
using namespace std;

#define MAX 100
//implementation of stack using array

class Stack
{
	
	int peek;
public:
	int stackArray[MAX];
	//constructor
	Stack()
	{
		peek = -1;
	}

	bool push(int iNo);
	int pop();
	int top();
	bool isEmpty();
	

};

int main()
{
	Stack st;
	st.pop();
	st.push(10);
	st.push(20);
	st.push(30);

	
	

	//print the top element
	cout<<"Top element of stack is :"<<st.top()<<endl;

	
	st.isEmpty();
	return 0;
}

bool Stack::push(int iNo)
{
	if(peek >= (MAX-1))
	{
		cout<<"Stack Overflow"<<endl;
		return false;
	}
	else
	{
		stackArray[++peek] = iNo;
		cout<<iNo<<" Pushed in stack"<<endl;
		return true;
	}
}

int Stack::pop()
{
	if(peek < 0)
	{
		cout<<"Stack Underflow"<<endl;
		return 0;
	}
	else
	{
		int temp = stackArray[peek--];
		return temp;
	}
}

int Stack::top()
{
	if(peek < 0)
	{
		cout<<"Stack Underflow"<<endl;
		return 0;
	}
	else
	{
		int temp = stackArray[peek];
		return temp;
	}
}

bool Stack::isEmpty() 
{ 
    return (peek < 0); 
} 
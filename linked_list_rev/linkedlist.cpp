#include <iostream>
using namespace std;

struct ll
{
	int data;
	ll * ptr;
	ll() {
	data = 0;
	}
};
ll * head = NULL;
// Insert at end
void insert(int x)
{
	if(head == NULL)
	{
		head = new ll();
		head -> data = x;
	}
	else
	{
		ll * temp = head;
		while(temp->ptr)
			temp = temp->ptr;
		temp -> ptr = new ll();
		(temp -> ptr) -> data = x;
	}	
}
// Pop from end
int pop()
{
	ll * temp = head;
	while(temp->ptr)
		temp = temp -> ptr;
	int val = temp -> data;
	delete temp;
	return val; 
}

// Display all elements
void display()
{
	ll * temp = head;
	while(temp)
	{
		cout<<temp->data;
		temp = temp->ptr;
	}
}
int main()
{	
	ll s1;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	cout<<pop();
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

class ll{
		struct Node *top;
	public:
		ll(){top=NULL; }
		void push(int x);
		int pop();
};

void ll::push(int x){
        struct Node* new_node = new Node;
        new_node->data = x;
        if(new_node == NULL)
	{
		cout<<"Overflow"<<endl;
		exit(1);
	}
	if(top == NULL)
                top = new_node;
        else
        {
                new_node->next = top;
                top = new_node;
        }
}
int ll::pop(){
	if(top == NULL)
	{
		cout<<"Underflow"<<endl;
		exit(1);
	
	}
	else
	{	struct Node* free_var = top; 
		top = top -> next;
		free(free_var);
		return top -> data;	
	}
}

int main ()
{	
	ll s1;
	s1.push(2);
	s1.push(3);
	int y = s1.pop();
	cout<<y;
	return 0;

}	

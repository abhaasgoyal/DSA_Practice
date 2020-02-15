#include <iostream>
using namespace std;



int a[9][9] = 		  {{0, 0, 0, 0, 0, 8, 4, 0, 0},  
                      {0, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {0, 0, 0, 0, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 2, 9, 0, 6, 0, 0},  
                      {0, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
bool b[9][9] = {};          
// Making a new array b and equating it with values of 1 where inputs are initialized as non zero by the user and 0 where the user has put 0
void initialize()
{
	int k,l;
	for(k=0;k<9;k++)
		for(l=0;l<9;l++)
			if(a[k][l] == 0)
				b[k][l] = false;
			else
				b[k][l] = true;
}

// Backtracking one place            
int backtrack(int &i,int &j)
{
	
	if (i==0 && j==0)
		{
			cout<<"Not possible";
			exit(2);
		}
	if(!b[i][j]) a[i][j] = 0;
	
	if (j==0)
	{
		j = 8;
		i--;
	}
	else
		j--;

	if(b[i][j]||a[i][j]==9||a[i][j]==0)
		return backtrack(i,j);
	
	return 1;
}

//Checking conditions for soduku whether a particular value at a particular place is right
int check(int x,int y)
{	
	
	int i,j;
	for(i=0;i<8;i++)
	{
		if((a[x][y] == a[x][i])&&(i!=y))
			return 0;
		if((a[x][y] == a[i][y])&&(i!=x))
			return 0;
	}
	int temp1 = 3*(x/3);
	int temp2 = 3*(y/3);

	for (i=0;i<3;i++)
		for( j=0;j<3;j++)
			if((a[temp1 + i][temp2 + j] == a[x][y])&&((temp1 + i != x)||(temp2 + j != y)))
					return 0;
	return 1;
}

// Going forward one place
void forward(int &i, int &j)
{
	if(j==8)
	{
		i++;
		j = 0;
	}
	else
		j++;
}

void driver()
{
	int i = 0, j = 0;
	// Non - Deterministic thaz why while I guess
	while(1)
	{
		
	// If forward takes here then end lmao
	if(i==9&&j==0)
			break;
	// If at a location, the values are predefined  or the values are non zero with acceptable value then go forward
	if(b[i][j]||(check(i,j)&&(a[i][j]!=0)))
		forward(i,j); 
	
	// Backtrack value at a location if the value being increased in the last case reaches 9
	else if(a[i][j] ==9)
	{	
		backtrack(i,j);
		// If AFTER BACKTRACTING that location is not predefined then increase value by one
		if(!b[i][j]) a[i][j]++;
	}
	// Normally if value is not acceptable at a particular value then increase it
	else if(!b[i][j]) a[i][j]++;
	
	}
	
	
}

int main()
{
	initialize();
	driver();
	int k,l;
	for(k=0;k<9;k++)
	{	
		for(l=0;l<9;l++)
			cout<<a[k][l]<<" "; 
		
		cout<<endl;
	}
	
	return 0;
}

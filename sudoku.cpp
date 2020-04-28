#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

bool issafe(int y,int x,int a[9][9])
{
	int save=a[y][x];
	//row
	for(int i=0;i<9;i++)
	{
		if(i==y)
		{
			continue;
		}
		else if(a[i][x]==save)
		{
			return false;
		}
	}
	//column
	for(int i=0;i<9;i++)
	{
		if(i==x)
		{
			continue;
		}
		else if(a[y][i]==save)
		{
			return false;
		}
	}
	//box
	int y1,x1;
	if(y<3)
	{
		if(x<3)
		{
			y1=0;
			x1=0;
		}
		else if(x<6)
		{
			y1=0;
			x1=3;
		}
		else
		{
			y1=0;
			x1=6;
		}
	}
	else if(y<6)
	{
		if(x<3)
		{
			y1=3;
			x1=0;
		}
		else if(x<6)
		{
			y1=3;
			x1=3;
		}
		else
		{
			y1=3;
			x1=6;
		}
	}
	else
	{
		if(x<3)
		{
			y1=6;
			x1=0;
		}
		else if(x<6)
		{
			y1=6;
			x1=3;
		}
		else
		{
			y1=6;
			x1=6;
		}
	}
	
	for(int i=y1;i<y1+3;i++)
	{
		for(int j=x1;j<x1+3;j++)
		{
			if(i==y&&j==x)
			{
				continue;
			}
			else if(a[i][j]==save)
			{
				return false;
			}
		}
	}
	
	
	return true;
	
}

struct node{
	node *next;
	node *pre;
	int i;
	int j;
	
}*curr,*start;

node* insert(node *cur,int y,int x)
{
	node *xx=(node*)malloc(sizeof(node));
	if(cur==NULL)
	{
		
		cur=xx;
		xx->i=y;	
		xx->j=x;
		xx->next=NULL;	
		xx->pre=NULL;
		start=xx;
		return cur;
		
	}
	else{
		xx->i=y;	
		xx->j=x;	
		xx->next=NULL;	
		xx->pre=cur;	
		cur->next=xx;
		return xx;
	}
	
		
}

int main()
{
	/*fill this array 
	use 0(zero) as space or blank space*/ 
	int a[9][9]={
				{1,0,0,4,8,9,0,0,6},
				{7,3,0,0,5,0,0,4,0},
				{4,6,0,0,0,1,2,9,5},
				{3,8,7,1,2,0,6,0,0},
				{5,0,1,7,0,3,0,0,8},
				{0,4,6,0,9,5,7,1,6},
				{9,1,4,6,0,0,0,8,0},
				{0,2,0,0,4,0,0,3,7},
				{8,0,3,5,1,2,0,0,4}
				};
				
	
				
	
	
	curr =NULL;
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(a[i][j]==0)
			{
				curr=insert(curr,i,j);
			}
		}
	}
	
	
	node *p=start;
	
	while(p!=NULL)
	{
		a[p->i][p->j]++;
		
		if(a[p->i][p->j]==10)
		{
			a[p->i][p->j]=0;
			p=p->pre;
		}	
		else
		{
			if(issafe(p->i,p->j,a))
			{
				p=p->next;
			}
			
		}
		
		system("CLS");
		cout<<"GARVIT URWEY SUDOKU SOLVER USING BACKTRACKING"<<endl;
		cout<<"solving....."<<endl;
	
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(a[i][j]==0)
				cout<<"_ ";
				else
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
		
		
	}
	
	
	
	system("CLS");
		cout<<"GARVIT URWEY SUDOKU SOLVER USING BACKTRACKING"<<endl;
		cout<<"Answer >>>"<<endl;
	
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(a[i][j]==0)
				cout<<"_ ";
				else
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	
	
	
	
}

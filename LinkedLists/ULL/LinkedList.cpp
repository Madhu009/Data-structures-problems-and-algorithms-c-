#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>
using namespace std;

struct node
{
	int nelements;
	int data[5];
	struct node *next;
};

class LinkedList
{
public:
	void insertend(int);
	node* createnode(int);
	void printlist();
	int getsize();
	void findnthNthElement(int);
	LinkedList()
	{
		head=NULL;
		tail=NULL;
		length=0;
	}
private:
	node *head,*tail;
	int length;
};

main()
{
	LinkedList linkedlist;
	linkedlist.insertend(10);
	linkedlist.insertend(20);
	linkedlist.insertend(30);
	linkedlist.insertend(40);
	linkedlist.insertend(50);
	linkedlist.insertend(60);
	linkedlist.insertend(70);
	linkedlist.insertend(80);
	linkedlist.insertend(90);

	linkedlist.printlist();
	int size=linkedlist.getsize();
	cout<<"the no of elements in the list are : "<<size<<endl;
	linkedlist.findnthNthElement(8);

}


void LinkedList::insertend(int data)
{
	//struct node *new_node=createnode(data);

	if (head==NULL)
	{
		struct node *new_node=new(struct node);
		new_node->data[0]=data;
		new_node->nelements+=1;
		head=new_node;
		tail=head;
		length++;
		cout<<"new node is added as head to the list "<<data<<endl;
		return;

	}
	if (tail->nelements<5)
	{
		tail->data[tail->nelements]=data;
		tail->nelements+=1;
	}
	else
	{
		struct node *new_node=new(struct node);
		length++;
		int i=0;

		for (int j=(tail->nelements/2)+1;j<tail->nelements;j++)
		{
			new_node->data[i++]=tail->data[j];
			tail->data[j]=0;
		}
		new_node->data[i++]=data;
		new_node->nelements=i;

		tail->nelements = tail->nelements/2 + 1;
        tail->next = new_node;  
        tail = new_node;


	}
	
}

void LinkedList::findnthNthElement(int n)
{
	if (n>getsize())
	{
		cout<<"number out of range"<<endl;
		return;
	}
	else
	{
		cout<<"the value is at "<<n<<" is ";
		struct node *temp=head;

		if (n>head->nelements)
		{
			int pos=(n/head->nelements);
			int value=n%head->nelements;

			for (int i=1;i<pos;i++)
				temp=temp->next;

			if(value==0)
				cout<<temp->data[temp->nelements-1]<<endl;
			else 
				cout<<temp->next->data[value-1]<<endl;
		}
		else
		{
			int value=n%head->nelements;
			if(value==0)
				cout<<temp->data[temp->nelements-1]<<endl;
			else 
				cout<<temp->data[value-1]<<endl;
		}
		
	}
}
int LinkedList::getsize()
{
	
	if (length==1)
	{	
		return head->nelements;
	}
	else
	{
		int size=(length-1)*head->nelements;
		size+=tail->nelements;
		return size;
	}
	
}



void LinkedList::printlist()
{
	struct node *temp=head;
	int len=sizeof(temp->data)/sizeof(temp->data[0]);

	cout<<"Printing the list"<<endl;
	for (int i=0;i<30;i++)
		cout<<"-";
	cout<<endl;

	cout<<"[ ";
	for(int i=0;i<len;i++)
	{
		if(temp->data[i]==0)
		{
			break;
		}

		cout<<temp->data[i]<<" ";

	}
	cout<<" ] ";

	while(temp->next!=0)
	{

		int len=sizeof(temp->next->data)/sizeof(temp->next->data[0]);
		cout<<" [ ";
		for(int i=0;i<len;i++)
		{
			if(temp->next->data[i]==0)
			{
				break;
			}

			cout<<temp->next->data[i]<<" ";

		}
		cout<<" ] ";
	
		temp=temp->next;
	}
	cout<<endl;


}

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class LinkedList
{
public:
	void insertend(int);
	node* createnode(int);
	void printlist();
	void insertbefore(int);
	void insertposition(int,int);
	LinkedList()
	{
		head=NULL;
		length=0;
	}
private:
	node *head;
	int length;
};

main()
{
	LinkedList linkedlist;
	linkedlist.insertend(10);
	linkedlist.insertend(20);
	linkedlist.insertend(30);
	linkedlist.insertend(40);
	linkedlist.insertbefore(5);
	linkedlist.insertposition(50,5);
	/*
	linkedlist.deletehead();
	linkedlist.deleteposition(5);
	linkedlist.deletematched(20);

	position=linkedlist.getposition(50);
	cout<<position<<endl;
	*/
	linkedlist.printlist();

}

node *LinkedList::createnode(int data)
{
	struct node *new_node=new(struct node);
	
	if (new_node==NULL)
	{
		cout<<"memory is not allocated "<<endl;
		return 0;
	}
	else
	{
		new_node->data=data;
		new_node->next=NULL;
		return new_node;
	}

}

void LinkedList::insertend(int data)
{
	struct node *new_node=createnode(data);

	if (head==NULL)
	{
		head=new_node;
		length++;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		length++;
	}


}

void LinkedList::printlist()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}

}

void LinkedList::insertbefore(int data)
{
	struct node *new_node=createnode(data);
	if (head==NULL)
	{
		head=new_node;
		length++;
	}
	else
	{
		new_node->next=head;
		head=new_node;
		length++;
	}
}

void LinkedList::insertposition(int data,int position)
{
	if (position>length)
	{
		cout<<"Error, position exceeds the length"<<endl;
		return;
	}
	if (position==1)
	{
		cout<<"Error, head is present there"<<endl;
		return; 
	}

	struct node *new_node=createnode(data);
	struct node *temp=head;
	for (int i=0;i<position-1;i++)
	{
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	length++;

}


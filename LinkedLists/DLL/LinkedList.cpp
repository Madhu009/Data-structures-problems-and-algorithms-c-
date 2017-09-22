#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};



class LinkedList
{
public:
	void insertend(int);
	node* createnode(int);
	void printlist();
	void insertbefore(int);
	void insertposition(int,int);
	void  deletehead();
	void deleteposition(int);
	void deletematched(int);
	int getposition(int);
	void printreverselist(node *temp);
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
	linkedlist.deletehead();
	linkedlist.deleteposition(4);
	linkedlist.deletematched(40);
	int position=linkedlist.getposition(10);
	cout<<position<<endl;
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
		new_node->prev=NULL;
		return new_node;
	}
}

void LinkedList::printlist()
{
	cout<<endl;
	struct node *temp=head,*reveresetemp;
	cout<<"printing the list : "<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	cout<<"[ ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		reveresetemp=temp;
		temp=temp->next;
	}
	cout<<"]"<<endl;
	printreverselist(reveresetemp);

}

void LinkedList::printreverselist(node *temp)
{
	cout<<"[ ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<"]"<<endl;

}


void LinkedList::insertend(int data)
{
	struct node *new_node=createnode(data);

	if (head==NULL)
	{
		head=new_node;
		length++;
		cout<<"new node is added as head to the list "<<new_node->data<<endl;

	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
		length++;
		cout<<"new node is added to the list "<<new_node->data<<endl;
	}

}

void LinkedList::insertbefore(int data)
{
	struct node *new_node=createnode(data);
	if (head==NULL)
	{
		head=new_node;
		length++;
		cout<<"new node is added as head to the list "<<new_node->data<<endl;

	}
	else
	{
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
		length++;
		cout<<"new node is added before head to the list "<<new_node->data<<endl;

	}
}


void LinkedList::insertposition(int data,int pos)
{
	if (pos==1)
	{
		cout<<"Error, head is present there"<<endl;
		return; 
	}

	pos=pos-1;
	if (pos>length)
	{
		cout<<"Error, position exceeds the length"<<endl;
		return;
	}

	struct node *new_node=createnode(data);

	struct node *temp=head;
	for (int i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
	new_node->prev=temp;
	new_node->next=temp->next;
	if(temp->next!=NULL)
	{
		temp->next->prev=new_node;
	}
	temp->next=new_node;
	length++;
	cout<<"new node is added to the list at the position "<<pos+1<<" and data is "<<new_node->data<<endl;

}


void LinkedList::deletehead()
{
	struct node *temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
	length--;
	cout<<"head deleted, new head marked"<<endl;
}

void LinkedList::deleteposition(int pos)
{
	if (pos==1)
	{
		deletehead();
		return;
	}
	if(pos>length)
	{
		cout<<"Position is out of range";
		return;
	}

	struct node *temp=head;
	for(int i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	if(temp->next!=NULL)
	{
		temp->next->prev=temp->prev;
	}

 	cout<<"node is deleted at the position "<<pos<<" and data is "<<temp->data<<endl;
	free(temp);
	length--;


}

void LinkedList::deletematched(int data)
{
	struct node *temp=head;
	if(temp->data==data)
	{
		deletehead();
		return;
	}

	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			temp->prev->next=temp->next;
			if(temp->next!=NULL)
			{
				temp->next->prev=temp->prev;
			}
 			cout<<"node is matched deleted "<<temp->data<<endl;
			free(temp);
			length--;
			return;
		}
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"Data is not found"<<endl;
}

int LinkedList::getposition(int data)
{
	struct node *temp=head;
	if(temp->data==data)
	{
		return 1;
	}
	int pos=2;
	while(temp->next!=NULL)
	{
		if(temp->next->data==data)
		{
			return pos;
		}
		pos++;
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		cout<<"data is not found"<<endl;
		return 0;
	}
}



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
	void  deletehead();
	void deleteposition(int);
	void deletematched(int);
	int getposition(int);
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
		new_node->next=new_node;
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
		cout<<"new node is added as head to the list "<<new_node->data<<endl;

	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=head;
		length++;
		cout<<"new node is added to the list "<<new_node->data<<endl;
	}


}

void LinkedList::printlist()
{
	cout<<endl;
	struct node *temp=head,*prev;
	cout<<"printing the list : "<<endl;
	for(int i=0;i<20;i++)
		cout<<"*";
	cout<<endl;
	cout<<"[ "<<temp->data<<" ";
	temp=temp->next;

	while(temp!=head)
	{
		cout<<temp->data<<" ";
		prev=temp;
		temp=temp->next;
	}
	cout<<"]"<<endl;
	if(temp==head)
	{
		cout<<"the list is circled "<<prev->data<<"-->"<<head->data<<endl;
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
		struct node *temp=head;

		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=head;
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
	new_node->next=temp->next;
	temp->next=new_node;
	length++;
	cout<<"new node is added to the list at the position "<<pos+1<<" and data is "<<new_node->data<<endl;

}

void LinkedList::deletehead()
{
	struct node *temp=head ,*del;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	del=temp->next;
	temp->next=del->next;
	head=head->next;
	free(del);
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
	for(int i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	struct node *del=temp->next;
	temp->next=del->next;
 	cout<<"node is deleted at the position "<<pos<<" and data is "<<del->data<<endl;
	free(del);
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

	while(temp->next!=head)
	{
		if(temp->next->data==data)
		{
			struct node *del=temp->next;
			temp->next=del->next;
 			cout<<"node is matched deleted "<<del->data<<endl;
			free(del);
			length--;
			return;
		}
		temp=temp->next;
	}
}

int LinkedList::getposition(int data)
{
	struct node *temp=head;
	if(temp->data==data)
	{
		return 1;
	}
	int pos=2;
	while(temp->next!=head)
	{
		if(temp->next->data==data)
		{
			return pos;
		}
		pos++;
		temp=temp->next;
	}
	if(temp->next==head)
	{
		cout<<"data is not found"<<endl;
		return 0;
	}
}





#include <iostream>
struct Node 
{
	int iData;
	Node *next;
	Node *prev;
	Node(int iValue)
	{
		iData = iValue;
		next = NULL;
		prev = NULL;
	}
};

Node *InsertBegin(Node *head,int idata);
void PrintDLList(Node * head);
Node *InsertEnd(Node *head,int idata);

Node* InsertAtPostion(Node* head,int idata,int iPos);
Node *ReverseDLL(Node *head);
Node *ReverseDLLJenny(Node *head);
Node *ReverseDLLMY(Node *head);

Node *DeleteHead(Node *head);
Node *DeleteLastNode(Node *head);

int main(void)
{
	Node *head = new Node(5);
	head = InsertBegin(head,4);
	PrintDLList(head);
	head = InsertBegin(head,2);
	PrintDLList(head);

	head = InsertAtPostion(head,6,2);
	PrintDLList(head);
	head  = InsertEnd(head,50);
	PrintDLList(head);
	head = ReverseDLLMY(head);
	PrintDLList(head);

	head = DeleteHead(head);
	PrintDLList(head);

	head = DeleteLastNode(head);
	PrintDLList(head);
	return 0;
}

Node *InsertBegin(Node *head,int idata)
{
	Node *temp = new Node(idata);
	temp->next = head;

	if(head != NULL)
		head->prev = temp;

	return temp;
}

void PrintDLList(Node * head)

{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}

	while(head != NULL)
	{
		printf("%d <-> ",head->iData);
		head = head->next;
	}
	printf("NULL\n");

}

Node *InsertEnd(Node *head,int idata)
{
	Node *temp = new Node(idata);
	if(head == NULL)
	{
		return temp;
	}

	Node *curr = head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = temp;
	temp->prev = curr;
	return head;
}

Node *ReverseDLL(Node *head)
{
	if(head == NULL || head->next == NULL)
		return head;

	Node *prev = NULL,*curr = head;

	while(curr != NULL)
	{
		prev = curr->prev;
		curr->prev = curr->next;
		curr->next = prev;
		curr = curr->prev;
	}
	return prev->prev;
}

Node *ReverseDLLJenny(Node *head)
{
	if(head == NULL || head->next == NULL)
		return head;

	Node *current = head,*nextnode = NULL;

	while(current != NULL)
	{
		nextnode = current->next;
		current->next = current->prev;
		current->prev = nextnode;
		current = nextnode;
	}

	/*
	 nextnode = current->next; // Store the next node
        current->next = current->prev; // Reverse the next pointer
        current->prev = nextnode; // Reverse the prev pointer
        current = nextnode; 
		*/
	
	return head->prev;
	

}
/*time complexity is O(n)
space complexity is O(1) constant auxilary space*/
Node *ReverseDLLMY(Node *head)
{
	if(head == NULL || head->next == NULL)
		return head;

	Node *tempNode = NULL;
	Node *CurrentNode = head;

	while(CurrentNode != NULL)
	{
		tempNode = CurrentNode->prev;
		CurrentNode->prev = CurrentNode->next;
		CurrentNode->next = tempNode;

		CurrentNode = CurrentNode->prev;
		
	}
	return tempNode->prev;
}

Node *DeleteHead(Node *head)
{
	if(NULL==head)
		return NULL;
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	else
	{
		Node *temp = head;
		head = head->next;
		head->prev = NULL;

		delete temp;
		return head;
	}
}

Node *DeleteLastNode(Node *head)
{
	if(NULL==head)
		return NULL;
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	else
	{
		Node *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->prev->next = NULL;


		delete temp;
		return head;
	}
}

Node* InsertAtPostion(Node* head,int idata,int iPos)
{
	Node* newNode = new Node(idata);

	Node* temp = head,*temp2 = NULL;

	while(iPos!=1)
	{
		temp = temp->next;
		iPos--;
	}
	temp2 = temp->next;
	temp->next = newNode;
	temp2->prev = newNode;
	newNode->next = temp2;
	newNode->prev = temp;
	

	return head;
}
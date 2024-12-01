#include <iostream>
struct Node 
{
	int iData;
	Node *next;
	Node(int iValue)
	{
		iData = iValue;
		next = NULL;
	}
};

void PrintLList(Node *head);
void PrintLList2(Node *head);
Node *InsertBegin(Node *head,int iValue);
Node *InsertEND(Node *head,int iValue);
Node *InsertAtPosition(Node *head,int iPos,int iValue);
Node *DeleteHead(Node *head);
Node *DeleteTail(Node *head);
int FindInLList(Node *head,int iKey);
int FindInLList1(Node *head,int iKey);
Node *ReverseLList(Node* head);
void PrintMiddleNaive(Node* head);
void PrintMiddleEfficient(Node* head);
Node *ReverseLListRecursive(Node* head);

int main(void)
{
	Node *head = NULL;
	//Insert at begining

	head = InsertBegin(head,30);
	head = InsertBegin(head,20);
	head = InsertBegin(head,10);
	PrintLList2(head);

	head = ReverseLListRecursive(head);
	PrintLList2(head);

	InsertAtPosition(head,3,8);
	PrintLList2(head);

	head = DeleteTail(head);

	PrintLList2(head);

	//head = ReverseLList(head);

	//PrintLList2(head);
	PrintMiddleNaive(head);
	PrintMiddleEfficient(head);
	//int k = FindInLList1(head,20);
	//printf("elemente 20 has found on %d node\n",FindInLList1(head,20));
	return 0;
}

//This function is to print linked list using Recursion
void PrintLList(Node *head)
{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("%d -> ",head->iData);
	PrintLList(head->next);
}

//This function is to print linked list using Iteration

void PrintLList2(Node * head)
{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}

	while(head != NULL)
	{
		printf("%d -> ",head->iData);
		head = head->next;
	}
	printf("NULL\n");

}
//function for insert node at begining 
//Time Complixity is O(1)

Node *InsertBegin(Node *head,int iValue)
{
	Node *temp = new Node(iValue);
	temp->next = head;
	return temp;
}

//Insertion at the end of a singly-linked list takes O(n) time. 
//space Complexity is O(1)
Node *InsertEND(Node *head,int iValue)
{
	Node *temp = new Node(iValue);
	if(head == NULL)
	{
		return temp;
	}
	Node *curr = head;
	while(curr->next != NULL) //here we have to traverse the entire list to reach the last node where the new node will be added.
	{
		curr=curr->next ;
	}
	curr->next = temp;
	return head;
}

/*this function is for isert node at given position 
for that three conrner case 
if the position is== 1 -> then add temp->next = head
if the postion is invalid then return head means curr is null
temp->next  =  curr->next
curr -> next  = temp 
time complixity is O(1) -> if the pos is 1
O(n) -> for valid position 
*/
Node *InsertAtPosition(Node *head,int iPos,int iValue)
{
	Node *temp = new Node(iValue);

	if(iPos == 1)
	{
		temp->next = head;
		return temp;
	}

	Node *curr = head;

	for(int i = 1;i<iPos -2 && curr!=NULL ; i++)
		curr = curr->next;

	if(curr == NULL)
		return head;

	temp->next = curr->next;
	curr->next = temp;
	return head;
}

/*here we need to deallocate the head so delete the head node
time complixity is O(1) */
Node *DeleteHead(Node *head)
{
	if(head == NULL)
		return NULL;
	else
	{
		Node *temp = head->next;
		delete head;
		return temp;
	}
}

/*delete the last node of sinle linked list
As we have to travel thorugh 2Nd last node to delete last node
so time complexity is Theta(N) -> N is the Number of Node
*/
Node *DeleteTail(Node *head)
{
	if(head==NULL)
		return NULL;

	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
	else
	{
		Node *curr = head;
		/*here we have to traverse the entire list 
		to reach the 2nd last node where the last node will be deleted.*/
		while(curr->next->next != NULL) 
		{
			curr=curr->next ;
		}
		delete(curr->next);
		curr->next = NULL;
		return head;
	}
}

/*solution for finding in linked list best time complexity is O(1)
worst time complexity is 0(N)-> were N is number of Node in 
linked list*/
int FindInLList(Node *head,int iKey)
{
	Node * curr = head;
	int iCounter = 1;
	while(curr->next != NULL)
	{
		if(curr->iData == iKey)
			return iCounter;
		else
		{
			iCounter++;
			curr = curr->next;
		}
	}
	return -1;
}

/*O(N) time complexity  
worst case is the when data is not Found in Linked list

Auxilary space O(N) coz every recursive Node* head has to create for parameter */
int FindInLList1(Node *head,int iKey)
{
	if(head == NULL)
		return -1;

	if(head->iData == iKey)
		return 1;

	else
	{
		int iRes = FindInLList1(head->next,iKey);
		if(iRes == -1)
			return -1;
		else 
			return(iRes+1);
	}
}

/*this ReverseLList() function take O(N) time complxicity coz
its visit all the node in one single loop

space complixity is clearly O(1) constant for (curr,prev,next)

Naive solution : crate a Auxilary array 
copy all the elements in vector/array and fetch from last element and fill
into New linked list and retrun it 
two time travesal through linked list*/
Node *ReverseLList(Node* head)
{
	Node *curr = head; 
	Node *prev = NULL;

	while(curr!=NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

void PrintMiddleNaive(Node* head)
{
	if(head == NULL) 
		return;

	int iCount =0;
	Node* curr;
	for(curr = head ; curr!=NULL ; curr=curr->next)
	{
		iCount++;
	}

	curr = head;
	for(int i=0 ; i<(iCount/2) ; i++)
	{
		curr = curr->next;
	}

	printf("Middle node %d\n",curr->iData);
}

void PrintMiddleEfficient(Node *head)
{
	if(head == NULL) 
		return;

	Node *slow = head;
	Node *fast = head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("Middle node %d\n",slow->iData);

}
//10->20->30->NULL
Node *ReverseLListRecursive(Node* head)
{
	if(head == NULL || head->next == NULL)
		return head;

	Node *restHead = ReverseLListRecursive(head->next);
	Node *restTail = head->next;
	restTail->next = head;
	head->next = NULL;
	return restHead;
}
//leetcode 143 Reorder List

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* curr = head;
        ListNode* middle;
        ListNode *slow = head, *fast = head;
        while (fast  && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        middle = slow;
        stack<ListNode*> st;
        
        curr = slow;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        while (!st.empty()) {
            ListNode* top = st.top();
            st.pop();

            top->next = curr->next;
            curr->next = top;
            curr = top->next;
            if(curr == NULL) break;
        }

        if(curr)
        {
            curr->next = NULL;
        }
    }


	ListNode *InsertEND(ListNode *head,int iValue)
	{
		ListNode *temp = new ListNode(iValue);
		if(head == NULL)
		{
			return temp;
		}
		ListNode *curr = head;
		while(curr->next != NULL) //here we have to traverse the entire list to reach the last node where the new node will be added.
		{
			curr=curr->next ;
		}
		curr->next = temp;
		return head;
	}
};

int main()
{
	Solution obj;

	ListNode * head = NULL;
	head = obj.InsertEND(head,1);
	head = obj.InsertEND(head,2);
	head = obj.InsertEND(head,3);
	head = obj.InsertEND(head,4);
	head = obj.InsertEND(head,5);

	obj.reorderList(head);

	head;
}

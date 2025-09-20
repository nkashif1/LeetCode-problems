/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode *cu=head;
        int count=0;
        while(cu!=nullptr)
        {
            cu=cu->next;
            count++;
        }
        int index_to_delete= count-n; //want to go to # before you want to delete
        if(index_to_delete==0)
        {
            ListNode *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        cu=head;
        for(int i=0; i<index_to_delete-1; i++) //go to the one before you want to delete
        {
            cu=cu->next;
        }
        ListNode *temp= cu->next;
        cu->next=cu->next->next;
        delete temp;
        return head;
    }
};

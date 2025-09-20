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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0); //for the new list we will have at the end
        ListNode *tail=&dummy; //add to end
        while(true)
        {
            ListNode *temp=nullptr;
            int index=-1;
            for(int i=0; i<lists.size(); i++)
            {
                if(lists[i]!=nullptr)
                {
                    if(temp == nullptr || lists[i]->val< temp->val)
                    {
                        temp=lists[i];
                        index=i;
                    }
                }
            }
            if(index==-1)
            {
                break;
            }
            tail->next=temp;
            tail=tail->next;
            lists[index]=lists[index]->next;
        }
        return dummy.next;
    }
};

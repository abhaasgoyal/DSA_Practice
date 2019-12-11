https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *add = NULL;
        struct ListNode *temp;
        int carry = 0,sum = 0;
        
            while(l1!=NULL||l2!=NULL)
            {   
                sum = 0;
                if(l1==NULL&&l2!=NULL)
                {   
                    sum = (l2->val)+carry;
                    l2 = l2 -> next;
                }
                else if(l2==NULL&&l1!=NULL)
                {   
                    sum = (l1->val)+carry;
                    l1 = l1 -> next;
                }
                else
                {   
                    sum =(l1->val)+(l2->val)+carry;
                    l1 = l1 -> next;
                    l2 = l2 -> next;
                }
                
                if(sum>9)
                {
                    sum = sum % 10;
                    carry = 1;
                }
                else
                    carry = 0;
                if(add==NULL)
                {   
                    add = new ListNode(sum);
                    temp = add;
                    continue;
                }
                struct ListNode *top = new ListNode(sum);
                temp ->next = top;     
                temp = temp -> next;
                
            }
        if(carry==1)
        {   
            while(temp->next!=NULL)
                temp = temp -> next;
            struct ListNode *top = new ListNode(1);
            temp ->next = top;
        }
        
    return add;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = helper(head);
        ListNode* np = head;
        if (!head) return nullptr;
        if (count==n){
            np = np->next;
            return np;
        }
        for (int i=0;i<count-n-1;i++){
            np = np->next;
        }
        ListNode* remove = np->next;
        if (!remove){
            np->next = nullptr;
        }
        else{
            np->next = remove->next;
        }
        return head;
        
    }
    
    int helper(ListNode* head){
        ListNode* np = head;
        int i = 0;
        while(np){
            np = np->next;
            i++;
        }
        return i;
    }
};

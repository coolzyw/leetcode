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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        if (lists.size()==1){
            return lists[0];
        }
        else if (lists.size()==2){
            ListNode* np0 = lists[0];
            ListNode* np1 = lists[1];
            ListNode* head = nullptr;
            bool first = true;
            ListNode* prev = nullptr;
            while (np0 && np1){
                ListNode* op = nullptr;
                if (np0->val <= np1->val){
                    op = new ListNode(np0->val);
                    ListNode* tmp = np0;
                    np0 = tmp->next;
                    delete tmp;
                }
                else{
                    op = new ListNode(np1->val);
                    ListNode* tmp = np1;
                    np1 = tmp->next;
                    delete tmp;
                }
                if (first==true){
                    head = op;
                    prev = head;
                    first = false;
                }
                else{
                    prev->next = op;
                    prev = op;
                }
            }
            if (np0){
                if (prev) {
                    prev->next = np0;
                }
                else{
                    head = np0;
                }
            }
            else if (np1){
                if (prev){
                    prev->next = np1;
                }
                else{
                    head = np1;
                }
            }
            else{
                return nullptr;
            }
            return head;
        }
        else{
            int divide = lists.size()/2;
            vector<ListNode*> first(lists.begin(), lists.begin()+divide);
            vector<ListNode*> second(lists.begin()+divide, lists.end());
            ListNode* op0 = mergeKLists(first);
            ListNode* op1 = mergeKLists(second);
            vector<ListNode*> last;
            last.push_back(op0);
            last.push_back(op1);
            ListNode* result = mergeKLists(last);
            return result;
        }
    }
};

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
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // attach the remaining nodes
        tail->next = (a ? a : b);
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<ListNode*> newLists;

        while (lists.size() > 1) {
            for(int i = 0; i < lists.size() - 1; i += 2) {
                newLists.push_back(merge(lists[i], lists[i + 1]));
            }
            if (lists.size() % 2 == 1) {
                newLists.push_back(lists.back());
            }
            swap(lists, newLists);
        }

        return lists[0];
    }
};
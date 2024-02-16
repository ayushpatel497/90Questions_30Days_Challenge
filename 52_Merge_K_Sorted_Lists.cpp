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

struct Compare {
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b-> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
        for (auto list : lists)
            if (list) min_heap.push(list);        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
                min_heap.push(node->next);
        }
        return dummy->next;
    }
};
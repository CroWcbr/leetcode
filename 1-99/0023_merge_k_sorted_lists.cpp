#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1)
        {
            vector<ListNode*> mergedLists;
            for (size_t i = 0; i < lists.size(); i += 2)
            {
                if (i + 1 < lists.size())
                    mergedLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                else
                    mergedLists.push_back(lists[i]);
            }
            lists = std::move(mergedLists);
        }
        return lists[0];
    }
};
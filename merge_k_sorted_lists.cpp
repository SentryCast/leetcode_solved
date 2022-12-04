 // https://leetcode.com/problems/merge-k-sorted-lists/
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <optional>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 class Solution
 {
 public:
     ListNode *mergeKLists(vector<ListNode *> &lists)
     {
        std::optional<ListNode*> start = std::nullopt;
        ListNode* ptr = new ListNode();

        ListNode* before_ptr = nullptr;
        bool ptr_init = false;

        if(lists.size() == 0) {
            return nullptr;
        }

        while(true) {
            if(ptr_init) {
                ptr->next = new ListNode();
                before_ptr = ptr;
                ptr = ptr->next;
            }
            std::optional<int> min_val = std::nullopt;
            size_t pos = 0;
            size_t empty_amount = 0;

            for(size_t i = 0; i < lists.size(); i++) {
                if(lists[i] != nullptr) {
                    if(!min_val.has_value() || lists[i]->val <= min_val) {
                        min_val = lists[i]->val;
                        pos = i;
                    }
                }
                else {
                    empty_amount += 1;
                    if (empty_amount == lists.size()) {
                        if(ptr_init) {
                            ptr = before_ptr;
                            ptr->next = nullptr;
                        }
                        if(start.has_value()) {
                            if(!ptr_init) {
                                start.value()->next = nullptr;
                            }
                            return start.value();
                        }
                        else {
                            return nullptr;
                        }
                    }
                }
                if(i == (lists.size() - 1)) {
                    if(start == std::nullopt) {
                        start = new ListNode();
                        start.value()->val = min_val.value();
                        start.value()->next = ptr;
                        lists[pos] = lists[pos]->next;
                    }
                    else {
                        ptr_init = true;
                        ptr->val = min_val.value();
                        lists[pos] = lists[pos]->next;
                    }
                }
            }
        }
     }
 };

int main() {

    ListNode* bob2 = new ListNode(5);
    ListNode* bob1 = new ListNode(4, bob2);
    ListNode* bob = new ListNode(1, bob1);


    ListNode* mark2 = new ListNode(4);
    ListNode* mark1 = new ListNode(3, mark2);
    ListNode* mark = new ListNode(1, mark1);


    ListNode* tim1 = new ListNode(6);
    ListNode* tim = new ListNode(2, tim1);


    ListNode* tt = new ListNode(1);

    std::vector<ListNode*> lists;
    // lists.push_back(bob);
    // lists.push_back(mark);
    // lists.push_back(tim);

    lists.push_back(tt);

    Solution s;

    ListNode* res = s.mergeKLists(lists);

    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;



    return 0;
}
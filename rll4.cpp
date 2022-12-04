// reverse linked list
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

void printList(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;       
    }
    cout << "\n";
}

ListNode* reverseLinkedList(ListNode* head)
{
    ListNode* following = nullptr;
    ListNode* prev = nullptr;
    while(head != nullptr)
    {
        following = head->next;
        head->next = prev;
        prev = head;
        head = following;
    }
    return prev;
}

int main() {
    ListNode* n4 = new ListNode(4, nullptr);
    ListNode *n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    printList(n1);
    
    printList(reverseLinkedList(n1));

}
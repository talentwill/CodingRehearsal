#include "../helper.h"

// 迭代法反转单链表
ListNode* iterationReverse(ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    ListNode* cur = head;
    head = nullptr;

    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = head;
        head = cur;
        cur = next;
    }

    return head;
}

// fast will reach to the end. [1,2,(3),4], [1,2,(3),4,5]
ListNode* middleNode1(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != nullptr) {
            fast = fast->next;
        }
    }
    return slow;
}

// fast only forward 2 steps. [1,(2),3,4], [1,2,(3),4,5]
ListNode* middleNode2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    ListNode* head = createListNodes({1,2,3,4});
    printListNodes(middleNode1(head));
    printListNodes(middleNode2(head));
    return 0;
}
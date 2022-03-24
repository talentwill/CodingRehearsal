#pragma once

#include <iostream>

#include <vector>
#include <list>
#include <initializer_list>
#include <queue>

#include <map>
#include <set>

#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createListNodes(initializer_list<int> list) {
    ListNode head;
    ListNode* p = &head;
    for (auto x: list) {
        p->next = new ListNode(x);
        p = p->next;
    }
    return head.next;
}

void printListNodes(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << ",";
        head = head->next; 
    }
    cout << endl;
}

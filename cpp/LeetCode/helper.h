#pragma once

#include <cassert>

#include <iostream>

#include <initializer_list>
#include <list>
#include <queue>
#include <vector>

#include <map>
#include <unordered_map>
#include <set>

#include <string>
#include <cmath>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNodes(initializer_list<int> list)
{
    ListNode head;
    ListNode *p = &head;
    for (auto x : list)
    {
        p->next = new ListNode(x);
        p = p->next;
    }
    return head.next;
}

void printListNodes(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
}

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define null INT32_MAX

TreeNode* createTree(vector<int> elements) {
    if (elements.empty()) {
        return nullptr;
    }

    queue<TreeNode *> nodes;
    TreeNode *root = new TreeNode(elements[0]);
    nodes.emplace(root);

    int i = 1;
    while (not nodes.empty() and i < elements.size())
    {
        auto node = nodes.front();
        nodes.pop();

        if (i < elements.size() and elements[i] != null) {
            node->left = new TreeNode(elements[i]);
            nodes.emplace(node->left);
        }
        i++;
        if (i < elements.size() and elements[i] != null)
        {
            node->right = new TreeNode(elements[i]);
            nodes.emplace(node->right);
        }
        i++;
    }

    return root;
}

void printTree(TreeNode* node) {
    if (node != nullptr) {
        cout << node->val << ", ";
        printTree(node->left);
        printTree(node->right);
    }
}

// vector
void print2DVectors(vector<vector<int>> v) {
    cout << " [";
    for (auto i : v)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << "],";
    }
    cout << "]\n";
}

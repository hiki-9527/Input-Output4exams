#ifndef TYPEDEF_H
#define TYPEDEF_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct DListNode {
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode() : val(0), pre(nullptr), next(nullptr) {}
    DListNode(int x) : val(x), pre(nullptr), next(nullptr) {}
    DListNode(int x, DListNode *pre, DListNode *next) : val(x), pre(pre), next(next) {}
};

#endif
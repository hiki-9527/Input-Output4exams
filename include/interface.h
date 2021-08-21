#ifndef INTERFACE_H
#define INTERFACE_H

#include "TypeDef.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> toVector(const char *, char splitFlag = ',');
void printVector(const vector<int> &v);
ListNode *toListNode(const vector<int> &v);
vector<int> toVector(ListNode *node);

TreeNode *toTreeNode(const char *, char splitFlag = ',');
void printTree(TreeNode *);
vector<vector<int>> levelOrder(TreeNode *root);

#endif
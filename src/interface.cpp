#include "../include/interface.h"

vector<int> toVector(const char* ptr, char splitFlag)
{
    string tmp(ptr);
    vector<int> res;
    auto begin = tmp.begin() + 1;
    auto end = tmp.end() - 1;
    auto pos = find(begin, end, splitFlag);
    while(pos != end)
    {
        res.push_back(stoi(tmp.substr(begin - tmp.begin(), pos - begin)));
        begin = pos + 1;
        pos = find(begin, end, splitFlag);
    }
    res.push_back(stoi(tmp.substr(begin - tmp.begin(), pos - begin)));
    return res;
}

void printVector(const vector<int>& v)
{
    if(v.empty())
    {
        cout << "[]" <<endl;
        return;
    }
    string tmp = "[";
    for(auto i : v)
    {
        tmp += to_string(i);
        tmp += ",";
    }
    tmp[tmp.size() - 1] = ']';
    cout << tmp <<endl;
}

ListNode* toListNode(const vector<int>& v)
{
    ListNode res;
    ListNode* tmp = &res;
    for(auto i : v)
    {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    return res.next;
}

vector<int> toVector(ListNode* node)
{
    vector<int> res;
    while(node)
    {
        res.push_back(node->val);
        node = node->next;
    }
    return res;
}

TreeNode* toTreeNode(const char* ptr, char splitFlag)
{
    string tmp(ptr);
    if(tmp == "[]")
    {
        return nullptr;
    }
    TreeNode* res = new TreeNode();
    queue<TreeNode*> d;
    d.push(res);
    auto begin = tmp.begin() + 1;
    auto end = tmp.end() - 1;
    auto pos = find(begin, end, splitFlag);
    string val = tmp.substr(begin - tmp.begin(), pos - begin);
    res->val = stoi(val);
    int i = 0;
    while(pos != end)
    {
        begin = pos + 1;
        pos = find(begin, end, splitFlag);
        val = tmp.substr(begin - tmp.begin(), pos - begin);
        if(val == "NULL" or val == "null")
        {
            if(i%2)
            {
                d.front()->right = nullptr;
                d.pop();
            }
            else
            {
                d.front()->left = nullptr;
            }
        }
        else
        {
            if(i%2)
            {
                d.front()->right = new TreeNode(stoi(val));
                d.push(d.front()->right);
                d.pop();
            }
            else
            {
                d.front()->left = new TreeNode(stoi(val));
                d.push(d.front()->left);
            }
        }
        i++;
    }
    return res;
}

void printTree(TreeNode* root)
{
    if (!root) {
        cout << "[]" <<endl;
        return;
    }
    string tmp = "[";

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        // tmp += "[";
        for (int i = 1; i <= size; ++i) {
            auto node = q.front(); q.pop();
            if(node)
            {
                tmp += to_string(node->val);
            }
            else
            {
                tmp += "null";
            }
            tmp += ",";
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        // tmp[tmp.size() - 1] = ']';
    }
    // tmp += "]";
    tmp[tmp.size() - 1] = ']';
    cout << tmp <<endl;
}



vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector <vector <int>> res;
    if (!root) {
        return res;
    }

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        res.push_back(vector <int> ());
        for (int i = 1; i <= size; ++i) {
            auto node = q.front(); q.pop();
            res.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return res;
}
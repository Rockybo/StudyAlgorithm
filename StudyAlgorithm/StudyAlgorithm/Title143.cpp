//
//  Title143.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/5.
//

/**
 143. 重排链表
 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 
 0->n->1->n-1->2

 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 给定链表 1->2->3->4, 重新排列为 1->4->2->3.

 
 [1,2,3,4]--------[1,4,2,3]
 
 */

/**
    解题思路：
方法一：因为链表不支持下标访问，可以转成线性表(数组)
 时间复杂度：O(N)  空间复杂度:O(N)，开辟线性空间
 
方法二：寻找链表中点 + 链表逆序 + 合并链表
 
 推荐方法二：时间复杂度：O(N)  空间复杂度:O(1)
 
 
 
 
 */
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/**
 emplace_back:添加一个新元素到结束的容器。该元件是构成在就地，即没有复制或移动操作进行。
 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 链表中点
ListNode* middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast -> next != nullptr && fast->next->next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

// 链表反转
ListNode* reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
        ListNode *nextTemp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 将原链表的两端合并。
void mergeList(ListNode* l1, ListNode* l2) {
    ListNode *l1_tmp;
    ListNode *l2_tmp;
    while (l1 || l2) {
        l1_tmp = l1 -> next;
        l2_tmp = l2 -> next;
        
        l1 -> next = l2;
        l1 = l1_tmp;
        
        l2 -> next = l1;
        l2 = l2_tmp;
    }
}

// 重排链表
void reorderList(ListNode *head) {
    if (head == nullptr) {
        return;
    }
    
    // 1.找到原链表的中点
    ListNode *mid = middleNode(head);
    ListNode *l1 = head;
    ListNode *l2 = mid -> next;
    mid -> next = nullptr;
    
    l2 = reverseList(head);
    mergeList(l1, l2);
}



void title143() {
    // 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
    ListNode *head = new ListNode(1);
    ListNode *subNode2 = new ListNode(2);
    ListNode *subNode3 = new ListNode(3);
    ListNode *subNode4 = new ListNode(4);
    ListNode *subNode5 = new ListNode(5);
//    ListNode *subNode6 = new ListNode(6);
    
    head -> next = subNode2;
    subNode2 -> next = subNode3;
    subNode3 -> next = subNode4;
    subNode4 -> next = subNode5;
//    subNode5 -> next = subNode6;
    
    cout << "链表：" << endl;
    ListNode *pre = head;
    while (pre) {
        cout << pre->val << endl;
        pre = pre -> next;
    }
    cout << "-----------" << endl;

//    reorderList(head);  方法一
}









// 方法一
void reorderList1(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    
    vector<ListNode *> vec;
    ListNode *node = head;
    // 用线性表存储链表
    while (node != nullptr) {
        vec.emplace_back(node);
        node = node -> next;
    }
    
    int i = 0, j = vec.size() - 1;
    while (i < j) {
        // 交换节点
        vec[i] -> next = vec[j];
        i++;
        // 推出循环
        if (i == j) {
            break;
        }
        // 交换节点
        vec[j] -> next = vec[i];
        j--;
    }
    /**
     i = 0, j = 5 -----
     i = 1, j = 4 -----
     i = 2, j = 3 -----
     i = 3, j = 3 break
     */
    
    vec[i] -> next = nullptr;
    
    cout << "重新排列链表：" << endl;
    while (head) {
        cout << head->val << endl;
        head = head -> next;
    }
    
}




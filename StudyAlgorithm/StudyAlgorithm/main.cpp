//
//  main.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/26.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
        两数相加
 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 请你将两个数相加，并以相同形式返回一个表示和的链表。
 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 */

ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *pre = new ListNode(0); // 哑节点
    ListNode *cur = pre;
    int carry = 0; // 进位
    while (l1 || l2) {
        // 判空处理
        int x = l1 == nullptr ? 0 : l1 -> val;
        int y = l2 == nullptr ? 0 : l2 -> val;
        int sum = x + y + carry;
        
        // 算出进位
        carry = sum / 10;
        // 取模
        sum = sum % 10;
        // 赋值节点
        cur->next = new ListNode(sum);
        
        // 重制当前节点
        cur = cur -> next;
        if (l1) {
            l1 = l1 -> next;
        }
        if (l2) {
            l2 = l2 -> next;
        }
    }
    
    // 如果最后进位还等于1，最后一位还需要进位。
    if (carry == 1) {
        cur -> next = new ListNode(carry);
    }
    return pre -> next;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *l1 = new ListNode(2);
    ListNode *ll1 = new ListNode(4);
    ListNode *lll1 = new ListNode(3);
    l1->next = ll1;
    ll1->next = lll1;
    
    ListNode *l2 = new ListNode(5);
    ListNode *ll2 = new ListNode(6);
    ListNode *lll2 = new ListNode(6);
    l2->next = ll2;
    ll2->next = lll2;
    ListNode *l = addTwoNumbers(l1, l2);
    while (l) {
        cout<< "val = " <<l->val << endl;
        l = l -> next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

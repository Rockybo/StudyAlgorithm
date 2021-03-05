//
//  Title020.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/5.
//

/**
 20. 有效的括号
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s
 输入：s = "{[]}"
 输出：true
 
 解题思路
 1、构造一个字典 key 为右括号，value为左括号
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    if (s.size() % 2 == 1) {
        return false;
    }
    unordered_map<char, char> map = {
        {']', '['},
        {')', '('},
        {'}', '{'}
    };
    // 创建一个栈
    stack<char> st;
    // 遍历字符串
    for (char ch : s) {
        // 如果是右括号
        if (map.count(ch)) {
            // 栈为空 || 栈顶不等于 字典的value（左括号）
            if (st.empty() || st.top() != map[ch]) {
                return false;
            }
            // 出栈
            st.pop();
        } else {
            // 如果是左括号，添加到栈中
            st.push(ch);
        }
    }
    return st.empty();
    
}
// 时间复杂度O(N)
// 空间复杂度O(1)

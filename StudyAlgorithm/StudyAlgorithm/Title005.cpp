//
//  Title005.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/26.
//


/**
 最长回文子串
 给你一个字符串 s，找到 s 中最长的回文子串。

 输入：s = "babad"
 输出："bab"
 解释："aba" 同样是符合题意的答案。
 
 输入：s = "cbbd"
 输出："bb"

 */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 动态规划
string longesPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
        }
    }
    return ans;
}

void test5() {
    string s = longesPalindrome("babad");
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << endl;
    }
    
    
}

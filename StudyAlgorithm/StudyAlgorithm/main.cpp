//
//  main.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/26.
//

#include <iostream>
#include <string>
#include <unordered_set>
/**
    unordered_set:
 count:在容器中查找值为 key 的元素的个数。
 erase:删除指定元素。
 insert:向容器中添加新元素。
 */
using namespace std;

// 滑动窗口
int lengthOfLongestSubstring(string s) {
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为-1
    // ans 记录长度
    int rk = -1, ans = 0;
    // 左指针的位置，初始值为-1
    
    // abcabcbb
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        
        // 右指针小于n 并且occ容器中没有这个字符
        while (rk + 1 < n && !occ.count(s[rk + 1])) {
            // 不断移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        
        // 第i 到rk 个字符是一个极长的无重复字符串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}
// 时间复杂度O(n) 空间复杂度O(|E|), E代表字符集while循环次数


int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abcabcbb";
    int a = lengthOfLongestSubstring(s);
    std::cout << "Hello, World!\n";
    return 0;
}

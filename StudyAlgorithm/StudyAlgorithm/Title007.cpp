//
//  Title007.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/2.
//

/**
 7. 整数反转
 输入：x = 123
 输出：321
 
 我们想重复“弹出” x 的最后一位数字，并将它“推入”到 rev 的后面。最后，rev 将与 x 相反。
 要在没有辅助堆栈 / 数组的帮助下 “弹出” 和 “推入” 数字，我们可以使用数学方法。
 
 数学方法
 
 */
#include <stdio.h>
#include <iostream>

class Solution {
public:
    // 123
    // 321
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10; // 取模，取出最后一位数字
            x /= 10; // 取出前面几位数字
            
//            int a = INT_MAX % 10; --->7
//            int b = INT_MIN % 10; --->-8
            
            // 边界条件判断和条件出口，防止数字溢出
            // 如果相反的数字 > 整数整除 || 相反的数字 等于 整数整除 并且 取模大于最大值的膜
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > INT_MAX % 10)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < INT_MIN % 10)) return 0;
            //
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

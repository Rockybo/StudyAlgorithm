//
//  Title008.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/2.
//

/**
 9. 回文数
 输入：x = 121
 输出：true
 
 输入：x = -121
 输出：false
 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

 */
#include <stdio.h>

// 3个条件
// 我们应该处理一些临界情况。所有负数都不可能是回文
// 所有个位是 0 的数字不可能是回文，因为最高位不等于 0

// 当原始数字小于或等于反转后的数字时，就意味着我们已经处理了一半位数的数字了。
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

// 时间复杂度：O(logn)
// 空间复杂度：O(1)。我们只需要常数空间存放若干变量。

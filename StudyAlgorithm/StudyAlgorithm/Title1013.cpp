//
//  Title1013.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/4.
//

/**
 1013. 将数组分成和相等的三个部分
 输入：[0,2,1,-6,6,-7,9,1,2,0,1]
 输出：true
 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1


 解题思路：因为是连续的三部分
 可以先算出前面一部分符合每一部分的值的下标，然后算出剩余的是否是target的两倍，符合条件返回yes
 */
#include <stdio.h>
bool canThreePartsEqualSum(vector<int>& arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        int a = arr[i];
        sum += a;
    }
    if (sum % 3 != 0) return false;
    
    int target = sum / 3;
    
    int n = arr.size(), i  = 0, cur = 0;
    while (i < n) {
        cur += arr[i];
        if (cur == target) {
            break;
        }
        ++i;
    }
    if (cur != target) {
        return false;
    }
    int j = i + 1;
    while (j + 1 < n) {
        cur += arr[j];
        // 只要满足前面两组是target的两倍，就返回true
        if (cur == target * 2) {
            return true;
        }
        ++j;
    }
    return false;
}

//
//  Title011.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/3/2.
//

/**
 11. 盛最多水的容器
 
 */
#include <stdio.h>
#include <vector>
#include <mach/mach.h>

using namespace std;

// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49
int maxArea(vector<int>& height) {
    // 双指针
    int l = 0, r = height.size() - 1;
    int ans = 0;
    // 左边小于右边
    while (l < r) {
        // 取出双指针的数组最小值 ✖️ 双指针的索引差值
        int area = min(height[l], height[r]) * (r - l);
        // 取最大面积
        ans = max(ans, area);
        // 因为取的是移动对应数字较小的那个指针的值，所以要左指针++
        if (height[l] <= height[r]) {
            ++l;
        }
        else { // 否则移动右指针--
            --r;
        }
    }
    return ans;
}
// 时间复杂度O(N) 双指针总计最多遍历整个数组一次
// 空间复杂度O(1)，只需要额外的常数级别的空间

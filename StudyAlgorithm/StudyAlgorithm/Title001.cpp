//
//  Title001.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/26.
//

#include <stdio.h>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 vector:顺序容器中的元素按照严格的线性顺序排序，动态数组
 push_back(const T& x):向量尾部增加一个元素X
 pop_back():删除向量中最后一个元素
 clear():清空向量中所有元素
    
 unordered_map:内部元素是无序的
 find 通过给定主键查找元素,没找到：返回unordered_map::end
 end  返回指向容器末尾位置的迭代器
 begin 返回指向容器起始位置的迭代器（iterator）
 */
// day1:
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hashTable;
    
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashTable.find(target - nums[i]);
        if (it != hashTable.end()) {
            // second存储的是 下标
            return {it->second, i};
        }
        hashTable[nums[i]] = i;
    }
    return {};
}

int title001() {
    // insert code here...
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int> result = twoSum(nums, 9);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

void test001() {
    // vector & unordered_map使用
    // vector
    vector<int> testNums = {2, 7};
    
    // unordered_map
    unordered_map<int, int> map1 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};
    
    unordered_map<int, int> map2;
    map2.insert(map1.begin(), map1.end());
    

    for (auto it = map1.begin(); it != map1.end(); ++it) {
        cout << "map1=" << it -> first << ":" << it ->second << endl;
    }
    cout << "-----------------------" << endl;
    
    for (auto it = map2.begin(); it != map2.end(); ++it) {
        cout << "map2=" << it -> first << ":" << it ->second << endl;
    }
}

//
//  main.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/26.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

extern int maxArea(vector<int>& height);

int main(int argc, const char * argv[]) {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    int a =  maxArea(arr);
    cout << "a:" << a << endl;
    
    vector<int> arr1 = {0,2,1,-6,6,-7,9,1,2,0,1};
    bool isSum = canThreePartsEqualSum(arr1);
    cout << "isSum=" << isSum  << endl;
    return 0;
}



//
//  Title006.cpp
//  StudyAlgorithm
//
//  Created by berlinbli on 2021/2/27.
//

/**
 6. Z 字形变换
 
 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

 P   A   H   N
 A P L S I I G
 Y   I   R
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

 输入：s = "PAYPALISHIRING", numRows = 4
 输出："PINALSIGYAHRPI"
 解释：
 P     I    N
 A   L S  I G
 Y A   H R
 P     I

 */
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 按行排序，从左向右迭代字符串
string convert(string s, int numRows) {
    
    if (numRows == 1) return s;
    
    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;
    
    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1; // 根据goingDown方向取决是否curRow +/- 1
    }
    // rows:
    /**
     c = P
     [0] ="P"
     [1] = ""
     [2] = ""
     c = A
     [0] = "P"
     [1] = "P"
     [2] = ""
     
     // 完全后
     [0] ="PAHN"
     [1] = "APLSIIG"
     [2] = "YIR"
     */
    
    string ret;
    for (string row : rows) ret += row;
    return ret;
}

void test6() {
    string s = "PAYPALISHIRING";
    string result = convert(s, 3);
    
    cout << result << endl;
    
}


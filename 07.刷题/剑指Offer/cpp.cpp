/*
 * @Author: baineng.shou baineng.shou@nio.com
 * @Date: 2023-08-17 10:22:49
 * @LastEditors: baineng.shou baineng.shou@nio.com
 * @LastEditTime: 2023-08-24 14:16:02
 * @FilePath:
 * /C-background-development-interview-experience/07.刷题/剑指Offer/cpp.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numWays(int n) {
    int dp1 = 1, dp2 = 2;
    int res = 0;
    if (n == 0) return 1;
    if (n <= 2) return n;
    for (int i = 3; i <= n; i++) {
      res = (dp1 + dp2) % 1000000007;
      dp1 = dp2;
      dp2 = res;
    }
    return res;
  }
};
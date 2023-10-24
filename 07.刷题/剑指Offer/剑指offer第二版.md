# 剑指 Offer 第二版

[toc]

## 剑指 Offer 03. 数组中重复的数字

[https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

**方法一：哈希表**

用哈希表（set、map都可）记录插入的数字，如果出现重复的数字就返回；
该方法适合在不改变数组的情况进行

```cpp
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    set<int> set;
    for (auto& i : nums) {
      auto res = set.insert(i);
      if (res.second == false) return i;
    }
    return -1;
  }
};
```

- 时间复杂度`O(n)`：需要遍历数组
- 空间复杂度`O(n)`：创建哈希表，最坏的情况需要存储`n`个元素

**方法二：原地交换**

我们发现这写数字的范围是在`0~n-1`，因此如果没有重复的数字，在排序之后所有的数字都应该在其正确位置上
遍历数组，每次将一个元素放在其正确位置上，如果遇到`nums[nums[i]] == nums[i]`，返回当前元素；最后在处理一下末尾元素即可

```cpp
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (i == nums[i])
        continue;
      else {
        if (nums[nums[i]] == nums[i]) return nums[i];
        swap(nums[i], nums[nums[i]]);
      }
    }
    return nums[len - 1] == len - 1 ? -1 : nums[len - 1];
  }
};
```

- 时间复杂度`O(n)`：需要遍历数组
- 空间复杂度`O(1)`：无额外数据结构

## 剑指 Offer 04. 二维数组中的查找

这题可以把整个矩阵逆时针旋转，把它想象成一个二叉搜索树，遵循左子树小于根节点小于右子树的原则，那么就采用遍历二叉树的方式来做，但是它不是真的二叉树，需要

- `target > matrix[i][j]`: i=i+1, j不变
- `target < matrix[i][j]`: i不变,  j=j-1
- `target == matrix[i][j]`: 成功

如下图所示：

![](https://pic.leetcode-cn.com/6584ea93812d27112043d203ea90e4b0950117d45e0452d0c630fcb247fbc4af-Picture1.png)

```cpp
class Solution {
public:
  bool func(vector<vector<int>> &matrix, int row, int col, int target) {
    if (row >= matrix.size() || col < 0)
      return false;
    if (matrix[row][col] > target)
      return func(matrix, row, col - 1, target);
    else if (matrix[row][col] < target)
      return func(matrix, row + 1, col, target);
    else
      return true;
    return false;
  }
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0)
      return false;
    return func(matrix, 0, matrix[0].size() - 1, target);
  }
};
```

- 时间复杂度`O(n+m)`：最差的结果便是target在左下角，因此最多循环 m+n 次
- 空间复杂度`O(n+m)`：需要 n+m 个函数调用栈

或者换一种思路，从右上角点处(0,n-1)出发，如果

- `target > matrix[i][j]`: 说明target比当前行所有的值都大，跳到下一行进行判断（i++）
- `target < matrix[i][j]`: 说明target只有可能在当前行内，只需要在当前行判断即可（j--）
- `target == matrix[i][j]`: 成功

两种方式原理都是一样的，只是思考的方式略有不同

```cpp
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
      if (matrix[i][j] > target)
        --j;
      else if (matrix[i][j] < target)
        ++i;
      else
        return true;
    }
    return false;
  }
};
```

- 时间复杂度`O(n+m)`：最差的结果便是target在左下角，因此最多循环 m+n 次
- 空间复杂度`O(1)`：除 i,j 无额外辅助空间

## 剑指 Offer 05. 替换空格

[https://leetcode.cn/problems/ti-huan-kong-ge-lcof/](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

**方法一：** 新建一个string类型，将s中的数据和替换空格的字符都拷贝过去，避免了数据右移。遍历字符串s，判断是否为空字符，如果是，str加上%20；如果不是，str加上字符

```cpp
class Solution {
 public:
  string replaceSpace(string s) {
    string str;
    for (auto c : s) {
      if (c == ' ')
        str += "%20";
      else
        str += c;
    }
    return str;
  }
};
```

- 时间复杂度`O(n)`：需要遍历字符串
- 空间复杂度`O(n)`：创建额外的字符串，该字符串大小不小于原字符串

**方法二：** 在不建立额外的字符串的情况下，可以先遍历一边字符串，得到空格字符的数量以确定转变后字符串的长度；然后采用快慢指针的方式从尾到头更改字符串。

```cpp
class Solution {
 public:
  string replaceSpace(string s) {
    int num = 0;
    int len = s.size();
    for (auto c : s) {
      if (c == ' ') ++num;
    }
    s.resize(len + num * 2);

    for (int i = len - 1, j = s.size() - 1; i < j; --i, --j) {
      if (s[i] == ' ') {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      } else {
        s[j] = s[i];
      }
    }
    return s;
  }
};
```

- 时间复杂度`O(n)`：需要遍历两次字符串
- 空间复杂度`O(n)`：基于当前字符串进行延伸和修改

## 剑指 Offer 06. 从尾到头打印链表

[https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

**方法一：递归**

看到这题，因为是从尾到头打印输出，首先想到的方式就是递归

```cpp
class Solution {
public:
    vector<int>res;

    vector<int> reversePrint(ListNode* head) {
        if(head==nullptr)
        {
            return {};
        }
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
```

因为要遍历N个节点，因此时间复杂度为：O(N)；
递归的实现方式调用函数栈，遍历N个节点，因此栈的大小至少为N，那么空间复杂度为：O(N)。

**方法二：辅助栈**

```cpp
#include <stack>
#include <vector>
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int>sta;
        vector<int>res;
        while (head!=nullptr) {
            sta.push(head->val);
            head=head->next;
        }
        while (!sta.empty()) {
            res.push_back(sta.top());
            sta.pop();
        }
        return res;
    }
};
```

**方法三：翻转数组**

```cpp
class Solution {
  public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 剑指 Offer 07. 重建二叉树

[https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)

前序遍历顺序：根 -> 左 -> 右
中序遍历顺序：左 -> 根 -> 右
在前序遍历中的节点，都可以在中序遍历中找到，其左右子树分别在该点的左右侧

![20230823105649](https://mubaicppnio.oss-cn-shanghai.aliyuncs.com/20230823105649.png)

程序设计：

1. 用map记录每个元素在中序数组中的下标
2. 递归创建二叉树，left，right为左/右子树的区间，root为当前根节点

```cpp
class Solution {
 public:
  TreeNode* buildTreeHelp(vector<int>& preorder, int left, int right,
                          int root) {
    if (left > right) return nullptr;

    TreeNode* node = new TreeNode(preorder[root]);

    int index = map[preorder[root]];

    node->left = buildTreeHelp(preorder, left, index - 1, root + 1);
    node->right = buildTreeHelp(preorder, index + 1, right, root + index - left + 1);

    return node;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      map[inorder[i]] = i;
    }
    return buildTreeHelp(preorder, 0, preorder.size() - 1, 0);
  }

 private:
  unordered_map<int, int> map;
};
```

- 时间复杂度O(n)：遍历n个节点
- 空间复杂度O(n)：需要创建n个二叉树节点

## 剑指 Offer 09. 用两个栈实现队列

栈是**先进后出**的数据结构，队列是**先进先出**的数据结构。
用两个栈实现一个队列，基本思想是用一个栈实现**进**，一个栈实现**出**；

- 进：选择一个栈push即可
- 出：选择另一个栈进行，前提是需要判断该栈是否存在元素，如果没有，需要从进的那个栈倒序把元素push到出栈中

![20230824105911](https://mubaicppnio.oss-cn-shanghai.aliyuncs.com/20230824105911.png)

```cpp
class CQueue {
 public:
  CQueue() {}

  void appendTail(int value) { T1.push(value); }

  int deleteHead() {
    int res = 0;

    if (T2.empty()) {
      if (T1.empty()) return -1;

      while (!T1.empty()) {
        T2.push(T1.top());
        T1.pop();
      }
    }
    res = T2.top();
    T2.pop();
    return res;
  }

 private:
  stack<int> T1;
  stack<int> T2;
};
```

- 时间复杂度O(n)：deleteHead()需要遍历其中一个栈
- 空间复杂度O(n)：最差的情况下，栈需要保存`n`个元素

## 剑指 Offer 10- I. 斐波那契数列

[https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/)

**动态规划**

非常标准的动态规划题，每一个 $f(n)$ 都可以向下拆分，以 $f(6)$ 为例：

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcStISSHUE8ETgWndFXMFgieWUlXfytlQ8bqCQ&usqp=CAU)

```cpp
class Solution {
 public:
  int fib(int n) {
    int f0 = 0, f1 = 1;
    int res = 0;
    if (n < 2) return n;

    for (int i = 2; i <= n; i++) {
      res = (f1 + f0) % 1000000007;
      f0 = f1;
      f1 = res;
    }

    return res;
  }
};
```

- 时间复杂度O(n)：需要遍历n-2个数
- 空间复杂度O(1)：无需额外内存空间

## 剑指 Offer 10- II. 青蛙跳台阶问题

[https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)

**动态规划**

其实和上一题的思想是一模一样的，假如跳上3级台阶，它可以由跳上一级台阶的跳法次数和跳上二级台阶的跳法次数相加。

```cpp
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
```

## 剑指 Offer 11. 旋转数组的最小数字

[https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)



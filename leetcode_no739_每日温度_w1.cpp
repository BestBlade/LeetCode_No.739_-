/* ------------------------------------------------------------------|
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	单调栈法
*
*	执行用时：72 ms, 在所有 C++ 提交中击败了63.37%的用户
*	内存消耗：38.8 MB, 在所有 C++ 提交中击败了41.73%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> pos;
    vector<int> res(T.size(), 0);
    for (int i = 0; i < T.size(); ++i) {
        if (pos.empty()) {
            pos.emplace(i);
        }
        else {
            while (!pos.empty() && T[pos.top()] < T[i]) {
                res[pos.top()] = i - pos.top();
                pos.pop();
            }
            pos.emplace(i);
        }
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // 数字对应字母映射表，下标对应数字
const char* phoneMap[] =
{
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// 回溯递归函数
// digits:输入数字串，index:当前处理到第几位，path:当前已拼接字符串，res:结果数组，count:结果计数
void backtrack(char* digits, int index, char* path, char*** res, int* count)
{
    int len = strlen(digits);
    // 递归终止：已经处理完所有数字，保存当前组合
    if (index == len)
    {
        (*res)[*count] = (char*)malloc(sizeof(char) * (len + 1));
        strcpy((*res)[*count], path);
        (*count)++;
        return;
    }
    // 当前数字对应的字母串
    char num = digits[index] - '0';
    const char* letters = phoneMap[num];
    int letterLen = strlen(letters);
    // 遍历当前数字所有可选字母
    for (int i = 0; i < letterLen; i++)
    {
        path[index] = letters[i];          // 选择当前字母
        backtrack(digits, index + 1, path, res, count); // 递归下一位
        // 回溯：无需手动撤销，下一轮循环会直接覆盖
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;
    int len = strlen(digits);

    // 计算结果总个数：每位字母数量相乘
    int total = 1;
    for (int i = 0; i < len; i++)
    {
        int num = digits[i] - '0';
        total *= strlen(phoneMap[num]);
    }

    // 动态分配结果数组
    char** res = (char**)malloc(sizeof(char*) * total);
    // 临时保存当前拼接路径
    char* path = (char*)malloc(sizeof(char) * (len + 1));
    path[len] = '\0'; // 字符串结束符

    // 回溯搜索
    backtrack(digits, 0, path, &res, returnSize);

    free(path); // 临时路径用完释放
    return res;
}

/*  第二步：回溯（深度优先搜索 DFS）—— 像走迷宫一样拼字母
    这是题目的 核心逻辑。我们要做的就是 把数字对应的字母，一个一个地组合起来。

    我们可以把这个过程想象成 走一棵树：
    从根节点出发（处理第 1 个数字）
    比如输入 "23"，先处理数字 2。
    数字 2 对应 a、b、c 三个字母。
    我们先选 a，往下走一层，去处理下一个数字 3。
    走到下一层（处理第 2 个数字）

    现在处理数字 3，它对应 d、e、f。
    我们先选 d，往下走一层。
    已经到了最后一个数字，拼完了！ 得到组合 "ad"，把它记录下来。
    回溯（退回来）

    从 "ad" 这条路退回来，回到数字 3 的层，换一个字母，选 e。
    拼出 "ae"，记录下来。
    再退回来，选 f，拼出 "af"，记录下来。
    继续回溯

    数字 3 的所有字母都试完了，退回到数字 2 的层。
    换一个字母，选 b，然后重复上面所有步骤，去组合 d、e、f → 得到 bd、be、bf。
    再换字母 c，组合出 cd、ce、cf。

    一句话总结回溯：
    选一个字母 → 往下拼到底 → 记录结果 → 退回来换一个字母 → 再拼
    循环往复，直到把所有可能的组合都找出来。                                              */
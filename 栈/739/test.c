/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    *returnSize = temperaturesSize;
    int* ans = (int*)calloc(temperaturesSize, sizeof(int)); // 初始化为0
    int* stack = (int*)malloc(temperaturesSize * sizeof(int)); // 栈存下标
    int top = -1; // 栈顶指针

    // 从右往左遍历
    for (int i = temperaturesSize - 1; i >= 0; i--)
    {
        // 弹出所有温度≤当前温度的下标（不可能成为下一个更高温）
        while (top != -1 && temperatures[stack[top]] <= temperatures[i])
        {
            top--;
        }
        // 栈不为空，栈顶就是第一个更高温的天，计算天数差
        if (top != -1)
        {
            ans[i] = stack[top] - i;
        }
        // 把当前天的下标入栈，供前面的天使用
        stack[++top] = i;
    }

    free(stack);
    return ans;
}

/*倒着遍历，栈存后面更高温天下标
低的踢走，高的留着算天数*/
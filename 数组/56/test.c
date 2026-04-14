/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 // 给 qsort 用，让区间按左端点升序排列，保证后续合并的顺序性
int cmp(const void* a, const void* b)
{
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;

    // 1. 按区间左端点升序排序
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // 2. 分配结果数组（最多不超过原数组大小）
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    // 3. 把第一个区间加入结果
    res[0] = (int*)malloc(2 * sizeof(int));
    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;

    // 4. 遍历剩余区间，合并
    for (int i = 1; i < intervalsSize; i++)
    {
        // 结果中最后一个区间
        int* last = res[*returnSize - 1];
        int currLeft = intervals[i][0];
        int currRight = intervals[i][1];

        if (currLeft <= last[1])
        {
            // 重叠：合并，更新右端点为最大值
            last[1] = (last[1] > currRight) ? last[1] : currRight;
        }
        else
        {
            // 不重叠：加入新区间
            res[*returnSize] = (int*)malloc(2 * sizeof(int));
            res[*returnSize][0] = currLeft;
            res[*returnSize][1] = currRight;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }

    return res;
}

/*  核心逻辑：只和最后一个合并好的区间比较，因为已经排序，前面的区间不可能再重叠
    合并条件：currLeft <= last[1]（当前区间左端点 ≤ 最后一个区间的右端点）
    合并操作：取两个区间右端点的最大值（比如 [1,3] 和 [2,6]，右端点取 6）
    不重叠：直接把当前区间加入结果，returnSize+1                        */
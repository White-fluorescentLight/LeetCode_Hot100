/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 // 回溯函数：递归生成全排列
void backtrack(int* nums, int numsSize, int* used, int* path, int pathLen, int** result, int* returnSize)
{
    // 递归终止条件：路径长度等于数组长度，说明找到一个完整排列
    if (pathLen == numsSize)
    {
        // 分配当前排列的内存，并复制路径
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(result[*returnSize], path, sizeof(int) * numsSize);
        (*returnSize)++;
        return;
    }

    // 遍历所有数字，选择未被使用的数字填入当前位置
    for (int i = 0; i < numsSize; i++)
    {

        if (!used[i])
        {
            // 选择：标记为已使用，加入路径
            used[i] = 1;
            path[pathLen] = nums[i];
            // 递归填充下一个位置
            backtrack(nums, numsSize, used, path, pathLen + 1, result, returnSize);
            // 回溯：取消标记，从路径移除
            used[i] = 0;
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    // 计算全排列总数：n!
    int total = 1;
    for (int i = 1; i <= numsSize; i++)
    {
        total *= i;
    }

    // 分配结果二维数组
    int** result = (int**)malloc(sizeof(int*) * total);
    // 分配列大小数组：每个排列长度都是numsSize
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    // 辅助数组：标记数字是否已使用
    int* used = (int*)calloc(numsSize, sizeof(int));
    // 路径数组：存储当前正在构建的排列
    int* path = (int*)malloc(sizeof(int) * numsSize);

    // 启动回溯
    backtrack(nums, numsSize, used, path, 0, result, returnSize);

    // 释放辅助数组
    free(used);
    free(path);

    return result;
}

/*用回溯法，通过used数组标记数字是否用过，递归填满一个排列后存起来，再取消标记（防止不能重复选）选择继续找下一个，直到找出所有全排列
   计算全排列总数必须是n的阶乘，满足全排列总数
   calloc 是C标准库函数，作用是分配内存并自动初始化为 0；
   memcpy 是按字节批量复制等同于循环遍历赋值*/
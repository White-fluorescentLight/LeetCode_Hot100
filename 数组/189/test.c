void rotate(int* nums, int numsSize, int k)
{
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        // 计算新位置：(原索引 + k) % 数组长度
        temp[(i + k) % numsSize] = nums[i];
    }
    // 拷贝回原数组
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = temp[i];
    }
    free(temp);
}

// 反转数组的辅助函数：反转nums[left...right]区间的元素
void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    if (k == 0) return;

    // 三次反转
    reverse(nums, 0, numsSize - 1);    // 1. 反转整个数组
    reverse(nums, 0, k - 1);           // 2. 反转前k个元素
    reverse(nums, k, numsSize - 1);    // 3. 反转后n-k个元素
}

/*  为什么能这么做？（数学原理）

    你可以把数组想象成一条环形的蛇
    向右轮转 k 步，本质上是把数组从 n-k 的位置 “切开”，把后 k 个元素搬到前面去。
    反转操作就像是把蛇翻过来
    通过3 次反转，我们先把尾巴弄到头上（整体反转），然后把尾巴理顺（前 k 反转），再把身子理顺（后 n−k 反转）*/
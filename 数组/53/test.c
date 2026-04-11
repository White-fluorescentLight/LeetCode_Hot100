int maxSubArray(int* nums, int numsSize)
{
    int current = nums[0];  // 当前子数组和
    int max = nums[0];      // 记录最大和

    for (int i = 1; i < numsSize; i++)
    {
        // 小于 0 扔了重新开始
        if (current < 0)
            current = nums[i];
        // 大于累加
        else
            current += nums[i];

        // 更新最大值
        if (current > max)
            max = current;
    }
    return max;
}

// 动态规划
int maxSubArray(int* nums, int numsSize)
{
    int current = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        current = (nums[i] > current + nums[i]) ? nums[i] : (current + nums[i]);
        if (current > maxSum)
        {
            maxSum = current;
        }
    }
    return maxSum;
}

/* 三目结果：
if (nums[i] > current + nums[i])
    current = nums[i];  // 前面的和是负数，直接舍弃，从当前元素重新开始
else
    current = current + nums[i];  // 前面的和是正数，继续累加   */
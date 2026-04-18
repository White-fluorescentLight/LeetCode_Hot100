int firstMissingPositive(int* nums, int numsSize)
{
    int n = numsSize;
    // 第一步：原地哈希，把数字x放到下标x-1的位置
    for (int i = 0; i < n; i++)
    {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        {
            // 交换nums[i]和它应该在的位置nums[nums[i]-1]
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    // 第二步：遍历找第一个缺失的正数
    for (int i = 0; i < n; i++) 
    {
        if (nums[i] != i + 1) 
        {
            return i + 1;
        }
    }
    // 1~n全都出现，答案是n+1
    return n + 1;
}

/*  第一步：归位「把数字 x 放到原本正确下标」
    规则：数字 x，必须待在下标 x-1 的位置

    交换条件，只有 3 个条件都满足才交换：
    nums[i] >= 1 → 必须是正数（负数、0 不管）
    nums[i] <= n → 必须在 1~n 范围内（太大的数不用管）
    nums[nums[i]-1] != nums[i] → 这个数字还没在正确位置

    第二步：找答案「最终数组看哪个不符合下标 + 1」
    全部归位完成后，从头到尾检查每一个下标 i    */
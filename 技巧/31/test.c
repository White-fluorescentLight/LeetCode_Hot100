void nextPermutation(int* nums, int numsSize)
{
    // i 初始在倒数第二个位置，也就是和最后一个数两两比的起点
    int i = numsSize - 2;

    // 循环条件：只要 i 没越界，且当前数 >= 右边的数，就继续往前比
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }

    if (i >= 0)
    {
        int j = numsSize - 1;
        // 从 i 右边找第一个比 nums[i] 大的数
        while (nums[j] <= nums[i])
        {
            j--;
        }
        // 交换 i 和 j 位置的数
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // 降序为最大排列，直接反转
    int left = i + 1;
    int right = numsSize - 1;
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

/*逻辑：
  找拐点：从后往前看，找到第一个「左边 < 右边」的地方，这个左边的位置，就是拐点 i

  怎么怎么找 i
  我们要的不是随便变大，而是要做到 “只大一点点” 就必须遵守一个原则：
  尽量不动左边的高位，只改右边的低位，因此从后往前筛选第一个前比后小的数
  找到了 i，那换谁上去？
  要 “只大一点点”，不能换太大的数 i 右边本来就是降序，从后往前找第一个比 nums [i] 大的，
  就是刚好大一点点的那个 → 这就是 j */
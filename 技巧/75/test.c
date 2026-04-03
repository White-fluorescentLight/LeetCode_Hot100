void sortColors(int* nums, int numsSize)
{
    int count0 = 0, count1 = 0, count2 = 0;
    //  计数
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }
    //  写回数组
    int idx = 0;
    for (int i = 0; i < count0; i++) nums[idx++] = 0;
    for (int i = 0; i < count1; i++) nums[idx++] = 1;
    for (int i = 0; i < count2; i++) nums[idx++] = 2;
}

//进阶
void sortColors(int* nums, int numsSize)
{
    int left = 0, right = numsSize - 1;
    int cur = 0;
    while (cur <= right)
    {
        if (nums[cur] == 0)
        {
            // 交换到0区间
            int temp = nums[cur];
            nums[cur] = nums[left];
            nums[left] = temp;
            left++;
            cur++;
        }
        else if (nums[cur] == 2)
        {
            // 交换到2区间
            int temp = nums[cur];
            nums[cur] = nums[right];
            nums[right] = temp;
            right--;
            // cur不前进，因为交换来的元素需要重新判断
        }
        else
        {
            // 1，直接前进
            cur++;
        }
    }
}

/*三指针：左0 右2，cur指针从前往后遍历遇左互换，遇右互换，遇1自增*/
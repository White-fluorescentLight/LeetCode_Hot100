void moveZeroes(int* nums, int numsSize)
{
    int left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        if (nums[right] != 0)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
        }
    }
}


/*双指针：left 标记下一个非零元素应放置的位置，right 遍历数组
  交换：当 right 遇到非零元素时，与 left 位置交换，left 后移*/
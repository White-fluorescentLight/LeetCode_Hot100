int singleNumber(int* nums, int numsSize)
{
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        res ^= nums[i];
    }
    return res;
}

/*异或运算性质

相同的数异或为0
任何数和0异或，结果还是他自己
异或运算满足交换律*/
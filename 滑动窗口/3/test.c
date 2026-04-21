int lengthOfLongestSubstring(char* s)
{
    // 哈希数组：ASCII一共128个字符，初始全部设为-1（代表没出现过）
    int lastIndex[128];
    for (int i = 0; i < 128; i++)
    {

        lastIndex[i] = -1;
    }

    int maxLen = 0; // 最长无重复子串长度
    int left = 0;   // 滑动窗口左边界

    // right是滑动窗口右边界，逐个遍历每个字符
    for (int right = 0; s[right] != '\0'; right++)
    {
        char c = s[right];
        // 如果当前字符在窗口[left, right)里已经出现过
        if (lastIndex[c] >= left)
        {
            // 左边界跳到重复字符下一位，收缩窗口
            left = lastIndex[c] + 1;
        }
        // 更新当前字符最新出现的下标
        lastIndex[c] = right;
        // 计算当前窗口长度，更新最大值
        int curLen = right - left + 1;
        if (curLen > maxLen)
        {
            maxLen = curLen;
        }
    }
    return maxLen;
}

/*  滑动窗口（双指针），维护一个【内部永远无重复字符】的连续区间

    right 一直向右遍历每一个字母 → 所有可能的子串右边界都不会漏掉
    遇到重复字母 → 只向右收缩左边界
   left，把重复字母踢出窗口，保证窗口内永远无重复
    每次窗口合法（无重复），都计算当前长度，和历史最大值maxLen比较更新
    最终maxLen就是全局最长答案       */
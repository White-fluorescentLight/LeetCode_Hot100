bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    // 1. 获取字符串长度
    int n = strlen(s);

    // 2. 创建 dp 数组
    // dp[i] = 前 i 个字符能不能拼成功
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp)); // 全部先设为 false

    // 3. 初始条件：空串一定能拼成功
    dp[0] = true;

    // 4. 遍历每一个位置 i（要判断前 i 个字符能不能拼）
    for (int i = 1; i <= n; i++)
    {

        // 5. 遍历所有可能的切割点 j
        // j 必须 < i，且 dp[i] 还没成功才继续找
        for (int j = 0; j < i && !dp[i]; j++)
        {

            // 6. 只有前 j 个能拼成功，才继续往后看
            if (dp[j])
            {

                // 7. 遍历字典里所有单词
                for (int k = 0; k < wordDictSize; k++)
                {

                    // 8. 从 j 到 i 的长度
                    int len = i - j;

                    // 9. 如果长度一样 + 内容一样
                    // 说明 j 到 i 是一个单词
                    if (strlen(wordDict[k]) == len &&
                        strncmp(s + j, wordDict[k], len) == 0)
                    {
                        dp[i] = true; // 前 i 个能拼成功
                        break;
                    }
                }
            }
        }
    }

    // 10. 答案就是：整个字符串能不能拼成功
    return dp[n];
}

/*  dp[0] = 能

    从第 1 个字符走到最后：
    回头看看前面有没有一个 j：
      前 j 个能拼好
      并且 j 到现在是一个单词
    有 → 现在也能拼好

    最后看能不能拼到最后    */
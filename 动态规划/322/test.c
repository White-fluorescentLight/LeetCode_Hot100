int coinChange(int* coins, int coinsSize, int amount)
{
    // 初始化dp数组
    // dp[i] 表示凑成金额i所需最少硬币数
    int dp[amount + 1];

    // 初始化为一个不可能的大数（amount+1是理论上的最大值，全用1元也只要amount个）
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }
    dp[0] = 0; // 金额0需要0个硬币

    // 遍历每一种硬币
    for (int k = 0; k < coinsSize; k++)
    {
        int coin = coins[k];
        // 完全背包：正序遍历（每个硬币可以无限拿）
        for (int j = coin; j <= amount; j++)
        {
            // 状态转移：取不使用当前硬币和使用当前硬币的最小值
            if (dp[j - coin] + 1 < dp[j])
            {
                dp[j] = dp[j - coin] + 1;
            }
        }
    }

    // 判断结果：如果dp[amount]还是大于amount，说明没凑出来
    return dp[amount] > amount ? -1 : dp[amount];
}

/*  1.先假装不知道怎么凑
    把所有金额的最小硬币数，先设成一个超级大的数（表示还没找到方法）

    2.从 0 开始，一个金额一个金额算
    dp[0] = 0（0 元不用硬币，这是起点）

    3.拿一种硬币，从硬币面额开始算
    比如硬币是 2，那就从金额 2 开始算，一直算到最大金额

    4.状态转移（最核心）
    我们现在要凑 j 元
    拿了一个硬币 coin
    剩下的钱就是 j - coin
    所以：
    凑 j 元的最小硬币数
    = 凑 j - coin 元的最小硬币数 + 1（加的就是当前这枚硬币）

    5.比大小、更新最小值
    拿「新算出来的这个方法」
    和「原来假设的最大值 / 旧方法」比较
    谁小，就用谁                                            */
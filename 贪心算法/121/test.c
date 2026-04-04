int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize <= 1)
    {
        return 0;
    }

    // 设最低价格
    int minPrice = prices[0];
    // 记录最大利润，初始为0
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        // 更新最低买入价格
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        // 计算当前卖出利润，更新最大利润
        int currentProfit = prices[i] - minPrice;
        if (currentProfit > maxProfit)
        {
            maxProfit = currentProfit;
        }
    }

    return maxProfit;
}

/*贪心策略：每一步都选择[当前最低买入价]，计算[当前最高卖出利润]，最终得到全局最大利润*/
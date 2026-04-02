int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right)
    {
        int currentWidth = right - left;
        int currentHeight = (height[left] < height[right]) ? height[left] : height[right];
        int currentArea = currentWidth * currentHeight;

        if (currentArea > maxArea)
        {
            maxArea = currentArea;
        }

        // 3. 移动指针：核心步骤！移动较矮的那边
        //    如果一样高，移动哪边都一样
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

/*从「最宽」的情况开始，每次只保留「有机会算出更大面积」的柱子，
直接排除「100% 不可能更大」的组合，用一次遍历就找到最大值
！只有移动矮的左指针，才有可能遇到更高的柱子，用「宽度变小」换「高度变大」，才有机会算出更大的面积
为什么选两个柱子里更矮的那个的高度（因为水会从矮的那边漏出去，高的没用）*/
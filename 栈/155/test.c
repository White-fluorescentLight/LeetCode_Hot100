// 栈节点（链表实现）
typedef struct StackNode
{
    int val;
    struct StackNode* next;
} StackNode;

typedef struct
{
    StackNode* data_top;  // 主栈栈顶
    StackNode* min_top;   // 辅助栈栈顶
} MinStack;

//  初始化栈
MinStack* minStackCreate()
{
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->data_top = NULL;
    obj->min_top = NULL;
    return obj;
}

//  入栈
void minStackPush(MinStack* obj, int val)
{
    // 1. 主栈入栈
    StackNode* new_data = (StackNode*)malloc(sizeof(StackNode));
    new_data->val = val;  // 赋值
    new_data->next = obj->data_top;  // 把新节点的 next 指向原来的栈顶，也就是让新节点[站在原来所有元素的上面]
    obj->data_top = new_data;  // 更新栈顶指针为当前元素

    // 2. 辅助栈入栈：仅当辅助栈为空 或 val ≤ 辅助栈栈顶时
    if (obj->min_top == NULL || val <= obj->min_top->val)
    {
        StackNode* new_min = (StackNode*)malloc(sizeof(StackNode));
        new_min->val = val;
        new_min->next = obj->min_top;
        obj->min_top = new_min;
    }
}

//  出栈
void minStackPop(MinStack* obj)
{
    if (obj->data_top == NULL) return; // 空栈不操作

    // 1. 主栈出栈
    StackNode* temp_data = obj->data_top;  // 把当前栈顶指针存到临时变量
    int pop_val = temp_data->val;          // 把要弹出的值存下来（给辅助栈判断用）
    obj->data_top = temp_data->next;       // 把栈顶更新为下一个节点（原栈顶的next）
    free(temp_data);                       // 释放

    // 2. 若弹出的值 == 辅助栈栈顶，辅助栈也出栈
    if (pop_val == obj->min_top->val)
    {
        StackNode* temp_min = obj->min_top;
        obj->min_top = temp_min->next;
        free(temp_min);
    }
}

//  取栈顶
int minStackTop(MinStack* obj)
{
    return obj->data_top->val;
}

//  取最小值
int minStackGetMin(MinStack* obj)
{
    return obj->min_top->val;
}

//  释放栈内存
void minStackFree(MinStack* obj)
{
    // 释放主栈
    while (obj->data_top != NULL)
    {
        StackNode* temp = obj->data_top;
        obj->data_top = temp->next;
        free(temp);
    }
    // 释放辅助栈
    while (obj->min_top != NULL)
    {
        StackNode* temp = obj->min_top;
        obj->min_top = temp->next;
        free(temp);
    }
    free(obj);  // 释放栈容器
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
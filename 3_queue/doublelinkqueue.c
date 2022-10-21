#include <stdio.h>
#include <stdlib.h>

// 双向链表节点
typedef struct tag_node
{
    struct tag_node *prev;
    struct tag_node *next;
    int value;
}node;

// 表头。注意，表头不存放元素值！！！
static node *phead=NULL;
// 节点个数。
static int  count=0;

// 新建“节点”。成功，返回节点指针；否则，返回NULL。
static node* create_node(int value)
{
    /* TODO: write code as below */
    /* TODO: 创建双向链表的Node */
    node *pnode = (node *)malloc(sizeof(node));
    if (NULL == pnode) {
        return NULL;
    }
    pnode->value = value;
    pnode->prev = NULL;
    pnode->next = NULL;
    return pnode;
}

// 新建“双向链表”。成功，返回0；否则，返回-1。
int create_dlink()
{
    // 创建表头
    phead = create_node(-1);
    if (!phead)
        return -1;

    // 设置“节点个数”为0
    count = 0;

    return 0;
}

// “双向链表是否为空”
int dlink_is_empty()
{
    return count == 0;
}

// 返回“双向链表的大小”
int dlink_size() {
    return count;
}

// 获取“双向链表中第index位置的节点”
static node* get_node(int index)
{
    /* TODO: write code as below */
    /* TODO: 获取双向链表的第index位置的Node */
    node *pnode = phead->next;
    int i = 0;
    while (pnode) {
        if (i == index) {
            return pnode;
        }
        pnode = pnode->next;
        i++;
    }
    return NULL;

}

// 获取“第一个节点”
static node* get_first_node()
{
    return get_node(0);
}

// 获取“最后一个节点”
static node* get_last_node()
{
    return get_node(count-1);
}

// 获取“双向链表中第index位置的元素的值”。成功，返回节点值；否则，返回-1。
int dlink_get(int index)
{
    /* TODO: write code as below */
    /* TODO: 创建双向链表指定index的Node中的值 */
    node *pnode = phead->next;
    int i = 0;
    while (pnode) {
        if (i == index) {
            return pnode->value;
        }
        pnode = pnode->next;
        i++;
    }
    return -1;
}

// 获取“双向链表中第1个元素的值”
int dlink_get_first()
{
    return dlink_get(0);
}

// 获取“双向链表中最后1个元素的值”
int dlink_get_last()
{
    return dlink_get(count-1);
}

// 将“value”插入到表头位置
int dlink_insert_first(int value)
{
    /* TODO: write code as below */
    /* TODO: 创建新的Node，并且将值存储在该Node，然后插入在双向链表的头部 */
    if (NULL == phead) {
        return -1;
    }
    node *pnode = create_node(value);
    if (NULL == pnode) {
        return -2;
    }
    pnode->next = phead->next;
    pnode->prev = phead;
    if (phead->next) {
        phead->next->prev = pnode;
    }
    phead->next = pnode;
    ++count;
    return 0;
}

// 将“value”插入到末尾位置
int dlink_append_last(int value)
{
    /* TODO: write code as below */
    /* TODO: 创建新的Node，并且将值存储在该Node，然后插入在双向链表的尾部 */
    if (NULL == phead) {
        return -1;
    }
    node *pnode = create_node(value);
    if (NULL == pnode) {
        return -2;
    }
    node *p = phead;
    while (p->next) {
        p = p->next;
    }
    p->next = pnode;
    pnode->prev = p;
    ++count;
    return 0;
}

// 删除“双向链表中index位置的节点”。成功，返回0；否则，返回-1。
int dlink_delete(int index)
{
    /* TODO: write code as below */
    /* TODO: 查到要删除的Node，然后从双向链表中移除，并释放内存 */
    if (NULL == phead) {
        return -1;
    }
    node *pnode = phead->next;
    int i = 0;
    while (pnode) {
        if (i == index) {
            node *tmp = pnode;
            pnode->prev->next = pnode->next;
            if (pnode->next) {
                pnode->next->prev = pnode->prev;
            }
            free(tmp);
            --count;
            return 0;
        }
        pnode = pnode->next;
        i++;
    }
    return -1;
}

// 删除第一个节点
int dlink_delete_first()
{
    return dlink_delete(0);
}

// 删除组后一个节点
int dlink_delete_last()
{
    return dlink_delete(count-1);
}

// 撤销“双向链表”。成功，返回0；否则，返回-1。
int destroy_dlink()
{
    if (!phead)
    {
        printf("%s failed! dlink is null!\n", __func__);
        return -1;
    }

    node *pnode=phead->next;
    node *ptmp=NULL;
    while(pnode != NULL)
    {
        ptmp = pnode;
        pnode = pnode->next;
        free(ptmp);
    }

    free(phead);
    phead = NULL;
    count = 0;

    return 0;
}

// 打印“双向链表”
void print_dlink()
{
    if (count==0 || (!phead))
    {
        printf("%s dlink is empty!\n", __func__);
        return ;
    }

    printf("%s dlink size()=%d\n", __func__, count);
    node *pnode=phead->next;
    while(pnode != phead)
    {
        printf("%d\n", pnode->value);
        pnode = pnode->next;
    }
}

int main()
{
    int tmp=0;

    // 创建“队列”
    create_dlink();

    // 将10, 20, 30 依次队列中
    dlink_append_last(10);
    dlink_append_last(20);
    dlink_append_last(30);

    // 将“队列开头的元素”赋值给tmp，并删除“该元素”
    tmp = dlink_get_first();
    printf("tmp=%d\n", tmp);
    dlink_delete_first();

    // 只将“队列开头的元素”赋值给tmp，不删除该元素.
    tmp = dlink_get_first();
    printf("tmp=%d\n", tmp);

    dlink_append_last(40);

    printf("empty()=%s\n", dlink_is_empty()?"yes":"no");
    printf("size()=%d\n", dlink_size());
    while (!dlink_is_empty())
    {
        printf("%d\n", dlink_get_first());
        dlink_delete_first();
    }

    // 销毁队列
    destroy_dlink();
}



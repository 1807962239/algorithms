typedef int ElemType;

//定义节点
typedef struct Node //必须显式声明节点类型名，因为指针域需要引用自身类型
{
    ElemType data;
    struct Node *next;
}Node;

//定义链表：本质是一个指向链表头节点Node的指针，也就是头指针，用LinkList表示
typedef struct Node *LinkList;

bool GetElem(LinkList L, int i, ElemType *e)
{
    //赋值p指向第一个节点（非头结点）
    Node *p = L->next;
    int j = 1;

    //这一步顺便处理了空表和i不合法的情况
    while(p && j < i) {
        p = p->next;
        j++;
    }
    if (!p) {
        return false;
    }
    *e = p->data;
    return true;
}

//插入元素到第i个，也就是插入到原第i个元素之前
bool ListInsert(LinkList *L, int i, ElemType e)
{
    //赋值p指向头结点
    Node *p = *L;
    int j = 1;
    
    //p为NULL的时候代表无法插入
    //j等于i的时候代表执行插入
    while(p && j < i) {
        p = p->next;
        j++;
    }

    if (!p) {
        return false;
    }

    Node *s = new Node;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList *L, int i, ElemType *e)
{
    Node *p = *L;
    int j = 1;

    //p是目标节点的前一个节点，所以当它下一个节点为空时就无法删除了
    while(p->next && j < i) {
        p = p->next;
        j++;
    }

    if (!p->next) {
        return false;
    }

    Node *q = p->next;
    *e = q->data;
    p->next = q->next;
    delete(q);
}

void CreateListHead(LinkList *L, int n)
{
    //创建头节点并初始化
    *L = new Node;
    (*L)->next = nullptr;

    Node *s;

    for (int i = 0; i < n; i++) {
        s = new Node;
        //假定全赋值为1
        s->data = 1;
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

void CreateListTall(LinkList *L, int n)
{
    *L = new Node;
    (*L)->next = nullptr;

    Node *p = *L;
    Node *s;

    for (int i = 0; i < n; i++) {
        s = new Node;
        s->data = 1;
        p->next = s;
        p = s;
    }

    p->next = nullptr;
}

void ClearList(LinkList *L)
{
    Node *p = (*L)->next;
    Node *q;

    while(p) {
        q = p->next;
        delete(p);
        p = q;
    }

    (*L)->next = nullptr;
}

typedef struct DoublyNode
{
    ElemType data;
    struct DoublyNode *prior;
    struct DoublyNode *next;
}DoublyNode, *DoublyLinkList;
//*DoublyLinkList代表直接创建了一个DoublyNode*变量叫做DoublyLinkList作为双向链表
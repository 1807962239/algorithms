typedef int ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode;

typedef struct
{
    QNode *front;
    QNode *rear;
}LinkQueue;

bool EnQueue(LinkQueue *Q, ElemType e)
{
    QNode *s = new QNode;
    s->data = e;
    s->next = nullptr;

    Q->rear->next = s;
    Q->rear = s;

    return true;
}

bool DeQueue(LinkQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear) {
        return false;
    }

    QNode *p = Q->front->next;
    *e = p->data;

    Q->front->next = p->next;

    //需要额外处理出队最后一个元素的情况
    if (Q->rear == p) {
        Q->rear = Q->front;
    }

    delete(p);
    return true;
}
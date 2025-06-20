typedef int ElemType;

#define QueueSize 20

typedef struct
{
    ElemType data[QueueSize];
    int front;
    int rear;
}SqQueue;

//创建空队列
bool InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + QueueSize) % QueueSize;
}

bool EnQueue(SqQueue *Q, ElemType e)
{
    //判断队满
    if ((Q->rear + 1) % QueueSize == Q->front) {
        return false;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % QueueSize;

    return true;
}

bool DeQueue(SqQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear) {
        return false;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % QueueSize;

    return true;
}
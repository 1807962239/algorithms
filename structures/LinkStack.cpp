typedef int ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode;

typedef struct
{
    StackNode *top;
    int count;  //可选
}LinkStack;

bool Push(LinkStack *S, ElemType e)
{
    StackNode *s = new StackNode;
    s->data = e;
    s->next = S->top;

    S->top = s;
    S->count++;

    return true;
}

bool Pop(LinkStack *S, ElemType *e)
{
    if (!S->top) {
        return false;
    }

    StackNode *q = S->top;
    *e = q->data;

    S->top = q->next;
    S->count--;

    delete(q);
    return true;
}
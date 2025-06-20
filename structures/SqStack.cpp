typedef int ElemType;

#define MAXSIZE 20

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

bool Push(SqStack *S, ElemType e)
{
    //考虑栈满的情况
    if (S->top + 1 == MAXSIZE) {
        return false;
    }

    S->data[++S->top] = e;
    return true;
}

bool Pop(SqStack *S, ElemType *e)
{
    if (S->top == -1) {
        return false;
    }

    *e = S->data[S->top--];
    return true;
}

typedef struct
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

bool Push(SqDoubleStack *S, ElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2) {
        return false;
    }

    if (stackNumber == 1) {
        S->data[++S->top1] = e;
    } else if (stackNumber == 2) {
        S->data[--S->top2] = e;
    }
    
    return true;
}

bool Pop(SqDoubleStack *S, ElemType *e, int stackNumber)
{
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return false;
        }
        *e = S->data[S->top1--];
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return false;
        }
        *e = S->data[S->top2++];
    }
    return true;
}
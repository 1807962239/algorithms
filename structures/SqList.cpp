#define MaxSize 100

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length; 
}SqList;

//这里i表示取第几个，e用来存储查找的元素
bool GetElem(SqList L, int i, ElemType *e)
{
	//考虑空表和i不合法的情况
	if (L.length == 0 || i < 1 || i > L.length) {
		return false;
	}
	
	*e = L.data[i - 1];
	
	return true;
}

//i表示插入到第几个位置
bool ListInsert(SqList *L, int i, ElemType e)
{
	//考虑表已满和i不合法的情况
	if (L->length == MAXSIZE || i < 1 || i > L->length + 1) {
		return false;
	}

	//插入位置不是表尾的情况，插入位置及其后面的元素需要逐个后移
	if (i <= L->length) {
		for (int index = L->length; index >= i; index--) {
			L->data[index] = L->data[index - 1];
		}
	}
	
	L->data[i - 1] = e;
	L->length++;

	return true;
}

//i表示删除第几个元素
bool ListDelete(SqList *list, int i, ElemType *e)
{
    //考虑为空表和i不合法的情况
    if (list->length == 0 || i < 1 || i > list->length) {
        return false;
    }

    *e = list->data[i - 1];

    //删除位置不是表尾的情况，删除位置及其后面的元素需要逐个前移
    if (i < list->length) {
        for (int index = i - 1; index < list->length - 1; index++) {
            list->data[index] = list->data[index + 1];
        }
    }

    list->length--;
    return true;
}

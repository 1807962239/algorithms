#include <iostream>

typedef std::string String;

/* 返回从pos位置开始，匹配到T作为S子串的第一个位置，匹配不到返回0
    字符索引从0开始，位置从1开始 */

//朴素的模式匹配
int Index(String S, String T, int pos)
{
    if (pos < 1 || pos > S.length()) {
        return 0;
    }

    //主串开始匹配的索引
    int i = pos - 1;

    //子串从索引0开始
    int j = 0;

    //i = S.length()代表匹配到头了
    //j = T.length()代表已经匹配到了
    while(i < S.length() && j < T.length()) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            //j代表往前走了几步，-j+1则是上一轮开始匹配索引的后一位索引
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == T.length()) {
        //此时i是匹配到的主串中子串的最后一个字符的后一位索引
        //j是i和j一起走过的步数，也就是子串长度
        //i - j就是开始匹配的索引，再+1就是位置
        return i - j + 1;
    }
    
    return 0;
}


//KMP算法

//构建next数组
void buildNext(String S, int next[]) {
    next[0] = -1;  // 初始化第一个位置为-1（特殊标记）
    
    int i = 0, j = -1;  // i是"主指针"，j是"匹配指针"

    while (i <  S.length() - 1) {  
        if (j == -1 || S[i] == S[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

//主函数
int Index_KMP(String S, String T, int pos) {
    if (pos < 1 || pos > S.length()) {
        return 0;
    }
    
    int i = pos - 1;  // 主串指针
    int j = 0;        // 匹配串指针
    int next[T.length()];
    
    buildNext(T, next); // 预处理next数组
    
    while (i < S.length() && j < T.length()) {
        if (j == -1 || S[i] == T[j]) { 
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    
    if (j == T.length()) {
        return i - j + 1; 
    }
    
    return 0;
}

//改良版的KMP算法
void buildNextval(String S, int next[]) {
    next[0] = -1;  // 初始化第一个位置为-1（特殊标记）
    
    int i = 0, j = -1;  // i是"主指针"，j是"匹配指针"

    while (i <  S.length() - 1) {  
        if (j == -1 || S[i] == S[j]) {
            i++;
            j++;
            if (S[i] == S[j]) {
                next[i] = next[j];  // 直接继承更早的跳转位置
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }
}
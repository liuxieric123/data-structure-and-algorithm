#include <stdio.h>
#include <string.h>
// brure-force
int BF_Index(char *s, char *t, int pos)
{
    int m, n, i, j;
    m = strlen(s);
    n = strlen(t);
    i = pos;
    while(i <= (m-n))
    {
        for(j = 0; j < n; j++)
        {
            if(s[i + j] == t[j])
            {
                if(j == (n - 1))
                {
                    return i + 1;
                }
                continue;
            } 
            else 
            {
                i++;
                break;
            }
        }      
    }
    return -1;
}

// kmp
void get_next(char *t, int *next)
{
    int n = strlen(t);
    int j = 2;
    next[0] = -1;
    if (n == 1)
    {
        return;
    }
    next[1] = 0;
    if (n == 2)
    {
        return;
    }
    while(j < n)
    {
        // 如果后缀最后一个字符与前缀最后一个字符相等，则将j位的next在next[j-1]基础上加1
        if (t[j - 1] == t[next[j - 1]]) 
        {
            next[j] = next[j - 1] + 1;
            j++;
        }
        // 如果上述条件不成立，判断后缀的最后一个字符是否与前缀的第一个字符相等，相等则j位置1
        else if (t[j - 1] == t[0]) 
        {
            next[j] = 1;
            j++;
        }
        // 如果上述两个条件均不成立，则前后缀没有公共部分，next置0
        else
        {
            next[j] = 0;
            j++;
        }
    }
    return;
}

int KMP_Index(char *s, char *t, int pos)
{
    int m, n, i, j, k;
    m = strlen(s);
    n = strlen(t);
    int next[n];
    get_next(t, next);
    i = pos;
    j = 0;
    while(i < (m - n))
    {
        if (s[i] == t[j])
        {
            if(j == (n - 1))
            {
                return i + 2 - n;
            }
            i++;
            j++;
            continue;
        }
        // 如果字符不匹配，根据当前位置对应的next值进行处理
        else
        {
            if (next[j] == -1)
            {
                i++;
            }
            else
            {
                j = next[j];
            }
        }
    }
    return -1;
}

int main(void)
{
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    printf("%i", KMP_Index(a, b, 0));
    return 0;
}
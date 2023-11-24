#include <stdio.h>
#include <string.h>
#define gc getchar_unlocked
template <typename T>
void getNum(T &val)
{
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc())
        if (ch == '-')
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - '0', ch = gc())
        ;
    if (bo)
        val = -val;
}
int main()
{
    int t;
    getNum<int>(t);
    while (t--)
    {
        int n;
        char c;
        char s[200000];
        getNum<int>(n);
        scanf("%c %s", &c, s);
        int i, j = strlen(s), index = 0;
        for (i = 0; s[i] != '\0'; i++, j++)
            if (s[i] != c)
            {
                s[j] = s[i];
            }
            else
            {
                index = i;
                break;
            }

        if (c == 'x' && s[index] == 'x')
        {
            printf("0\n");
            continue;
        }
        int st1 = -1, st2 = -1, fn1 = -1, fn2 = -1;
        for (i = index; i < n + index; i++)
        {
            if (s[i] == c && st1 == -1)
                st1 = i;

            else if (s[i] == c && st1 != -1 && st2 == -1 && fn1 != -1)
                st2 = i;

            if (s[i] == 'x' && fn1 == -1)
                fn1 = i;

            else if (s[i] == 'x' && fn1 != -1 && fn2 == -1 && st1 != -1 && st2 != -1)
                fn2 = i;

            if (st1 != -1 && st2 != -1 && fn1 != -1 && fn2 != -1)
                break;
        }
        if (fn2 == -1 && st2 == -1)
            printf("%d\n", fn1 - st1);
        else if (fn2 == -1)
            printf("%d\n", (fn1 - st1) > (fn1 + n - st2) ? (fn1 - st1) : (fn1 + n - st2));
        else
            printf("%d\n", (fn1 - st1) > (fn2 - st2) ? (fn1 - st1) : (fn2 - st2));
    }
    return 0;
}

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

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
    int jml, uang, tc;
    getNum<int>(tc);
    while (tc--)
    {
        int langkah = 0, total = 0;

        priority_queue<int> descending;
        priority_queue<long, vector<long>, greater<long>> ascending;
        getNum<int>(jml);
        vector<int> daftarAngka;
        for (int i = 0; i < jml; i++)
        {
            getNum<int>(uang);
            total += uang;
            daftarAngka.push_back(uang);
        }

        if (total % jml != 0)
        {
            printf("-1\n");
            continue;
        }

        int target = total / jml;
        for (int data : daftarAngka)
        {
            if (data != target)
            {
                if (data < target)
                    ascending.push(data);
                else
                    descending.push(data);
            }
        }

        while (descending.size() != 0 && ascending.size() != 0)
        {
            int selisih = (descending.top() - ascending.top()) / 2;
            langkah++;
            if (ascending.top() + selisih != target)
            {
                if (ascending.top() + selisih < target)
                    ascending.push(ascending.top() + selisih);
                else
                    descending.push(ascending.top() + selisih);
            }

            if (descending.top() - selisih != target)
            {
                if (descending.top() - selisih < target)
                    ascending.push(descending.top() - selisih);
                else
                    descending.push(descending.top() - selisih);
            }
            descending.pop();
            ascending.pop();
        }
        printf("%d\n", langkah);
    }
    return 0;
}
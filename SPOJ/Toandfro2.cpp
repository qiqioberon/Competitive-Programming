#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
        {
            break;
        }
        char s[1000]; // Batasan panjang string, sesuaikan sesuai kebutuhan.
        scanf("%s", s);

        int batasI = 0;
        int panjang = strlen(s);
        int batasAwal = (n * 2) - 1;
        int batasAkhir = 1;
        int i = 0;

        while (i < panjang)
        {
            if (i < panjang)
            {
                if (i == batasI)
                {
                    if (s[i] >= 'a' && s[i] <= 'z')
                    {
                        printf("%c", s[i]);
                    }
                }
                i += batasAwal;
                if (i < panjang)
                {
                    if (s[i] >= 'a' && s[i] <= 'z')
                    {
                        printf("%c", s[i]);
                    }
                }
                i += batasAkhir;
                if (i < panjang)
                {
                    if (s[i] >= 'a' && s[i] <= 'z')
                    {
                        printf("%c", s[i]);
                    }
                }
            }

            if (i >= panjang)
            {
                batasI++;
                i = batasI;
                batasAwal -= 2;
                batasAkhir += 2;
            }
            if (batasI == n || batasAwal <= 0 || batasAkhir >= n * 2)
            {
                break;
            }
        }

        printf("\n");
    }

    return 0;
}

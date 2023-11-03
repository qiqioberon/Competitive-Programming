#define gc getchar_unlocked //define gc


//buat vscode karna getchar_unlocked berbahaya di vscode
//jadi diganti getchar biar bisa jalan
inline char getchar_unlocked()
{
    return getchar();
}

//jika int
void get(int &val)
{
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = getchar_unlocked(); ch < '0' || '9' < ch; ch = getchar_unlocked())
        if (ch == '-')
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - '0', ch = getchar_unlocked())
        ;
    if (bo)
        val = -val;
}

//bebas tipe data
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

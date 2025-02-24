#include <iostream>
int main()
{
    int x = 0;
    while (x < 7)
    {
        x += 1;

        if (x == 3)
        {
            std::cout << "continue x=" << x << std::endl;
            continue; // 後続の処理をスキップする。whileの条件に関わるような処理はこの後続に書かないように(無限ループになる)
        }

        if (x == 6)
        {
            std::cout << "break x=" << x << std::endl;
            break; // ループを抜ける
        }

        std::cout << "increment in while x=" << x << std::endl;
    }
    std::cout << "while done x=" << x << std::endl;

    for (int i = 0; i < 5; ++i) // 前置インクリメントはコピーが発生しないのでこちらの書き方が通例
    {
        std::cout << "increment in for loop i=" << i << std::endl;
    }

    return 0;
}
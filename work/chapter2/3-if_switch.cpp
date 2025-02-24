#include <iostream>

int main()
{
    int x;
    std::cout << "数値を入力してください。: ";
    std::cin >> x;

    if (0 < x < 11)
    {
        std::cout << "1 ~ 10の値です。: " << x << std::endl;
    }
    else if (10 < x < 21)
    {
        std::cout << "11~20の値です。 : " << x << std::endl;
    }
    else
    {
        std::cout << "1 ~ 20以外の値です。 : " << x << std::endl;
    }

    // switch : 使用できるxの型 int型, enum型のどちらかのみ
    // if文よりも効率が良いらしい(if文は上から実行していくが、switchは直接そのケースに飛ぶ)
    switch (x)
    {
    case 0:
        std::cout << "0が入力されました!" << std::endl;
        break;
    case 10:
        std::cout << "10が入力されました!" << std::endl;
        break;
    default:
        break;
    }

    return 0;
}
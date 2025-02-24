#include <iostream>
#include <cstdint> // int32_t で必要
int main()
{
    // 宣言
    int a = 5;
    std::cout << a << std::endl; // 5

    // 以下でも可能
    int b;
    b = 10;
    std::cout << b << std::endl; // 10

    // 初期値を設定しないまま出力してみる(不定な値が入るので注意)
    int c;
    std::cout << c << std::endl; // 実行するたびに変わる0とか982467264とか

    // const
    const int d = 1;
    // d = 2; // これはエラー

    // constexpr 定数
    constexpr int e = 3;

    // 型推論
    auto f = 5;
    std::cout << f << std::endl;

    // bool
    bool ok = true;

    // char
    char char_ = 'x';

    // サイズ指定付き整数型
    // 型のサイズがコンパイラによってまちまちなので、複数のコンパイラに対応するプログラムを書くときはサイズ指定つき整数型を使用する
    std::int32_t g = 5;
    std::cout << g << std::endl; // 5

    // 浮動小数点(float)
    float h = 1.234;
    std::cout << h << std::endl; // 1.234

    // 浮動小数点(double)
    // doubleの方が精度が良い。計算に時間がかかる。
    double i = 1.234;
    std::cout << i << std::endl; // 1.234

    // auto(自動推論)
    auto j = 100;
    auto k = 'A';
    auto l = 1.234;
    std::cout << typeid(j).name() << std::endl; // i : intのi
    std::cout << typeid(k).name() << std::endl; // c : charのc
    std::cout << typeid(l).name() << std::endl; // d : doubleのd 自動推論の場合はdoubleが割り当てられる(おそらくコンパイラ次第でfloat)
}
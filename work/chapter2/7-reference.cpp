#include <iostream>

int main()
{
    /**
     * 参照
     * 「 型　&参照変数名 = 変数名 」とすることで、変数の別名(エイリアス)を作成する。
     */
    int x = 5;
    int &ref_x = x;                  // xのアドレスではなく、そのままxを渡す。
    std::cout << ref_x << std::endl; // 5

    // 参照を通じて値を変更
    ref_x = 10;
    std::cout << x << std::endl; // 10

    // 参照は実体の別名なので、アドレスも同じになる
    std::cout << &x << std::endl;     // 0x7ffd66eda55c
    std::cout << &ref_x << std::endl; // 0x7ffd66eda55c

    // const参照(readonlyになる)
    int y = 20;
    const int &const_ref_y = y;
    // const_ref_y = 30; // const参照は値の変更ができない

    // ポインタとの関係
    int *x_ptr = &x;
    int &from_pointer_x = *x_ptr;

    return 0;
}
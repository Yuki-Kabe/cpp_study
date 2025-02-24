#include <iostream>
int main()
{
    /**
     * ポインタ
     * 「 型* ポインタ変数名 = &変数名 」 で行う
     * & : 参照演算子
     */

    int x = 5, y = 10;
    int *x_p = &x;                 // ポインタ変数の宣言
    std::cout << x_p << std::endl; // 0x7ffeeb59fcd4

    x_p = &y;                      // 参照先の変更
    std::cout << x_p << std::endl; // 0x7ffeeb59fcd8
    x_p = &x;

    /**
     * デリファレンス
     * 「 *ポインタ変数 」 で行う
     */
    // デリファレンス
    std::cout << *(x_p) << std::endl; // 5
    std::cout << *(&x) << std::endl;  // もちろんこっちも可能(&xをデリファレンス)

    // デリファレンスで値を変更
    *(x_p) = 10;
    std::cout << x << std::endl; // 10

    // デリファレンスして値をコピー
    int z = *(x_p);
    std::cout << z << std::endl; // 10

    /**
     * nullポインタ
     * 参照がないことを明示的に表す。ポインタ変数 = NULLでも同じ意味になるらしいが、C++11からはnullptrの使用が推奨されている
     */
    int *null_p = nullptr;

    /**
     * constポインタ
     * constをつける位置が2種類ある。
     * 「 const 型 *ポインタ変数 = &変数 」 : 参照先の値の固定(readonly的な感じになる。forループとか、関数の引数とかで使われることがある)
     * 「 型 *const ポインタ変数 = &変数 」: ポインタの固定(参照先アドレスを変更できない)。*がconstにつくことに注意
     */
    const int *const_x_p = &x;
    // *const_x_p = 3; // デリファレンスによる値を変更することはできない(readonly)
    x = 20;                                 // x自体の値の変更は可能なので注意。あくまでポインタを通した値の変更はできないだけ(readonly)
    std::cout << *(const_x_p) << std::endl; // 20

    int *const x_const_p = &x;
    // x_const_p = &y; // 参照先アドレスの変更は不可能

    return 0;
}
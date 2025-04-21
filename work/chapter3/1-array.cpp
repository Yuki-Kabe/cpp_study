#include <iostream>

void printArr(const int *array_p, int size);

int main()
{
    // 初期化
    int x[5] = {0, 1, 2, 3, 4};
    int y[] = {5, 6, 7, 8, 9}; // 要素数を省略できる
    int z[3];                  // size=3の配列を初期化(値は不定なものが入るので注意)
    int w[3] = {};             // 全て0で初期化される = {0, 0, 0}

    // アクセス
    int x_0 = x[0];
    x[0] = 10;
    z[0] = 1;
    z[1] = 2;
    std::cout << x[0] << std::endl; // 10
    std::cout << z[2] << std::endl; // 250409904
    std::cout << w[2] << std::endl; // 0

    /** 配列はポインタに暗黙変換される
     * ローカル変数で宣言された配列は、関数引数に渡す際に先頭要素へのポインタに変換される。
     * そのため、ポインタを通して要素にアクセスすることができる。
     * 連続したメモリで確保するため、先頭のポインタにインデックスを足すことで次の要素にスライドできる
     */
    int *x_p = x;
    std::cout << *(x_p) << std::endl;     // 10=x[0]
    std::cout << *(x_p + 1) << std::endl; // 1=x[1]
    // xはポインタ型なのでもちろんこれもできる
    std::cout << *(x + 2) << std::endl; // 2=x[2]

    /** ループ
     * 配列のサイズはローカルの場合に限ってsizeof()で取得できる
     * sizeof() : 配列全体のバイト数を求める
     *「 sizeof(array) / sizeof(array[0]) 」 で配列の要素数を取得できる。
     */
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); ++i)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    // 関数に配列を渡す場合はサイズ情報が失われるので、呼び出し側でサイズを計算して渡す
    printArr(y, sizeof(y) / sizeof(y[0]));

    return 0;
}

/** 関数に配列を渡す
 * 関数の引数で配列を渡すときは、実際には配列はポインタに暗黙変換される。
 * そのため、配列のサイズ情報は失われるので、サイズを別途渡す必要がある。
 */
void printArr(const int *array_p, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array_p[i] << " ";
    }
    std::cout << std::endl;
}
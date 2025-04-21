#include <iostream>

int main()
{
    int x[] = {1, 2, 3};
    /** iterを使ったループ
     * std::begin(array)で配列の先頭要素を指すイテレータを取得できる
     * std::end(array)で最終要素の1つ先を指すイテレータを取得できる。end()はループの終了判定などに使われる
     * イテレータを使用することでコンテナの種類に依存しないで処理を共通化できる
     */
    // forループ
    for (auto iter = std::begin(x); iter != std::end(x); ++iter)
    {
        std::cout << *(iter) << " "; // iterはポインタのように扱うのでデリファレンスで値を取り出す(ポインタとは違うらしい)
    }
    std::cout << std::endl;

    // whileループ
    auto iter = std::begin(x);
    while (iter != std::end(x))
    {
        std::cout << *(iter) << " ";
        ++iter;
    }
    std::cout << std::endl;

    return 0;
}
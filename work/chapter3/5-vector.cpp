#include <vector>
#include <iostream>

int main()
{
    // 初期化
    std::vector<int> vec_1 = {1, 2, 3, 4, 5};
    std::vector<int> vec_2(3); // {0, 0, 0}

    // アクセス
    vec_1.at(0); // 1

    // 要素数の取得
    size_t size = vec_1.size();

    /** 要素の追加/削除
     * emplace_back(value) : 末尾に入力のvalueで要素を追加 (push_back()もあるが、emplace_back()の方がパフォーマンスが良い)
     * pop_back() : 末尾の要素を削除
     * insert(iter, value) : iterの位置にvalueを追加する。(後ろがずれるので計算量O(N))
     * erase(iter) : iterの位置の要素を削除する。
     */
    vec_1.emplace_back(6); // {1, 2, 3, 4, 5, 6}
    vec_1.pop_back();      // {1, 2, 3, 4, 5}
    // 3番目に10を追加
    auto iter = vec_1.begin();  // 先頭のiterを取得
    vec_1.insert(iter + 2, 10); // {1, 2, 10, 3, 4, 5}

    // insert()後にiterがリセットされるのでそのまま実行すると先頭が削除される
    vec_1.erase(iter);     // {2, 10, 3, 4, 5}
    vec_1.erase(iter + 2); // {2, 10, 4, 5}

    // 先頭のポインタを取得
    int *vec_1_ptr = vec_1.data(); // 0x55a4fc8bbed0
    *(vec_1_ptr);                  // 1
    *(vec_1_ptr + 1);              // 2

    // ループ
    for (int i = 0; i < vec_1.size(); ++i)
    {
        std::cout << vec_1.at(i) << " ";
    }
    std::cout << std::endl;

    // iterを使ったループ
    for (auto iter = vec_1.begin(); iter != vec_1.end(); ++iter)
    {
        std::cout << *(iter) << " ";
    }
    std::cout << std::endl;

    // range basedなループ
    for (const int &ref : vec_1)
    {
        std::cout << ref << " ";
    }
    std::cout << std::endl;
}
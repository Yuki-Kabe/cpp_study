#include <iostream>
#include <set>
#include <unordered_set>

int main()
{
    /** setとunordered_set
     * std::set : 平行二分木で実装されており、キーがソートされている。探索の計算量はO(log_n)
     * std::unordered_set : ハッシュテーブルで実装されており、キーはソートされていないが、探索の計算量はO(1)。ハッシュが衝突すると最悪O(n)
     * どちらも使い方は同じ。基本的にunordered_setの方がパフォーマンスが高いので、キーに順序を持たせるとかでなければこっちが良さそう
     */

    // 初期化
    std::set<std::string> set = {
        "Alice",
        "Bob",
    };
    std::unordered_set<std::string> unordered_set = {
        "Thomas",
        "Mickel",
    };

    /** 要素の存在確認
     * set.count(要素) : 存在する場合は1、存在しない場合は0が返る
     * set.find(要素) : 存在する場合はその要素のiter、存在しない場合はend()が返る
     */
    std::cout << set.count("Alice") << std::endl;              // 1
    std::cout << set.count("element_not_exist_") << std::endl; // 0

    auto iter = set.find("Alice");
    std::cout << "Key: " << *iter << std::endl; // Alice

    /** 要素の追加と削除
     * set.insert(要素) : 指定された値で要素を追加
     * set.erase(要素) : 指定されたキーの要素を削除
     */
    set.insert("Eve");
    unordered_set.insert("Kevin");

    // 要素の削除
    set.erase("Bob");

    // iterを使用したループ
    for (auto iter = set.begin(); iter != set.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    // range basedなループ
    for (const std::string &ref : set)
    {
        std::cout << ref << " ";
    }
    std::cout << std::endl;

    /** メンバ関数
     * set.size() : 要素数を取得
     * set.empty() : 要素数が0ならtrue
     * set.clear() : 要素を全て削除
     */

    // 要素数の取得
    std::cout << "set.size(): " << set.size() << std::endl; // 2

    // 要素が空かどうかを確認
    std::cout << "set.empty(): " << set.empty() << std::endl; // 0

    // 要素を全て削除
    set.clear();
    std::cout << "set.empty(): " << set.empty() << std::endl; // 1
}
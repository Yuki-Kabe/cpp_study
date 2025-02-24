#include <map>
#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
    /**
     * mapとunordered_map
     * std::map : 平行二分木で実装されており、キーがソートされている。探索の計算量はO(log_n)
     * std::unordered_map : ハッシュテーブルで実装されており、キーはソートされていないが、探索の計算量はO(1)。ハッシュが衝突すると最悪O(n)
     * どちらも使い方は同じ。基本的にunordered_mapの方がパフォーマンスが高いので、キーに順序を持たせるとかでなければこっちが良さそう
     */

    // 初期化
    std::map<std::string, int> map = {
        {"Alice", 18},
        {"Bob", 20},
    };
    std::unordered_map<std::string, int> unordered_map = {
        {"Thomas", 30},
        {"Mickel", 25},
    };

    /** 要素参照について
     * 次の2パターンあるが、.at()によるアクセスが安全
     * map["キー"] : 存在しないキーにアクセスすると、新しく要素がデフォルト値で作成されてしまう。
     * map.at("キー") : 存在しないキーにアクセスすると、std::out_of_range のポインタが返る
     */
    map["Alice"];               // 18
    unordered_map.at("Thomas"); // 30
    map["key_not_exist"];       // 存在しないキーなので{"key_not_exist", 0}が追加される
    // unordered_map.at("Test"); // これはエラーになる

    /** 要素の追加と削除
     * map.insert({"キー", 値}) : 指定された値で要素を追加
     * map.erase("キー") : 指定されたキーの要素を削除
     */
    map.insert({"Eve", 19});
    unordered_map.insert({"Kevin", 40});

    // 要素の削除
    map.erase("Thomas");

    // iterを使用したループ
    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        // キー : iter->first
        // バリュー : iter->second
        // iterはポインタのような扱いをするので->でアクセスする(実際ポインタとは違うらしい)
        std::cout << "Key: " << iter->first << "\tValue: " << iter->second << std::endl;
    }

    // range basedなループ
    for (const std::pair<std::string, int> &pair_ref : unordered_map)
    {
        std::cout << "Key: " << pair_ref.first << "\tValue: " << pair_ref.second << std::endl;
    }
}
#include <utility> // std::pair で必要
#include <tuple>   // std::tie() で必要
#include <string>
#include <iostream>

int main()
{
    // 初期化(3パターンある)
    std::pair<std::string, int> pair_1{"Bob", 20};
    std::pair<std::string, int> pair_2("Alice", 30);
    std::pair<std::string, int> pair_3 = std::make_pair("Thomas", 40);

    /** 要素アクセス
     *  2通りある
     * 「 std::get<インデックス>(変数名) 」でアクセスできる
     * 「 変数名.first, 変数名.second 」 でもアクセス可能
     */
    std::get<0>(pair_1); // "Bob"
    std::get<1>(pair_1); // 20
    pair_1.first;        // "Bob"
    pair_1.second;       // 20

    // std::tie()でペアの要素を個別の変数にまとめて代入できる
    std::string name;
    int age;
    std::tie(name, age) = pair_1; // name: "Bob", age: 20
}
#include <tuple>
#include <string>
#include <iostream>

int main()
{
    // 初期化(3パターンある)
    std::tuple<std::string, int> tuple1{"Bob", 20};
    std::tuple<std::string, int> tuple2("Alice", 30);
    std::tuple<std::string, int, double> tuple3 = std::make_tuple("Thomas", 30, 170.0);

    // 要素アクセス
    std::get<0>(tuple1); // "Bob"
    std::get<1>(tuple1); // 20

    // std::tie()で個別の変数にまとめて代入できる
    std::string name;
    int age;
    double height;
    std::tie(name, age, height) = tuple3; // name: "Tohams", age: 20, height: 170.0
}
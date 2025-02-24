#include <iostream>
int main()
{
    // enum
    enum Day
    {
        Sun, // 0
        Mon, // 1
        Tue, // 2
        Wed, // 3
        Thu, // 4
        Fri, // 5
        Sat  // 6
    };
    std::cout << Wed << std::endl; // 3
    int a = Sat;                   // 変数に代入
    std::cout << a << std::endl;   // 6

    enum Numbers
    {
        Zero,      // 0
        One,       // 1
        Two,       // 2
        Seven = 7, // 7 : 数を指定できる
        Eight,     // 8 = 7+1 : 指定した数を基準に再度数字を割り当てる
        Nine,      // 9
        Ten,       // 10
        // Sun // これはDayで指定したのでエラーになる
    };
    std::cout << Zero << std::endl; // 0

    // enum class
    enum class EnumClassDay
    {
        Sun, // 0
        Mon, // 1
        Tue, // 2
        Wed, // 3
        Thu, // 4
        Fri, // 5
        Sat  // 6
    };
    std::cout << static_cast<int>(EnumClassDay::Tue) << std::endl; // intにキャストする必要あり。また、{enum class名}::{enum}で指定する必要がある
    int b = static_cast<int>(EnumClassDay::Fri);                   // こちらもキャストする必要あり

    enum class EnumClassNumbers
    {
        Zero,      // 0
        One,       // 1
        Two,       // 2
        Seven = 7, // 7
        Eight,     // 8
        Nine,      // 9
        Ten,       // 10
        Sun        // 11 : enum class の場合は{enum class名}::{enum}で指定するため、一意に特定できるので同じenumを使える
    };
    std::cout << static_cast<int>(EnumClassNumbers::Sun) << std::endl; // 11

    return 0;
}
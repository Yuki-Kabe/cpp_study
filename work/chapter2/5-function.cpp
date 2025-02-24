#include <iostream>

// 前方宣言
int Add(int x, int y);
int Add(std::string x, std::string y);

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

/**
 * コマンドライン引数
 * argc : コマンドラインで渡された引数の個数
 * argv[] : コマンドラインで渡された引数がchar*で格納されるstringにする場合はキャストが必要
 *  argv[0] : 実行ファイル名
 *  argv[1]~ : 渡された引数
 */
int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    HelloWorld();
    std::cout << Add(1, 2) << std::endl; // 3
    // オーバーロードしたメソッド
    std::cout << Add("10", "1") << std::endl; // 11

    /**
     * 関数ポインタ
     * 「 戻り値の型 (*関数ポインタ変数名)(引数の型) = 関数名; 」で宣言する
     */
    int (*function_p)(int, int) = Add;
    std::cout << Add(3, 5) << std::endl; // 8
}

// mainの前で前方宣言する必要あり
int Add(int x, int y)
{
    return x + y;
}

// 関数のオーバーロード(引数の個数や型が異なる場合、同じ名前の関数を定義することができる)
int Add(std::string x, std::string y)
{
    return std::stoi(x) + std::stoi(y);
}
#include <iostream>
#include <string>
#include <cstring> // C言語スタイルの文字列操作に必要

std::string concatStdString(const std::string &s1, std::string &s2);
void concatCString(const char *s1, const char *s2, char *dest, size_t dest_size);

int main()
{
    std::string s1 = "ABC", s2 = "DEF";
    std::cout << s1 << std::endl; // ABC

    // 要素にアクセス
    std::cout << s1[0] << std::endl; // A
    std::cout << s1[1] << std::endl; // B
    // at()を使うと範囲外にアクセスしたときにエラーが投げられるので安全にアクセスできる
    std::cout << s1.at(2) << std::endl; // C
    // std::cout << s1.at(3) << std::endl; // 安全にアクセスできる
    // std::cout << s1[4] << std::endl; // こちらは実行できてしまう

    /**
     * 文字列の取得
     * .size()か.length()でできる。どちらもバイト数なのでマルチバイト文字(ascii以外の日本語とか)を使うときは文字数と異なるので注意
     */
    std::cout << s1.length() << std::endl;

    // 関数に文字列を渡す
    std::string concated_str = concatStdString(s1, s2);
    std::cout << concated_str << std::endl;

    // 上と同じことをC言語スタイルの文字列で同じことをやる
    // std::string の c_str() を使うと、C言語スタイルの null終端文字列(const char*) に変換できる
    const char *c1 = s1.c_str();
    const char *c2 = s2.c_str();
    // オーバーフローしないくらい十分大きなバッファを用意する必要がある
    char concat_str_buffer[50];
    concatCString(c1, c2, concat_str_buffer, sizeof(concat_str_buffer)); // 配列は関数に渡すとポインタに暗黙的に変換されるのでconcat_str_bufferのまま渡す
    // std::coutに文字列ポインタを渡すと、先頭アドレスから始まり、ヌル終端文字\0に辿りつくまで文字列を出力し続けるので文字列全体が出力できる
    std::cout << concat_str_buffer << std::endl;
}

/** 関数に文字列を渡す
 * 配列とは違ってそのまま渡せる
 * コピーするとコストが高いので参照で受け取ることが多いらしい。
 * std::stringは動的にメモリを管理しているので、配列のサイズを気にすることなく操作できる
 */
std::string concatStdString(const std::string &s1, std::string &s2)
{
    return s1 + s2;
}

/** 関数にC言語スタイル文字列を渡す
 * バッファのサイズを自前で管理する必要あり
 * *dest : 新しく結果を格納する配列のポインタ
 * dest_size : *destはarray decayされて、単なる先頭要素のポインタなのでサイズ情報がない。そのためsizeof()で正しい情報を取得できないので、sizeを別途渡してあげる必要がある
 */
void concatCString(const char *s1, const char *s2, char *dest, size_t dest_size)
{
    // s1をdestにコピー
    std::strcpy(dest, s1);
    // 現在の dest に格納されている文字数(バイト数)を取得し、
    // 残りのバッファサイズを計算して s2 を連結する。(null終端文字列分を考慮して-1する)
    std::strncat(dest, s2, dest_size - std::strlen(dest) - 1);
}

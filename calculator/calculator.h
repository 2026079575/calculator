#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

class Calculator{
public:
    stack<string>infix;//中缀
    stack<string> symbol;//符号
    stack<string> suffix;//后缀
    stack<string> count;//计算
    //输出中缀栈
    void print_infix();
    //中缀转后缀
    void infix_to_suffix();
    //输出后缀栈
    void print_suffix();
    //输出字符栈
    void print_symbol();
    //判断是否为数字
    bool isNumber(const std::string& str);
    //分割入栈
    void segmentation_str(const string &str);
    //判断优先级
    int priority(const string &str);
    //处理括号
    void curly_bracket_processing();
    //后缀栈翻转
    void suffix_flipping();
    //计算结果
    void calculation_results();
    //输出结果
    void print_result();
    //初始化所有栈
    void initialization();
    //检查格式
    bool check(const string &str);
//    void printStack();

};




#endif
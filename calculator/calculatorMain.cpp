#include "calculator.h"

int main() {
    Calculator calculator;
//    string input = "1+(33+24)*6";//132+6*+
//    string input = "1+2+(3+4+5*6)*7"; // 12+34+56*+7*+
//    string input = "1+2+3";//12+3+
//    string input = "1+2*3+4";//123*+4+
//    string input = "6*((5+(2+3)*8)+3)";//6523+8*+3+*
//    string suffixExpression;
//    calculator.segmentation_str(input);
////    calculator.printInfix();
//    calculator.infix_to_suffix();
//    calculator.calculation_results();
    string input;
    cout << "输入Q将会终止程序" << endl;
    cout << "请输入要计算的式子类似1+(33+24)*6" << endl;
    while (true){
        cout << "请输入: ";
        getline(cin,input);
        if (input == "Q"){
            cout << "感谢使用!Bye Bye~";
            break;
        }
        if(!calculator.check(input)){
            cout << "输入格式有问题,请重新输入!" << endl;
            cout << "请输入: ";
        }else{
            calculator.initialization();
            calculator.segmentation_str(input);
            calculator.infix_to_suffix();
            calculator.calculation_results();
            cout << input<<"=";
            calculator.print_result();
            cout << endl;
        }
    }
    return 0;
}

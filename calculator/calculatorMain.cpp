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
    cout << "����Q������ֹ����" << endl;
    cout << "������Ҫ�����ʽ������1+(33+24)*6" << endl;
    while (true){
        cout << "������: ";
        getline(cin,input);
        if (input == "Q"){
            cout << "��лʹ��!Bye Bye~";
            break;
        }
        if(!calculator.check(input)){
            cout << "�����ʽ������,����������!" << endl;
            cout << "������: ";
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

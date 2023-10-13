
#include "calculator.h"


void Calculator::segmentation_str(const string &str) {
    stack<string> x;
    stringstream ss(str);
    string token;
    char c;
    while (ss.get(c)) {
        if (!isdigit(c)) { // ����ַ��������֣�����зָ�
            if (!token.empty()) {
                x.push(token);
                token.clear();
            }
            x.emplace(1,c);
        } else {
            token += c; // ����ַ������֣�������ӵ���ǰ��token��
        }
    }
    if (!token.empty()) {
        x.push(token); // �����һ��token��ջ
    }
    while (!x.empty()){
        infix.push(x.top());
        x.pop();
    }
}


void Calculator::print_infix() {
    cout << "��׺ջ" << endl;
    while (!infix.empty()){
        cout << infix.top() << endl;
        infix.pop();
    }
}
void Calculator::print_suffix() {
    cout << "��׺ջ" << endl;
    while (!suffix.empty()){
        cout << suffix.top() << endl;
        suffix.pop();
    }
}
void Calculator::print_symbol() {
    cout << "����ջ" << endl;
    while (!symbol.empty()){
        cout << symbol.top() << endl;
        symbol.pop();
    }
}
bool Calculator::isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
int Calculator::priority(const string &str) {
    if (str == "*" || str == "/") {
        return 2;
    }
    else if (str == "+" || str == "-") {
        return 1;
    }
    return 0;
}
void Calculator::curly_bracket_processing(){
    symbol.push(infix.top());
    infix.pop();
    while (infix.top()!=")"){
        if (infix.top()=="("){
            curly_bracket_processing();
        } else if (isNumber(infix.top())){
            suffix.push(infix.top());
            infix.pop();
        } else if ((infix.top()=="+"||infix.top()=="-"||infix.top()=="*"||infix.top()=="/")&&symbol.top()=="("){
            symbol.push(infix.top());
            infix.pop();
        } else if ((infix.top()=="+"||infix.top()=="-"||infix.top()=="*"||infix.top()=="/")&&symbol.top()!="("){
            if (priority(infix.top())> priority(symbol.top())){
                symbol.push(infix.top());
                infix.pop();
            } else if (priority(infix.top())==priority(symbol.top())){
                suffix.push(infix.top());
                infix.pop();
            } else if (priority(infix.top())<priority(symbol.top())){
                suffix.push(symbol.top());
                symbol.pop();
                if (priority(symbol.top())==priority(infix.top())&&symbol.top()!="("){
                    suffix.push(infix.top());
                    infix.pop();
                }
            }
        }
    }
    if (infix.top()==")"){
        infix.pop();
        while (symbol.top()!="("){
            suffix.push(symbol.top());
            symbol.pop();
        }
        symbol.pop();
    }

}

void Calculator::infix_to_suffix() {
    while (!infix.empty()){
        if (isNumber(infix.top())) {
            suffix.push(infix.top());
            infix.pop();
        }else if ((infix.top()=="+"||infix.top()=="-"||infix.top()=="*"||infix.top()=="/")&&symbol.empty()){
            symbol.push(infix.top());
            infix.pop();
        }else if (infix.top()=="("){
            curly_bracket_processing();
        } else if ((infix.top()=="+"||infix.top()=="-"||infix.top()=="*"||infix.top()=="/")&&symbol.top()!="("){
            if (priority(infix.top())> priority(symbol.top())){
                symbol.push(infix.top());
                infix.pop();
            } else if (priority(infix.top())==priority(symbol.top())){
                suffix.push(infix.top());
                infix.pop();
            } else if (priority(infix.top())<priority(symbol.top())){
                suffix.push(symbol.top());
                symbol.pop();
                if (priority(symbol.top())==priority(infix.top())&&symbol.top()!="("){
                    suffix.push(infix.top());
                    infix.pop();
                }
            }
        } else if ((infix.top()=="+"||infix.top()=="-"||infix.top()=="*"||infix.top()=="/")&&symbol.top()=="("){
            symbol.push(infix.top());
            infix.pop();
        }
//        infix.pop();
    }
    while (!symbol.empty()){
        suffix.push(symbol.top());
        symbol.pop();
    }
    suffix_flipping();
}

void Calculator::suffix_flipping() {
    stack<string> x;
    while (!suffix.empty()) {
        x.push(suffix.top());
        suffix.pop();
    }
    suffix=x;
}

void Calculator::calculation_results() {
    while (!suffix.empty()){
        if (isNumber(suffix.top())) {
            count.push(suffix.top());
            suffix.pop();
        } else if (suffix.top()=="+"||suffix.top()=="-"||suffix.top()=="*"||suffix.top()=="/") {
            string num1 = count.top();
            count.pop();
            string num2 = count.top();
            count.pop();
            if(suffix.top()=="+"){
                suffix.pop();
                count.push(to_string(stod(num2)+stod(num1)));
            } else if (suffix.top()=="-"){
                suffix.pop();
                count.push(to_string(stod(num2)-stod(num1)));
            } else if (suffix.top()=="*"){
                suffix.pop();
                count.push(to_string(stod(num2)*stod(num1)));
            } else if (suffix.top()=="/"){
                suffix.pop();
                count.push(to_string(stod(num2)/stod(num1)));
            }
        }
    }
}

void Calculator::print_result() {
    cout << count.top();
    count.pop();
}

void Calculator::initialization() {
    while (!infix.empty()) {
        infix.pop();
    }
    while (!symbol.empty()) {
        symbol.pop();
    }
    while (!suffix.empty()) {
        suffix.pop();
    }
    while (!count.empty()) {
        count.pop();
    }
}

bool Calculator::check(const string &str) {
    for (char c : str) {
        if (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            return true; // �����Ƿ��ַ�
        }
    }
    return false; // �������Ƿ��ַ�
}




#include <iostream>
#include <stack>

using namespace std;

string equation;
stack<char> s;

int prec(char op)
{
	switch (op) {
	    case '(': case ')': return 0;
	    case '+': case '-': return 1;
	    case '*': case '/': return 2;
	}
	return -1;
}

string infix_to_posix(string str){
    int idx = 0;
    char op;
    string tmp = "";
    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        switch(now){
            case '+':
            case '-':
            case '*':
            case '/':
                while(!s.empty() && (prec(now) <= prec(s.top()))){
                    tmp += s.top();
                    s.pop();
                }
                s.push(now);
                break;
            case '(':
                s.push(now);
                break;
            case ')':
                op = s.top();
                s.pop();
                while(op != '('){
                    tmp += op;
                    op = s.top();
                    s.pop();
                }
                break;
            default:
                tmp += now;
                break;
        }
    }
    while(!s.empty()){
        tmp += s.top();
        s.pop();
    }
    return tmp;
}

int main(void){
    cin >> equation;
    string result = infix_to_posix(equation);
    cout << result << '\n';
    return 0;
}
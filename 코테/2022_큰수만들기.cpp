#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    int temp = 0;
    for (int i = 0; i < number.length(); i++) {
        if (s.empty()) s.push(number.at(i));
        else {
            if (k <= temp) {
                s.push(number.at(i));
            }
            else {
                if (s.top() < number.at(i)) {
                    while (!s.empty() && (s.top() < number.at(i))) {
                        if (k <= temp)break;
                        temp++;
                        s.pop();
                    }
                    s.push(number.at(i));
                }
                else {
                    s.push(number.at(i));
                }
            }
        }
    }
    while (temp < k) {
        temp++;
        s.pop();
    }
    stack<char> ss;
    while (!s.empty()) {
        char c = s.top();
        //cout<<c<<" ";
        s.pop();
        ss.push(c);
    }
    while (!ss.empty()) {
        char c = ss.top();
        ss.pop();
        answer += c;
    }
    return answer;
}
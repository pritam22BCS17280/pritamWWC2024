/*
Que 4:-- Valid parenthesis on leet code.
*/
Code:
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> stack;
    // Mapping of closing brackets to opening brackets
    unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
    
    for (char c : s) {
        if (mapping.count(c)) { // If it is a closing bracket
            // Get the top element of the stack, or a dummy value if the stack is empty
            char topElement = stack.empty() ? '#' : stack.top();
            stack.pop();
            // If the mapping does not match, return false
            if (mapping[c] != topElement) {
                return false;
            }
        } else {
            // It's an opening bracket, push onto the stack
            stack.push(c);
        }
    }
    
    // If the stack is empty, the parentheses are valid
    return stack.empty();
}

int main() {
    string s = "{[()]}";
    if (isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
/*
OUTPUT:-
  
Valid
  */

  

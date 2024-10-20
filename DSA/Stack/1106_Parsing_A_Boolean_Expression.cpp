#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

bool parseBoolExpr(string expression) {
    stack<char> st;  // Stack to hold operators and operands (true/false values)
    for (char &ch : expression) {
        if (ch == '(' || ch == ',') continue;  // Ignore opening parentheses and commas
        
        if (ch == 't' || ch == 'f' || ch == '!' || ch == '|' || ch == '&') {
            st.push(ch);  // Push boolean values and operators onto the stack
        }
        else if (ch == ')') {  // When we encounter a closing parenthesis
            bool hasTrue = false, hasFalse = false;
            
            // Pop the stack and evaluate the expression within parentheses
            while (!st.empty() && st.top() != '!' && st.top() != '|' && st.top() != '&') {
                char val = st.top();  // Get the top value
                st.pop();
                
                if (val == 't') hasTrue = true;
                if (val == 'f') hasFalse = true;
            }
            
            char op = st.top();  // Get the operator ('!', '|', '&')
            st.pop();  // Remove the operator from the stack
            
            char result = 'f';  // Default result is 'false'
            
            if (op == '!') {
                result = hasTrue ? 'f' : 't';  // '!' negates the truth value
            }
            else if (op == '&') {
                result = (hasFalse) ? 'f' : 't';  // '&' returns true only if all are true
            }
            else if (op == '|') {
                result = hasTrue ? 't' : 'f';  // '|' returns true if at least one is true
            }
            
            st.push(result);  // Push the result of the expression back onto the stack
        }
    }
    
    return st.top() == 't';  // The final result will be at the top of the stack
}


int main() {
    // Test cases
    string expr1 = "!(&(t,f,t))";  // Expected result: true (negation of AND of t, f, t)
    string expr2 = "|(f,t)";       // Expected result: true (OR of f, t)
    string expr3 = "&(t,t,f)";     // Expected result: false (AND of t, t, f)

    // Call the function with test expressions
    cout << "Expression: " << expr1 << " -> " << (parseBoolExpr(expr1) ? "true" : "false") << endl;
    cout << "Expression: " << expr2 << " -> " << (parseBoolExpr(expr2) ? "true" : "false") << endl;
    cout << "Expression: " << expr3 << " -> " << (parseBoolExpr(expr3) ? "true" : "false") << endl;

    return 0;
}

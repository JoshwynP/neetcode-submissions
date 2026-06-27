class Solution {
public:
    int eval(char op, int a, int b) {
    switch (op) {
        case '*': return a * b;
        case '+': return a + b;
        case '-': return a - b;
        case '/': return (b != 0) ? a / b : 0;
        default:  return 0;
    }
}

    int evalRPN(vector<string>& tokens) {
        std::stack<string> mystack;

        int a,b;
        for (string s: tokens)
        {
            if (s == "+" ||s == "-" || s == "*" || s == "/")
            {
                b = stoi(mystack.top());
                mystack.pop();
                a = stoi(mystack.top());
                mystack.pop();
                mystack.push(std::to_string(eval(s[0], a, b)));
            }
            else
            {
                mystack.push(s);
            }
        }
        return std::stoi(mystack.top());
    }
};

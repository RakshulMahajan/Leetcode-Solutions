class Solution {
public:
    bool parseBoolExpr(string expression) {
    stack<char> stk;

    for (char ch : expression) {
        if (ch == ',' || ch == '(') {
            continue;
        }

        if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
            stk.push(ch);
        } else if (ch == ')') {
            bool hasTrue = false, hasFalse = false;
            while (stk.top() == 't' || stk.top() == 'f') {
                hasTrue |= stk.top() == 't';
                hasFalse |= stk.top() == 'f';
                stk.pop();
            }

            char op = stk.top();
            stk.pop();

            bool result;
            if (op == '!') {
                result = !hasTrue;
            } else if (op == '&') {
                result = !hasFalse;
            } else {
                result = hasTrue;
            }

            stk.push(result ? 't' : 'f');
        }
    }

    return stk.top() == 't';
}

};
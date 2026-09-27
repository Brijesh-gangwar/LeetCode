class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");

        for (char ch : s) {
            if (ch == '(') {
                st.push("");
            } else if (ch == ')') {
                string topstr = st.top();
                st.pop();

                reverse(topstr.begin(), topstr.end());

                if (st.empty()) {
                    st.push(topstr);
                } else {
                    string prevstr = st.top();
                    st.pop();

                    prevstr += topstr;
                    st.push(prevstr);
                }
            } else {
                string topstr = st.top();
                st.pop();

                topstr += ch;
                st.push(topstr);
            }
        }
        return st.top();
    }
};
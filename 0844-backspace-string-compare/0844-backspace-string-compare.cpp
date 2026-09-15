class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st1;

        // Process of s
        for (char ch : s) {
            if (ch == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(ch);
            }
        }

        // Process of t
        for (char ch : t) {
            if (ch == '#') {
                if (!st1.empty())
                    st1.pop();
            } else {
                st1.push(ch);
            }
        }

        // Compareing the resulting stacks
        if (st.size() != st1.size())
            return false;

        while (!st.empty()) {
            if (st.top() != st1.top())
                return false;

            st.pop();
            st1.pop();
        }

        return true;
    }
};
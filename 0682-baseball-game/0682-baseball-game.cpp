class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string op : operations) {
            if (op == "C") {
                st.pop();
            }
            else if (op == "D") {
                st.push(st.top() * 2);
            }
            else if (op == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            }
            else {
                st.push(stoi(op));
            }
        }

        int result = 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};


class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, subtreeSize, heavy;
    vector<int> head, pos;
    int timer = 0;

    vector<int> seg;
    int base = 1;

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    // First DFS: find parent, depth, subtree size and heavy child.
    void dfs1(int u, int p) {
        parent[u] = p;
        subtreeSize[u] = 1;
        int largest = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs1(v, u);

            subtreeSize[u] += subtreeSize[v];

            if (subtreeSize[v] > largest) {
                largest = subtreeSize[v];
                heavy[u] = v;
            }
        }
    }

    // Second DFS: assign HLD positions and chain heads.
    void dfs2(int u, int h, string& s, vector<int>& arr) {
        head[u] = h;
        pos[u] = timer;
        arr[timer++] = charMask(s[u]);

        if (heavy[u] != -1) {
            dfs2(heavy[u], h, s, arr);
        }

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            dfs2(v, v, s, arr);
        }
    }

    void build(vector<int>& arr) {
        while (base < (int)arr.size())
            base *= 2;

        seg.assign(2 * base, 0);

        for (int i = 0; i < (int)arr.size(); i++)
            seg[base + i] = arr[i];

        for (int i = base - 1; i >= 1; i--)
            seg[i] = seg[2 * i] ^ seg[2 * i + 1];
    }

    // XOR of positions in [l, r).
    int rangeQuery(int l, int r) {
        int result = 0;

        for (l += base, r += base; l < r; l /= 2, r /= 2) {
            if (l & 1)
                result ^= seg[l++];

            if (r & 1)
                result ^= seg[--r];
        }

        return result;
    }

    void update(int p, int value) {
        p += base;
        seg[p] = value;

        for (p /= 2; p >= 1; p /= 2)
            seg[p] = seg[2 * p] ^ seg[2 * p + 1];
    }

    // XOR of all node characters on the path u -> v.
    int pathQuery(int u, int v) {
        int result = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            result ^= rangeQuery(pos[head[u]], pos[u] + 1);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        result ^= rangeQuery(pos[u], pos[v] + 1);

        return result;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.resize(n);
        depth.assign(n, 0);
        subtreeSize.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);

        dfs1(0, -1);

        vector<int> arr(n);
        timer = 0;
        dfs2(0, 0, s, arr);

        build(arr);

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;
            string third;

            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];

                s[u] = c;
                update(pos[u], charMask(c));
            } else {
                int v = stoi(third);
                int mask = pathQuery(u, v);

                // Zero or one set bit means palindrome is possible.
                answer.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};

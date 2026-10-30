
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Build directed graph.
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count]
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Starting node itself counts as 1 character.
        dist[0][1] = 0;

        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, count] = pq.top();
            pq.pop();

            // Skip outdated states.
            if (cost != dist[u][count])
                continue;

            // First valid destination state popped is optimal.
            if (u == n - 1)
                return (int)cost;

            // Explore neighbours.
            for (auto [v, w] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = count + 1;
                }
                else {
                    newCount = 1;
                }

                // Invalid consecutive sequence.
                if (newCount > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCount]) {

                    dist[v][newCount] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};

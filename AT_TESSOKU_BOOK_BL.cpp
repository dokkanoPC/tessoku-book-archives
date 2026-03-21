#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric> // std::iota()
#include <queue>
#include <functional>
void Show(const std::vector<int> &v)
{
    std::cout << ": {";

    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] + 1;

        if (i != v.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "}\n";
}
struct Edge
{
    int to;
    int cost; // 重みあり
    /*p() {
        // 直接x, yにアクセスできる
        std::pair p{to, cost};
        return p;
  }*/
};
int main()
{
    int N, a, b, c, M;
    std::queue<int> Q;
    std::cin >> N >> M;
    std::vector<std::vector<Edge>> G(N);
    for (int i = 0; i < M; i++)
    {
        std::cin >> a >> b >> c;
        G.at(a - 1).push_back({b - 1, c});
        G.at(b - 1).push_back({a - 1, c}); // 方向なし
    }
    std::vector<long long> v(N, -1);
    Q.push(0);
    v[0] = 0;
    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for (int i = 0; i < G.at(top).size(); i++)
        {
            int to = G.at(top).at(i).to;
            if (v.at(to) == -1)
            {
                Q.push(to);
                v.at(to) = v.at(top) + G.at(top).at(i).cost;
                // std::cout << to << ' ' << v.at(to) << '\n';
            }
            else if (v.at(top) + G.at(top).at(i).cost < v.at(to))
            {
                // std::cout << to << ' ' << v.at(to) << '\n';
                Q.push(to);
                v.at(to) = v.at(top) + G.at(top).at(i).cost;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << '\n';
    }
}

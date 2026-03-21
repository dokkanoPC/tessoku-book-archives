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
/*struct Edge {方向あり
    int from;
    int to;
    int cost;//重みあり
 };*/
int main()
{
    int N, a, b, M;
    std::queue<int> Q;
    std::cin >> N >> M;
    std::vector<std::vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        std::cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1); // 方向なし
    }
    std::vector<int> v(N, -1);
    Q.push(0);
    v[0] = 0;
    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for (int i = 0; i < G.at(top).size(); i++)
        {
            int to = G.at(top).at(i);
            if (v.at(to) == -1)
            {
                Q.push(to);
                v.at(to) = v.at(top) + 1;
            }
            /*else if (v.at(top) + 1 < v.at(to))
            {
                Q.push(to);
                v.at(to) = v.at(top) + 1;
            }*/
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << '\n';
    }
}

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
/*struct Edge
{
    int to;
    int cost;
};*/
int main()
{
    int N, a, M;
    std::queue<int> Q;
    std::cin >> N >> M;
    std::vector<std::vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        std::cin >> a;
        G.at(i).push_back(a - 1;);
    }
}

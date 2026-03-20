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
int main()
{
    int N, M, a, b;
    std::cin >> N >> M;
    std::vector<std::vector<int>> G(N);
    while (M--)
    {
        std::cin >> a >> b;
        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1); // 方向なし
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << i + 1;
        Show(G.at(i));
    }
}
#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int64_t a, b, c;
        std::cin >> a >> b >> c;
        if (a * b != c)
            std::cout << "16 BIT S/W ONLY" << '\n';
        else
            std::cout << "POSSIBLE DOUBLE SIGMA" << '\n';
    }
}
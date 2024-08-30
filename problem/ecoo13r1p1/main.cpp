#include <iostream>
#include <string>

using namespace std;

string getInputLine()
{
    while (cin.good())
    {
        string str;
        getline(cin, str);
        if (str.empty())
            continue;
        return str;
    }
    return "";
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N = 0;
    cin >> N;
    int late = 0;
    int remain = 0;
    while (true)
    {
        auto str = getInputLine();
        if (str.empty() || str == "EOF")
            break;
        if (str == "TAKE")
        {
            N++;
            if (N > 999)
                N = 1;
            late++;
            remain++;
        }
        else if (str == "SERVE")
        {
            remain--;
        }
        else if (str == "CLOSE")
        {
            cout << late << " " << remain << " " << N << endl;
            late = 0;
            remain = 0;
        }
    }
    return 0;
}
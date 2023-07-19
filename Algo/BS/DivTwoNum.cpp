#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int i = 0, n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int j = 0; j < n + 1; j++)
    {
        a[j] = i++;
    }

    int s = 0, e = a.size() - 1;
    int q = 0, r = 0;

    int m = s + (e - s) / 2;
    while (s <= e)
    {

        if (a[m] * k <= n)
        {
            q = a[m];

            r = n - k * a[m];
            s = m + 1;
        }
        else if (a[m] * k > n)
            e = m - 1;

        m = s + (e - s) / 2;
    }

    cout << q << " " << r;

    return 0;
}
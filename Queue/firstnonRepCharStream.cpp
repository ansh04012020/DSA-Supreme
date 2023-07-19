#include <iostream>
#include <queue>
#include <string>

using namespace std;
void fstNonRepchr(queue<int> &que)
{
}

int main()
{
    string str = "zarcaazrd", ans = "";
    int freq[26] = {0};
    queue<char> que;
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        freq[ch - 'a']++;
        que.push(ch);

        while (!que.empty())
        {
            if (freq[que.front() - 'a'] == 1)
            {
                ans.push_back(que.front());
                break;
            }
            else
                que.pop();
        }

        if(que.empty())
        ans.push_back('#');
    }
    cout << ans;

    return 0;
}

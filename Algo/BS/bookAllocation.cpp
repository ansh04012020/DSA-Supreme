#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, t;
    cin >> n;
    vector<int> bookPages;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        bookPages.push_back(t);
    }
    int m;
    cin >> m;
    vector<int> student(bookPages.begin(), bookPages.begin() + m);

    vector<int> index(m - 1);
    for (int i = 0; i < m - 1; i++)
        index[i] = i + 1;

    int k = m;

    int min = INT_MAX, minI, turns = 0;


    while(turns<n-m){
        min=INT_MAX;

    for (auto i : student)
        cout << i << " ";
    cout << endl;
   

    for (int j = 0; j < m; j++)
    {
        if (j == m - 1 && (student[m - 1] + bookPages[k] < min))
        {
            min = student[m - 1] + bookPages[k];
            minI = m - 1;
            // k++;
        }
        else if (j!=m-1 && student[j] + bookPages[index[j]] < min)
        {
            min = student[j] + bookPages[index[j]];
            minI = j;
        }
    }
 

    cout << min << " " << minI << endl;

    for (int i = minI; i < m; i++)
    {
        if ( i == m - 1 )
        {
            student[i] = student[i]+bookPages[k];
            k++;
        }
        
        else  
        {
            student[i] += bookPages[index[i]];
            student[i+1]-=bookPages[index[i]];
            index[i] = index[i] + 1;
        }
      
    }
 for (auto i : student)
        cout << i << " ";
cout << endl<<endl;

     turns++;
    }
    int max=INT_MIN;
    for (auto i : student)
    {
        if(i>max)
        max=i;
    }
    cout<<max<<endl;

    return 0;
}
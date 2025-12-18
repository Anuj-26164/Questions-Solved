

// C++ program to generate
// n-bit Gray codes

#include <bits/stdc++.h>
using namespace std;

vector<string> generateGray(int n)
{
    if (n <= 0)
        return {"0"};

    if (n == 1)
    {
        return {"0", "1"};
    }

    vector<string> recAns =
        generateGray(n - 1);
    vector<string> mainAns;

    for (int i = 0; i < recAns.size(); i++)
    {
        string s = recAns[i];
        mainAns.push_back("0" + s);
    }
    for (int i = recAns.size() - 1; i >= 0; i--)
    {
        string s = recAns[i];
        mainAns.push_back("1" + s);
    }
    return mainAns;
}

void generateGrayarr(int n)
{
    vector<string> arr;
    arr = generateGray(n);
    for (int i = 0; i < arr.size();
         i++)
        cout << arr[i] << endl;
}

int main()
{
    int n;cin>>n;
    generateGrayarr(n);
    return 0;
}
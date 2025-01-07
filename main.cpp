#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countMax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING_ARRAY upRight as parameter.
 */

long countMax(vector<string> upRight)
{
    int n = upRight.size();
    vector<int> row(n, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < n; i++)
    {
        string s = upRight[i];
        istringstream ss(s);
        string token;
        getline(ss, token, ' ');
        row[i] = stoi(token);
        getline(ss, token, ' ');
        col[i] = stoi(token);
    }

    int minRow = *min_element(row.begin(), row.end());
    int minCol = *min_element(col.begin(), col.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (long long)(row[i] - minRow) * (col[i] - minCol);
    }

    return ans;
}
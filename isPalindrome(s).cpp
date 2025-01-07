class Solution
{
public:
    bool isPalindrome(string s)
    {
        s = regex_replace(s, regex("[^a-zA-Z0-9]"), "");
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int st = 0;
        int ed = s.length() - 1;

        while (st < ed)
        {
            if (s[st] == s[ed])
            {
                st++;
                ed--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
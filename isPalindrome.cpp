class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
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
/*

other solotion

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        long num = 0;
        long tmp = x;
        while (x > 0)
        {
            num = num * 10 + x % 10;
            x /= 10;
        }
        if (tmp == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
*/
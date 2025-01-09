class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]])
            {
                result -= roman[s[i]];
            }
            else
            {
                result += roman[s[i]];
            }
        }
        return result;
    }
};

{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}

;
/*
class Solution
{
public:
    int romanToInt(string s)
    {

        const pair<int, const char *> roman_map[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        int result = 0;
        for (const auto &entry : roman_map)
        {
            while (s.find(entry.second) == 0)
            {
                result += entry.first;
                s = s.substr(strlen(entry.second));
            }
        }
        return result;
    }
};

*/
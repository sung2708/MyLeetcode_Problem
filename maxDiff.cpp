class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxS = s;
        for (char& c : maxS) {
            if (c != '9') {
                char from = c;
                for (char& ch : maxS) {
                    if (ch == from) ch = '9';
                }
                break;
            }
        }
        
        string minS = s;
        if (minS[0] != '1') {
            char from = minS[0];
            for (char& ch : minS) {
                if (ch == from) ch = '1';
            }
        } else {
            for (int i = 1; i < minS.size(); ++i) {
                if (minS[i] != '0' && minS[i] != '1') {
                    char from = minS[i];
                    for (int j = 0; j < minS.size(); ++j) {
                        if (minS[j] == from) minS[j] = '0';
                    }
                    break;
                }
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
    string t = "#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    int C = 0, R = -1, rad; 
    int resC=1, resLen=1;
    vector<int> p(t.size(), 0);
    for (int i = 0; i < t.length(); ++i) {
        if (i <= R) {
            rad = min(p[2*C-i], R-i); 
        } else {
            rad = 0; 
        }
        // Try to extend
        while (i+rad < t.size() && i-rad >= 0 && t[i-rad] == t[i+rad]) {
            rad++; 
        }
        p[i] = rad-1;
        if (i + rad - 1 > R) {
            C = i; 
            R = i + rad - 1; 
        }
        if(resLen< p[i] ){
            resLen=p[i];
            resC=i;
        }
    }   

        return s.substr( (resC- resLen)/2, resLen);
    }
};

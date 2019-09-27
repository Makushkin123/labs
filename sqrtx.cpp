//https://leetcode.com/problems/sqrtx/ 
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        double a = 0.0;
        double b = 1.0;
        
        do{
            a = b;
            b = (a + (x / a)) / 2;
        }while(abs(b - a) > 0.0001);
        return (int)b;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

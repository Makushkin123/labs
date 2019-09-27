// https://leetcode.com/problems/factorial-trailing-zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0; 
        do{
            n = n / 5; 
            sum = n + sum; 
        }while (n > 0); 
        return sum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

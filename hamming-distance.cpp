//https://leetcode.com/problems/hamming-distance/ 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0; 
        while(x != 0 || y != 0){
            if((x % 2) != (y % 2)){
                count++; 
            }
            x = x / 2; 
            y = y / 2; 
        }
        return count; 
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        std::string::size_type b1 = 0, b2 = 0;
        std::string::size_type n1, n2;
        while (b1 < v1.size() || b2 < v2.size()) {
            if (b1 < v1.size())
                n1 = std::stoi(v1.substr(b1));
            else
                n1 = 0;
            if (b2 < v2.size())
                n2 = std::stoi(v2.substr(b2));
            else
                n2 = 0;
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
            b1 = v1.find('.', b1);
            b2 = v2.find('.', b2);
            if (b1 == std::string::npos) {
                b1 = v1.size();
            }
            else {
                b1++;
            }
            if (b2 == std::string::npos) {
                b2 = v2.size();
            }
            else {
                b2++;
            }
        }
        return 0;
    }
};

int main() {
    std::cout << Solution().compareVersion("1.3", "1.4") << std::endl;

    return 0;
}

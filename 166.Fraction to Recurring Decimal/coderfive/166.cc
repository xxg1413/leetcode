#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <sstream>
using std::string;

class Solution {
public:
    string fractionToDecimal(int arg_num, int arg_den) {
        long long numerator = arg_num, denominator = arg_den;
        std::ostringstream buf;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            buf << '-';
        numerator = std::abs(numerator);
        denominator = std::abs(denominator);
        long long d = numerator/denominator;
        numerator %= denominator;
        buf << d;
        if (numerator != 0)
            buf << '.';
        else
            return buf.str();
        std::vector<int> num;
        std::vector<int> div;
        while (numerator != 0) {
            auto it = std::find(num.begin(), num.end(), numerator);
            if (it != num.end()) {
                auto i = it-num.begin();
                std::copy(div.begin(), div.begin()+i, std::ostream_iterator<int>(buf, ""));
                buf << '(';
                std::copy(div.begin()+i, div.end(), std::ostream_iterator<int>(buf, ""));
                buf << ')';
                return buf.str();
            }
            num.push_back(numerator);
            numerator *= 10;
            d = numerator/denominator;
            div.push_back(d);
            numerator %= denominator;
        }
        std::copy(div.begin(), div.end(), std::ostream_iterator<int>(buf, ""));
        return buf.str();
    }
};


int main() {
    std::cout << Solution().fractionToDecimal(1, 3) << std::endl
              << Solution().fractionToDecimal(1, 2) << std::endl
              << Solution().fractionToDecimal(2, 1) << std::endl
              << Solution().fractionToDecimal(-2147483648, -1) << std::endl;

    return 0;
}

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            int i = 0, j = 0, size = path.size();
            for (; j < size; j++) {
                if (!(i > 0 && path[i-1] == '/' && path[j] == '/'))
                        path[i++] = path[j];
                if (path[j] == '/') {
                     while (j < size && path[j] == '/')
                         j++;
                     j--;
                     if (j+2 < size && path[j+1] == '.' && path[j+2] == '.'
                         && (j+3 == size || path[j+3] == '/')) {
                         if (prev_slash (path, i)) {
                             path[i++] = '.';
                             path[i++] = '.';
                         }
                         j += 2;
                     }
                     else if (j+1 < size && path[j+1] == '.'
                             && (j+2 == size || path[j+2] == '/')) {
                         j += 1;
                     }
                 }
            }
            path.resize (i);
            if (i == 0) path.push_back ('/');
            if (path.size() != 1 && path.back() == '/')
                path.pop_back();
            return path;
        }
        int prev_slash (string& path, int& i) {
            int j = i-2;
            if (i == 1 && path[0] == '/') return 0;
            while (j >= 0 && path[j] != '/') j--;
            if (j < 0) return 1;
            else {
                if (j+3 < i && path[j+1] == '.' && path[j+2] == '.' && path[j+3] == '/')
                    return 1;
                else
                    i = j+1;
            }
            return 0;
        }
};

/*
 * input: string_without_space ## string_without_space
 */

int main() {
    int err = 0;
    string buf, path, ret, expected;

    while (true) {
        cin >> path;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().simplifyPath(path);
        if (ret != expected) {
            err = 1;
            cout << "input: '" << path << "'\n"
                 << "ret: '" << ret << "'\n"
                 << "expected: '" << expected << "'\n\n";
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}

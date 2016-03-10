class Solution {
public:
    void reverseWords(string &s) {
	string res;
	int end = s.size()-1;
	int begin;
	while (end >= 0) {
	    while (end >= 0 && std::isspace(s[end])) end--;
	    if (end < 0) break;
	    begin = end-1;
	    while (begin >= 0 && !std::isspace(s[begin])) begin--;
	    std::copy(s.begin()+begin+1, s.begin()+end+1, std::back_inserter(res));
	    end = begin;
	    res.push_back(' ');
	}
	if (res.size() > 0) res.pop_back();
	s = res;
    }
};

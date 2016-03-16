class Solution {
public:
    int evalRPN(vector<string>& tokens) {
	int i = tokens.size()-1;
	return eval (tokens, i);
    }
    int eval (vector<string>& tokens, int& i) {
	if (i < 0) return 0;
	string& s = tokens[i--];
	if (s.size() != 1 || std::isdigit(s[0])) {
	    return std::stoi(s); 
	}
	int right = eval (tokens, i);
	int left = eval (tokens, i);
	switch (s[0]) {
	    case '+':
		return left+right;
	    case '-':
		return left-right;
	    case '*':
		return left*right;
	    case '/':
		return left/right;
	}
    }
};

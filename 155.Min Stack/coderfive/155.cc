class MinStack {
    vector<int> value;
    vector<int> min_v;
public:
    void push(int x) {
	value.push_back(x);
	if (min_v.empty())
	    min_v.push_back(x);
	else
	    min_v.push_back(std::min(x,min_v.back()));
    }

    void pop() {
	value.pop_back();
	min_v.pop_back();
    }

    int top() {
	return value.back();
    }

    int getMin() {
	if (min_v.empty()) return -1;
	return min_v.back();
    }
};

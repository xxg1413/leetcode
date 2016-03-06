class Solution {
public:
    int numTrees(int n) {
	    vector<int> v {0,1};
	    v.resize(n+1);
	    int stop, delta;
	    for (int i = 2; i <= n; i++) {
		    delta = 0;
		    v[i] = v[i-1];
		    stop = (i+1)/2;
		    if (i & 1) {
			    stop--;
			    delta = v[stop]*v[stop];
		    }
		    for (int j = 1; j < stop; j++)
			    v[i] += v[j] * v[i-j-1];
		    v[i] *= 2;
		    v[i] += delta;
	    }

	    return v[n];
    }
};

//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int first_maxx = -1;
	    int sec_maxx = -1;
	    for (int i=0; i<n; ++i) {
	        int x = arr[i];
	        if (x > first_maxx) {
	            sec_maxx = first_maxx;
	            first_maxx = x;
	        } else if (x < first_maxx && x > sec_maxx)
	            sec_maxx = x;
	    }
	    return sec_maxx;
	}
};
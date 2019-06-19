class Solution {
    public int mySqrt(int x) {
        if (x <= 1)
            return x;
        
        int mid = 1;
        int left = 1;
        int right = x;
	    while (left <= right) { 
		    mid = left + (right - left) / 2;
		    if (mid > x / mid)
			    right = mid - 1;
		    else if (mid < x / mid)
			    left = mid + 1;
            else
                return mid;
	    }
        return right;
    }
}
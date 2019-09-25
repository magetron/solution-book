// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int len = n;
    	char *cur = buf;
        int count = 0;
		while (n > 0) {
			count += read4(cur);
			cur += 4;
			n -= 4;
		}
		return min(count, len);	
    }
};



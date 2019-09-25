// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    int buf_p = 0;
    int r_len = 0;
    char buffer[5];

    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (buf_p == r_len) { // aligns
                buf_p = 0;
                r_len = read4(buffer);
                if (r_len == 0) break; // can't read anything
            }
            buf[i++] = buffer[buf_p++];
        }
        return i;
    }
    
};


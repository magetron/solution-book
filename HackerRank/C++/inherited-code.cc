#include <cstring>
class BadLengthException : public std::exception {
public:    
    int n;
    
    BadLengthException (int m) : n(m) {}
    
    const char* what() const throw () { 
        string ns = to_string(n);
        char *ret = new char[ns.length() + 1];
        strcpy(ret, ns.c_str());
        return ret;
    }
};



class BadLengthException : public std::exception {
public:
    int n;

    BadLengthException (int m) : n(m) {}

    int what() {
        return n;
    }
};


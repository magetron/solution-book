#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

static int fast_io = [] ()  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Rectangle {
public:
    int width, height;

    //Rectangle (int w, int h) : width(w), height(h) { }

    virtual void display () {
        cout << width << " " << height << endl; 
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input () {
        cin >> Rectangle::width >> Rectangle::height;
    }

    void display () {
        cout << Rectangle::width * Rectangle::height << endl;
    }
};

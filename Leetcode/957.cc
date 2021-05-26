#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
      vector<vector<int>> dictc{};

      vector<int> first{}; first.reserve(8);
      for (size_t i = 0; i < 8; i++) {
        if (i > 0 && i < 7) {
          first.push_back(cells[i - 1] == cells[i + 1] ? 1 : 0);
        } else {
          first.push_back(0);
        }
      }
      dictc.push_back(first);

      vector<int> prevc(first);
      vector<int> newc(first);

      int d = 0;
      while (d < 256) {
        std::fill(newc.begin(), newc.end(), 0);
        for (size_t i = 0; i < 8; i++) {
          if (i > 0 && i < 7) {
            if (prevc[i - 1] == prevc[i + 1]) {
              newc[i] = 1;
            }
          } else {
            // first end
            newc[i] = 0;
          }
        }
        prevc = newc;
        dictc.push_back(newc);
        d++;
        if (newc == first) break;
      }

      return dictc[(n - 1) % d];
    }
};



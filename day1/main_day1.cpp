//
// Created by Dino on 01.12.2023.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  vector<int> calibration_values{};

  string line{};
  ifstream i_stream{"input.txt"};
  if (i_stream.is_open()) {
    while (getline(i_stream, line)) {
      char f_num{0};
      char l_num{0};
      bool found_first{false};

      for (const char ch: line) {
        if (isdigit(ch)) {
          if (!found_first) {
            f_num = ch;
            found_first = true;
          }

          l_num = ch;
        }
      }
      string pair{f_num};
      pair += l_num;
      const int pair_int = stoi(pair);
      calibration_values.push_back(pair_int);
    }
    int sum{0};
    for (const int cv : calibration_values) {
      sum += cv;
    }
    cout << sum;
  }
  else {
    cout << "failed to open file";
  }
  i_stream.close();
  return 0;
}

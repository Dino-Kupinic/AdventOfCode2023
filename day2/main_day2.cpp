//
// Created by Dino on 06.12.2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

struct Set {
  vector<pair<int, string>> cubes;
};

struct Game {
  int id;
  vector<Set> sets;
};

int main() {
  vector<Game> games{};
  pair<int, string> max_red{12, "red"};
  pair<int, string> max_green{13, "green"};
  pair<int, string> max_blue{14, "blue"};

  string line{};
  ifstream i_stream{"example.txt"};
  if (i_stream.is_open()) {
    regex game_id_regex{"(\\d+)"};

    while (getline(i_stream, line)) {
      Game temp_game{};
      sregex_iterator id_iterator(line.begin(), line.end(), game_id_regex);
      sregex_iterator end;
      // match_results::begin?
      for (sregex_iterator i = id_iterator; i != end; ++i) {
        smatch match = *i;
        std::string match_str = match.str();
        std::cout << "  " << match_str << '\n';
      }
    }
  }
  else {
    cout << "failed to open file";
  }
  i_stream.close();
  return 0;
}

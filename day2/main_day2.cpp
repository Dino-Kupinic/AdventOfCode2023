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

vector<string> split_line_into_segments(const string&line) {
  vector<string> temp{};
  istringstream stream{line};
  string segment{};
  while (getline(stream, segment, ';')) {
    temp.push_back(segment);
  }
  return temp;
}

int main() {
  vector<Game> games{};
  pair<int, string> max_red{12, "red"};
  pair<int, string> max_green{13, "green"};
  pair<int, string> max_blue{14, "blue"};

  string line{};
  ifstream i_stream{"example.txt"};
  if (i_stream.is_open()) {
    regex game_id_regex{R"(\d+)"};
    regex cube_regex{R"([\d]+\s[\w]+(?:,[\d]+\s[\w]+)*)"};

    while (getline(i_stream, line)) {
      Game temp_game{};
      if (smatch matcher; regex_search(line, matcher, game_id_regex)) {
        const int game_id = stoi(matcher[0]);

        size_t idx_of_colon = line.find(':');
        vector<string> games_played = split_line_into_segments(line.substr(idx_of_colon));
        for (const auto& game: games_played) {
          for (auto i = sregex_iterator(game.begin(), game.end(), cube_regex); i != sregex_iterator(); ++i) {
            const smatch&matches = *i;
            std::cout << matches.str() << '\n';
          }
          std::cout<<"End of game"<<std::endl;
        }
      }
    }
  }
  else {
    cout << "failed to open file";
  }
  i_stream.close();
  return 0;
}

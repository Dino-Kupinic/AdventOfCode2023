//
// Created by Dino on 06.12.2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <ranges>

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

void parse_games(vector<Game>&games) {
  string line{};
  ifstream i_stream{"input.txt"};

  if (i_stream.is_open()) {
    const regex game_id_regex{R"(\d+)"};
    const regex cube_regex{R"([\d]+\s[\w]+(?:,[\d]+\s[\w]+)*)"};

    while (getline(i_stream, line)) {
      Game temp_game{};
      if (smatch matcher; regex_search(line, matcher, game_id_regex)) {

        const int game_id = stoi(matcher[0]);
        const size_t idx_colon = line.find(':');
        const vector<string> sets_played = split_line_into_segments(line.substr(idx_colon + 1));

        for (const auto&set: sets_played) {
          Set temp_set;
          for (auto i = sregex_iterator(set.begin(), set.end(), cube_regex); i != sregex_iterator(); ++i) {
            const smatch&matches = *i;
            const string cube_string = matches.str();
            const size_t idx_whitespace = cube_string.find(' ');
            const int cube_amount = stoi(cube_string.substr(0, idx_whitespace));
            const string cube_color = cube_string.substr(idx_whitespace + 1);
            const pair temp_pair{cube_amount, cube_color};
            temp_set.cubes.push_back(temp_pair);
          }
          temp_game.sets.push_back(temp_set);
        }
        temp_game.id = game_id;
        games.push_back(temp_game);
      }
    }
  }
  else {
    cout << "failed to open file";
  }
  i_stream.close();
}

int main() {
  vector<Game> games{};
  const pair<int, string> max_red{12, "red"};
  const pair<int, string> max_green{13, "green"};
  const pair<int, string> max_blue{14, "blue"};

  parse_games(games);
  vector<int> invalid_games;
  for (const auto&[id, sets]: games) {
    int sum_red{};
    int sum_green{};
    int sum_blue{};
    for (const auto&[cubes]: sets) {
      for (const auto&[amount, color]: cubes) {
        if (color == "red") {
          sum_red += amount;
        }
        if (color == "green") {
          sum_green += amount;
        }
        if (color == "blue") {
          sum_blue += amount;
        }
      }
    }
    const bool invalid_red = sum_red > max_red.first;
    const bool invalid_green = sum_green > max_green.first;
    const bool invalid_blue = sum_blue > max_blue.first;
    if (invalid_red || invalid_green || invalid_blue) {
      invalid_games.push_back(id);
    }
  }
  for (const auto game_id: invalid_games) {
    auto it = ranges::find_if(games, [game_id](const Game&game) {
      return game_id == game.id;
    });
    if (it != games.end()) {
      games.erase(it);
    }
  }
  int sum_valid_game_ids{};
  for (const auto&[id, sets]: games) {
    sum_valid_game_ids += id;
  }
  cout << sum_valid_game_ids;
  return 0;
}

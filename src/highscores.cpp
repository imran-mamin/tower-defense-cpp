
#include "highscores.hpp"

#include "json.hpp"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <vector>
#include <iostream>


const std::string highscoresKey = "highscores";


void HighScores::SortDecreasingOrder(const std::uint32_t level) {
	std::sort(highScores_[level].begin(), highScores_[level].end(), [](std::uint64_t h1, std::uint64_t h2){ return h1 > h2; });
}

/* TODO: Make sure there is no double entry for same level. */
HighScores::HighScores(const std::string &path) : path_(path) {
	std::ifstream is(path);
  	nlohmann::json data = nlohmann::json::parse(is);

	/* Go through the high scores. */
	for (const auto &levelAndHighscores : data[highscoresKey]) {
		std::uint32_t level;
		std::vector<std::uint64_t> highscores;

		data.at(levelAndHighscores[0]).get_to(level);
		std::cout << "success" << std::endl;
		data.at(level).get_to(highScores_[level]);
		
		/* Sort the scores in descending order. */
		SortDecreasingOrder(level);
	}

}

void HighScores::AddNewScore(const std::uint32_t level, const std::uint64_t highscore) {
	std::ofstream os(path_);
	nlohmann::json jsonfile;

	/* Add the new score and sort the vector. */
	highScores_[level].push_back(highscore);
	SortDecreasingOrder(level);

	/* For any level: if there is more than maximum number of entries, then
	 * remove the smallest ones until there is the maximum amount of entries. */
	for (auto level : highScores_) {
		while (level.second.size() > maxHighscoreCountPerLevel) {
			level.second.pop_back();
		}
	}

	/* Output the json data. */
	jsonfile[highscoresKey] = highScores_;
	os << jsonfile;
}


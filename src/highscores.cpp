
#include "highscores.hpp"

#include "json.hpp"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <vector>
#include <iostream>


const std::string highscoresKey = "highscores";

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
		data.at(level).get_to(highscores);
		
		highScores_[level] = std::vector<HighScore>();
		for (auto highscore : highscores) {
			highScores_[level].push_back(HighScore(highscore));
		}

		/* Sort the scores in descending order. */
		std::sort(highScores_[level].begin(), highScores_[level].end(), [](HighScore h1, HighScore h2){ return h1.Score() > h2.Score(); });
	}

}

void HighScores::AddNewScore(HighScore highscore) {
	//std::ofstream os(path_);
	//nlohmann::json jsonfile;

	/* Do we need to remove entry? */
	//if () {
		//
	//}
	/* TODO: */

	// TODO:

	//os << jsonfile;
}


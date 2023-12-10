
#pragma once

#include <cstdint>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

const std::uint32_t maxHighscoreCountPerLevel = 10;

class HighScore {
   public:
    HighScore(std::uint64_t score)
	: score_(score) {}

    std::uint64_t Score() const { return score_; }

   private:
    const std::uint64_t score_;
};

class HighScores {
   public:
	/* Load the highscores. */
    HighScores(const std::string &path);

    /* Return highscores for the wanted level or an empty vector if there are no
     * highscores for that level. */
    std::vector<HighScore> LevelHighscores(const std::uint32_t level) {
		if (highScores_.count(level)) {
		    return highScores_.at(level);
		}

		return std::vector<HighScore>();
    }

	/* Add a new highscore and save it. */
    void AddNewScore(HighScore highscore);

   private:
    std::map<std::uint32_t, std::vector<HighScore>> highScores_;
    const std::string path_;
};

class HighScoreReadingError : public std::runtime_error {
   public:
    HighScoreReadingError(const std::string &what) : std::runtime_error(what) {}
};


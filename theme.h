#pragma once
#include <string>

enum class Theme { Normal, Winter };

struct Assets {
    std::string clear_block;
    std::string dirt_block;
    std::string grass_block;
    std::string question_block;
    std::string brick_block;
    std::string cloud_top_left;
    std::string cloud_top_right;
    std::string cloud_bottom_left;
    std::string cloud_bottom_right;
    std::string left_mountain_block;
    std::string right_mountain_block;
    std::string bush_block;
};

namespace assets {
    Assets make(Theme);
    void set_theme(Theme);           // set the global theme once (e.g., on startup)
    Assets const& current();         // get the active asset set
}

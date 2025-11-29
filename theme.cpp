#include "theme.h"

namespace {
    constexpr const char* kBaseNormal = "Textures/Level/";
    constexpr const char* kBaseWinter = "Textures/Level_Winter/";

    inline const char* base(Theme t) {
        return (t == Theme::Winter) ? kBaseWinter : kBaseNormal;
    }

    Assets g_assets; // global active assets
}

Assets assets::make(Theme t) {
    const std::string b = base(t);
    return Assets{
        b + "clear.png",
        b + "dirt.png",
        b + "dirt_grass.png",
        b + "question.png",
        b + "brick.png",
        b + "cloud_top_left.png",
        b + "cloud_top_right.png",
        b + "cloud_bottom_left.png",
        b + "cloud_bottom_right.png",
        b + "mountain_left.png",
        b + "mountain_right.png",
        b + "small_bush.png"
    };
}

void assets::set_theme(Theme t) {
    g_assets = make(t);
}

Assets const& assets::current() {
    return g_assets;
}

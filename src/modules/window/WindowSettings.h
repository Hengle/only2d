//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_WINDOWSETTINGS_H
#define ONLY2D_WINDOWSETTINGS_H

#include <cstdint>
#include <utility>
#include <string>
#include <vector>

namespace only2d
{
    class WindowSettings
    {
    public:
        WindowSettings();

        void load(const std::vector<std::pair<std::string, std::string>> &settings);

        int32_t x = 0;
        int32_t y = 0;
        int32_t width = 0;
        int32_t height = 0;
        int32_t minWidth = 0;
        int32_t minHeight = 0;
        int32_t maxWidth = 0;
        int32_t maxHeight = 0;
        bool fullscreen = false;
        bool borderless = false;
        bool resizeable = false;
        bool highdpi = false;
    };
}

#endif //ONLY2D_WINDOWSETTINGS_H

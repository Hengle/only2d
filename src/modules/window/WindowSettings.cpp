//
// Created by leafnsand on 2015/5/28.
//

#include <common/Console.h>
#include "WindowSettings.h"

#include <sstream>

namespace only2d
{
    WindowSettings::WindowSettings() :
            x(0),
            y(0),
            width(0),
            height(0),
            minWidth(0),
            minHeight(0),
            maxWidth(0),
            maxHeight(0),
            fullscreen(false),
            borderless(false),
            resizeable(false),
            highdpi(false)
    {
    }

    void WindowSettings::load(const std::vector<std::pair<std::string, std::string>> &settings)
    {
        for (auto setting : settings)
        {
            if (setting.first == "x")
            {
                std::stringstream ss(setting.second);
                ss >> x;
                continue;
            }
            else if (setting.first == "y")
            {
                std::stringstream ss(setting.second);
                ss >> y;
                continue;
            }
            else if (setting.first == "width")
            {
                std::stringstream ss(setting.second);
                ss >> width;
                continue;
            }
            else if (setting.first == "height")
            {
                std::stringstream ss(setting.second);
                ss >> height;
                continue;
            }
            else if (setting.first == "minWidth")
            {
                std::stringstream ss(setting.second);
                ss >> minWidth;
                continue;
            }
            else if (setting.first == "minHeight")
            {
                std::stringstream ss(setting.second);
                ss >> minHeight;
                continue;
            }
            else if (setting.first == "maxWidth")
            {
                std::stringstream ss(setting.second);
                ss >> maxWidth;
                continue;
            }
            else if (setting.first == "maxHeight")
            {
                std::stringstream ss(setting.second);
                ss >> maxHeight;
                continue;
            }
            else if (setting.first == "fullscreen")
            {
                fullscreen = setting.second == "true";
                continue;
            }
            else if (setting.first == "borderless")
            {
                borderless = setting.second == "true";
                continue;
            }
            else if (setting.first == "resizeable")
            {
                resizeable = setting.second == "true";
                continue;
            }
            else if (setting.first == "highdpi")
            {
                highdpi = setting.second == "true";
                continue;
            }
            else
            {
                Console::log << "invalid setting: " << setting.first << Console::endl;
            }
        }
    }
}
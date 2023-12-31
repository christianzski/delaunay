#pragma once
#include "geometry.h"

namespace delaunay {
    std::vector<triangle> triangulate(const std::vector<point>& points);
}

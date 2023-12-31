# Delaunay Triangulation
A library to compute the 2D delaunay triangulation of a set of points, using the Bowyer-Watson algorithm. While not the fastest algorithm for triangulation, it's easy enough to understand.

<p align="center">
  <img src="https://github.com/christianzski/delaunay/assets/64230990/1a4ad6b2-00ca-439c-8860-c417b46819a4">
</p>

# Building
## Requirements
* A C++17 compliant compiler
* CMake (version 3.x)

```bash
mkdir build
cd build
cmake ..
make
```

# Usage

```cpp
#include "delaunay.h"

int main() {
  std::vector<point> points = ...;
  std::vector<triangle> triangles = delaunay::triangulate(points);
}
```

# References
* https://en.wikipedia.org/wiki/Bowyer-Watson_algorithm
    - For an overview of the general algorithm
* https://math.stackexchange.com/questions/4001660
    - For a discussion on points approaching collinearity and the more stringent requirements of the super triangle

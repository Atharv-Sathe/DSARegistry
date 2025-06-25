#include <iostream>
#include <vector>
using namespace std;

/*

You are given an image represented by an m x n grid of integers image, where image[i][j] 
represents the pixel value of the image. You are also given three integers sr, sc, and color. 
Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side 
with the original pixel, either horizontally or vertically) and shares the same color as the 
starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying 
their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

*/

vector<vector<int>> inPlaceBFS(vector<vector<int>>& image, int sr, int sc,
                               int color) {
  int m = image.size();
  int n = image[0].size();
  int originalColor{image[sr][sc]};

  if (originalColor == color) return image;

  image[sr][sc] = -1;

  vector<pair<int, int>> dirc{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool changed{false};
  while (true) {
    changed = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (image[i][j] == -1) {
          for (auto [x, y] : dirc) {
            int newR = i + x;
            int newC = j + y;
            if (newR >= m || newR < 0 || newC >= n || newC < 0) continue;

            if (image[newR][newC] == originalColor) {
              image[newR][newC] = -1;
              changed = true;
            }
          }
        }
      }
    }

    if (!changed) break;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (image[i][j] == -1) image[i][j] = color;
    }
  }

  return image;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                              int color) {
  // int m = image.size();
  // int n = image[0].size();
  // int originalColor{image[sr][sc]};

  // if (originalColor == color) return image;

  // queue<pair<int, int>> q;
  // q.push({sr, sc});
  // image[sr][sc] = color;

  // vector<pair<int, int>> dirc{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  // while(!q.empty()) {
  //     auto [r, c] = q.front();
  //     q.pop();

  //     for (auto [x, y] : dirc) {
  //         int newR = r + x;
  //         int newC = c + y;

  //         if (newR >= m || newR < 0 || newC >= n || newC < 0) continue;

  //         if (image[newR][newC] == originalColor) {
  //             image[newR][newC] = color;
  //             q.push({newR, newC});
  //         }
  //     }
  // }

  // return image;

  return inPlaceBFS(image, sr, sc, color);
}

int main() { return 0; }
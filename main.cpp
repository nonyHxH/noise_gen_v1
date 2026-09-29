#include <iostream>
#include <fstream>
#include <random>
using namespace std;

#define WIDTH 256
#define HEIGHT 256

int main() {
  mt19937 rng(random_device{}());
  uniform_int_distribution<int> dist(0,255);

  ofstream out("noise_img.ppm");
  out<<"P3\n"<<WIDTH<<" "<<HEIGHT<<"\n255\n";

  for (int y=0;y<HEIGHT;y++) {
    for (int x=0;x<WIDTH;x++) {
      int p =dist(rng);
      int q =dist(rng);
      int r =dist(rng);
      out << p << ' ' << q << ' ' << r << '\n';
    }
  }
}
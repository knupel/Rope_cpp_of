#include "vec_base.hpp"

void vec2_base() {
  vec2<float> v(1,3.5);
    // std::cout << "0 setup >> ratio_x: " << ratio_x << " || ratio_y: "<< ratio_y << std::endl ;
  std::cout << "v: " << v.x() << " | "<< v.y() << std::endl;


  v.mapping(2, 4, 20, 40);
  std::cout << "v: " << v.x() << " | "<< v.y() << std::endl;
;
}
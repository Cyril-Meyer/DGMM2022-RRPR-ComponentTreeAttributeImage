/*
 * This file is part of libTIM.
 *
 * Copyright (©) 2005-2013  Benoit Naegel
 * Copyright (©) 2013 Theo de Carpentier
 * Copyright (©) 2022-2023  Cyril Meyer
 */

#ifndef Point_h
#define Point_h

#include <iostream>

#include "Common/Types.h"

namespace LibTIM {

template <class T>
struct Point {
  T x, y, z;

  Point(TCoord x = 0, TCoord y = 0, TCoord z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  Point& operator+=(Point<T> q) {
    x += q.x;
    y += q.y;
    z += q.z;
    return *this;
  }
  Point& operator-=(Point<T> q) {
    x -= q.x;
    y -= q.y;
    z -= q.z;
    return *this;
  }
  bool operator==(Point<T> q) { return (x == q.x && y == q.y && z == q.z); }

  void operator=(const Point<T>& q) {
    this->x = q.x;
    this->y = q.y;
    this->z = q.z;
  }

  Point(const Point& q) { operator=(q); }
  void operator()(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void print() { std::cout << x << " " << y << " " << z << "\n"; }
};

template <class T>
Point<T> operator+(Point<T> p, Point<T> q) {
  Point<T> r = p;
  return r += q;
}

template <class T>
Point<T> operator-(Point<T> p, Point<T> q) {
  Point<T> r = p;
  return r -= q;
}

}  // namespace LibTIM

#endif

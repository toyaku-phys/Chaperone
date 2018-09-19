#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Vector3D.hpp"
#include "Struct.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

template<typename ELEMENTS>
void OutYUBA(const int& step, const ELEMENTS& elements, const std::string& file_name, const std::string& tag, bool trunc_f=false);

template<typename ELEMENTS>
void OutYUBA(const int& step, const ELEMENTS& elements, const std::string& file_name, const std::string& tag, bool trunc_f);

void OutYUBA(const int& step, const std::vector<Vector3D>& elements, const std::string& file_name, const std::string& tag, bool trunc_f);

template<typename GETLINE, typename TIME_RANGE>
std::vector<Vector3D> get_next_Beads(GETLINE& gl, const TIME_RANGE& tr);

template<typename GETLINE, typename TIME_RANGE>
std::vector<Vector3D> get_next_Coordinate(GETLINE& gl,const TIME_RANGE& tr);

template<typename GETLINE, typename TIME_RANGE>
std::vector<Triangle> get_next_Triangle(GETLINE& gl,const TIME_RANGE& tr);

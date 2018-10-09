#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "Vector3D.hpp"
#include "Struct.hpp"
#include "FileReader.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>


void OutYUBA(const int& step, const std::vector<Vector3D>& elements, const std::string& file_name, const std::string& tag, bool trunc_f=true);
void OutYUBA(const int& step, const std::vector<Triangle>& elements, const std::string& file_name, const std::string& tag, bool trunc_f=true);

std::vector<Vector3D> get_next_Beads(      Getline& gl, const std::tuple<int,int>& tr);
std::vector<Vector3D> get_next_Coordinate( Getline& gl, const std::tuple<int,int>& tr);
std::vector<Triangle> get_next_Triangle(   Getline& gl, const std::tuple<int,int>& tr);

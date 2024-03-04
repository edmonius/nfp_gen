#ifndef DATA_LOADER_H
#define DATA_LOADER_H
#include <string>
#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include <nlohmann/json.hpp>

#include "utils/utils.hpp"


namespace data_loader{


void Load_DAT_Circles_from_to(std::string &datpath, FRM_ARRAY_TYPE &pieces);

void Load_DAT_Pieces_from_to(const std::string &datpath, FRM_ARRAY_TYPE &pieces);

void Load_DAT_Board_from_to(std::string &datpath, FRM_ARRAY_TYPE &board,int &length, int &width, std::vector <std::vector <int> > &grid, int res);

void Load_DAT_Parameters(std::string &datpath, int &npieces,int &typerot, int &typepiec,int &piecepos,std :: vector <int> &piecestoremove );

#endif

}
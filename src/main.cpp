#include <iostream>
#include "data_loader/data_loader.hpp"

int main(){
    
    FRM_ARRAY_TYPE loaded_pieces;
    FRM_ARRAY_TYPE loaded_board;
    std::string pieces_path = "pieces_plg.json";
    std::string xmlpath2 = "board.dat";
    std::string xmlpath3 = "teste.dat";
    int pecas {0};

    data_loader::Load_DAT_Pieces_from_to(pieces_path, loaded_pieces);

}
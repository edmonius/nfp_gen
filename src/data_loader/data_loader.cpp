#include "data_loader/data_loader.hpp"
using json = nlohmann::json;

bool isboard = false;

void data_loader::Load_DAT_Circles_from_to(std::string &datpath, FRM_ARRAY_TYPE &pieces)
{
    // std::list<poligono> piece;
    poligono tmp_piece;
    segmento tmp_sgm;
    forma tmp_frm;
    char STR[256];
    int npieces, identical_pieces, vx_number;
    double x, y, r;
    int n, i, k;

    // Input File Stream
    // std::ifstream stream1("tetris.dat");
    // const char *pathdaat="tetris.dat";
    std::ifstream stream1(datpath.c_str());

    // para Output File Stream usar ofstream
    if (!stream1)
    {
        std::cout << "While opening a file an error is encountered. (pieces_cc.dat)" << std::endl;
    }
    else
    {
        std::cout << "File is successfully opened. (pieces_cc.dat)" << std::endl;

        // Number of pieces
        do
            stream1 >> STR;
        while ((sscanf(STR, "%d", &npieces) != 1) && (!stream1.eof()));

        // cout<<"Total pieces:"<<npieces<<std::endl;

        // Loads each pieces data
        for (i = 0; i < npieces; i++)
        {

            // currently ignored! (each piece is only readed once, even when there are multiple equal pieces)
            // cout<<" -------------------------------- Round "<<i<<" --------------------------------"<<std::endl;
            do
                stream1 >> STR;
            while ((sscanf(STR, "%d", &identical_pieces) != 1) && (!stream1.eof()));
            // cout<<"Identical pieces:"<<identical_pieces<<std::endl;
            std::cout << "identical_pieces: " << identical_pieces;
            // reads vx number of current piece
            do
                stream1 >> STR;
            while ((sscanf(STR, "%d", &vx_number) != 1) && (!stream1.eof()));
            // cout<<"Vertex number:"<<vx_number<<std::endl;

            // Loads all vertices of the current piece
            // cout<<"Loading vx:"<<std::endl;

            k = 0;
            while (k < (vx_number))
            {
                if (!stream1.eof())
                {

                    stream1 >> STR;
                    n = sscanf(STR, "%lf", &x);

                    std::cout << "X >> " << x << std::endl;
                    if (n > 0)

                    {
                        // cout<<STR<<" - ";
                        stream1 >> STR;
                        n = sscanf(STR, "%lf", &y);

                        if (n > 0)
                        {
                            stream1 >> STR;
                            n = sscanf(STR, "%lf", &r);

                            if (n > 0)
                            {
                                k++;

                                tmp_sgm.c0.x = x;
                                tmp_sgm.c0.y = y;
                                tmp_sgm.p0.x = r;
                                tmp_sgm.p0.y = 0.0;
                                tmp_sgm.p1.x = 0.0;
                                tmp_sgm.p1.y = 0.0;
                                tmp_piece.sgm.push_back(tmp_sgm);
                            }
                        }
                    }
                }
            }

            tmp_frm.plg.push_back(tmp_piece);
            tmp_piece.sgm.clear();
        }
        pieces.push_back(tmp_frm);
        tmp_frm.plg.clear();
    }
}
void data_loader::Load_DAT_Pieces_from_to(const std::string &datpath, FRM_ARRAY_TYPE &pieces)
{
    poligono tmp_poly;
    segmento tmp_sgm;
    forma tmp_frm;

    // Input File Stream
    std::ifstream config_path(datpath.c_str());
    if(!config_path) {
        std::cout << "Error while opening (" << datpath << ")." << std::endl;
        return;
    }
    else{
        std::cout << "Loaded (" << datpath << ")." << std::endl;
    }
    json data = json::parse(config_path);
    int n_pieces{data["n_pieces"]};    

    for (int piece_no = 0; piece_no < n_pieces; piece_no ++){

        // first vertex
        ponto first_vx(0,0);
        segmento tmp_sgm;

        bool is_first_vx {true};
        int n_vertices{data["pieces"][piece_no]["n_vertices"]};

        for (int vx = 0; vx< n_vertices; vx ++) {
            if (is_first_vx){
                tmp_sgm.p1.x = data["pieces"][piece_no]["vertices"][vx]["x"];
                tmp_sgm.p1.y = data["pieces"][piece_no]["vertices"][vx]["y"];
                first_vx.x = data["pieces"][piece_no]["vertices"][vx]["x"];
                first_vx.y = data["pieces"][piece_no]["vertices"][vx]["y"];
                is_first_vx = false;
            }
            else {
                tmp_sgm.p0.x = tmp_sgm.p1.x;
                tmp_sgm.p0.y = tmp_sgm.p1.y;
                tmp_sgm.p1.x = data["pieces"][piece_no]["vertices"][vx]["x"];;
                tmp_sgm.p1.y = data["pieces"][piece_no]["vertices"][vx]["y"];
                tmp_poly.sgm.push_back(tmp_sgm);
            }
        }
        // merge last segment to close circuit
        tmp_sgm.p0.x = tmp_sgm.p1.x;
        tmp_sgm.p0.y = tmp_sgm.p1.y;
        tmp_sgm.p1.x = first_vx.x;
        tmp_sgm.p1.y = first_vx.y;

        tmp_poly.sgm.push_back(tmp_sgm);
        tmp_frm.plg.push_back(tmp_poly);
        tmp_frm.frm_id = data["pieces"][piece_no]["piece_id"];
        pieces.push_back(tmp_frm);
        
        // reset temporary elements for next polygon
        tmp_poly.sgm.clear();
        tmp_frm.plg.clear();
    }
    utils::Print_geo_array(pieces);
}


void data_loader::Load_DAT_Parameters(std::string &datpath, int &npieces, int &typerot, int &typepiec, int &piecepos, std::vector<int> &piecestoremove)
{
    // std::list<poligono> piece;
    char STR[256];
    int aux2, a, aux3;
    char lol;

    std::ifstream stream1(datpath.c_str());

    // para Output File Stream usar ofstream
    if (!stream1)
    {
        std::cout << "While opening a file an error is encountered (" << datpath << ")." << std::endl;
    }
    else
    {
        std::cout << "File is successfully opened." << std::endl;
    }

    // Number of pieces
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &npieces) != 1) && (!stream1.eof()));

    // Pieces Type
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &typepiec) != 1) && (!stream1.eof()));

    // Rotations Type
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &typerot) != 1) && (!stream1.eof()));

    // Pieces Positioning
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &piecepos) != 1) && (!stream1.eof()));

    // Use last iteration
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &aux3) != 1) && (!stream1.eof()));

    // Pieces to remove positioning
    do
        stream1 >> STR;
    while ((sscanf(STR, "%d", &aux2) != 1) && (!stream1.eof()));

    if (aux2 > 0)
    {

        for (int aux = 0; aux < aux2; aux++)
        {

            do
            {
                stream1 >> STR;
            } while ((sscanf(STR, "%d", &a) != 1) && (!stream1.eof()));

            piecestoremove.push_back(a);
        }
    }
}
#include "utils.hpp"

namespace utils
{

template <class T>
void Print_geo_array(T &argument) // suporte genérico
{
    std::cout << std::endl
                << "Error: Print_geo_array[Argument type not suported]." << std::endl
                << std::endl;
}

void Print_geo_array( SGM_ARRAY_TYPE &array) // suporte para os 3 tipos de array de sgm
{
    SGM_ARRAY_ITERATOR SgmIterator;
    for (SgmIterator = array.begin(); SgmIterator != array.end(); SgmIterator++)
    {
        std::cout << std::endl
                    << " |    |___Segm ID:" << (*SgmIterator).sgm_id;
        std::cout << " Type:" << (*SgmIterator).sgm_type;

        std::cout << " SubType:" << (*SgmIterator).sub_type;
        std::cout << " p0:[" << (*SgmIterator).p0.x << "," << (*SgmIterator).p0.y << "]";
        std::cout << " p1:[" << (*SgmIterator).p1.x << "," << (*SgmIterator).p1.y << "]";

        std::cout << " c0:[" << (*SgmIterator).c0.x << "," << (*SgmIterator).c0.y << "]";
        std::cout << " c1:[" << (*SgmIterator).c1.x << "," << (*SgmIterator).c1.y << "]";
    }
    std::cout << std::endl;
}

void Print_geo_array( PLG_ARRAY_TYPE &array)
{

    for (PLG_ARRAY_ITERATOR PlgIterator = array.begin(); PlgIterator != array.end(); PlgIterator++)
    {
        std::cout << std::endl
                    << " |___Poly ID:" << (*PlgIterator).plg_id;
        std::cout << " Type:" << (*PlgIterator).plg_type;

        Print_geo_array((*PlgIterator).sgm);
    }
}

void Print_geo_array( FRM_ARRAY_TYPE &array) // suporte para os 3 tipos de array de frm
{
    FRM_ARRAY_ITERATOR FrmIterator;
    for (FrmIterator = array.begin(); FrmIterator != array.end(); FrmIterator++)
    {
        std::cout << std::endl
                    << std::endl
                    << " Form ID:" << (*FrmIterator).frm_id;
        std::cout << " Type:" << (*FrmIterator).frm_type;

        Print_geo_array((*FrmIterator).plg);
    }
}
}
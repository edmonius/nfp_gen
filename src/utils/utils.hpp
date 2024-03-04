#include"types/types.hpp"
#include <iostream>
#pragma once

namespace utils{
    
template <class T>
void Print_geo_array(T &argument);
void Print_geo_array( SGM_ARRAY_TYPE &array);
void Print_geo_array( PLG_ARRAY_TYPE &array); 
void Print_geo_array( FRM_ARRAY_TYPE &array);
}

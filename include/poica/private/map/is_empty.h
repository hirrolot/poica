#ifndef POICA_PRIVATE_MAP_IS_EMPTY_H
#define POICA_PRIVATE_MAP_IS_EMPTY_H

#include <boost/vmd/vmd.hpp>

#define POICA_P_MAP_IS_EMPTY(map) BOOST_VMD_IS_EMPTY(BOOST_PP_EMPTY() map)

#endif // POICA_PRIVATE_MAP_IS_EMPTY_H

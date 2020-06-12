#ifndef POICA_POICA_P_AUX
#define POICA_POICA_P_AUX

#include <boost/preprocessor.hpp>

#define POICA_P_PREFIX(something) BOOST_PP_CAT(POICA_P_, something)

#define POICA_P_USELESS_TYPEDEF(name)                                          \
    typedef int POICA_P_PREFIX(BOOST_PP_CAT(name, _UselessTypedef))

#endif // POICA_POICA_P_AUX
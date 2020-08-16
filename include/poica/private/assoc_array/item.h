#ifndef POICA_PRIVATE_ASSOC_ARRAY_ITEM_H
#define POICA_PRIVATE_ASSOC_ARRAY_ITEM_H

#include <boost/preprocessor.hpp>

#define POICA_P_ASSOC_ARRAY_ITEM(name, value) ((name)(value))

#define POICA_P_ASSOC_ARRAY_ITEM_NAME(item)                              \
    BOOST_PP_SEQ_ELEM(0, POICA_P_ASSOC_ARRAY_ITEM_EXPAND item)

#define POICA_P_ASSOC_ARRAY_ITEM_VALUE(item)                             \
    BOOST_PP_SEQ_ELEM(0, POICA_P_ASSOC_ARRAY_ITEM_EXPAND item)

#define POICA_P_ASSOC_ARRAY_ITEM_EXPAND(item) item

#endif // POICA_PRIVATE_ASSOC_ARRAY_ITEM_H

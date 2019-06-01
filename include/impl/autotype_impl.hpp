//
// Created by Guy Marino on 2019-06-01.
//

#ifndef AUTOTYPE_AUTOTYPE_IMPL_HPP
#define AUTOTYPE_AUTOTYPE_IMPL_HPP

#include <autotype.hpp>

using namespace std;
using namespace celstd;

template<class T> autotype::autotype(T object) {
    this->autotype_type = typeid(T);
    this->autotype_data = malloc(sizeof(T));
    *((T*)this->autotype_data) = object;
}

template<class T> autotype::operator T(){
    typedef autotype_type_info info_t;

    if (info_t(typeid(T)) == this->autotype_type){
        return *((T*)this->autotype_data);
    }
    else throw bad_autotype_cast(typeid(T));
}



#endif //AUTOTYPE_AUTOTYPE_IMPL_HPP

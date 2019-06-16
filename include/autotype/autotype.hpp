#ifndef AUTOTYPE_AUTOTYPE_H
#define AUTOTYPE_AUTOTYPE_H

#include <string>
#include <typeinfo>

#include <autotype/autotype_type_info.hpp>
#include <autotype/bad_autotype_cast.hpp>

using namespace std;
using namespace celstd::autotype_help;

namespace celstd {

    class autotype {
    public:
        // Typedef section
        typedef autotype_type_info info_t;

    private:
        // Autotype core data
        info_t autotype_type;
        void* autotype_data;

    public:
        // Constructors
        autotype();
        autotype(autotype& other);
        template<class T> autotype(T object);

        // Destructor
        ~autotype();

        // Implicit Converter
        template<class T> operator T();

        // Equality/String operators
        string to_string();

        // Member access functions
        const info_t& get_type_info ();
        void* get_core_data();
    };
}

#include "autotype/impl/autotype_impl.hpp"

#endif //AUTOTYPE_AUTOTYPE_H
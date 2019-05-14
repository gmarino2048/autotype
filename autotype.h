#ifndef AUTOTYPE_AUTOTYPE_H
#define AUTOTYPE_AUTOTYPE_H

#include <string>

using namespace std;

namespace celstd {

    // Make a not-weird container for the type info
    struct autotype_type_info {
        string type_name;
        size_t type_hash;
    };

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
        autotype(autotype& other);
        template<class T> autotype(T object);

        // Destructor
        ~autotype();

        // Implicit Converter
        template<class T> operator T();

        // Member access functions
        info_t get_type_info ();
        void* get_core_data();
    };
}

#endif //AUTOTYPE_AUTOTYPE_H
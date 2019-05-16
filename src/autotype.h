#ifndef AUTOTYPE_AUTOTYPE_H
#define AUTOTYPE_AUTOTYPE_H

#include <string>
#include <typeinfo>

using namespace std;

namespace celstd {

    // Make a not-weird container for the type info
    struct autotype_type_info {
        string type_name;
        size_t type_hash;

        autotype_type_info();
        autotype_type_info(const type_info& info);

        bool equals(const autotype_type_info& other) const;
        string to_string();

        operator string();
        bool operator ==(const autotype_type_info& rhs) const;
        bool operator !=(const autotype_type_info& rhs) const;
    };

    // Make an exception to be thrown for bad type
    class bad_autotype_cast : exception {
    private:
        string message;
        bad_autotype_cast();

    public:
        bad_autotype_cast(autotype_type_info type);

        const char* what();
        string get_message();
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
        autotype();
        autotype(autotype& other);
        template<class T> autotype(T object);

        // Destructor
        ~autotype();

        // Implicit Converter
        template<class T> operator T();

        // Equality/String operators
        string to_string();
        operator string();

        // Member access functions
        const info_t& get_type_info ();
        void* get_core_data();
    };
}

#endif //AUTOTYPE_AUTOTYPE_H
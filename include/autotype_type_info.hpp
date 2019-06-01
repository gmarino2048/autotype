
#ifndef AUTOTYPE_AUTOTYPE_TYPE_INFO_HPP
#define AUTOTYPE_AUTOTYPE_TYPE_INFO_HPP

#include <string>
#include <sstream>

using namespace std;

namespace celstd::autotype_help{

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

}

#endif //AUTOTYPE_AUTOTYPE_TYPE_INFO_HPP

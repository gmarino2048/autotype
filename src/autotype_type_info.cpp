
#include <autotype_type_info.hpp>

using namespace std;
using namespace celstd::autotype_help;

// Define autotype type info
autotype_type_info::autotype_type_info() {
    const type_info& info = typeid(nullptr_t);
    this->type_name = info.name();
    this->type_hash = info.hash_code();
}

autotype_type_info::autotype_type_info(const type_info& info) {
    this->type_name = info.name();
    this->type_hash = info.hash_code();
}

bool autotype_type_info::equals(const autotype_type_info &other) const {
    return other.type_hash == this->type_hash;
}

string autotype_type_info::to_string() {
    stringstream ss;
    ss << "autotype_type_info<" << type_name << ">" << endl;
    return ss.str();
}

autotype_type_info::operator string(){
    return to_string();
}

bool autotype_type_info::operator==(const autotype_type_info &rhs) const {
    return equals(rhs);
}

bool autotype_type_info::operator!=(const autotype_type_info &rhs) const {
    return !(equals(rhs));
}
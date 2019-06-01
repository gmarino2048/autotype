
#include <string>
#include <sstream>
#include <typeinfo>

#include <autotype.hpp>

using namespace std;
using namespace celstd;

// Define autotype section
autotype::autotype(){
    this-> autotype_data = nullptr;
    this-> autotype_type = typeid(nullptr_t);
}

autotype::autotype(autotype& other){
    this->autotype_data = other.autotype_data;
    this->autotype_type = other.autotype_type;
}

autotype::~autotype() {
    free(this->autotype_data);
}

string autotype::to_string(){
    stringstream ss;
    ss << "autotype<" << autotype_type.type_name << ">" << endl;
    return ss.str();
}

autotype::operator string(){
    return to_string();
}

const autotype::info_t& autotype::get_type_info() {
    return autotype_type;
}

void* autotype::get_core_data(){
    return autotype_data;
}
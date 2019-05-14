
#include <string>
#include <sstream>
#include <typeinfo>
#include "autotype.h"

using namespace std;
using namespace celstd;

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

bool autotype_type_info::equals(celstd::autotype_type_info &other) {
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

bool autotype_type_info::operator==(celstd::autotype_type_info& rhs) {
    return equals(rhs);
}

bool autotype_type_info::operator!=(celstd::autotype_type_info &rhs) {
    return !(equals(rhs));
}

// Define bad_autotype_cast section
bad_autotype_cast::bad_autotype_cast() {
    message = "";
}

bad_autotype_cast::bad_autotype_cast(autotype_type_info type) {
    stringstream ss;
    ss << "Cannot convert autotype to type " << type.type_name << endl;
    message = ss.str();
}

const char* bad_autotype_cast::what(){
    return message.c_str();
}

string bad_autotype_cast::get_message() {
    return message;
}

// Define autotype section
autotype::autotype(){
    this-> autotype_data = nullptr;
    this-> autotype_type = typeid(nullptr_t);
}

autotype::autotype(autotype& other){
    this->autotype_data = other.autotype_data;
    this->autotype_type = other.autotype_type;
}

template<class T> autotype::autotype(T object) {
    this->autotype_type = typeid(T);
    this->autotype_data = malloc(sizeof(T));
    *((T*)this->autotype_data) = object;
}

autotype::~autotype() {
    free(this->autotype_data);
}

template<class T> autotype::operator T(){
    typedef autotype_type_info info_t;

    if (info_t(typeid(T)) == this->autotype_type){
        return *((T*)this->autotype_data);
    }
    else throw bad_autotype_cast(typeid(T));
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
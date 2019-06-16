
#include <string>
#include <autotype/bad_autotype_cast.hpp>

using namespace std;
using namespace celstd::autotype_help;

// Define bad_autotype_cast section
bad_autotype_cast::bad_autotype_cast() {
    message = "";
}

bad_autotype_cast::bad_autotype_cast(string message) {
    this->message = message;
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
//
// Created by Guy Marino on 2019-06-01.
//

#ifndef AUTOTYPE_BAD_AUTOTYPE_CAST_HPP
#define AUTOTYPE_BAD_AUTOTYPE_CAST_HPP

#include <string>

#include <autotype/autotype_type_info.hpp>

using namespace std;

namespace celstd::autotype_help{

    // Make an exception to be thrown for bad type
    class bad_autotype_cast : exception {
    private:
        string message;
        bad_autotype_cast();

    public:
        bad_autotype_cast(string message);
        bad_autotype_cast(autotype_type_info type);

        const char* what();
        string get_message();
    };

}

#endif //AUTOTYPE_BAD_AUTOTYPE_CAST_HPP

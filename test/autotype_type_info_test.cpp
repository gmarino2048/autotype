
#include <gtest/gtest.h>
#include <autotype/autotype.hpp>

using namespace std;
using namespace celstd;

namespace {
    typedef autotype_type_info ati;

    TEST(TypeInfo, EmptyConstructorTest){
        ati info;

        EXPECT_EQ(info.type_hash, typeid(nullptr_t).hash_code());
        EXPECT_EQ(info.type_name, typeid(nullptr_t).name());
    }

    TEST(TypeInfo, SimpleConstructorTest){
        ati info(typeid(int));

        EXPECT_EQ(info.type_hash, typeid(int).hash_code());
        EXPECT_EQ(info.type_name, typeid(int).name());
    }

    TEST(TypeInfo, CopyConstructorTest){
        ati info(typeid(string));
        ati other(info);

        EXPECT_NE(&info, &other);
    }

    TEST(TypeInfo, TestToString){
        ati infostring(typeid(string));
        ati infoint(typeid(int));

        string str_name = typeid(string).name();
        string int_name = typeid(int).name();

        stringstream ss;
        ss << "autotype_type_info<" << str_name << ">" << endl;

        EXPECT_EQ(infostring.to_string(), ss.str());

        ss.str("");
        ss << "autotype_type_info<" << int_name << ">" << endl;

        EXPECT_EQ(infoint.to_string(), ss.str());
    }

    TEST(TypeInfo, TestEquals){
        ati info(typeid(string));
        ati copy(info);
        ati same_type(typeid(string));

        EXPECT_EQ(info, copy);
        EXPECT_EQ(info, same_type);
    }

    TEST(TypeInfo, StringOperatorTest){
        ati info(typeid(int));

        // Explicit cast
        EXPECT_EQ((string)info, "autotype_type_info<i>\n");
        // Implicit cast
        string info_string = info;
        EXPECT_EQ("autotype_type_info<i>\n", info_string);
    }
}
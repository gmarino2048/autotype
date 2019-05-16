
#include <gtest/gtest.h>
#include <autotype.h>

using namespace std;
using namespace celstd;

namespace {
    TEST(TypeInfo, EmptyConstructorTest){
        autotype_type_info info;

        EXPECT_EQ(info.type_hash, typeid(nullptr_t).hash_code());
        EXPECT_EQ(info.type_name, typeid(nullptr_t).name());
    }

    TEST(TypeInfo, SimpleConstructorTest){
        autotype_type_info info(typeid(int));

        EXPECT_EQ(info.type_hash, typeid(int).hash_code());
        EXPECT_EQ(info.type_name, typeid(int).name());
    }

    TEST(TypeInfo, CopyConstructorTest){
        autotype_type_info info(typeid(string));
        autotype_type_info other(info);

        EXPECT_NE(&info, &other);
    }

    TEST(TypeInfo, TestToString){
        autotype_type_info infostring(typeid(string));
        autotype_type_info infoint(typeid(int));

        EXPECT_EQ(infostring.to_string(), "autotype_type_info<NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE>\n");
        EXPECT_EQ(infoint.to_string(), "autotype_type_info<i>\n");
    }

    TEST(TypeInfo, TestEquals){
        autotype_type_info info(typeid(string));
        autotype_type_info copy(info);
        autotype_type_info same_type(typeid(string));

        EXPECT_EQ(info, copy);
        EXPECT_EQ(info, same_type);
    }

    TEST(TypeInfo, StringOperatorTest){
        autotype_type_info info(typeid(int));

        // Explicit cast
        EXPECT_EQ((string)info, "autotype_type_info<i>\n");
        // Implicit cast
        string info_string = info;
        EXPECT_EQ("autotype_type_info<i>\n", info_string);
    }
}
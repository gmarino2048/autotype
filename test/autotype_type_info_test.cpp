
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

    TEST(TypeInfo, OperatorTest){
        autotype_type_info info(typeid(int));

        // Explicit cast
        EXPECT_EQ((string)info, "autotype_type_info<i>\n");
        // Implicit cast
        string info_string = info;
        EXPECT_TRUE("autotype_type_info<i>\n" == info_string);
    }
}
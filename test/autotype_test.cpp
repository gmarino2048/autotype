

#include <gtest/gtest.h>
#include <autotype.hpp>

using namespace std;
using namespace celstd;

namespace {
    TEST(Autotype, TestConversionToAutotype){
        string str = "Hello World";
        EXPECT_NO_THROW(autotype at = str);

        int in = 45;
        EXPECT_NO_THROW(autotype at = in);

        float fl = 12.5;
        EXPECT_NO_THROW(autotype at = fl);

        struct test {
            int x;
            int y;
        };

        test tst {
            .x = 4,
            .y = 5
        };
        EXPECT_NO_THROW(autotype at = tst);
    }

    TEST(Autotype, GetCoreDataTest){
        string str = "Hello World";
        autotype at = str;

        void* data = at.get_core_data();
        EXPECT_EQ(*((string*)data), str);

        int in = 45;
        at = in;
        data = at.get_core_data();
        EXPECT_EQ(*((int*)data), in);
    }
}


#include <gtest/gtest.h>
#include <autotype/autotype.hpp>
#include <autotype/bad_autotype_cast.hpp>

using namespace std;
using namespace celstd;

namespace {
    typedef autotype at;
    typedef bad_autotype_cast bac;

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

    TEST(Autotype, TestGoodConversion){
        int x = 45;
        at auto_int = x;

        ASSERT_NO_THROW(int y = auto_int;);
        int y = auto_int;
        EXPECT_EQ(x, y);

        string a = "Hello World";
        at auto_str = a;
        ASSERT_NO_THROW(string b = auto_str;);
        string c = auto_str;

        EXPECT_EQ(a, c);
    }

    TEST(Autotype, TestBadConversion){
        at auto_int = 45;
        EXPECT_THROW(float x = auto_int;, bad_autotype_cast);
        EXPECT_THROW(double x = auto_int;, bad_autotype_cast);
        EXPECT_THROW(string x = auto_int;, bad_autotype_cast);

        at auto_str = string("Hello World");
        EXPECT_THROW(int x = auto_str;, bad_autotype_cast);
        EXPECT_THROW(float y = auto_str;, bad_autotype_cast);

        struct test_1 { int x; };
        struct test_2 { int x; };

        at auto_test_1 = test_1{45};
        EXPECT_THROW(test_2 z = auto_test_1, bad_autotype_cast);
    }
}
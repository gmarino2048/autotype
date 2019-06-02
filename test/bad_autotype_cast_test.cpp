
#include <sstream>
#include <typeinfo>

#include <gtest/gtest.h>
#include <bad_autotype_cast.hpp>
#include <autotype_type_info.hpp>

using namespace std;
using namespace celstd::autotype_help;

namespace {
    typedef bad_autotype_cast bac;
    typedef autotype_type_info ati;

    TEST(BadAutotypeCast, TestStringConstructor){
        const char* message = "This is the message";

        bac exception(message);
        // Cast to string to avoid pointer bullshit
        EXPECT_EQ(string(exception.what()), string(message));
    }

    TEST(BadAutotypeCast, TestTypeInfoConstructor){
        // Test with int, string, double, long
        const ati types[] = {
            typeid(int),
            typeid(string),
            typeid(double),
            typeid(long)
        };

        for (auto type : types){
            bac temp(type);

            stringstream ss;
            ss << "Cannot convert autotype to type " << type.type_name << endl;

            EXPECT_EQ(temp.what(), ss.str());
        }
    }

    TEST(BadAutotypeCast, TestMessageTyping){
        bac test("Sample Message");

        EXPECT_EQ(typeid(test.what()), typeid(const char*));
        EXPECT_EQ(typeid(test.get_message()), typeid(string));
    }

    TEST(BadAutotypeCast, TestThrowable){
        const ati types[] = {
                typeid(int),
                typeid(string),
                typeid(double),
                typeid(long)
        };

        auto throwexcept = [](ati type){
            throw bac(type);
            EXPECT_TRUE(false);
        };

        for (auto type : types){
            EXPECT_THROW(throwexcept(type), bac);
        }
    }

    TEST(BadAutotypeCast, TestTryCatch){
        try{
            throw bad_autotype_cast("This is a message");
            EXPECT_TRUE(false);
        }
        catch(bad_autotype_cast&){
            EXPECT_TRUE(true);
        }
        catch(exception&){
            EXPECT_TRUE(false);
        }
    }
}
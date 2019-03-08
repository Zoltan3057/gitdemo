#include <gtest/gtest.h>
#include <string.h>

int Foo(int a, int b){
    if(a == 0 || b == 0)
        throw "don't do that";
    int c = a % b;
    if(c == 0)
        return b;
    return Foo(b,c);
}

bool MutuallyPrime(int m, int n)
{
    return Foo(m , n) > 1;
}

TEST(PredicateAssertionTest, Demo)
{
    int m = 5, n = 6;
    EXPECT_PRED2(MutuallyPrime, m, n);
}

TEST(ExplicitTest, Demo)
{
    //ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    //FAIL(); // Fatal Assertion，不往下执行该案例。

    SUCCEED();
}


TEST(StringCmpTest, Demo)
{
    char* pszCoderZh = "CoderZh";
    wchar_t* wszCoderZh = L"CoderZh";
    std::string strCoderZh = "CoderZh";
    std::wstring wstrCoderZh = L"CoderZh";

    EXPECT_STREQ("CoderZh", pszCoderZh);
    EXPECT_STREQ(L"CoderZh", wszCoderZh);

    EXPECT_STRNE("CnBlogs", pszCoderZh);
    EXPECT_STRNE(L"CnBlogs", wszCoderZh);

    EXPECT_STRCASEEQ("coderzh", pszCoderZh);
    //EXPECT_STRCASEEQ(L"coderzh", wszCoderZh);    不支持

    EXPECT_STREQ("CoderZh", strCoderZh.c_str());
    EXPECT_STREQ(L"CoderZh", wstrCoderZh.c_str());
}

TEST(FooTest, HandleNoneZeroInput){
    EXPECT_EQ(2, Foo(4,10));
    EXPECT_EQ(6, Foo(30,18));
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

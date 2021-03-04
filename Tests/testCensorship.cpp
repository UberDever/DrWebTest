#include "pch.h"
#include "../DrWebTest/Censorship.hpp"

TEST(Censorship, NonCensorableString)
{
	MyString example1 = "ExampleNormal";
	MyString example2 = "ExampleSuperior";
	example1.swap(example2);
	EXPECT_STREQ(example1.c_str(), "ExampleSuperior");
}

TEST(Censorship, CensorableStringInLowercase)
{
	MyString example1 = "Example";
	MyString example2 = "Exampledr.web";
	try
	{
		example1.swap(example2);
		FAIL() << "Exception on swap must be thrown";
	}
	catch (std::invalid_argument e)
	{
		EXPECT_STREQ(e.what(), "Substring \"dr.web\" in any case if forbidden");
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument exception";
	}
	EXPECT_STREQ(example1.c_str(), "Example");
}

TEST(Censorship, CensorableStringInUpperCase)
{
	MyString example1 = "Example";
	MyString example2 = "ExampleDR.WEB";
	try
	{
		example1.swap(example2);
		FAIL() << "Exception on swap must be thrown";
	}
	catch (std::invalid_argument e)
	{
		EXPECT_STREQ(e.what(), "Substring \"dr.web\" in any case if forbidden");
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument exception";
	}
	EXPECT_STREQ(example1.c_str(), "Example");
}

TEST(Censorship, CensorableStringInRandomCase)
{
	MyString example1 = "Example";
	MyString example2 = "ExampledR.wEB";
	try
	{
		example1.swap(example2);
		FAIL() << "Exception on swap must be thrown";
	}
	catch (std::invalid_argument e)
	{
		EXPECT_STREQ(e.what(), "Substring \"dr.web\" in any case if forbidden");
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument exception";
	}
	EXPECT_STREQ(example1.c_str(), "Example");
}
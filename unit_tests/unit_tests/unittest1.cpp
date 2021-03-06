#include "stdafx.h"
#include "CppUnitTest.h"
#include "catch.hpp"
#include "observer_post_office.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("magazines")
	{
		post_office* post = new post_office();
		reader* Reader = new reader(post, "John");
		post->attach(Reader);
		post->set_mag("something");
		bool res;
		vector<string> mags = Reader->get_pubs();
		if (mags[0] == "something") res = true;
		else res = false;
		REQUIRE(res == true);
	};
	TEST_CASE("sub_name")
	{
		post_office* post = new post_office();
		reader* Reader = new reader(post, "John");
		post->attach(Reader);
		string n = Reader->get_name();
		REQUIRE(n == "John");
	};
}
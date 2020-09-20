//
// Created by MFunction on 09/20/2020.
//

#define BOOST_TEST_MODULE XANATEST

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(BoostTest_Checkin) {
	auto i = 1;
	BOOST_TEST(i == 1);
	BOOST_TEST_MESSAGE("Boost Test checked in successfully.");
}
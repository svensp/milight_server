/**@file	/home/cmd-keen/Projekte/milight_server/tests/test.cpp
 * @author	cmd-keen
 * @version	704
 * @date
 * 	Created:	Mi 01 Jun 2016 13:54:54 CEST \n
 * 	Last Update:	Mi 01 Jun 2016 13:54:54 CEST
 */

/*===========================================================================*/
/*===============================[ Test Runner ]=============================*/
/*===========================================================================*/
#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>

/*===========================================================================*/
/*===============================[  ]===============================*/
/*===========================================================================*/
BOOST_AUTO_TEST_SUITE(global);


BOOST_AUTO_TEST_CASE(isTrue) {

	BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_SUITE_END();

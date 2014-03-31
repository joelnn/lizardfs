#include <gtest/gtest.h>

#include <signal.h>

#include "common/crc.h"
#include "common/strerr.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	mycrc32_init();
	strerr_init();
	signal(SIGPIPE, SIG_IGN);
	return RUN_ALL_TESTS();
}

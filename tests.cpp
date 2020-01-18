#include "lib.h"
#include "gtest/gtest.h"

TEST(OperatorSum, expectedSum) {

ifstream file("../schedule.txt");
Road *mas = new Road[V];
string a;

Read_file(mas);


EXPECT_EQ(Way_to("a","d", mas), 1);
EXPECT_EQ(Way_to("a","f", mas), 10);
EXPECT_EQ(Way_to("b","f", mas), 9);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
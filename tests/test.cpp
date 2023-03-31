#include <gtest/gtest.h>
#include <vector>
#include "graphs.hpp"

TEST( Test, Subtest_1){
    std::vector<int> tmp = 
    {
        1, 0, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 0, 0, 
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 1
    };
    graph MyGraph(tmp);
    std::vector <int> result = {0, 3};
    ASSERT_TRUE(MyGraph.ShortestWay(0, 3) == result);

}

TEST( Test, Subtest_2){
    std::vector<int> tmp = 
    {
        1, 0, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 0, 1, 0, 1, 
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 1
    };
    graph MyGraph(tmp);
    std::vector <int> result = {0, 2, 4};
    ASSERT_TRUE(MyGraph.ShortestWay(0, 4) == result);

}

TEST( Test, Subtest_3){
    std::vector<int> tmp = 
    {
        1, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 0, 1, 1, 0, 
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 1
    };
    graph MyGraph(tmp);
    ASSERT_THROW(MyGraph.ShortestWay(0, 2), error);

}

TEST( Test, Subtest_4){
    std::vector<int> tmp = 
    {
        1, 0, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 1, 
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 1
    };
    graph MyGraph(tmp);
    std::vector <int> result = {0, 3, 1};
    ASSERT_TRUE(MyGraph.ShortestWay(0, 1) == result);

}

TEST( Test, Subtest_5){
    std::vector<int> tmp = 
    {
        1, 0, 0, 1, 1,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0, 
        0, 0, 0, 1, 0,
        0, 1, 0, 0, 1
    };
    graph MyGraph(tmp);
    auto temp =  MyGraph.ShortestWay(0, 2);
    std::vector <int> result = {0, 4, 1, 2};
    ASSERT_TRUE(MyGraph.ShortestWay(0, 2) == result);

}


int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
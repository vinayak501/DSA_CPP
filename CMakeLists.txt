cmake_minimum_required(VERSION 3.28)
project(CPP_Codes)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Codes Linked_List.cpp ListNode.cpp ListNode.h
        DListNode.cpp
        DListNode.h
        Doubly_Linked_List.cpp
        reverse_DLL.cpp
        sum_2_LL.cpp
        odd_even_LL.cpp
        english_to_integer_words.cpp
        clockwise_spiral_marix.cpp
        region_cut_GH.cpp
        minimum_no_of_days_to_disconnect_island_GH.cpp
        assign_cookies_GR.cpp
        frog_jump_DP.cpp
        lemonade_change.cpp
        unique_paths_DP.cpp
        combination_sum_2.cpp
        unique_paths_2.cpp)

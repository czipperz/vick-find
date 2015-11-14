#include <ncurses.h>

#include "../../../test/catch.hpp"
#include "../src/find.hh"

using namespace vick;
using namespace vick::find;

TEST_CASE("move_forward_find") {
    contents contents;
    contents.push_back(" hi man search way too hard for me");

    initscr();
    move_forward_find(contents, 'o', 2);
    CHECK(contents.x == 21);
    move_forward_find(contents, 'm', 1);
    CHECK(contents.x == 32);
    endwin();
}

TEST_CASE("move_backward_find") {
    contents contents;
    contents.push_back(" Simple text to search on");
    contents.x = 24;

    initscr();
    move_backward_find(contents, 'e', 1);
    CHECK(contents.x == 17);
    move_backward_find(contents, ' ', 1);
    CHECK(contents.x == 15);
    endwin();
}

TEST_CASE("move_forward_until_match") {
    contents contents;
    contents.push_back(" hi man search way too hard for me");

    initscr();
    move_forward_until_match(contents, 'o', 2);
    CHECK(contents.x == 20);
    move_forward_until_match(contents, 'm', 1);
    CHECK(contents.x == 31);
    endwin();
}

TEST_CASE("move_backward_until_match") {
    contents contents;
    contents.push_back(" Simple text to search on");
    contents.x = 24;

    initscr();
    move_backward_until_match(contents, 'e', 1);
    CHECK(contents.x == 18);
    move_backward_until_match(contents, ' ', 1);
    CHECK(contents.x == 16);
    endwin();
}

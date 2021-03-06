/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <ncurses.h>

#include "catch.hpp"

#include "../lib.hh"

using namespace vick;
using namespace vick::find;

TEST_CASE("move_forward_find") {
    contents contents({" hi man search way too hard for me"});

    move_forward_find(contents, 'o', 2);
    CHECK(contents.x == 21);
    move_forward_find(contents, 'm', 1);
    CHECK(contents.x == 32);
}

TEST_CASE("move_backward_find") {
    contents contents({" Simple text to search on"});
    contents.x = contents.cont[0].size() - 1;

    move_backward_find(contents, 'e', 1);
    CHECK(contents.x == 17);
    move_backward_find(contents, ' ', 1);
    CHECK(contents.x == 15);
}

TEST_CASE("move_forward_until_match") {
    contents contents({" hi man search way too hard for me"});

    move_forward_until_match(contents, 'o', 2);
    CHECK(contents.x == 20);
    move_forward_until_match(contents, 'm', 1);
    CHECK(contents.x == 31);
}

TEST_CASE("move_backward_until_match") {
    contents contents({" Simple text to search on"});
    contents.x = contents.cont[0].size() - 1;

    move_backward_until_match(contents, 'e', 1);
    CHECK(contents.x == 18);
    move_backward_until_match(contents, ' ', 1);
    CHECK(contents.x == 16);
}

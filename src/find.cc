#include <ncurses.h>

#include "../../../src/show_message.hh"
#include "find.hh"

void move_forward_find(contents& contents, boost::optional<int> op) {
    if(op && op.get() < 0) {
        return move_backward_find(contents, -op.get());
    }
    int times = op ? op.get() : 1;
    char ch = getch();
    auto new_x = contents.x + 1;

    if(contents.cont[contents.y].size() - contents.x < 1) return;

    for(; new_x < contents.cont[contents.y].size(); new_x++) {
        if(contents.cont[contents.y][new_x] == ch) {
            --times;
        }
        if(times == 0) {
            contents.x = new_x;
            return;
        }
    }
    show_message(std::string("Can't find '") + ch + '\'');
}

void move_backward_find(contents& contents, boost::optional<int> op) {
    if(op && op.get() < 0) {
        return move_forward_find(contents, -op.get());
    }
    int times = op ? op.get() : 1;
    char ch = getch();
    auto new_x = contents.x - 1;

    if(contents.x < 1) return;

    for(; new_x > 0; new_x--) {
        if(contents.cont[contents.y][new_x] == ch) {
            --times;
        }
        if(times == 0) {
            contents.x = new_x;
            return;
        }
    }
    if(times == 1 && contents.cont[contents.y][0] == ch) {
        contents.x = 0;
        return;
    }
    show_message(std::string("Can't find '") + ch + '\'');
}

void move_forward_until_match(contents& contents, boost::optional<int> op) {
    if(op && op.get() < 0) {
        return move_backward_until_match(contents, -op.get());
    }
    move_forward_find(contents, op);
    contents.x--;
}

void move_backward_until_match(contents& contents, boost::optional<int> op) {
    if(op && op.get() < 0) {
        return move_forward_until_match(contents, -op.get());
    }
    move_backward_find(contents, op);
    contents.x++;
}

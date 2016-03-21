#include <ncurses.h>

#include "../../../src/show_message.hh"
#include "find.hh"

namespace vick {
namespace find {

boost::optional<std::shared_ptr<change> >
move_forward_find_i(contents& contents, boost::optional<int> op) {
    return move_forward_find(contents, getch(), op ? op.get() : 1);
}

boost::optional<std::shared_ptr<change> >
move_forward_find(contents& contents, char ch, int times) {
    if (times < 0)
        return move_backward_find(contents, ch, -times);
    if (contents.cont[contents.y].size() - contents.x < 1)
        return boost::none;

    auto new_x = contents.x + 1;

    for (; new_x < contents.cont[contents.y].size(); new_x++) {
        if (contents.cont[contents.y][new_x] == ch) {
            --times;
        }
        if (times == 0) {
            contents.x = new_x;
            return boost::none;
        }
    }
    show_message(std::string("Can't find '") + ch + '\'');
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_backward_find_i(contents& contents, boost::optional<int> op) {
    return move_backward_find(contents, getch(), op ? op.get() : 1);
}

boost::optional<std::shared_ptr<change> >
move_backward_find(contents& contents, char ch, int times) {
    if (times < 0)
        return move_forward_find(contents, ch, -times);
    if (contents.x < 1)
        return boost::none;

    auto new_x = contents.x - 1;

    for (; new_x > 0; new_x--) {
        if (contents.cont[contents.y][new_x] == ch) {
            --times;
        }
        if (times == 0) {
            contents.x = new_x;
            return boost::none;
        }
    }
    if (times == 1 and contents.cont[contents.y][0] == ch) {
        contents.x = 0;
        return boost::none;
    }
    show_message(std::string("Can't find '") + ch + '\'');
    return boost::none;
}

boost::optional<std::shared_ptr<change> >
move_forward_until_match_i(contents& contents,
                           boost::optional<int> op) {
    if (op and op.get() < 0)
        return move_backward_until_match_i(contents, -op.get());
    auto ret =
        move_forward_find(contents, getch(), op ? op.get() : 1);
    if (contents.x > 0)
        contents.x--;
    return ret;
}
boost::optional<std::shared_ptr<change> >
move_forward_until_match(contents& contents, char ch, int times) {
    if (times < 0)
        return move_backward_until_match(contents, ch, -times);
    auto ret = move_forward_find(contents, ch, times);
    if (contents.x > 0)
        contents.x--;
    return ret;
}

boost::optional<std::shared_ptr<change> >
move_backward_until_match_i(contents& contents,
                            boost::optional<int> op) {
    if (op and op.get() < 0)
        return move_forward_until_match_i(contents, -op.get());
    auto ret =
        move_backward_find(contents, getch(), op ? op.get() : 1);
    if (contents.x < contents.cont[contents.y].size() - 1)
        contents.x++;
    return ret;
}
boost::optional<std::shared_ptr<change> >
move_backward_until_match(contents& contents, char ch, int times) {
    if (times < 0)
        return move_forward_until_match(contents, ch, -times);
    auto ret = move_backward_find(contents, ch, times);
    if (contents.x < contents.cont[contents.y].size() - 1)
        contents.x++;
    return ret;
}
}
}

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef HEADER_GUARD_FIND_H
#define HEADER_GUARD_FIND_H

#include "contents.hh"

namespace vick {
namespace find {

/*!
 * \file find.hh
 * \brief Basic commands that have to do with moving until finding
 * characters
 */

/*!
 * \brief Moves forward onto a character that is interactively
 * prompted
 *
 * It moves on top of the character so that calling it again will be
 * the same as using a prefix argument of two.
 *
 * Example when using ``f`` and prefix of one (cursor is ``|``):
 * \code
 * |start of text
 * start o|f text
 * \endcode
 *
 * \param[in,out] contents The contents to move on
 * \param[in] times The number of times to find the character that the
 * user inputs interactively.
 *
 * \post ``contents.y`` didn't change
 * \post ``contents.x`` is between ``0`` and
 * ``contents.cont[contents.y].size() - 1``, inclusive
 */
boost::optional<std::shared_ptr<change> >
move_forward_find_i(contents& contents,
                    boost::optional<int> times = 1);

boost::optional<std::shared_ptr<change> >
move_forward_find(contents& contents, char char_to_find,
                  int times = 1);

/*!
 * \brief Moves backward onto a character that is interactively
 * prompted
 *
 * It moves on top of the character so that calling it again will be
 * the same as using a prefix argument of two.
 *
 * Example when using ``f`` and prefix of one (cursor is ``|``):
 * \code
 * start of tex|t
 * start o|f text
 * \endcode
 *
 * \param[in,out] contents The contents to move on
 * \param[in] times The number of times to find the character that the
 * user inputs interactively.
 *
 * \post ``contents.y`` didn't change
 * \post ``contents.x`` is between ``0`` and
 * ``contents.cont[contents.y].size() - 1``, inclusive
 */
boost::optional<std::shared_ptr<change> >
move_backward_find_i(contents& contents,
                     boost::optional<int> times = 1);

boost::optional<std::shared_ptr<change> >
move_backward_find(contents& contents, char char_to_find,
                   int times = 1);

/*!
 * \brief Moves forward onto a character that is interactively
 * prompted then moves back one
 *
 * It moves on top of the character so that calling it again will be
 * the same as using a prefix argument of two.
 *
 * Example when using ``f`` and prefix of one (cursor is ``|``):
 * \code
 * |start of text
 * start |of text
 * \endcode
 *
 * \param[in,out] contents The contents to move on
 * \param[in] times The number of times to find the character that the
 * user inputs interactively.
 *
 * \post ``contents.y`` didn't change
 * \post ``contents.x`` is between ``0`` and
 * ``contents.cont[contents.y].size() - 1``, inclusive
 */
boost::optional<std::shared_ptr<change> >
move_forward_until_match_i(contents& contents,
                           boost::optional<int> times = 1);

boost::optional<std::shared_ptr<change> >
move_forward_until_match(contents& contents, char char_to_find,
                         int times = 1);

/*!
 * \brief Moves backward onto a character that is interactively
 * prompted then moves forward one
 *
 * It moves on top of the character so that calling it again will be
 * the same as using a prefix argument of two.
 *
 * Example when using ``f`` and prefix of one (cursor is ``|``):
 * \code
 * start of tex|t
 * start of| text
 * \endcode
 *
 * \param[in,out] contents The contents to move on
 * \param[in] times The number of times to find the character that the
 * user inputs interactively.
 *
 * \post ``contents.y`` didn't change
 * \post ``contents.x`` is between ``0`` and
 * ``contents.cont[contents.y].size() - 1``, inclusive
 */
boost::optional<std::shared_ptr<change> >
move_backward_until_match_i(contents& contents,
                            boost::optional<int> times = 1);

boost::optional<std::shared_ptr<change> >
move_backward_until_match(contents& contents, char char_to_find,
                          int times = 1);
}
}

#endif

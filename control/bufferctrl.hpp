/*************************************************************************
** Copyright (c) 2011-2012 Accusoft                                     **
** This program is free software, licensed under the GPLv3              **
** see README.license for details                                       **
**									**
** For obtaining other licenses, contact the author at                  **
** thor@math.tu-berlin.de                                               **
**                                                                      **
** Written by Thomas Richter (THOR Software)                            **
** Sponsored by Accusoft, Tampa, FL and					**
** the Computing Center of the University of Stuttgart                  **
**************************************************************************

This software is a complete implementation of ITU T.81 - ISO/IEC 10918,
also known as JPEG. It implements the standard in all its variations,
including lossless coding, hierarchical coding, arithmetic coding and
DNL, restart markers and 12bpp coding.

In addition, it includes support for new proposed JPEG technologies that
are currently under discussion in the SC29/WG1 standardization group of
the ISO (also known as JPEG). These technologies include lossless coding
of JPEG backwards compatible to the DCT process, and various other
extensions.

The author is a long-term member of the JPEG committee and it is hoped that
this implementation will trigger and facilitate the future development of
the JPEG standard, both for private use, industrial applications and within
the committee itself.

  Copyright (C) 2011-2012 Accusoft, Thomas Richter <thor@math.tu-berlin.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/
/*
**
** This is a common subclass of both the class controlling the
** hierarchical process, the LineAdapter, as well as the class controlling
** direct communication with the user buffer, the BitmapCtrl.
** It only exists for casting between the two and to the target class,
** the line or block buffer.
**
** $Id: bufferctrl.hpp,v 1.4 2012-06-02 10:27:13 thor Exp $
**
*/

#ifndef CONTROL_BUFFERCTRL_HPP
#define CONTROL_BUFFERCTRL_HPP

/// Includes
#include "../tools/environment.hpp"
///

/// Class BufferCtrl
// This is a common subclass of both the class controlling the
// hierarchical process, the LineAdapter, as well as the class controlling
// direct communication with the user buffer, the BitmapCtrl.
// It only exists for casting between the two and to the target class,
// the line or block buffer.
class BufferCtrl : public JKeeper {
  //
  // Nothing in it.
  //
public:
  BufferCtrl(class Environ *env)
    : JKeeper(env)
  { }
  //
  virtual ~BufferCtrl(void)
  { }
  //  
  // Return true in case this buffer is organized in lines rather
  // than blocks.
  virtual bool isLineBased(void) const = 0;
  //
  // First time usage: Collect all the information for encoding.
  // May throw on out of memory situations
  virtual void PrepareForEncoding(void) = 0;
  //
  // First time usage: Collect all the information for decoding.
  // May throw on out of memory situations.
  virtual void PrepareForDecoding(void) = 0;
  //
  // Indicate the frame height after the frame has already been
  // started. This call makes the necessary adjustments to handle
  // the DNL marker which appears only after the scan.
  virtual void PostImageHeight(ULONG height) = 0;
};
///

///
#endif

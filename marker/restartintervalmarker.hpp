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
** This class keeps the restart interval size in MCUs.
**
** $Id: restartintervalmarker.hpp,v 1.2 2012-06-02 10:27:14 thor Exp $
**
*/

#ifndef MARKER_RESTARTINTERVALMARKER_HPP
#define MARKER_RESTARTINTERVALMARKER_HPP

/// Includes
#include "../tools/environment.hpp"
///

/// Forwards
class ByteStream;
///

/// RestartIntervalMarker
// This class keeps the restart interval size in MCUs.
class RestartIntervalMarker : public JKeeper {
  //
  // The restart interval size in MCUs, or zero if restart markers
  // are disabled.
  UWORD     m_usRestartInterval;
  //
public:
  RestartIntervalMarker(class Environ *env);
  //
  ~RestartIntervalMarker(void)
  {
  }
  //
  // Install the defaults, namely the interval.
  void InstallDefaults(UWORD inter)
  {
    m_usRestartInterval = inter;
  }
  //
  // Return the currently active restart interval.
  UWORD RestartIntervalOf(void) const
  {
    return m_usRestartInterval;
  }
  //
  // Write the marker (without the marker id) to the stream.
  void WriteMarker(class ByteStream *io) const;
  //
  // Parse the marker from the stream.
  void ParseMarker(class ByteStream *io);
  //
};
///

///
#endif

/***************************************************************************
                          signalvertexbuffer.h  -  description
                             -------------------
    copyright            : (C) 2002 by Tue and Ken Haste Andersen and Kenny 
                                       Erleben
    email                :
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SIGNALVERTEXBUFFER_H
#define SIGNALVERTEXBUFFER_H

/** Display rate in Hz. This relates to the display resolution */
const int DISPLAYRATE = 200;

/**
 * A Signal Vertex Array Buffer.
 * This class is capable of preprosseing a
 * signal into a 3D representation.
 *
 * Each signal value is transformed into a 3D
 * point. The signal is plotted uniformly along
 * the x-axe, with an interspacing of 1 unit. Signal
 * values indicate the y-coordinate of the points.
 *
 * z-coordinates are set to zero for all points.
 */

#include "../defs.h"
#include <qobject.h>
#include <qgl.h>

class EngineBuffer;
class SoundBuffer;
class FastVertexArray;

typedef struct
{
    float           *p1, *p2;
    int             len1, len2;
} bufInfo;

class SignalVertexBuffer : public QObject
{
public:
    SignalVertexBuffer(EngineBuffer *engineBuffer, FastVertexArray *vertex);
    virtual ~SignalVertexBuffer();

    void update();
    bufInfo getVertexArray();
    int getBufferLength();
    int getDisplayLength();
    
    /** An openGL vertex array of a "unaltered" signal. */
    GLfloat *buffer;

private:
    /** The total number of samples in the buffer. */
    int len;
    /** Resample factor. An even integer determining the factor to reduce the incomming signal with */
    int resampleFactor;
    /** Number of samples to display (used in getVertexArray) */             
    int displayLen;
    /** Pointer to EngineBuffer */
    EngineBuffer *enginebuffer;
    /** Pounter to SoundBuffer */
    SoundBuffer *soundbuffer;
    /** Pointer to CFastVertexArray */
    FastVertexArray *vertex;
};
#endif


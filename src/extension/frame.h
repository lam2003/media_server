#ifndef MEDIA_SERVER_FRAME_H
#define MEDIA_SERVER_FRAME_H

namespace media_server {
typedef enum {
    TrackInvalid = -1,
    TrackVideo   = 0,
    TrackAudio   = 1,
    TrackTitle   = 2,
    TrackMax     = 3
} TrackType;

typedef enum {
    CodecInvalid = -1,
    CodecH264    = 0,
    CodecH265    = 1,
    CodecAAC     = 2,
    CodecG711A   = 3,
    CodecG711U   = 4,
    CodecOpus    = 5,
    CodecMax     = 6
} CodecType;

}  // namespace media_server

#endif
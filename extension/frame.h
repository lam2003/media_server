#ifndef MEDIA_SERVER_FRAME_H
#define MEDIA_SERVER_FRAME_H

namespace media_server {
typedef enum {
  TrackInvalid = -1,
  TrackVideo = 0,
  TrackAudio = 1,
  TrackTitle = 2,
  TrackMax = 3
} TrackType;

}  // namespace media_server

#endif
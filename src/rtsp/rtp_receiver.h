#ifndef MEDIA_SERVER_RTSP_RTP_RECEIVER_H
#define MEDIA_SERVER_RTSP_RTP_RECEIVER_H

namespace rtsp {
class RTPReceiver {
 public:
  RTPReceiver() {}
  virtual ~RTPReceiver() {}

 protected:
  bool HandleOneRTP(int track_index);
};
}  // namespace rtsp

#endif
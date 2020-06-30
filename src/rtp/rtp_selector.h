#ifndef MEDIA_SERVER_RTP_SELECTOR_H
#define MEDIA_SERVER_RTP_SELECTOR_H

#include <memory>

namespace media_server {

class RTPSelector : public std::enable_shared_from_this<RTPSelector> {
  public:
    ~RTPSelector();
    RTPSelector();

  public:
    static RTPSelector& Instance();

    // bool InputRTP()
};

}  // namespace media_server

#endif
#ifndef MEDIA_SERVER_RTSP_H
#define MEDIA_SERVER_RTSP_H

#include <extension/frame.h>

#include <map>
#include <memory>
#include <string>

namespace rtsp {
class SDPTrack {
  public:
    typedef std::shared_ptr<SDPTrack> Ptr;

    std::string ToString() const;

    std::string GetName() const;

  public:
    // sdp version，目前为0，无子版本号
    std::string v = "0";
    // media 媒体行,描述流媒体格式
    // 例如： m=audio 58779 UDP / TLS / RTP / SAVPF 111 103 104 9 0 8 106 105 13
    // 126
    std::string m;
    // owner 对于会话源的描述
    // o=(用户名)（会话标识）（版本）（网络类型）（地址类型）（地址）
    // 例如：o=StreamingServer 3677033027 1437537780000 IN IP4 192.168.1.44
    std::string o;
    // session 会话名
    // 例如：./test.mp4
    std::string s;
    // info 会话信息，对会话的文字性说明
    std::string i;
    // connection 连接信息
    // 例如：c=IN IP4 0.0.0.0
    std::string c;
    // time 会话活动时间
    // 例如：t=0 0
    std::string t;
    // bandwidth 带宽信息
    // 例如：b=AS:256

    // "AS" (for Application Specific Maximum) which may be used to specify the
    // total bandwidth for a single media stream from one site
    // "RS" indicates the RTCP bandwidth allocated to active data
    // senders (as defined by the RTP spec) and "RR" indicates the RTCP
    // bandwidth allocated to other participants in the RTP session (i.e.,
    // receivers).
    std::string b;

    uint16_t port;

    float duration = 0;
    float start    = 0;
    float end      = 0;

    std::map<char, std::string>        other;
    std::map<std::string, std::string> attr;

    // payload type
    int                     pt;
    std::string             codec;
    int                     samplerate;
    int                     channel;
    std::string             fmtp;
    std::string             control;
    std::string             control_surffix;
    media_server::TrackType type;

    uint8_t  interleaved = 0;
    bool     inited      = false;
    uint32_t ssrc        = 0;
    uint16_t seq         = 0;
    uint32_t timestamp   = 0;
};
}  // namespace rtsp

#endif
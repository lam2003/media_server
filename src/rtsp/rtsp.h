#ifndef MEDIA_SERVER_RTSP_H
#define MEDIA_SERVER_RTSP_H

#include <extension/frame.h>

#include <map>
#include <memory>
#include <string>

namespace rtsp {

// https://en.wikipedia.org/wiki/RTP_payload_formats
#define RTP_PT_MAP(XX)                                                         \
    XX(PCMU, media_server::TrackAudio, 0, 8000, 1, media_server::CodecG711U)   \
    XX(GSM, media_server::TrackAudio, 3, 8000, 1, media_server::CodecInvalid)  \
    XX(G723, media_server::TrackAudio, 4, 8000, 1, media_server::CodecInvalid) \
    XX(DVI4_8000, media_server::TrackAudio, 5, 8000, 1,                        \
       media_server::CodecInvalid)                                             \
    XX(DVI4_16000, media_server::TrackAudio, 6, 16000, 1,                      \
       media_server::CodecInvalid)                                             \
    XX(LPC, media_server::TrackAudio, 7, 8000, 1, media_server::CodecInvalid)  \
    XX(PCMA, media_server::TrackAudio, 8, 8000, 1, media_server::CodecG711A)   \
    XX(G722, media_server::TrackAudio, 9, 8000, 1, media_server::CodecInvalid) \
    XX(L16_Stereo, media_server::TrackAudio, 10, 44100, 2,                     \
       media_server::CodecInvalid)                                             \
    XX(L16_Mono, media_server::TrackAudio, 11, 44100, 1,                       \
       media_server::CodecInvalid)                                             \
    XX(QCELP, media_server::TrackAudio, 12, 8000, 1,                           \
       media_server::CodecInvalid)                                             \
    XX(CN, media_server::TrackAudio, 13, 8000, 1, media_server::CodecInvalid)  \
    XX(MPA, media_server::TrackAudio, 14, 90000, 1,                            \
       media_server::CodecInvalid)                                             \
    XX(G728, media_server::TrackAudio, 15, 8000, 1,                            \
       media_server::CodecInvalid)                                             \
    XX(DVI4_11025, media_server::TrackAudio, 16, 11025, 1,                     \
       media_server::CodecInvalid)                                             \
    XX(DVI4_22050, media_server::TrackAudio, 17, 22050, 1,                     \
       media_server::CodecInvalid)                                             \
    XX(G729, media_server::TrackAudio, 18, 8000, 1,                            \
       media_server::CodecInvalid)                                             \
    XX(CelB, media_server::TrackVideo, 25, 90000, 1,                           \
       media_server::CodecInvalid)                                             \
    XX(JPEG, media_server::TrackVideo, 26, 90000, 1,                           \
       media_server::CodecInvalid)                                             \
    XX(nv, media_server::TrackVideo, 28, 90000, 1, media_server::odecInvalid)  \
    XX(H261, media_server::TrackVideo, 31, 90000, 1,                           \
       media_server::CodecInvalid)                                             \
    XX(MPV, media_server::TrackVideo, 32, 90000, 1,                            \
       media_server::CodecInvalid)                                             \
    XX(MP2T, media_server::TrackVideo, 33, 90000, 1,                           \
       media_server::CodecInvalid)                                             \
    XX(H263, media_server::TrackVideo, 34, 90000, 1, media_server::CodecInvalid)

class SDPTrack final {
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
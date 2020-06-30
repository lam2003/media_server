#include <common/version.h>
#include <rtsp/rtsp.h>
#include <utils/utils.h>

namespace rtsp {

static void get_attr_sdp(const std::map<std::string, std::string>& attr,
                         common_library::__StringPrinter&          printer)
{
    const std::map<std::string, std::string>::value_type* ptr = nullptr;
    for (const std::pair<const std::string, std::string>& it : attr) {
        if (it.first == "control") {
            ptr = &it;
            continue;
        }

        if (it.second.empty()) {
            printer << "a=" << it.first << "\r\n";
        }
        else {
            printer << "a=" << it.first << ":" << it.second << "\r\n";
        }
    }
    if (ptr) {
        printer << "a=" << ptr->first << ":" << ptr->second << "\r\n";
    }
}

std::string SDPTrack::ToString() const
{
    common_library::__StringPrinter printer;
    switch (type) {
        case media_server::TrackTitle: {
            printer << "v=" << v << "\r\n";
            if (!o.empty()) {
                printer << "o=" << o << "\r\n";
            }
            if (!c.empty()) {
                printer << "c=" << c << "\r\n";
            }
            if (!t.empty()) {
                printer << "t=" << t << "\r\n";
            }

            printer << "s=Streamed By " << SERVER_VERSION << "\r\n";
            get_attr_sdp(attr, printer);
            break;
        }

        case media_server::TrackAudio:
        case media_server::TrackVideo: {
            if (type == media_server::TrackAudio) {
                // 0代表版本号，RTP表示传输协议,AVP(audio video
                // profile)表示未加密的传输，SAVP表示通过SRTP加密传输
                printer << "m=audio 0 RTP/AVP" << pt << "\r\n";
            }
            else {
                printer << "m=video 0 RTP/AVP" << pt << "\r\n";
            }

            if (!b.empty()) {
                printer << "b=" << b << "\r\n";
            }

            get_attr_sdp(attr, printer);
            break;
        }

        default: {
            break;
        }
    }

    return printer;
}
}  // namespace rtsp
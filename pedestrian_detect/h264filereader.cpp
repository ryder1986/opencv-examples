#include "h264filereader.h"
//#include <cstring>
H264FileReader::H264FileReader()
{
}
int H264FileReader::open_h264_file(m_h264_file_common *common)
{

    AVFormatContext **av_format_context=&common->av_format_context;
    char * fn=common->file_name;
    //	av_register_all();
    if (fn != NULL) {
        const char *fileName = fn;
        *av_format_context = avformat_alloc_context();
        if (avformat_open_input(av_format_context, fileName, NULL, 0) != 0) {
            prt(err, "file %s not found", fileName);
            // exit_program()
            return -1;
        } else if (avformat_find_stream_info(*av_format_context, NULL) < 0) {
            // exit_program()
            return -1;
        }
    }
    return 0;
    //   prt(info,"%x",av_format_context);
}
int H264FileReader::get_file_264buf(m_h264_file_common *common)
{
    AVFormatContext *av_format_context=common->av_format_context;
    AVPacket *h264_pkt=&common->h264_pkt;
    av_init_packet(h264_pkt);
    if ((av_read_frame(av_format_context, h264_pkt) >= 0)) {
        //    prt(info," pkt  size+++++++++++++++++++++++++++++++++++++++++ %d",h264_pkt->size);
    }
    return 0;
}


void H264FileReader::read()
{
    get_file_264buf(&ctx);
    p_data=ctx.h264_pkt.data;
    size=ctx.h264_pkt.size;
    prt(info,"%d",ctx.h264_pkt.size);
}

ui8 * H264FileReader::get_file_name()
{
    return (ui8 *)h264_file;
}

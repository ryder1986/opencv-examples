#ifndef H264FILEREADER_H
#define H264FILEREADER_H
#include "common.h"
#ifdef __cplusplus
extern "C"{
#endif
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#ifdef __cplusplus
}
#endif
#define MAX_LEN 300000
typedef struct h264_file_common {
    char file_name[FILENAME_MAX];
    AVFormatContext *av_format_context;
    AVPacket h264_pkt;
} m_h264_file_common;
typedef struct buffer_head {
    long length;
    int version;
} m_buffer_head;

class H264FileReader
{
public:
    H264FileReader();
    ~H264FileReader()
    {
        close_h264_file(&ctx);
    }

    H264FileReader(ui8 *file_name)
    {
        av_register_all();
        strcpy(ctx.file_name,(char *)file_name);
        strcpy((char *)h264_file,(char *)file_name);
        open_h264_file(&ctx);
    }
    int open_h264_file(m_h264_file_common *common);
    int get_file_264buf(m_h264_file_common *common);
    void read();
    void close_h264_file(m_h264_file_common *common)
    {
        avformat_close_input(&common->av_format_context);
    }
    ui8* get_file_name();
    int size;
    unsigned  char *p_data;
    m_h264_file_common ctx;
private:
    ui8 h264_file[FILENAME_MAX];

    static unsigned char buf[MAX_LEN];
    m_buffer_head bf_head;

};

#endif // H264FILEREADER_H

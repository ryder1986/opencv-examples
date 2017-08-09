#ifndef H264DECODER_H
#define H264DECODER_H

#include <stdio.h>
#include <string.h>
#ifdef HW_DECODE
#include <va/va.h>
#include <va/va_drm.h>
#include "hw_vaapi.h"
#endif
#include "common.h"
#ifdef __cplusplus
extern "C" {
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
#include <unistd.h>
#include <pthread.h>

#ifdef __cplusplus
}
#endif
//#define USE_FILE
#define PLAY_FRAMES
//typedef struct{
//    AVFrame * pFrame_;
//    AVCodecContext * codec_;
//    AVCodec * videoCodec;
//    AVFormatContext *av_format_context;
//    AVPacket h264_pkt;
//    FILE * out_file;
//#ifdef HW_DECODE
//    struct va_info vainfo;
//#endif
//    unsigned char *y;
//    unsigned char *u;
//    unsigned char *v;
//    int frames;
//#ifdef USE_FILE
//    int frms=0;
//#endif
//#ifdef SEND_TO_CLIENT
//    unsigned int h264_len;
//    unsigned char h264_buf[200000];

//#endif
//#ifdef PLAY_FRAMES

//    int w;
//    unsigned char  buf_src[640*480*3/2];
//    unsigned char  buf_dst[640*480*3];
//    int frame_ready;
//    int first_frame;
//    pthread_t p_handle;
//    //m_timed_func_data timer_data;
//#endif
//    char *fn=NULL;

//}mDeCoder;


typedef struct codec_common {
    AVFrame * p_av_frame;
    AVCodecContext * p_av_codec_ctx;
    AVCodec * p_av_codec;
    AVPacket av_pkt;
    unsigned char *oubuf;
    unsigned char *oubufu;
    unsigned char *oubufv;
    int frames;
#ifdef HW_DECODE
    struct va_info vainfo;
#endif
} m_codec_common;


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
class H264Decoder
{
public:
    H264Decoder(){

    }
    ~H264Decoder()
    {

    }

    void open_decoder()
    {
        open_h264_decoder();
    }
    void close_decoder()
    {
        close_h264_decoder();
    }
    int decode(char *pkt,int len,unsigned char **y,unsigned char **u, unsigned char **v)
    {
        return  h264_decode(pkt,len,y,u,v);
    }
private:
    m_codec_common codec_info[8];
    int index=0;
    int h264_decode(char *data,int size,unsigned char **y, unsigned char **u,unsigned char **v)
    {

        m_codec_common *de=&codec_info[index];
        de->av_pkt.data=(unsigned char *)data;
        de->av_pkt.size=size;
        //    prt(info,"bf[0]:%c , bf[%d]:%c",  data[0]='a', size-1,data[size-1]='z');
        if (!ffmeg_decode_video1(&de->av_pkt, de->p_av_codec_ctx, de->p_av_frame,index)) {
            prt(info,"decode ok");
            (de->oubuf) = (unsigned char *) de->p_av_frame->data[0];
            (de->oubufu) = (unsigned char *) de->p_av_frame->data[1];
            (de->oubufv) = (unsigned char *) de->p_av_frame->data[2];

            *y = (unsigned char *) de->p_av_frame->data[0];
            *u = (unsigned char *) de->p_av_frame->data[1];
            *v= (unsigned char *) de->p_av_frame->data[2];
            return 1;
        }
        //   cv::Mat a(480,640,CV_8UC1);;
        //        cv::Mat a;
        //        a.create(480,640,CV_8U);
        //            memcpy(a.data,de->p_av_frame->data[0], 640*480);

        //             cv::imshow("dfsafsd",a);
        //           prt(info,"decode end");

        return 0;
    }
    int ffmeg_decode_video1(AVPacket *pkt,
                            AVCodecContext *m_AVCodeContext, AVFrame *m_AVFrame,int index)
    {
#ifdef HW_DECODE
        //struct va_info *vainfo = &de->vainfo;
#endif
        int got_picture = 0;
        int len = 0;
        av_init_packet(pkt);

#ifdef SEND_TO_CLIENT
        memcpy(de->h264_buf, pkt->data, pkt->size);

        de->h264_len = pkt->size;
#endif
        while (pkt->size > 0) {
            len = avcodec_decode_video2(m_AVCodeContext, m_AVFrame, &got_picture,
                                        pkt);
            if (len < 0) {
                return -1;
            }
            if (got_picture) {
#ifdef HW_DECODE
                vaapi_decode_to_image(&codec_info[index].vainfo);		//get rst buffer from hw surface
#endif

                return 0;
                break;
            }
            pkt->size -= len;
            pkt->data += len;
        }
        return 1;
    }

    int close_h264_decoder()
    {
        int index=0;
        m_codec_common *common=&codec_info[index];

        if (common->p_av_frame) {
            av_free(common->p_av_frame);
            common->p_av_frame=NULL;
        }
        if (common->p_av_codec_ctx) {
            avcodec_close(common->p_av_codec_ctx);
            common->p_av_codec_ctx=NULL;
        }

        return 1;
    }

    int open_h264_decoder()
    {
        int index=0;
        m_codec_common *codec_common=&codec_info[index];

        AVFrame ** p_p_av_frame=&codec_common->p_av_frame;
        AVCodecContext ** p_p_av_codec_ctx=&codec_common->p_av_codec_ctx;
        AVCodec ** p_p_av_codec=&codec_common->p_av_codec;

        //	AVFrame * p_av_frame=*p_p_av_frame;
        //	AVCodecContext * p_av_codec_ctx=*p_p_av_codec_ctx;
        //	AVCodec * p_av_codec=*p_p_av_codec;
        //char *fn = de->fn;
        //de->frames=0;
#ifdef PLAY_FRAMES
        //	create_detach_thread(play_thread, 1, de);
        //	start_gl_window(&de->w);
#endif
        av_register_all();
        //	if (fn != NULL) {
        //		const char *fileName = fn;
        //		de->av_format_context = avformat_alloc_context();
        //		if (avformat_open_input(&de->av_format_context, fileName, NULL, 0) != 0) {
        //			prt(err, "file %s not found", fileName);
        //			exit_program()
        //			;
        //		} else if (avformat_find_stream_info(de->av_format_context, NULL) < 0) {
        //			exit_program()
        //			;
        //		}
        //	}
        *p_p_av_codec = avcodec_find_decoder(CODEC_ID_H264);
        *p_p_av_codec_ctx = avcodec_alloc_context3(*p_p_av_codec);
        if (avcodec_open2(*p_p_av_codec_ctx, *p_p_av_codec, NULL) >= 0)
            *p_p_av_frame= avcodec_alloc_frame();
        else {
            //	H264DeocderRelease(de);
            return -1;
        }
#ifdef HW_DECODE
        codec_common->vainfo.vaapi_context = NULL;
        codec_common->vainfo.vaapi_context_ffmpeg = NULL;
        codec_common->vainfo.av_frame = codec_common->p_av_frame;
        //#ifdef HW_DECODE
        open_va(&(codec_common->vainfo));
        ffmpeg_init_context(&(codec_common->p_av_codec_ctx));
        //#endif
        codec_common->p_av_codec_ctx->opaque = &codec_common->vainfo;
#endif
        return 0;
    }

};

#endif // H264DECODER_H

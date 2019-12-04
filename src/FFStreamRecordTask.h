#ifndef FFStreamRecordTask_H
#define FFStreamRecordTask_H


class FFStreamRecordTask
{
public:
    FFStreamRecordTask();
    virtual ~FFStreamRecordTask();

	void  SetInputUrl(string rtspUrl);
	void  SetOutputPath(string outputPath);

    void  StartRecvStream();
    void  StopRecvStream();

	void GetVideoSize(long & width, long & height)
	{
		width  = m_video_width;
		height = m_video_height;
	}

	void  SetNotifyWnd(HWND hNotify)
	{
		m_hNotifyWnd = hNotify;
	}
		
	BOOL   CheckTimeOut(DWORD dwCurrentTime);

private:
    void run();

    int    OpenInputStream();
    void   CloseInputStream();

    void   readAndMux();

	static DWORD WINAPI ReadingThrd(void * pParam);

	int   openOutputStream();
	void  closeOutputStream();


private:

    string m_InputUrl;
    string m_outputFile;

    AVFormatContext* m_inputAVFormatCxt;
    AVBitStreamFilterContext* m_bsfcAAC;
	AVBitStreamFilterContext* m_bsfcH264;

	int m_videoStreamIndex;
	int m_audioStreamIndex;

    AVFormatContext* m_outputAVFormatCxt;

    char m_tmpErrString[64];
    bool m_stop_status;

	HANDLE m_hReadThread;

	BOOL   m_bInputInited;
	BOOL   m_bOutputInited;

	int    m_video_width, m_video_height;
	int    m_frame_rate;

	HWND    m_hNotifyWnd;

	DWORD     m_dwStartConnectTime; //��ʼ���յ�ʱ�䣬ϵͳʱ�䣬��λ������
	DWORD     m_dwLastRecvFrameTime; //��һ���յ�֡���ݵ�ʱ�䣬ϵͳʱ�䣬��λ������
	DWORD     m_nMaxRecvTimeOut; //����������ݵĳ�ʱʱ�䣬��λ������
	DWORD     m_nMaxConnectTimeOut; //���ӳ�ʱ����λ������

	int       m_nRecordedTimeLen; //¼�Ƶ�������

};

#endif // FFStreamRecordTask_H

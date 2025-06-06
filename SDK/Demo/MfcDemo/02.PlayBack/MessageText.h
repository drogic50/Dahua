#ifndef MESSAGETEXT_H
#define MESSAGETEXT_H

#include <windows.h>

#define MSG_ERROR_PASSWORD			"密码不正确"
#define MSG_ERROR_USER				"帐户不存在"
#define MSG_ERROR_TIMEOUT			"等待登录返回超时"
#define MSG_ERROR_RELOGGIN			"帐号已登录"
#define MSG_ERROR_LOCKED			"帐号已被锁定"
#define MSG_ERROR_BLOCKLIST			"帐号已被列为禁止名单"
#define MSG_ERROR_BUSY				"资源不足，系统忙"
#define MSG_ERROR_CONNECT			"连接主机失败"
#define MSG_ERROR_NETWORK			"网络连接失败"
#define MSG_ERROR_LISTEN			"设备监听出错"
#define MSG_DEVICE_DISCONNECT		"设备断线"

#define MSG_ERROR_IOCTRL_IN			"设置IO输入不正常"
#define MSG_ERROR_IOCTRL_OUT		"设置IO输出不正常"
#define MSG_ERROR_ALARMCHL_OVERMAX	"输入报警通道大于最大值"
#define MSG_ERROR_ALARM_STATUS		"获取报警状态错误"

#define MSG_CLIENTSTATE_DISKERR			"坏硬盘:"
#define MSG_CLIENTSTATE_ALARM			"报警:"
#define MSG_CLIENTSTATE_ALMDEC			"报警解码器"
#define MSG_CLIENTSTATE_RECORDING		"录像:"
#define MSG_CLIENTSTATE_MOTION			"动态检测:"
#define MSG_CLIENTSTATE_VIDEOLOST		"视频丢失:"
#define MSG_CLIENTSTATE_CLIENTSTATE		"状态:"
#define MSG_CLIENTSTATE_SOUND			"音频报警："
#define MSG_CLIENTSTATE_SHELTER			"遮挡报警："
#define MSG_CLIENTSTATE_DISKFULL		"硬盘满："
#define MSG_CLIENTSTATE_SERIAL			"序列号:"

#define MSG_WORKSTATE_SHELTER			"遮挡报警:"
#define MSG_WORKSTATE_RECORDING			"录象状态:"

#define MSG_WORKSTATE_CLIENTSTATE		"设备状态      :  "
#define MSG_WORKSTATE_NORMAL			"正常"
#define MSG_WORKSTATE_CPUTOOHIGH		"cpu占用过高"
#define MSG_WORKSTATE_HARDWAREEROR		"硬件错误"
#define MSG_WORKSTATE_UNKNOWNEEROR		"错误原因不明"
#define MSG_WORKSTATE_DISPLAYSTATE		"   设备显示状态: "
#define MSG_WORKSTATE_UNNORMAL			"不正常"
#define MSG_WORKSTATE_RECORDCHL			"录像通道        :  "
#define MSG_WORKSTATE_VIDEOLOSTCHL		"信号丢失通道:  "
#define MSG_WORKSTATE_HARDWAREERRCHL	"硬件异常通道:  "
#define MSG_WORKSTATE_VIDEOLOSTCHL		"信号丢失通道:  "
#define MSG_WORKSTATE_ALARMINPUT		"输入端口报警:  "
#define MSG_WORKSTATE_ALARMOUTPUT		"输出端口报警:  "

#define MSG_PTZCTRL_NOCHANNEL			"通道没打开"
#define MSG_PTZCTRL_CTRLFAILED			"云台菜单控制操作失败"

#define MSG_DEMODLG_SPLITTYPE_1			"单画面"
#define MSG_DEMODLG_SPLITTYPE_4			"四画面"
#define MSG_DEMODLG_SPLITTYPE_9			"九画面"
#define MSG_DEMODLG_SPLITTYPE_16		"十六画面"
#define MSG_DEMODLG_CHECKSEL			"请先连接设备和在上表中选中"
#define MSG_DEMODLG_PLAYING				"当前画面正在播放,请先关闭当前播放功能"
#define MSG_DEMODLG_OPENCHLFAILED		"打开通道失败，可能通道已经在别的窗口中打开了"
#define MSG_DEMODLG_NOPREVIEW			"无多画面预览"
#define MSG_DEMODLG_SAVEDATAFAILED		"保存数据失败"
#define MSG_DEMODLG_PLAYFAILED			"打开播放失败"
#define MSG_DEMODLG_PTZCMDFAILED		"云台控制参数出错或命令不实现"
#define MSG_DEMODLG_NOTOPENNED			"当前画面没打开"
#define MSG_DEMODLG_PTZCTRLFAILED		"云台控制操作失败"
#define MSG_DEMODLG_NOTPLAYING			"当前不在播放"
#define MSG_DEMODLG_PLAYCTRLFAILED		"播放操作控制失败"
#define MSG_DEMODLG_PAUSE				"  暂停  "
#define MSG_DEMODLG_PLAY				"  播放  "
#define MSG_DEMODLG_STOPPLAYFAILED		"停止播放失败"
#define MSG_DEMODLG_CANTCAPTURE			"当前未打开图像,不能抓图"
#define MSG_DEMODLG_CAPTUREFAILED		"抓图失败"
#define MSG_DEMODLG_CANTFORCE_I			"当前通道不在预览,不能强制I帧"
#define MSG_DEMODLG_FAILEDFORCE_I		"强制I帧失败"
#define MSG_DEMODLG_REALSAVE_STOPPED	"保存实时数据已关闭"
#define MSG_DEMODLG_MONITOR				"预览"
#define MSG_DEMODLG_PREVIEW				"预览"
#define MSG_DEMODLG_PLAYBACKCHL			"回放通道"
#define MSG_DEMODLG_CYCLEMONITOR		"轮循"
#define MSG_DEMODLG_UPDATING			"开始升级...."
#define MSG_DEMODLG_UPDATEFAILED		"升级失败"
#define MSG_DEMODLG_NOTMONITOR			"当前画面不是预览画面"
#define MSG_DEMODLG_OPENTALKFAILED		"打开对讲失败"
#define MSG_DEMODLG_CLOSETALKFAILED		"关闭对讲失败"
#define MSG_DEMODLG_OPENFILEFAILED		"打开文件失败"
#define MSG_DEMODLG_ERROR_CYCLING		"当前通道正在轮循"
#define MSG_DEMODLG_REBOOTFAILED		"重启设备失败"
#define MSG_DEMODLG_REBOOTDONE			"设备已重启"
#define MSG_DEMODLG_SHUTDOWNFAILED		"关闭设备失败"
#define MSG_DEMODLG_SHUTDOWNDONE		"设备已关闭"

#define MSG_RECORDCTRL_SETUPFAILED		"保存设置录像不正常"
#define MSG_RECORDCTRL_QUERYSTATEFAILED	"获取录像状态错误"

#define MSG_SCHRECORD_NODEVICE			"请先选择已连接的设备"
#define MSG_SCHRECORD_CHOOSEDEVICE		"设备选择"
#define MSG_SCHRECORD_CHLNO_INVALID		"通道号无效"
#define MSG_SCHRECORD_CHLNO				"通道号"
#define MSG_SCHRECORD_TIMEINPUT_ERR		"时间输入有误，请重新输入"
#define MSG_SCHRECORD_TIMEINPUT			"时间输入"
#define MSG_SCHRECORD_QUERYFAILED		"查询失败"
#define MSG_SCHRECORD_NORECORD			"查无记录"
#define MSG_SCHRECORD_QUERYTYPE_LIST	"列表查询"
#define MSG_SCHRECORD_QUERYTYPE_ALARM	"报警查询"
#define MSG_SCHRECORD_QUERYTYPE_CARD	"卡号查询"
#define MSG_SCHRECORD_DVC_AND_CHL		"设备和通道"
#define MSG_SCHRECORD_STARTTIME			"开始时间"
#define MSG_SCHRECORD_ENDTIME			"结束时间"
#define MSG_SCHRECORD_SIZE				"大小"
#define MSG_SCHRECORD_DOWNLORD_CB_ERR	"下载回调出错"
#define MSG_SCHRECORD_DOWNLOAD_FIN		"下载完毕"
#define MSG_SCHRECORD_DOWNLOADFILE_SEL	"请查询和选择要下载的文件"
#define MSG_SCHRECORD_DOWNLOAD			"开始"
#define MSG_SCHRECORD_CANCELDOWNLOAD		"停止"
#define MSG_SCHRECORD_CANCELED			"下载已停止"
#define MSG_SCHRECORD_PLAYFILE_SEL		"请查询和选择要播放的的文件"
#define MSG_SCHRECORD_PLAY				"播放"
#define MSG_SCHRECORD_STARTDLFAILED		"下载失败，请重试"
#define MSG_SCHRECORD_STOPDLFAILED		"停止下载失败"
#define MSG_SCHRECORD_ILLEGALFRAME		"帧率范围1-120"

#define MSG_SPLITINFO_BLANK				"当前显示画面空白，可以选择预览或回放图像"
#define MSG_SPLITINFO_MONITOR			"网络预览"
#define MSG_SPLITINFO_PLAYBACK			"网络回放"
#define MSG_SPLITINFO_PREVIEW			"网络预览"
#define MSG_SPLITINFO_CYCLEMONITOR		"轮循预览"
#define MSG_SPLITINFO_NOLIMIT			" 无限制 "
#define MSG_SPLITINFO_NODEVICE			"请先选择已连接的设备"
#define MSG_SPLITINFO_CHOOSEDEVICE		"设备选择"
#define MSG_SPLITINFO_LIMIT_FAILED		"限定码流失败"

#define MSG_TRANSCOM_DATABIT_BITS		"位"
#define MSG_TRANSCOM_STOPBIT_1BIT		" 1 位"
#define MSG_TRANSCOM_STOPBIT_15BITS		" 1.5 位"
#define MSG_TRANSCOM_STOPBIT_2BITS		" 2 位"
#define MSG_TRANSCOM_PARITY_NO			"无校验"
#define MSG_TRANSCOM_PARITY_ODD			"奇校验"
#define MSG_TRANSCOM_PARITY_EVEN		"偶校验"
#define MSG_TRANSCOM_CLOSECOM			"关闭串口"
#define MSG_TRANSCOM_OPENCOM			"打开串口"
#define MSG_TRANSCOM_OPENTRANSCOMFAILED	"打开透明串口失败"
#define MSG_TRANSCOM_SENDDATAFAILED		"发送数据失败"

#define MSG_CYCLE_OPENCHANNELFAILED		"轮循中打开通道失败"
#define MSG_CYCLE_CLOSECHANNELFAILED		"轮循中通道关闭失败"
#define MSG_CYCLE_STOPCYCLEERROR		"停止轮循出错!"
#define MSG_CYCLE_STOPMONITORERROR		"停止实时预览出错!"
#define MSG_CYCLE_STOPNETPLAYERROR		"停止网络回放出错!"
#define MSG_CYCLE_STOPMULTIPLAYERROR		"停止多画面预览出错!"

#define NAME_DEVICE				"设备"
#define NAME_CHANNEL				"通道"
#define NAME_SCRN				"屏幕"
#define NAME_UNBROADCASTDEV		"非广播设备"
#define NAME_BROADCASTDEV		"广播设备"

#define NAME_CFG_SERVERCONFIG			"设备属性"
#define NAME_CFG_CHANNELCONFIG			"图像通道属性"
#define NAME_CFG_SERIALCONFIG			"串口属性"
#define NAME_CFG_ALARMCONFIG			"报警属性"
#define NAME_CFG_ALARMRECORD			"录象配置"
#define NAME_CFG_USERCONFIG				"用户配置"
#define NAME_CFG_NETWORK				"网络配置"
/*
#define NAME_ALARMCFG_ALLINPUT			"全部报警量"
#define NAME_ALARMCFG_INPUT			"报警量"
#define NAME_ALARMCFG_ALLOUTPUT			"全部报警输出"
#define NAME_ALARMCFG_OUTPUT			"报警输出"
#define MSG_ALARMCFG_GETINPUTCFGFAILED		"获取报警参数失败!"
#define MSG_ALARMCFG_GETOUTPUTCFGFAILED		"获取报警输出参数失败!"
#define MSG_ALARMCFG_HOURERROR			"小时的范围在0 -- 24之间!"
#define MSG_ALARMCFG_MINUTEERROR		"分钟的范围在0 -- 60之间!"
#define MSG_ALARMCFG_TIMEILLEGAL		"布防时间不能超过24:00!"
#define MSG_ALARMCFG_TIMEILLEGAL2		"布防起始时间不能大于停止时间!"
#define MSG_ALARMCFG_TIMEILLEGAL3		"布防时间段不能重复!"
*/
#define NAME_CHANNELCFG_ALLCHANNEL		"全部通道"
#define NAME_CHANNELCFG_CHANNEL			"通道"
#define NAME_CHANNELCFG_STOPREC			"停止录像"
#define NAME_CHANNELCFG_STARTREC		"远程录像"
#define MSG_CHANNELCFG_GETCHANNELCFGFAILED	"获取参数失败!通道:"

#define NAME_SERIALCFG_ALLCHANNEL		"全部通道"
#define NAME_SERIALCFG_CHANNEL			"通道"
#define MSG_SERIALCFG_PSWCHECKERROR		"密码校验不正确！"


//#define MSG_SERIALCFG_NONE			"无校验"
//#define MSG_SERIALCFG_ODD			"奇校验"
//#define MSG_SERIALCFG_EVEN			"偶校验"

#define MSG_CLOSESOUNDFAILED			"关闭音频失败"
#define MSG_OPENSOUNDFAILED				"打开音频失败"

#define MSG_VERSION						"  --NetSDK版本:"

#define MSG_UG_OPENFILE				"打开文件"
#define MSG_UG_FAILED				"失败"
#define MSG_UG_ERROR				"错误"
#define MSG_FILE_MISSTYPE				"当前文件不是正确的升级文件"
#define MSG_UG_STARTFAILED			"开始升级失败"
#define MSG_UG_SENDFAILED				"发送升级文件失败"
#define MSG_UG_STOPFAILED				"结束升级失败"
#define MSG_UG_DONE				"升级完成，设备即将重启"
#define MSG_TRANSFER_DONE				"文件已传送完毕，请等待.."
#define MSG_UP_PROGRESS					"升级进度"

#define NAME_BTN_NORMAL					"常规"
#define NAME_BTN_ADVANCE				"高级"
#define NAME_BTN_PTZ					"云台"
#define NAME_BTN_DEVLIST				"设备"
#define NAME_BTN_COLOR					"颜色"
#define NAME_BTN_CBDATA					"回调"
#define NAME_BTN_PBCTRL					"回放"

#define NAME_RUNTIME_CHANNEL			"通道:"
#define NAME_RUNTIME_TOTAL				"设备:"

#define ERROR_NET_NOERROR					"没有错误"		
#define ERROR_NET_ERROR						"未知错误"		
#define ERROR_NET_SYSTEM_ERROR				"Windows系统出错"
#define ERROR_NET_NETWORK_ERROR				"网络错误，可能是因为网络超时"		
#define ERROR_NET_DEV_VER_NOMATCH			"设备协议不匹配"		
#define ERROR_NET_INVALID_HANDLE			"句柄无效"		
#define ERROR_NET_OPEN_CHANNEL_ERROR		"打开通道失败"		
#define ERROR_NET_CLOSE_CHANNEL_ERROR		"关闭通道失败"		
#define ERROR_NET_ILLEGAL_PARAM				"用户参数不合法"		
#define ERROR_NET_SDK_INIT_ERROR			"SDK初始化出错"		
#define ERROR_NET_SDK_UNINIT_ERROR			"SDK清理出错"		
#define ERROR_NET_RENDER_OPEN_ERROR			"申请render资源出错"		
#define ERROR_NET_DEC_OPEN_ERROR			"打开解码库出错"		
#define ERROR_NET_DEC_CLOSE_ERROR			"关闭解码库出错"		
#define ERROR_NET_MULTIPLAY_NOCHANNEL		"多画面预览中检测到通道数为0"		
#define ERROR_NET_TALK_INIT_ERROR			"录音库初始化失败"		
#define ERROR_NET_TALK_NOT_INIT				"录音库未经初始化"			
#define ERROR_NET_TALK_SENDDATA_ERROR		"发送音频数据出错"		
#define ERROR_NET_NO_TALK_CHANNEL			"未发现语音通道"		
#define ERROR_NET_NO_AUDIO					"该通道未打开音频"										
#define ERROR_NET_REAL_ALREADY_SAVING		"实时数据已经处于保存状态"		
#define ERROR_NET_NOT_SAVING				"未保存实时数据"		
#define ERROR_NET_OPEN_FILE_ERROR			"打开文件出错"		
#define ERROR_NET_PTZ_SET_TIMER_ERROR		"启动云台控制定时器失败"		
#define ERROR_NET_RETURN_DATA_ERROR			"对返回数据的校验出错"		
#define ERROR_NET_INSUFFICIENT_BUFFER		"没有足够的缓存"		
#define ERROR_NET_NOT_SUPPORTED				"当前SDK未支持该功能"		
#define ERROR_NET_NO_RECORD_FOUND			"查询不到录象"
#define ERROR_NET_LOGIN_ERROR_PASSWORD		"密码不正确"		
#define ERROR_NET_LOGIN_ERROR_USER			"帐户不存在"		
#define ERROR_NET_LOGIN_ERROR_TIMEOUT		"等待登录返回超时"		
#define ERROR_NET_LOGIN_ERROR_RELOGGIN		"帐号已登录"		
#define ERROR_NET_LOGIN_ERROR_LOCKED		"帐号已被锁定"		
#define ERROR_NET_LOGIN_ERROR_BLOCKLIST		"帐号已被列为禁止名单"		
#define ERROR_NET_LOGIN_ERROR_BUSY			"资源不足，系统忙"		
#define ERROR_NET_LOGIN_ERROR_CONNECT		"连接主机失败"		
#define ERROR_NET_LOGIN_ERROR_NETWORK		"网络连接失败"										
#define ERROR_NET_RENDER_SOUND_ON_ERROR		"Render库打开音频出错"		
#define ERROR_NET_RENDER_SOUND_OFF_ERROR	"Render库关闭音频出错"		
#define ERROR_NET_RENDER_SET_VOLUME_ERROR	"Render库控制音量出错"		
#define ERROR_NET_RENDER_ADJUST_ERROR		"Render库设置画面参数出错"		
#define ERROR_NET_RENDER_PAUSE_ERROR		"Render库暂停播放出错"		
#define ERROR_NET_RENDER_SNAP_ERROR			"Render库抓图出错"		
#define ERROR_NET_RENDER_STEP_ERROR			"Render库步进出错"		
#define ERROR_NET_RENDER_FRAMERATE_ERROR	"Render库设置帧率出错"		
#define ERROR_NET_CONFIG_DEVBUSY			"暂时无法设置"		
#define ERROR_NET_CONFIG_DATAILLEGAL		"配置数据不合法"									
#define ERROR_NET_NO_INIT					"CLientSDK未经初始化"		
#define ERROR_NET_DOWNLOAD_END				"下载已结束"		

#define NAME_MENU_FULLSCREEN				"全屏显示"
#define NAME_MENU_MULTISCREEN				"多屏显示"
#define NAME_MENU_AUTOADJUST				"自动调整"

#define MSG_ALARMCFG_ALARMIN				"报警输入"
#define MSG_ALARMCFG_MOTION					"动态检测"
#define MSG_ALARMCFG_VIDEOLOST				"视频丢失"
#define MSG_ALARMCFG_BLINE					"视频遮挡"
#define MSG_ALARMCFG_DISK					"硬盘报警"

#define MSG_ALARMCFG_WHOLEWEEK				"整个星期"
#define MSG_ALARMCFG_MONDAY					"星期一"
#define MSG_ALARMCFG_TUESDAY				"星期二"
#define MSG_ALARMCFG_WEDNESDAY				"星期三"
#define MSG_ALARMCFG_THURSDAY				"星期四"
#define MSG_ALARMCFG_FRIDAY					"星期五"
#define MSG_ALARMCFG_SATURDAY				"星期六"
#define MSG_ALARMCFG_SUNDAY					"星期天"

#define NAME_ALARMCFG_NOPEN					"常开"
#define NAME_ALARMCFG_NCLOSE				"常闭"

#define NAME_NETCFG_NET1					"10MBase-T"
#define NAME_NETCFG_NET2					"10MBase-T全双工"
#define NAME_NETCFG_NET3					"100MBase-TX"
#define NAME_NETCFG_NET4					"100M全双工"
#define NAME_NETCFG_NET5					"10M/100M自适应"
#define NAME_NETCFG_REMOTE_ALARM			"报警服务器"
#define NAME_NETCFG_REMOTE_LOG				"日志服务器"
#define NAME_NETCFG_REMOTE_SMTP				"SMTP服务器"
#define NAME_NETCFG_REMOTE_MULTICAST		"多播组"
#define NAME_NETCFG_REMOTE_NFS				"NFS服务器"
#define NAME_NETCFG_REMOTE_FTP				"Ftp服务器"
#define NAME_NETCFG_REMOTE_PPPOE			"PPPoE服务器"
#define NAME_NETCFG_REMOTE_DDNS				"DDNS服务器"
#define NAME_NETCFG_REMOTE_DNS				"DNS服务器"

#define NAME_NETCFG_PPPOE_IP				"注册IP"
#define NAME_NETCFG_DDNS_HOSTNAME			"DDNS主机名"

#define MSG_CONFIG_SUCCESS					"保存成功"

#define NAME_STREAM_MAIN					"主码流"
#define NAME_STREAM_SUB1					"从码流_1"
#define NAME_STREAM_SUB2					"从码流_2"
#define NAME_STREAM_SUB3					"从码流_3"

#endif

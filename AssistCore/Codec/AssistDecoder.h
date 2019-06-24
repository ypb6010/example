#pragma once
#include "../Core/Codec/DecoderBase.h"
/**
 * 类名称：	AssistDecoder
 * 类简介：	本类中由各个客户端的转码具体实现
 * ******	网络序列化字符串 ==>> 反序列化==>> 二进制实体结构 ==>> 本地序列化（boost序列化）
 * ******	序列化和反序列化后，将最终的本地序列化字符串放入消息队列
 */
class AssistDecoder:public DecoderBase
{
public:
	AssistDecoder();
	virtual ~AssistDecoder();
	event_handler decode_diagnosis(std::string const& strBody);	

	event_handler decode_diagnosis_info(std::string const& strBody);

	event_handler decode_diagnosis_list(std::string const& strBody);

	event_handler decode_next(std::string const& strBody);

	event_handler decode_response_call(std::string const& strBody);

	event_handler decode_sure_pass_push(std::string const& strBody);

	event_handler decode_pause_push(std::string const& strBody);

	event_handler decode_leave(std::string const& strBody);

	event_handler decode_leave_recover(std::string const& strBody);

	event_handler decode_complte_push(std::string const& strBody);

	event_handler decode_spare(std::string const& strBody);

	event_handler decode_doctro_complete(std::string const& strBody);

	event_handler decode_history(std::string const& strBody);
};


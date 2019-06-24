#pragma once


class ExpertsEncoder :public EncoderBase
{
public:
	ExpertsEncoder();
	~ExpertsEncoder();

	msg_handler encode_start_service(std::string const& strMsg);
	msg_handler encode_call_next(std::string const& strMsg);
	msg_handler encode_heartbeat(std::string const& strMsg);
	msg_handler encode_pause(std::string const& strMsg);
	msg_handler encode_sure_pass(std::string const& strMsg);
	msg_handler encode_stop(std::string const& strMsg);
	msg_handler encode_leave(std::string const& strMsg);
	msg_handler encode_leave_recover(std::string const& strMsg);
	msg_handler encode_complete(std::string const& strMsg);
	msg_handler encode_history(std::string const& strMsg);
	msg_handler encode_add_history(std::string const& strMsg);
};


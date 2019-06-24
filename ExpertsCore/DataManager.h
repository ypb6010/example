#pragma once

class EXPERTSCORE_EXPORT  DataManager
{
public:
	DataManager();
	~DataManager();
	void setDoctorInfo(DoctorInfoResponse const& doctorInfo);
	DoctorInfoResponse doctorInfo() const;

	void setCurrentRegID(std::string register_id);
	std::string currentRegID() const;

	std::string room() const;
	void setRoom(std::string room);

	void setNextID(std::string patient_id);
	std::string nextID() const;

	void addWaitElem(ListProperty const& elem);
	void addWaitElems(stateList const& elems);
	void removeWaitFromID(std::string const& patient_id);


	void addPassElem(ListProperty const& elem);
	void addPassElems(stateList const& elems);
	void removePassFromID(std::string const& patient_id);

	void addPauseElem(ListProperty const& elems);
	void addPauseElems(stateList const& elems);
	void removePauseFromID(std::string const& patient_id);

	void addCompleteElem(ListProperty const& elem);
	void addCompleteElems(stateList const& elems);
	void removeCompleteFromID(std::string const& patient_id);

	std::string currentAssistID() const;
	void setCurrentAssistID(std::string assist_id);

	PatientBaseInfo currentPatInfo() const;
	void setCurrentPatInfo(PatientBaseInfo currentPat);

	DiagnosisInfoResponse currentAssist() const;
	void setCurrentAssist(DiagnosisInfoResponse assistInfo);

	std::string currentPatID() const;
	void setCurrentPatID(std::string patient_id);

	std::string currentPatName() const;
	void setCurrentPatName(std::string patient_name);

	std::string setNexPatID() const;
	void nexPatID(std::string patient_id);

	std::string nextPatName() const;
	void setNextPatName(std::string patient_name);

	std::optional<IllHistoryResponse> currentPatHistory();
	void setCurrentHistory(IllHistoryResponse const& histroy);

	void resetCurrent();
	void resetAssist();
private:
	void addElem(stateList& list, ListProperty const& elem);
	void addElems(stateList& list, stateList const& elems);
	void removeElemFromID(stateList& list, std::string const& patient_id);
private:
	std::string								m_currentAssistID;
	std::string								m_room;
	std::string								m_currentPatID;
	std::string								m_currentPatName;
	std::string								m_nexPatID;
	std::string								m_nextPatName;
	std::string								m_currentRegID;
	PatientBaseInfo							m_currentPatInfo;
	DiagnosisInfoResponse					m_currentAssist;
	DoctorInfoResponse						m_dotorInfo;
	std::optional<IllHistoryResponse>		m_currentHistory;
	stateList								m_waitList;
	stateList								m_passList;
	stateList								m_pauseList;
	stateList								m_completeList;
public:
};


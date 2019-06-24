#pragma once
#include "assistcore_global.h"

class ASSISTCORE_EXPORT  DataManager
{
	typedef boost::mutex				mutex_type;
public:
	DataManager();
	~DataManager();
	void setDiagnosisInfo(DiagnosisInfoResponse const& diagnoisis);
	DiagnosisInfoResponse diagnosisInfo() const;

	void setCurrentPatID(std::string const& person);
	std::string currentPatID() const;

	void setCurrentPatName(std::string const& patient_name);
	std::string currentPatName()const;

	void setNextPatID(std::string const& person);
	std::string nextPatID() const;

	void setNextName(std::string const& patient_name);
	std::string nextName() const;
	
	void addWaitElem(ListProperty const& elem);
	void addWaitElems(stateList const& elems);

	void addPassElem(ListProperty const& elem);
	void addPassElems(stateList const& elems);

	void addPauseElem(ListProperty const& elems);
	void addPauseElems(stateList const& elems);

	void addCompleteElem(ListProperty const& elem);
	void addCompleteElems(stateList const& elems);

	std::string currentDoctorID() const;
	void setCurrentDoctorID(std::string doctorID);

	std::string currentRegID() const;
	void setCurrentRegID(std::string registerID);

	std::string room() const;
	void setRoom(std::string currentRoom);

	PatientBaseInfo currentPatInfo() const;
	void setCurrentPatInfo(PatientBaseInfo currentPatient);

	DoctorInfoResponse currentDoctor() const;
	void setCurrentDoctor(DoctorInfoResponse currentDoc);

	std::optional<IllHistoryResponse> currentPatHistory();
	void setCurrentHistory(IllHistoryResponse const& histroy);

	void resetCurrent();
	void resetNext();

	void resetAllList();

	ListProperty findPauseFromPatientID(std::string const&& patient_id);
	ListProperty findPassFromPatientID(std::string const&& patient_id);
private:
	void addElem(stateList& list, ListProperty const& elem);
	void addElems(stateList& list, stateList const& elems);
	ListProperty findForPatientID(stateList& list, std::string const&& patient_id);
private:
	mutex_type								m_mu;
	std::string								m_currentDoctorID;
	std::string								m_currentRegID;
	std::string								m_room;
	std::string								m_currentPatID;
	std::string								m_currentPatName;
	std::string								m_nextPatID;
	std::string								m_nextPatName;
	PatientBaseInfo							m_currentPatInfo;
	DoctorInfoResponse						m_currentDoctor;
	DiagnosisInfoResponse					m_diagnosis;
	std::optional<IllHistoryResponse>		m_currentHistory;
	stateList								m_waitList;
	stateList								m_passList;
	stateList								m_pauseList;
	stateList								m_completeList;
};


#include "stable.h"
#include "DataManager.h"


DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

void DataManager::setDoctorInfo(DoctorInfoResponse const& doctorInfo)
{
	m_dotorInfo = doctorInfo;
}

DoctorInfoResponse DataManager::doctorInfo() const
{
	return m_dotorInfo;
}

void DataManager::setCurrentRegID(std::string register_id)
{
	m_currentRegID = register_id;
}

std::string DataManager::currentRegID() const
{
	return m_currentRegID;
}


std::string DataManager::room() const
{
	return m_room;
}

void DataManager::setRoom(std::string room)
{
	m_room = room;
}



void DataManager::setNextID(std::string patient_id)
{
	nexPatID(patient_id);
}

std::string DataManager::nextID() const
{
	return setNexPatID();
}

void DataManager::addWaitElem(ListProperty const& elem)
{
	addElem(m_waitList, elem);
}

void DataManager::addWaitElems(stateList const& elems)
{
	addElems(m_waitList, elems);
}

void DataManager::addPassElem(ListProperty const& elem)
{
	addElem(m_passList, elem);
}

void DataManager::addPassElems(stateList const& elems)
{
	addElems(m_passList, elems);
}

void DataManager::removePassFromID(std::string const& patient_id)
{
	removeElemFromID(m_passList, patient_id);
}

void DataManager::removePauseFromID(std::string const& patient_id)
{
	removeElemFromID(m_pauseList, patient_id);
}

void DataManager::addPauseElem(ListProperty const& elem)
{
	addElem(m_pauseList, elem);
}

void DataManager::addPauseElems(stateList const& elems)
{
	addElems(m_pauseList, elems);
}

void DataManager::addCompleteElem(ListProperty const& elem)
{
	addElem(m_completeList, elem);
}

void DataManager::addCompleteElems(stateList const& elems)
{
	addElems(m_completeList, elems);
}

void DataManager::removeCompleteFromID(std::string const& patient_id)
{
	removeElemFromID(m_completeList, patient_id);
}

std::string DataManager::currentAssistID() const
{
	return m_currentAssistID;
}

void DataManager::setCurrentAssistID(std::string assist_id)
{
	m_currentAssistID = assist_id;
}

PatientBaseInfo DataManager::currentPatInfo() const
{
	return m_currentPatInfo;
}

void DataManager::setCurrentPatInfo(PatientBaseInfo currentPat)
{
	m_currentPatInfo = currentPat;
}

DiagnosisInfoResponse DataManager::currentAssist() const
{
	return m_currentAssist;
}

void DataManager::setCurrentAssist(DiagnosisInfoResponse assistInfo)
{
	m_currentAssist = assistInfo;
}

std::string DataManager::currentPatID() const
{
	return m_currentPatID;
}

void DataManager::setCurrentPatID(std::string patient_id)
{
	m_currentPatID = patient_id;
}

std::string DataManager::currentPatName() const
{
	return m_currentPatName;
}

void DataManager::setCurrentPatName(std::string patient_name)
{
	m_currentPatName = patient_name;
}

std::string DataManager::setNexPatID() const
{
	return m_nexPatID;
}

void DataManager::nexPatID(std::string patient_id)
{
	m_nexPatID = patient_id;
}

std::string DataManager::nextPatName() const
{
	return m_nextPatName;
}

void DataManager::setNextPatName(std::string patient_name)
{
	m_nextPatName = patient_name;
}

std::optional<IllHistoryResponse> DataManager::currentPatHistory()
{
	return m_currentHistory;
}

void DataManager::setCurrentHistory(IllHistoryResponse const& histroy)
{
	m_currentHistory = histroy;
}

void DataManager::resetCurrent()
{
	m_currentPatInfo = PatientBaseInfo();
	m_currentAssist = DiagnosisInfoResponse();
	m_currentHistory = std::make_optional(IllHistoryResponse());
	m_currentRegID = std::string();
	//m_room = std::string();
	m_currentPatID = std::string();
	m_currentPatName = std::string();
}

void DataManager::resetAssist()
{
	m_currentAssist = DiagnosisInfoResponse();
}

void DataManager::addElem(stateList& list, ListProperty const& elem)
{
	list.push_back(elem);
}

void DataManager::addElems(stateList& list, stateList const& elems)
{
	list.insert(list.end(), elems.begin(), elems.end());
}

void DataManager::removeElemFromID(stateList& list, std::string const& patient_id)
{
	auto it = std::find_if(list.begin(), list.end(), [&](ListProperty& item)->bool {
		return item.patient_id == patient_id;
	});
	if (it != m_waitList.end())
	{
		list.erase(it);
	}
}

void DataManager::removeWaitFromID(std::string const& patient_id)
{
	removeElemFromID(m_waitList, patient_id);
}

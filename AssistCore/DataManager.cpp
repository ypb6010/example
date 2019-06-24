#include "stable.h"
#include "DataManager.h"


DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

void DataManager::setDiagnosisInfo(DiagnosisInfoResponse const& strequestrMsg)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_diagnosis = strequestrMsg;
}

DiagnosisInfoResponse DataManager::diagnosisInfo() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_diagnosis;
}

void DataManager::setCurrentPatID(std::string const& patient_id)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentPatID = patient_id;
}


std::string DataManager::currentPatID() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_currentPatID;
}

void DataManager::setCurrentPatName(std::string const& patient_name)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentPatName = patient_name;
}

std::string DataManager::currentPatName() const
{
	return m_currentPatName;
}

void DataManager::setNextPatID(std::string const& nextID)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_nextPatID = nextID;
}

std::string DataManager::nextPatID() const
{
	return m_nextPatID;
}

void DataManager::setNextName(std::string const& patient_name)
{
	m_nextPatName = patient_name;
}

std::string DataManager::nextName() const
{
	return m_nextPatName;
}

void DataManager::addWaitElem(ListProperty const& elem)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElem(m_waitList, elem);
}

void DataManager::addWaitElems(stateList const& elems)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElems(m_waitList, elems);
}

void DataManager::addPassElem(ListProperty const& elem)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElem(m_passList, elem);
}

void DataManager::addPassElems(stateList const& elems)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElems(m_passList, elems);
}

void DataManager::addPauseElem(ListProperty const& elem)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElem(m_pauseList, elem);
}

void DataManager::addPauseElems(stateList const& elems)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElems(m_pauseList, elems);
}

void DataManager::addCompleteElem(ListProperty const& elem)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElem(m_completeList, elem);
}

void DataManager::addCompleteElems(stateList const& elems)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	addElems(m_completeList, elems);
}

std::string DataManager::currentDoctorID() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_currentDoctorID;
}

void DataManager::setCurrentDoctorID(std::string doctorID)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentDoctorID = doctorID;
}

std::string DataManager::currentRegID() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_currentRegID;
}

void DataManager::setCurrentRegID(std::string registerID)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentRegID = registerID;
}

std::string DataManager::room() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_room;
}

void DataManager::setRoom(std::string currentRoom)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_room = currentRoom;
}

PatientBaseInfo DataManager::currentPatInfo() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_currentPatInfo;
}

void DataManager::setCurrentPatInfo(PatientBaseInfo currentPatient)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentPatInfo = currentPatient;
}

DoctorInfoResponse DataManager::currentDoctor() const
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	return m_currentDoctor;
}

void DataManager::setCurrentDoctor(DoctorInfoResponse currentDoc)
{
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentDoctor = currentDoc;
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
	boost::make_unique_lock(const_cast<mutex_type&>(m_mu));
	m_currentDoctor = DoctorInfoResponse();
	m_currentPatInfo = PatientBaseInfo();
	m_currentHistory = std::make_optional(IllHistoryResponse());;
	m_currentDoctorID = std::string();
	m_currentRegID = std::string();
	m_room = std::string();
	m_currentPatID = std::string();
	m_currentPatName = std::string();
}

void DataManager::resetNext()
{
	m_nextPatID = std::string();
	m_nextPatName = std::string();
}

void DataManager::resetAllList()
{
	m_waitList.clear();
	m_pauseList.clear();
	m_pauseList.clear();
	m_completeList.clear();
}

ListProperty DataManager::findPauseFromPatientID(std::string const&& patient_id)
{
	return findForPatientID(m_pauseList, std::move(patient_id));
}

ListProperty DataManager::findPassFromPatientID(std::string const&& patient_id)
{
	return findForPatientID(m_passList, std::move(patient_id));
}

void DataManager::addElem(stateList& list, ListProperty const& elem)
{
	list.push_back(elem);
}

void DataManager::addElems(stateList& list, stateList const& elems)
{
	list.insert(list.end(), elems.begin(), elems.end());
}

ListProperty DataManager::findForPatientID(stateList& list, std::string const&& patient_id)
{
	auto it = std::find_if(list.begin(), list.end(), [&](ListProperty const& value)->bool {
		return value.patient_id == patient_id;
	});
	if (it != list.end())
		return *it;
	return ListProperty();
}

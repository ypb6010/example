// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CommandID.proto

#include "stable.h"
#include "CommandID.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace message {
}  // namespace message
void InitDefaults_CommandID_2eproto() {
}

static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_CommandID_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_CommandID_2eproto[6];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_CommandID_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_CommandID_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

static ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptorsTable assign_descriptors_table_CommandID_2eproto = {
  {}, AddDescriptors_CommandID_2eproto, "CommandID.proto", schemas,
  file_default_instances, TableStruct_CommandID_2eproto::offsets,
  file_level_metadata_CommandID_2eproto, 0, file_level_enum_descriptors_CommandID_2eproto, file_level_service_descriptors_CommandID_2eproto,
};

const char descriptor_table_protodef_CommandID_2eproto[] =
  "\n\017CommandID.proto\022\007message*c\n\014CL_Command"
  "ID\022\023\n\017CL_COMMAND_NONE\020\000\022\037\n\032CL_COMMAND_VE"
  "RSION_REQUEST\020\351\007\022\035\n\030CL_COMMAND_LOGIN_REQ"
  "UEST\020\352\007*e\n\014LC_CommandID\022\023\n\017LC_COMMAND_NO"
  "NE\020\000\022 \n\033LC_COMMAND_VERSION_RESPONSE\020\211\'\022\036"
  "\n\031LC_COMMAND_LOGIN_RESPONSE\020\212\'*\207\005\n\023CA_Co"
  "mmandID_Assist\022\035\n\031CA_COMMAND_DIAGNOSIS_N"
  "ONE\020\000\022+\n&CA_COMMAND_DIAGNOSIS_BASE_LIST_"
  "REQUEST\020\271\027\022+\n&CA_COMMAND_DIAGNOSIS_HEART"
  "BEAT_REQUEST\020\272\027\022\'\n\"CA_COMMAND_DIAGNOSIS_"
  "BEGIN_REQUEST\020\273\027\0221\n,CA_COMMAND_DIAGNOSIS"
  "_PASSWORD_MODIFY_REQUEST\020\274\027\022/\n*CA_COMMAN"
  "D_DIAGNOSIS_AVATAR_MODIFY_REQUEST\020\275\027\022/\n*"
  "CA_COMMAND_DIAGNOSIS_CALL_RESPONSE_REQUE"
  "ST\020\276\027\022/\n*CA_COMMAND_DIAGNOSIS_PAUSE_RECO"
  "VER_REQUEST\020\277\027\022.\n)CA_COMMAND_DIAGNOSIS_P"
  "ASS_RECOVER_REQUEST\020\300\027\022\'\n\"CA_COMMAND_DIA"
  "GNOSIS_LEAVE_REQUEST\020\301\027\022/\n*CA_COMMAND_DI"
  "AGNOSIS_LEAVE_RECOVER_REQUEST\020\302\027\022*\n%CA_C"
  "OMMAND_DIAGNOSIS_COMPLETE_REQUEST\020\303\027\022\'\n\""
  "CA_COMMAND_DIAGNOSIS_SPARE_REQUEST\020\304\027\022)\n"
  "$CA_COMMAND_DIAGNOSIS_HISTORY_REQUEST\020\305\027"
  "*\365\004\n\024CA_CommandID_Experts\022\032\n\026CA_COMMAND_"
  "DOCTOR_NONE\020\000\022(\n#CA_COMMAND_DOCTOR_BASE_"
  "LIST_REQUEST\020\241\037\022(\n#CA_COMMAND_DOCTOR_HEA"
  "RTBEAT_REQUEST\020\242\037\022$\n\037CA_COMMAND_DOCTOR_B"
  "EGIN_REQUEST\020\243\037\022.\n)CA_COMMAND_DOCTOR_PAS"
  "SWORD_MODIFY_REQUEST\020\244\037\022,\n\'CA_COMMAND_DO"
  "CTOR_AVATAR_MODIFY_REQUEST\020\245\037\022#\n\036CA_COMM"
  "AND_DOCTOR_CALL_REQUEST\020\246\037\022(\n#CA_COMMAND"
  "_DOCTOR_SURE_PASS_REQUEST\020\247\037\022#\n\036CA_COMMA"
  "ND_DOCTOR_STOP_REQUEST\020\250\037\022$\n\037CA_COMMAND_"
  "DOCTOR_PAUSE_REQUEST\020\251\037\022$\n\037CA_COMMAND_DO"
  "CTOR_LEAVE_REQUEST\020\252\037\022,\n\'CA_COMMAND_DOCT"
  "OR_LEAVE_RECOVER_REQUEST\020\253\037\022\'\n\"CA_COMMAN"
  "D_DOCTOR_COMPLETE_REQUEST\020\254\037\022&\n!CA_COMMA"
  "ND_DOCTOR_HISTORY_REQUEST\020\255\037\022*\n%CA_COMMA"
  "ND_DOCTOR_HISTORY_ADD_REQUEST\020\256\037*\326\006\n\023AC_"
  "CommandID_Assist\022\035\n\031AC_COMMAND_NONE_DIAG"
  "NOSIS\020\000\022\'\n\"AC_COMMAND_DIAGNOSIS_BASE_RES"
  "PONSE\020\3316\022,\n\'AC_COMMAND_DIAGNOSIS_HEARTBE"
  "AT_RESPONSE\020\3326\022(\n#AC_COMMAND_DIAGNOSIS_B"
  "EGIN_RESPONSE\020\3336\0222\n-AC_COMMAND_DIAGNOSIS"
  "_PASSWORD_MODIFY_RESPONSE\020\3346\0220\n+AC_COMMA"
  "ND_DIAGNOSIS_AVATAR_MODIFY_RESPONSE\020\3356\022*"
  "\n%AC_COMMAND_DIAGNOSIS_ACCEPT_CALL_PUSH\020"
  "\3366\0220\n+AC_COMMAND_DIAGNOSIS_RESPONSE_CALL"
  "_RESPONSE\020\3376\022$\n\037AC_COMMAND_DIAGNOSIS_PAU"
  "SE_PUSH\020\3406\0220\n+AC_COMMAND_DIAGNOSIS_PAUSE"
  "_RECOVER_RESPONSE\020\3416\022/\n*AC_COMMAND_DIAGN"
  "OSIS_PASS_RECOVER_RESPONSE\020\3426\022#\n\036AC_COMM"
  "AND_DIAGNOSIS_LIST_PUSH\020\3436\022%\n AC_COMMAND"
  "_DOCTOR_SURE_PASS_PUSH\020\3446\022(\n#AC_COMMAND_"
  "DIAGNOSIS_LEAVE_RESPONSE\020\3456\0220\n+AC_COMMAN"
  "D_DIAGNOSIS_LEAVE_RECOVER_RESPONSE\020\3466\022+\n"
  "&AC_COMMAND_DIAGNOSIS_COMPLETE_RESPONSE\020"
  "\3476\022(\n#AC_COMMAND_DIAGNOSIS_SPARE_RESPONS"
  "E\020\3506\022\'\n\"AC_COMMAND_DIAGNOSIS_COMPLETE_PU"
  "SH\020\3516\022*\n%AC_COMMAND_DIAGNOSIS_HISTORY_RE"
  "SPONSE\020\3526*\365\005\n\024AC_CommandID_Experts\022\032\n\026AC"
  "_COMMAND_DOCTOR_NONE\020\000\022$\n\037AC_COMMAND_DOC"
  "TOR_BASE_RESPONSE\020\301>\022)\n$AC_COMMAND_DOCTO"
  "R_HEARTBEAT_RESPONSE\020\302>\022%\n AC_COMMAND_DO"
  "CTOR_BEGIN_RESPONSE\020\303>\022$\n\037AC_COMMAND_DOC"
  "TOR_CALL_RESPONSE\020\304>\022.\n)AC_COMMAND_DOCTO"
  "R_ACCEPT_CALL_RESULT_PUSH\020\305>\022)\n$AC_COMMA"
  "ND_DOCTOR_SURE_PASS_RESPONSE\020\306>\022$\n\037AC_CO"
  "MMAND_DOCTOR_STOP_RESPONSE\020\307>\022%\n AC_COMM"
  "AND_DOCTOR_PAUSE_RESPONSE\020\310>\022/\n*AC_COMMA"
  "ND_DOCTOR_PASSWORD_MODIFY_RESPONSE\020\311>\022-\n"
  "(AC_COMMAND_DOCTOR_AVATAR_MODIFY_RESPONS"
  "E\020\312>\022 \n\033AC_COMMAND_DOCTOR_LIST_PUSH\020\313>\022#"
  "\n\036AC_COMMAND_DOCTOR_ROOM_ID_PUSH\020\314>\022%\n A"
  "C_COMMAND_DOCTOR_LEAVE_RESPONSE\020\315>\022-\n(AC"
  "_COMMAND_DOCTOR_LEAVE_RECOVER_RESPONSE\020\316"
  ">\022(\n#AC_COMMAND_DOCTOR_COMPLETE_RESPONSE"
  "\020\317>\022\'\n\"AC_COMMAND_DOCTOR_HISTORY_RESPONS"
  "E\020\320>\022+\n&AC_COMMAND_DOCTOR_HISTORY_ADD_RE"
  "SPONSE\020\321>b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CommandID_2eproto = {
  false, InitDefaults_CommandID_2eproto, 
  descriptor_table_protodef_CommandID_2eproto,
  "CommandID.proto", &assign_descriptors_table_CommandID_2eproto, 3137,
};

void AddDescriptors_CommandID_2eproto() {
  static constexpr ::PROTOBUF_NAMESPACE_ID::internal::InitFunc deps[1] =
  {
  };
 ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_CommandID_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_CommandID_2eproto = []() { AddDescriptors_CommandID_2eproto(); return true; }();
namespace message {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CL_CommandID_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[0];
}
bool CL_CommandID_IsValid(int value) {
  switch (value) {
    case 0:
    case 1001:
    case 1002:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* LC_CommandID_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[1];
}
bool LC_CommandID_IsValid(int value) {
  switch (value) {
    case 0:
    case 5001:
    case 5002:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CA_CommandID_Assist_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[2];
}
bool CA_CommandID_Assist_IsValid(int value) {
  switch (value) {
    case 0:
    case 3001:
    case 3002:
    case 3003:
    case 3004:
    case 3005:
    case 3006:
    case 3007:
    case 3008:
    case 3009:
    case 3010:
    case 3011:
    case 3012:
    case 3013:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CA_CommandID_Experts_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[3];
}
bool CA_CommandID_Experts_IsValid(int value) {
  switch (value) {
    case 0:
    case 4001:
    case 4002:
    case 4003:
    case 4004:
    case 4005:
    case 4006:
    case 4007:
    case 4008:
    case 4009:
    case 4010:
    case 4011:
    case 4012:
    case 4013:
    case 4014:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AC_CommandID_Assist_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[4];
}
bool AC_CommandID_Assist_IsValid(int value) {
  switch (value) {
    case 0:
    case 7001:
    case 7002:
    case 7003:
    case 7004:
    case 7005:
    case 7006:
    case 7007:
    case 7008:
    case 7009:
    case 7010:
    case 7011:
    case 7012:
    case 7013:
    case 7014:
    case 7015:
    case 7016:
    case 7017:
    case 7018:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AC_CommandID_Experts_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&assign_descriptors_table_CommandID_2eproto);
  return file_level_enum_descriptors_CommandID_2eproto[5];
}
bool AC_CommandID_Experts_IsValid(int value) {
  switch (value) {
    case 0:
    case 8001:
    case 8002:
    case 8003:
    case 8004:
    case 8005:
    case 8006:
    case 8007:
    case 8008:
    case 8009:
    case 8010:
    case 8011:
    case 8012:
    case 8013:
    case 8014:
    case 8015:
    case 8016:
    case 8017:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace message
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
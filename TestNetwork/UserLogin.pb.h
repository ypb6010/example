// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserLogin.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_UserLogin_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_UserLogin_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_UserLogin_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_UserLogin_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
void AddDescriptors_UserLogin_2eproto();
namespace message {
class UserLoginRequest;
class UserLoginRequestDefaultTypeInternal;
extern UserLoginRequestDefaultTypeInternal _UserLoginRequest_default_instance_;
class UserLoginResponse;
class UserLoginResponseDefaultTypeInternal;
extern UserLoginResponseDefaultTypeInternal _UserLoginResponse_default_instance_;
}  // namespace message
PROTOBUF_NAMESPACE_OPEN
template<> ::message::UserLoginRequest* Arena::CreateMaybeMessage<::message::UserLoginRequest>(Arena*);
template<> ::message::UserLoginResponse* Arena::CreateMaybeMessage<::message::UserLoginResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace message {

// ===================================================================

class UserLoginRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:message.UserLoginRequest) */ {
 public:
  UserLoginRequest();
  virtual ~UserLoginRequest();

  UserLoginRequest(const UserLoginRequest& from);
  UserLoginRequest(UserLoginRequest&& from) noexcept
    : UserLoginRequest() {
    *this = ::std::move(from);
  }

  inline UserLoginRequest& operator=(const UserLoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserLoginRequest& operator=(UserLoginRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const UserLoginRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserLoginRequest* internal_default_instance() {
    return reinterpret_cast<const UserLoginRequest*>(
               &_UserLoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(UserLoginRequest* other);
  friend void swap(UserLoginRequest& a, UserLoginRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UserLoginRequest* New() const final {
    return CreateMaybeMessage<UserLoginRequest>(nullptr);
  }

  UserLoginRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UserLoginRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const UserLoginRequest& from);
  void MergeFrom(const UserLoginRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(UserLoginRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "message.UserLoginRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string account = 2;
  void clear_account();
  static const int kAccountFieldNumber = 2;
  const std::string& account() const;
  void set_account(const std::string& value);
  void set_account(std::string&& value);
  void set_account(const char* value);
  void set_account(const char* value, size_t size);
  std::string* mutable_account();
  std::string* release_account();
  void set_allocated_account(std::string* account);

  // string password = 3;
  void clear_password();
  static const int kPasswordFieldNumber = 3;
  const std::string& password() const;
  void set_password(const std::string& value);
  void set_password(std::string&& value);
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  std::string* mutable_password();
  std::string* release_password();
  void set_allocated_password(std::string* password);

  // string public_key = 4;
  void clear_public_key();
  static const int kPublicKeyFieldNumber = 4;
  const std::string& public_key() const;
  void set_public_key(const std::string& value);
  void set_public_key(std::string&& value);
  void set_public_key(const char* value);
  void set_public_key(const char* value, size_t size);
  std::string* mutable_public_key();
  std::string* release_public_key();
  void set_allocated_public_key(std::string* public_key);

  // int32 user_type = 1;
  void clear_user_type();
  static const int kUserTypeFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::int32 user_type() const;
  void set_user_type(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:message.UserLoginRequest)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr account_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr public_key_;
  ::PROTOBUF_NAMESPACE_ID::int32 user_type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_UserLogin_2eproto;
};
// -------------------------------------------------------------------

class UserLoginResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:message.UserLoginResponse) */ {
 public:
  UserLoginResponse();
  virtual ~UserLoginResponse();

  UserLoginResponse(const UserLoginResponse& from);
  UserLoginResponse(UserLoginResponse&& from) noexcept
    : UserLoginResponse() {
    *this = ::std::move(from);
  }

  inline UserLoginResponse& operator=(const UserLoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserLoginResponse& operator=(UserLoginResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const UserLoginResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserLoginResponse* internal_default_instance() {
    return reinterpret_cast<const UserLoginResponse*>(
               &_UserLoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(UserLoginResponse* other);
  friend void swap(UserLoginResponse& a, UserLoginResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UserLoginResponse* New() const final {
    return CreateMaybeMessage<UserLoginResponse>(nullptr);
  }

  UserLoginResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UserLoginResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const UserLoginResponse& from);
  void MergeFrom(const UserLoginResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(UserLoginResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "message.UserLoginResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string user_name = 5;
  int user_name_size() const;
  void clear_user_name();
  static const int kUserNameFieldNumber = 5;
  const std::string& user_name(int index) const;
  std::string* mutable_user_name(int index);
  void set_user_name(int index, const std::string& value);
  void set_user_name(int index, std::string&& value);
  void set_user_name(int index, const char* value);
  void set_user_name(int index, const char* value, size_t size);
  std::string* add_user_name();
  void add_user_name(const std::string& value);
  void add_user_name(std::string&& value);
  void add_user_name(const char* value);
  void add_user_name(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& user_name() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_user_name();

  // string nonce = 1;
  void clear_nonce();
  static const int kNonceFieldNumber = 1;
  const std::string& nonce() const;
  void set_nonce(const std::string& value);
  void set_nonce(std::string&& value);
  void set_nonce(const char* value);
  void set_nonce(const char* value, size_t size);
  std::string* mutable_nonce();
  std::string* release_nonce();
  void set_allocated_nonce(std::string* nonce);

  // string server_uuid = 2;
  void clear_server_uuid();
  static const int kServerUuidFieldNumber = 2;
  const std::string& server_uuid() const;
  void set_server_uuid(const std::string& value);
  void set_server_uuid(std::string&& value);
  void set_server_uuid(const char* value);
  void set_server_uuid(const char* value, size_t size);
  std::string* mutable_server_uuid();
  std::string* release_server_uuid();
  void set_allocated_server_uuid(std::string* server_uuid);

  // string server_address = 3;
  void clear_server_address();
  static const int kServerAddressFieldNumber = 3;
  const std::string& server_address() const;
  void set_server_address(const std::string& value);
  void set_server_address(std::string&& value);
  void set_server_address(const char* value);
  void set_server_address(const char* value, size_t size);
  std::string* mutable_server_address();
  std::string* release_server_address();
  void set_allocated_server_address(std::string* server_address);

  // string user_uuid = 4;
  void clear_user_uuid();
  static const int kUserUuidFieldNumber = 4;
  const std::string& user_uuid() const;
  void set_user_uuid(const std::string& value);
  void set_user_uuid(std::string&& value);
  void set_user_uuid(const char* value);
  void set_user_uuid(const char* value, size_t size);
  std::string* mutable_user_uuid();
  std::string* release_user_uuid();
  void set_allocated_user_uuid(std::string* user_uuid);

  // @@protoc_insertion_point(class_scope:message.UserLoginResponse)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> user_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nonce_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr server_uuid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr server_address_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr user_uuid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_UserLogin_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserLoginRequest

// int32 user_type = 1;
inline void UserLoginRequest::clear_user_type() {
  user_type_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 UserLoginRequest::user_type() const {
  // @@protoc_insertion_point(field_get:message.UserLoginRequest.user_type)
  return user_type_;
}
inline void UserLoginRequest::set_user_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  user_type_ = value;
  // @@protoc_insertion_point(field_set:message.UserLoginRequest.user_type)
}

// string account = 2;
inline void UserLoginRequest::clear_account() {
  account_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginRequest::account() const {
  // @@protoc_insertion_point(field_get:message.UserLoginRequest.account)
  return account_.GetNoArena();
}
inline void UserLoginRequest::set_account(const std::string& value) {
  
  account_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginRequest.account)
}
inline void UserLoginRequest::set_account(std::string&& value) {
  
  account_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginRequest.account)
}
inline void UserLoginRequest::set_account(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  account_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginRequest.account)
}
inline void UserLoginRequest::set_account(const char* value, size_t size) {
  
  account_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginRequest.account)
}
inline std::string* UserLoginRequest::mutable_account() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginRequest.account)
  return account_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginRequest::release_account() {
  // @@protoc_insertion_point(field_release:message.UserLoginRequest.account)
  
  return account_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginRequest::set_allocated_account(std::string* account) {
  if (account != nullptr) {
    
  } else {
    
  }
  account_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), account);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginRequest.account)
}

// string password = 3;
inline void UserLoginRequest::clear_password() {
  password_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginRequest::password() const {
  // @@protoc_insertion_point(field_get:message.UserLoginRequest.password)
  return password_.GetNoArena();
}
inline void UserLoginRequest::set_password(const std::string& value) {
  
  password_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginRequest.password)
}
inline void UserLoginRequest::set_password(std::string&& value) {
  
  password_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginRequest.password)
}
inline void UserLoginRequest::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginRequest.password)
}
inline void UserLoginRequest::set_password(const char* value, size_t size) {
  
  password_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginRequest.password)
}
inline std::string* UserLoginRequest::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginRequest.password)
  return password_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginRequest::release_password() {
  // @@protoc_insertion_point(field_release:message.UserLoginRequest.password)
  
  return password_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginRequest::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginRequest.password)
}

// string public_key = 4;
inline void UserLoginRequest::clear_public_key() {
  public_key_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginRequest::public_key() const {
  // @@protoc_insertion_point(field_get:message.UserLoginRequest.public_key)
  return public_key_.GetNoArena();
}
inline void UserLoginRequest::set_public_key(const std::string& value) {
  
  public_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginRequest.public_key)
}
inline void UserLoginRequest::set_public_key(std::string&& value) {
  
  public_key_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginRequest.public_key)
}
inline void UserLoginRequest::set_public_key(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  public_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginRequest.public_key)
}
inline void UserLoginRequest::set_public_key(const char* value, size_t size) {
  
  public_key_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginRequest.public_key)
}
inline std::string* UserLoginRequest::mutable_public_key() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginRequest.public_key)
  return public_key_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginRequest::release_public_key() {
  // @@protoc_insertion_point(field_release:message.UserLoginRequest.public_key)
  
  return public_key_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginRequest::set_allocated_public_key(std::string* public_key) {
  if (public_key != nullptr) {
    
  } else {
    
  }
  public_key_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), public_key);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginRequest.public_key)
}

// -------------------------------------------------------------------

// UserLoginResponse

// string nonce = 1;
inline void UserLoginResponse::clear_nonce() {
  nonce_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginResponse::nonce() const {
  // @@protoc_insertion_point(field_get:message.UserLoginResponse.nonce)
  return nonce_.GetNoArena();
}
inline void UserLoginResponse::set_nonce(const std::string& value) {
  
  nonce_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.nonce)
}
inline void UserLoginResponse::set_nonce(std::string&& value) {
  
  nonce_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginResponse.nonce)
}
inline void UserLoginResponse::set_nonce(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  nonce_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginResponse.nonce)
}
inline void UserLoginResponse::set_nonce(const char* value, size_t size) {
  
  nonce_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginResponse.nonce)
}
inline std::string* UserLoginResponse::mutable_nonce() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginResponse.nonce)
  return nonce_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginResponse::release_nonce() {
  // @@protoc_insertion_point(field_release:message.UserLoginResponse.nonce)
  
  return nonce_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginResponse::set_allocated_nonce(std::string* nonce) {
  if (nonce != nullptr) {
    
  } else {
    
  }
  nonce_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), nonce);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginResponse.nonce)
}

// string server_uuid = 2;
inline void UserLoginResponse::clear_server_uuid() {
  server_uuid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginResponse::server_uuid() const {
  // @@protoc_insertion_point(field_get:message.UserLoginResponse.server_uuid)
  return server_uuid_.GetNoArena();
}
inline void UserLoginResponse::set_server_uuid(const std::string& value) {
  
  server_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.server_uuid)
}
inline void UserLoginResponse::set_server_uuid(std::string&& value) {
  
  server_uuid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginResponse.server_uuid)
}
inline void UserLoginResponse::set_server_uuid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  server_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginResponse.server_uuid)
}
inline void UserLoginResponse::set_server_uuid(const char* value, size_t size) {
  
  server_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginResponse.server_uuid)
}
inline std::string* UserLoginResponse::mutable_server_uuid() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginResponse.server_uuid)
  return server_uuid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginResponse::release_server_uuid() {
  // @@protoc_insertion_point(field_release:message.UserLoginResponse.server_uuid)
  
  return server_uuid_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginResponse::set_allocated_server_uuid(std::string* server_uuid) {
  if (server_uuid != nullptr) {
    
  } else {
    
  }
  server_uuid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), server_uuid);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginResponse.server_uuid)
}

// string server_address = 3;
inline void UserLoginResponse::clear_server_address() {
  server_address_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginResponse::server_address() const {
  // @@protoc_insertion_point(field_get:message.UserLoginResponse.server_address)
  return server_address_.GetNoArena();
}
inline void UserLoginResponse::set_server_address(const std::string& value) {
  
  server_address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.server_address)
}
inline void UserLoginResponse::set_server_address(std::string&& value) {
  
  server_address_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginResponse.server_address)
}
inline void UserLoginResponse::set_server_address(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  server_address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginResponse.server_address)
}
inline void UserLoginResponse::set_server_address(const char* value, size_t size) {
  
  server_address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginResponse.server_address)
}
inline std::string* UserLoginResponse::mutable_server_address() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginResponse.server_address)
  return server_address_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginResponse::release_server_address() {
  // @@protoc_insertion_point(field_release:message.UserLoginResponse.server_address)
  
  return server_address_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginResponse::set_allocated_server_address(std::string* server_address) {
  if (server_address != nullptr) {
    
  } else {
    
  }
  server_address_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), server_address);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginResponse.server_address)
}

// string user_uuid = 4;
inline void UserLoginResponse::clear_user_uuid() {
  user_uuid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserLoginResponse::user_uuid() const {
  // @@protoc_insertion_point(field_get:message.UserLoginResponse.user_uuid)
  return user_uuid_.GetNoArena();
}
inline void UserLoginResponse::set_user_uuid(const std::string& value) {
  
  user_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.user_uuid)
}
inline void UserLoginResponse::set_user_uuid(std::string&& value) {
  
  user_uuid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:message.UserLoginResponse.user_uuid)
}
inline void UserLoginResponse::set_user_uuid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  user_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:message.UserLoginResponse.user_uuid)
}
inline void UserLoginResponse::set_user_uuid(const char* value, size_t size) {
  
  user_uuid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginResponse.user_uuid)
}
inline std::string* UserLoginResponse::mutable_user_uuid() {
  
  // @@protoc_insertion_point(field_mutable:message.UserLoginResponse.user_uuid)
  return user_uuid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserLoginResponse::release_user_uuid() {
  // @@protoc_insertion_point(field_release:message.UserLoginResponse.user_uuid)
  
  return user_uuid_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserLoginResponse::set_allocated_user_uuid(std::string* user_uuid) {
  if (user_uuid != nullptr) {
    
  } else {
    
  }
  user_uuid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), user_uuid);
  // @@protoc_insertion_point(field_set_allocated:message.UserLoginResponse.user_uuid)
}

// repeated string user_name = 5;
inline int UserLoginResponse::user_name_size() const {
  return user_name_.size();
}
inline void UserLoginResponse::clear_user_name() {
  user_name_.Clear();
}
inline const std::string& UserLoginResponse::user_name(int index) const {
  // @@protoc_insertion_point(field_get:message.UserLoginResponse.user_name)
  return user_name_.Get(index);
}
inline std::string* UserLoginResponse::mutable_user_name(int index) {
  // @@protoc_insertion_point(field_mutable:message.UserLoginResponse.user_name)
  return user_name_.Mutable(index);
}
inline void UserLoginResponse::set_user_name(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.user_name)
  user_name_.Mutable(index)->assign(value);
}
inline void UserLoginResponse::set_user_name(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:message.UserLoginResponse.user_name)
  user_name_.Mutable(index)->assign(std::move(value));
}
inline void UserLoginResponse::set_user_name(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  user_name_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:message.UserLoginResponse.user_name)
}
inline void UserLoginResponse::set_user_name(int index, const char* value, size_t size) {
  user_name_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:message.UserLoginResponse.user_name)
}
inline std::string* UserLoginResponse::add_user_name() {
  // @@protoc_insertion_point(field_add_mutable:message.UserLoginResponse.user_name)
  return user_name_.Add();
}
inline void UserLoginResponse::add_user_name(const std::string& value) {
  user_name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:message.UserLoginResponse.user_name)
}
inline void UserLoginResponse::add_user_name(std::string&& value) {
  user_name_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:message.UserLoginResponse.user_name)
}
inline void UserLoginResponse::add_user_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  user_name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:message.UserLoginResponse.user_name)
}
inline void UserLoginResponse::add_user_name(const char* value, size_t size) {
  user_name_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:message.UserLoginResponse.user_name)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
UserLoginResponse::user_name() const {
  // @@protoc_insertion_point(field_list:message.UserLoginResponse.user_name)
  return user_name_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
UserLoginResponse::mutable_user_name() {
  // @@protoc_insertion_point(field_mutable_list:message.UserLoginResponse.user_name)
  return &user_name_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_UserLogin_2eproto

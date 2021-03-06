// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo.proto

#include "echo.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_echo_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ResultCode_echo_2eproto;
namespace echoservice {
class ResultCodeDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ResultCode> _instance;
} _ResultCode_default_instance_;
class EchoRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EchoRequest> _instance;
} _EchoRequest_default_instance_;
class EchoResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<EchoResponse> _instance;
} _EchoResponse_default_instance_;
}  // namespace echoservice
static void InitDefaultsscc_info_EchoRequest_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echoservice::_EchoRequest_default_instance_;
    new (ptr) ::echoservice::EchoRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echoservice::EchoRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_EchoRequest_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_EchoRequest_echo_2eproto}, {}};

static void InitDefaultsscc_info_EchoResponse_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echoservice::_EchoResponse_default_instance_;
    new (ptr) ::echoservice::EchoResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echoservice::EchoResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_EchoResponse_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_EchoResponse_echo_2eproto}, {
      &scc_info_ResultCode_echo_2eproto.base,}};

static void InitDefaultsscc_info_ResultCode_echo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::echoservice::_ResultCode_default_instance_;
    new (ptr) ::echoservice::ResultCode();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::echoservice::ResultCode::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ResultCode_echo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ResultCode_echo_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_echo_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_echo_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* file_level_service_descriptors_echo_2eproto[1];

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_echo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echoservice::ResultCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echoservice::ResultCode, errcode_),
  PROTOBUF_FIELD_OFFSET(::echoservice::ResultCode, errmsg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echoservice::EchoRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echoservice::EchoRequest, text_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::echoservice::EchoResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::echoservice::EchoResponse, result_),
  PROTOBUF_FIELD_OFFSET(::echoservice::EchoResponse, text_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::echoservice::ResultCode)},
  { 7, -1, sizeof(::echoservice::EchoRequest)},
  { 13, -1, sizeof(::echoservice::EchoResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echoservice::_ResultCode_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echoservice::_EchoRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::echoservice::_EchoResponse_default_instance_),
};

const char descriptor_table_protodef_echo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\necho.proto\022\013echoservice\"-\n\nResultCode\022"
  "\017\n\007errcode\030\001 \001(\005\022\016\n\006errmsg\030\002 \001(\014\"\033\n\013Echo"
  "Request\022\014\n\004text\030\001 \001(\014\"E\n\014EchoResponse\022\'\n"
  "\006result\030\001 \001(\0132\027.echoservice.ResultCode\022\014"
  "\n\004text\030\002 \001(\0142M\n\016EchoServiceRpc\022;\n\004Echo\022\030"
  ".echoservice.EchoRequest\032\031.echoservice.E"
  "choResponseB\003\200\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_echo_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_echo_2eproto_sccs[3] = {
  &scc_info_EchoRequest_echo_2eproto.base,
  &scc_info_EchoResponse_echo_2eproto.base,
  &scc_info_ResultCode_echo_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_echo_2eproto_once;
static bool descriptor_table_echo_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_echo_2eproto = {
  &descriptor_table_echo_2eproto_initialized, descriptor_table_protodef_echo_2eproto, "echo.proto", 264,
  &descriptor_table_echo_2eproto_once, descriptor_table_echo_2eproto_sccs, descriptor_table_echo_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_echo_2eproto::offsets,
  file_level_metadata_echo_2eproto, 3, file_level_enum_descriptors_echo_2eproto, file_level_service_descriptors_echo_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_echo_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_echo_2eproto), true);
namespace echoservice {

// ===================================================================

void ResultCode::InitAsDefaultInstance() {
}
class ResultCode::_Internal {
 public:
};

ResultCode::ResultCode()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echoservice.ResultCode)
}
ResultCode::ResultCode(const ResultCode& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_errmsg().empty()) {
    errmsg_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.errmsg_);
  }
  errcode_ = from.errcode_;
  // @@protoc_insertion_point(copy_constructor:echoservice.ResultCode)
}

void ResultCode::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ResultCode_echo_2eproto.base);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  errcode_ = 0;
}

ResultCode::~ResultCode() {
  // @@protoc_insertion_point(destructor:echoservice.ResultCode)
  SharedDtor();
}

void ResultCode::SharedDtor() {
  errmsg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ResultCode::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ResultCode& ResultCode::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ResultCode_echo_2eproto.base);
  return *internal_default_instance();
}


void ResultCode::Clear() {
// @@protoc_insertion_point(message_clear_start:echoservice.ResultCode)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errmsg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  errcode_ = 0;
  _internal_metadata_.Clear();
}

const char* ResultCode::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 errcode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          errcode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_errmsg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ResultCode::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echoservice.ResultCode)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 errcode = 1;
  if (this->errcode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_errcode(), target);
  }

  // bytes errmsg = 2;
  if (this->errmsg().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_errmsg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echoservice.ResultCode)
  return target;
}

size_t ResultCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echoservice.ResultCode)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes errmsg = 2;
  if (this->errmsg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_errmsg());
  }

  // int32 errcode = 1;
  if (this->errcode() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_errcode());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ResultCode::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echoservice.ResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  const ResultCode* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ResultCode>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echoservice.ResultCode)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echoservice.ResultCode)
    MergeFrom(*source);
  }
}

void ResultCode::MergeFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echoservice.ResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.errmsg().size() > 0) {

    errmsg_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.errmsg_);
  }
  if (from.errcode() != 0) {
    _internal_set_errcode(from._internal_errcode());
  }
}

void ResultCode::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echoservice.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ResultCode::CopyFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echoservice.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResultCode::IsInitialized() const {
  return true;
}

void ResultCode::InternalSwap(ResultCode* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  errmsg_.Swap(&other->errmsg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(errcode_, other->errcode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ResultCode::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void EchoRequest::InitAsDefaultInstance() {
}
class EchoRequest::_Internal {
 public:
};

EchoRequest::EchoRequest()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echoservice.EchoRequest)
}
EchoRequest::EchoRequest(const EchoRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_text().empty()) {
    text_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
  // @@protoc_insertion_point(copy_constructor:echoservice.EchoRequest)
}

void EchoRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_EchoRequest_echo_2eproto.base);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

EchoRequest::~EchoRequest() {
  // @@protoc_insertion_point(destructor:echoservice.EchoRequest)
  SharedDtor();
}

void EchoRequest::SharedDtor() {
  text_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EchoRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EchoRequest& EchoRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EchoRequest_echo_2eproto.base);
  return *internal_default_instance();
}


void EchoRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:echoservice.EchoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  text_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* EchoRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes text = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_text();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EchoRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echoservice.EchoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes text = 1;
  if (this->text().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_text(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echoservice.EchoRequest)
  return target;
}

size_t EchoRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echoservice.EchoRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes text = 1;
  if (this->text().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_text());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EchoRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echoservice.EchoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const EchoRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EchoRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echoservice.EchoRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echoservice.EchoRequest)
    MergeFrom(*source);
  }
}

void EchoRequest::MergeFrom(const EchoRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echoservice.EchoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.text().size() > 0) {

    text_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
}

void EchoRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echoservice.EchoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoRequest::CopyFrom(const EchoRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echoservice.EchoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoRequest::IsInitialized() const {
  return true;
}

void EchoRequest::InternalSwap(EchoRequest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  text_.Swap(&other->text_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata EchoRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void EchoResponse::InitAsDefaultInstance() {
  ::echoservice::_EchoResponse_default_instance_._instance.get_mutable()->result_ = const_cast< ::echoservice::ResultCode*>(
      ::echoservice::ResultCode::internal_default_instance());
}
class EchoResponse::_Internal {
 public:
  static const ::echoservice::ResultCode& result(const EchoResponse* msg);
};

const ::echoservice::ResultCode&
EchoResponse::_Internal::result(const EchoResponse* msg) {
  return *msg->result_;
}
EchoResponse::EchoResponse()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echoservice.EchoResponse)
}
EchoResponse::EchoResponse(const EchoResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_text().empty()) {
    text_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
  if (from._internal_has_result()) {
    result_ = new ::echoservice::ResultCode(*from.result_);
  } else {
    result_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:echoservice.EchoResponse)
}

void EchoResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_EchoResponse_echo_2eproto.base);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  result_ = nullptr;
}

EchoResponse::~EchoResponse() {
  // @@protoc_insertion_point(destructor:echoservice.EchoResponse)
  SharedDtor();
}

void EchoResponse::SharedDtor() {
  text_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete result_;
}

void EchoResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EchoResponse& EchoResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_EchoResponse_echo_2eproto.base);
  return *internal_default_instance();
}


void EchoResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:echoservice.EchoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  text_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == nullptr && result_ != nullptr) {
    delete result_;
  }
  result_ = nullptr;
  _internal_metadata_.Clear();
}

const char* EchoResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .echoservice.ResultCode result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_result(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes text = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_text();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EchoResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:echoservice.EchoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .echoservice.ResultCode result = 1;
  if (this->has_result()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::result(this), target, stream);
  }

  // bytes text = 2;
  if (this->text().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_text(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echoservice.EchoResponse)
  return target;
}

size_t EchoResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:echoservice.EchoResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes text = 2;
  if (this->text().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_text());
  }

  // .echoservice.ResultCode result = 1;
  if (this->has_result()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *result_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EchoResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:echoservice.EchoResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const EchoResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EchoResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:echoservice.EchoResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:echoservice.EchoResponse)
    MergeFrom(*source);
  }
}

void EchoResponse::MergeFrom(const EchoResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:echoservice.EchoResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.text().size() > 0) {

    text_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
  if (from.has_result()) {
    _internal_mutable_result()->::echoservice::ResultCode::MergeFrom(from._internal_result());
  }
}

void EchoResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:echoservice.EchoResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoResponse::CopyFrom(const EchoResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:echoservice.EchoResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoResponse::IsInitialized() const {
  return true;
}

void EchoResponse::InternalSwap(EchoResponse* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  text_.Swap(&other->text_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(result_, other->result_);
}

::PROTOBUF_NAMESPACE_ID::Metadata EchoResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

EchoServiceRpc::~EchoServiceRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* EchoServiceRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_echo_2eproto);
  return file_level_service_descriptors_echo_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* EchoServiceRpc::GetDescriptor() {
  return descriptor();
}

void EchoServiceRpc::Echo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::echoservice::EchoRequest*,
                         ::echoservice::EchoResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Echo() not implemented.");
  done->Run();
}

void EchoServiceRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_echo_2eproto[0]);
  switch(method->index()) {
    case 0:
      Echo(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::echoservice::EchoRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::echoservice::EchoResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& EchoServiceRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::echoservice::EchoRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& EchoServiceRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::echoservice::EchoResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

EchoServiceRpc_Stub::EchoServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
EchoServiceRpc_Stub::EchoServiceRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
EchoServiceRpc_Stub::~EchoServiceRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void EchoServiceRpc_Stub::Echo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::echoservice::EchoRequest* request,
                              ::echoservice::EchoResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace echoservice
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::echoservice::ResultCode* Arena::CreateMaybeMessage< ::echoservice::ResultCode >(Arena* arena) {
  return Arena::CreateInternal< ::echoservice::ResultCode >(arena);
}
template<> PROTOBUF_NOINLINE ::echoservice::EchoRequest* Arena::CreateMaybeMessage< ::echoservice::EchoRequest >(Arena* arena) {
  return Arena::CreateInternal< ::echoservice::EchoRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::echoservice::EchoResponse* Arena::CreateMaybeMessage< ::echoservice::EchoResponse >(Arena* arena) {
  return Arena::CreateInternal< ::echoservice::EchoResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

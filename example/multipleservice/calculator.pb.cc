// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: calculator.proto

#include "calculator.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_calculator_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CalculateResultCode_calculator_2eproto;
namespace multipleservice {
class CalculateResultCodeDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CalculateResultCode> _instance;
} _CalculateResultCode_default_instance_;
class CalculateRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CalculateRequest> _instance;
} _CalculateRequest_default_instance_;
class CalculateResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CalculateResponse> _instance;
} _CalculateResponse_default_instance_;
}  // namespace multipleservice
static void InitDefaultsscc_info_CalculateRequest_calculator_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::multipleservice::_CalculateRequest_default_instance_;
    new (ptr) ::multipleservice::CalculateRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::multipleservice::CalculateRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CalculateRequest_calculator_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CalculateRequest_calculator_2eproto}, {}};

static void InitDefaultsscc_info_CalculateResponse_calculator_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::multipleservice::_CalculateResponse_default_instance_;
    new (ptr) ::multipleservice::CalculateResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::multipleservice::CalculateResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_CalculateResponse_calculator_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_CalculateResponse_calculator_2eproto}, {
      &scc_info_CalculateResultCode_calculator_2eproto.base,}};

static void InitDefaultsscc_info_CalculateResultCode_calculator_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::multipleservice::_CalculateResultCode_default_instance_;
    new (ptr) ::multipleservice::CalculateResultCode();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::multipleservice::CalculateResultCode::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CalculateResultCode_calculator_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CalculateResultCode_calculator_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_calculator_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_calculator_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* file_level_service_descriptors_calculator_2eproto[1];

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_calculator_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResultCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResultCode, errcode_),
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResultCode, errmsg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateRequest, a_),
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateRequest, b_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResponse, result_),
  PROTOBUF_FIELD_OFFSET(::multipleservice::CalculateResponse, c_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::multipleservice::CalculateResultCode)},
  { 7, -1, sizeof(::multipleservice::CalculateRequest)},
  { 14, -1, sizeof(::multipleservice::CalculateResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::multipleservice::_CalculateResultCode_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::multipleservice::_CalculateRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::multipleservice::_CalculateResponse_default_instance_),
};

const char descriptor_table_protodef_calculator_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020calculator.proto\022\017multipleservice\"6\n\023C"
  "alculateResultCode\022\017\n\007errcode\030\001 \001(\005\022\016\n\006e"
  "rrmsg\030\002 \001(\014\"(\n\020CalculateRequest\022\t\n\001a\030\001 \001"
  "(\005\022\t\n\001b\030\002 \001(\005\"T\n\021CalculateResponse\0224\n\006re"
  "sult\030\001 \001(\0132$.multipleservice.CalculateRe"
  "sultCode\022\t\n\001c\030\002 \001(\0052\316\002\n\024CalculatorServic"
  "eRpc\022L\n\003Add\022!.multipleservice.CalculateR"
  "equest\032\".multipleservice.CalculateRespon"
  "se\022L\n\003Sub\022!.multipleservice.CalculateReq"
  "uest\032\".multipleservice.CalculateResponse"
  "\022L\n\003Mul\022!.multipleservice.CalculateReque"
  "st\032\".multipleservice.CalculateResponse\022L"
  "\n\003Div\022!.multipleservice.CalculateRequest"
  "\032\".multipleservice.CalculateResponseB\003\200\001"
  "\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_calculator_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_calculator_2eproto_sccs[3] = {
  &scc_info_CalculateRequest_calculator_2eproto.base,
  &scc_info_CalculateResponse_calculator_2eproto.base,
  &scc_info_CalculateResultCode_calculator_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_calculator_2eproto_once;
static bool descriptor_table_calculator_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_calculator_2eproto = {
  &descriptor_table_calculator_2eproto_initialized, descriptor_table_protodef_calculator_2eproto, "calculator.proto", 569,
  &descriptor_table_calculator_2eproto_once, descriptor_table_calculator_2eproto_sccs, descriptor_table_calculator_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_calculator_2eproto::offsets,
  file_level_metadata_calculator_2eproto, 3, file_level_enum_descriptors_calculator_2eproto, file_level_service_descriptors_calculator_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_calculator_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_calculator_2eproto), true);
namespace multipleservice {

// ===================================================================

void CalculateResultCode::InitAsDefaultInstance() {
}
class CalculateResultCode::_Internal {
 public:
};

CalculateResultCode::CalculateResultCode()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:multipleservice.CalculateResultCode)
}
CalculateResultCode::CalculateResultCode(const CalculateResultCode& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_errmsg().empty()) {
    errmsg_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.errmsg_);
  }
  errcode_ = from.errcode_;
  // @@protoc_insertion_point(copy_constructor:multipleservice.CalculateResultCode)
}

void CalculateResultCode::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CalculateResultCode_calculator_2eproto.base);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  errcode_ = 0;
}

CalculateResultCode::~CalculateResultCode() {
  // @@protoc_insertion_point(destructor:multipleservice.CalculateResultCode)
  SharedDtor();
}

void CalculateResultCode::SharedDtor() {
  errmsg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CalculateResultCode::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CalculateResultCode& CalculateResultCode::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CalculateResultCode_calculator_2eproto.base);
  return *internal_default_instance();
}


void CalculateResultCode::Clear() {
// @@protoc_insertion_point(message_clear_start:multipleservice.CalculateResultCode)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errmsg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  errcode_ = 0;
  _internal_metadata_.Clear();
}

const char* CalculateResultCode::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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

::PROTOBUF_NAMESPACE_ID::uint8* CalculateResultCode::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:multipleservice.CalculateResultCode)
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
  // @@protoc_insertion_point(serialize_to_array_end:multipleservice.CalculateResultCode)
  return target;
}

size_t CalculateResultCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:multipleservice.CalculateResultCode)
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

void CalculateResultCode::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:multipleservice.CalculateResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  const CalculateResultCode* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CalculateResultCode>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:multipleservice.CalculateResultCode)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:multipleservice.CalculateResultCode)
    MergeFrom(*source);
  }
}

void CalculateResultCode::MergeFrom(const CalculateResultCode& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:multipleservice.CalculateResultCode)
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

void CalculateResultCode::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:multipleservice.CalculateResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CalculateResultCode::CopyFrom(const CalculateResultCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:multipleservice.CalculateResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CalculateResultCode::IsInitialized() const {
  return true;
}

void CalculateResultCode::InternalSwap(CalculateResultCode* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  errmsg_.Swap(&other->errmsg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(errcode_, other->errcode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CalculateResultCode::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void CalculateRequest::InitAsDefaultInstance() {
}
class CalculateRequest::_Internal {
 public:
};

CalculateRequest::CalculateRequest()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:multipleservice.CalculateRequest)
}
CalculateRequest::CalculateRequest(const CalculateRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&a_, &from.a_,
    static_cast<size_t>(reinterpret_cast<char*>(&b_) -
    reinterpret_cast<char*>(&a_)) + sizeof(b_));
  // @@protoc_insertion_point(copy_constructor:multipleservice.CalculateRequest)
}

void CalculateRequest::SharedCtor() {
  ::memset(&a_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&b_) -
      reinterpret_cast<char*>(&a_)) + sizeof(b_));
}

CalculateRequest::~CalculateRequest() {
  // @@protoc_insertion_point(destructor:multipleservice.CalculateRequest)
  SharedDtor();
}

void CalculateRequest::SharedDtor() {
}

void CalculateRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CalculateRequest& CalculateRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CalculateRequest_calculator_2eproto.base);
  return *internal_default_instance();
}


void CalculateRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:multipleservice.CalculateRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&a_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&b_) -
      reinterpret_cast<char*>(&a_)) + sizeof(b_));
  _internal_metadata_.Clear();
}

const char* CalculateRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 a = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          a_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 b = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          b_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* CalculateRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:multipleservice.CalculateRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 a = 1;
  if (this->a() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_a(), target);
  }

  // int32 b = 2;
  if (this->b() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_b(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:multipleservice.CalculateRequest)
  return target;
}

size_t CalculateRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:multipleservice.CalculateRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 a = 1;
  if (this->a() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_a());
  }

  // int32 b = 2;
  if (this->b() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_b());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CalculateRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:multipleservice.CalculateRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const CalculateRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CalculateRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:multipleservice.CalculateRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:multipleservice.CalculateRequest)
    MergeFrom(*source);
  }
}

void CalculateRequest::MergeFrom(const CalculateRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:multipleservice.CalculateRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.a() != 0) {
    _internal_set_a(from._internal_a());
  }
  if (from.b() != 0) {
    _internal_set_b(from._internal_b());
  }
}

void CalculateRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:multipleservice.CalculateRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CalculateRequest::CopyFrom(const CalculateRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:multipleservice.CalculateRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CalculateRequest::IsInitialized() const {
  return true;
}

void CalculateRequest::InternalSwap(CalculateRequest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(a_, other->a_);
  swap(b_, other->b_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CalculateRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void CalculateResponse::InitAsDefaultInstance() {
  ::multipleservice::_CalculateResponse_default_instance_._instance.get_mutable()->result_ = const_cast< ::multipleservice::CalculateResultCode*>(
      ::multipleservice::CalculateResultCode::internal_default_instance());
}
class CalculateResponse::_Internal {
 public:
  static const ::multipleservice::CalculateResultCode& result(const CalculateResponse* msg);
};

const ::multipleservice::CalculateResultCode&
CalculateResponse::_Internal::result(const CalculateResponse* msg) {
  return *msg->result_;
}
CalculateResponse::CalculateResponse()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:multipleservice.CalculateResponse)
}
CalculateResponse::CalculateResponse(const CalculateResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._internal_has_result()) {
    result_ = new ::multipleservice::CalculateResultCode(*from.result_);
  } else {
    result_ = nullptr;
  }
  c_ = from.c_;
  // @@protoc_insertion_point(copy_constructor:multipleservice.CalculateResponse)
}

void CalculateResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CalculateResponse_calculator_2eproto.base);
  ::memset(&result_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&c_) -
      reinterpret_cast<char*>(&result_)) + sizeof(c_));
}

CalculateResponse::~CalculateResponse() {
  // @@protoc_insertion_point(destructor:multipleservice.CalculateResponse)
  SharedDtor();
}

void CalculateResponse::SharedDtor() {
  if (this != internal_default_instance()) delete result_;
}

void CalculateResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CalculateResponse& CalculateResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CalculateResponse_calculator_2eproto.base);
  return *internal_default_instance();
}


void CalculateResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:multipleservice.CalculateResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == nullptr && result_ != nullptr) {
    delete result_;
  }
  result_ = nullptr;
  c_ = 0;
  _internal_metadata_.Clear();
}

const char* CalculateResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .multipleservice.CalculateResultCode result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_result(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 c = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          c_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* CalculateResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:multipleservice.CalculateResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .multipleservice.CalculateResultCode result = 1;
  if (this->has_result()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::result(this), target, stream);
  }

  // int32 c = 2;
  if (this->c() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_c(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:multipleservice.CalculateResponse)
  return target;
}

size_t CalculateResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:multipleservice.CalculateResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .multipleservice.CalculateResultCode result = 1;
  if (this->has_result()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *result_);
  }

  // int32 c = 2;
  if (this->c() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_c());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CalculateResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:multipleservice.CalculateResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const CalculateResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CalculateResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:multipleservice.CalculateResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:multipleservice.CalculateResponse)
    MergeFrom(*source);
  }
}

void CalculateResponse::MergeFrom(const CalculateResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:multipleservice.CalculateResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_result()) {
    _internal_mutable_result()->::multipleservice::CalculateResultCode::MergeFrom(from._internal_result());
  }
  if (from.c() != 0) {
    _internal_set_c(from._internal_c());
  }
}

void CalculateResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:multipleservice.CalculateResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CalculateResponse::CopyFrom(const CalculateResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:multipleservice.CalculateResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CalculateResponse::IsInitialized() const {
  return true;
}

void CalculateResponse::InternalSwap(CalculateResponse* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(result_, other->result_);
  swap(c_, other->c_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CalculateResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

CalculatorServiceRpc::~CalculatorServiceRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* CalculatorServiceRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_calculator_2eproto);
  return file_level_service_descriptors_calculator_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* CalculatorServiceRpc::GetDescriptor() {
  return descriptor();
}

void CalculatorServiceRpc::Add(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::multipleservice::CalculateRequest*,
                         ::multipleservice::CalculateResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Add() not implemented.");
  done->Run();
}

void CalculatorServiceRpc::Sub(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::multipleservice::CalculateRequest*,
                         ::multipleservice::CalculateResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Sub() not implemented.");
  done->Run();
}

void CalculatorServiceRpc::Mul(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::multipleservice::CalculateRequest*,
                         ::multipleservice::CalculateResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Mul() not implemented.");
  done->Run();
}

void CalculatorServiceRpc::Div(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::multipleservice::CalculateRequest*,
                         ::multipleservice::CalculateResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Div() not implemented.");
  done->Run();
}

void CalculatorServiceRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_calculator_2eproto[0]);
  switch(method->index()) {
    case 0:
      Add(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::multipleservice::CalculateRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::multipleservice::CalculateResponse*>(
                 response),
             done);
      break;
    case 1:
      Sub(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::multipleservice::CalculateRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::multipleservice::CalculateResponse*>(
                 response),
             done);
      break;
    case 2:
      Mul(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::multipleservice::CalculateRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::multipleservice::CalculateResponse*>(
                 response),
             done);
      break;
    case 3:
      Div(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::multipleservice::CalculateRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::multipleservice::CalculateResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& CalculatorServiceRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::multipleservice::CalculateRequest::default_instance();
    case 1:
      return ::multipleservice::CalculateRequest::default_instance();
    case 2:
      return ::multipleservice::CalculateRequest::default_instance();
    case 3:
      return ::multipleservice::CalculateRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& CalculatorServiceRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::multipleservice::CalculateResponse::default_instance();
    case 1:
      return ::multipleservice::CalculateResponse::default_instance();
    case 2:
      return ::multipleservice::CalculateResponse::default_instance();
    case 3:
      return ::multipleservice::CalculateResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

CalculatorServiceRpc_Stub::CalculatorServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
CalculatorServiceRpc_Stub::CalculatorServiceRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
CalculatorServiceRpc_Stub::~CalculatorServiceRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void CalculatorServiceRpc_Stub::Add(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::multipleservice::CalculateRequest* request,
                              ::multipleservice::CalculateResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void CalculatorServiceRpc_Stub::Sub(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::multipleservice::CalculateRequest* request,
                              ::multipleservice::CalculateResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void CalculatorServiceRpc_Stub::Mul(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::multipleservice::CalculateRequest* request,
                              ::multipleservice::CalculateResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}
void CalculatorServiceRpc_Stub::Div(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::multipleservice::CalculateRequest* request,
                              ::multipleservice::CalculateResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(3),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace multipleservice
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::multipleservice::CalculateResultCode* Arena::CreateMaybeMessage< ::multipleservice::CalculateResultCode >(Arena* arena) {
  return Arena::CreateInternal< ::multipleservice::CalculateResultCode >(arena);
}
template<> PROTOBUF_NOINLINE ::multipleservice::CalculateRequest* Arena::CreateMaybeMessage< ::multipleservice::CalculateRequest >(Arena* arena) {
  return Arena::CreateInternal< ::multipleservice::CalculateRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::multipleservice::CalculateResponse* Arena::CreateMaybeMessage< ::multipleservice::CalculateResponse >(Arena* arena) {
  return Arena::CreateInternal< ::multipleservice::CalculateResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

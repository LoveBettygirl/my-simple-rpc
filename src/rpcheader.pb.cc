// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpcheader.proto

#include "rpcheader.pb.h"

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
namespace mysimplerpc {
class RpcHeaderDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RpcHeader> _instance;
} _RpcHeader_default_instance_;
}  // namespace mysimplerpc
static void InitDefaultsscc_info_RpcHeader_rpcheader_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::mysimplerpc::_RpcHeader_default_instance_;
    new (ptr) ::mysimplerpc::RpcHeader();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::mysimplerpc::RpcHeader::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RpcHeader_rpcheader_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RpcHeader_rpcheader_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_rpcheader_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_rpcheader_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_rpcheader_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_rpcheader_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mysimplerpc::RpcHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::mysimplerpc::RpcHeader, servicename_),
  PROTOBUF_FIELD_OFFSET(::mysimplerpc::RpcHeader, methodname_),
  PROTOBUF_FIELD_OFFSET(::mysimplerpc::RpcHeader, argssize_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::mysimplerpc::RpcHeader)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mysimplerpc::_RpcHeader_default_instance_),
};

const char descriptor_table_protodef_rpcheader_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017rpcheader.proto\022\013mysimplerpc\"F\n\tRpcHea"
  "der\022\023\n\013serviceName\030\001 \001(\014\022\022\n\nmethodName\030\002"
  " \001(\014\022\020\n\010argsSize\030\003 \001(\rb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_rpcheader_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_rpcheader_2eproto_sccs[1] = {
  &scc_info_RpcHeader_rpcheader_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_rpcheader_2eproto_once;
static bool descriptor_table_rpcheader_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rpcheader_2eproto = {
  &descriptor_table_rpcheader_2eproto_initialized, descriptor_table_protodef_rpcheader_2eproto, "rpcheader.proto", 110,
  &descriptor_table_rpcheader_2eproto_once, descriptor_table_rpcheader_2eproto_sccs, descriptor_table_rpcheader_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_rpcheader_2eproto::offsets,
  file_level_metadata_rpcheader_2eproto, 1, file_level_enum_descriptors_rpcheader_2eproto, file_level_service_descriptors_rpcheader_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_rpcheader_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_rpcheader_2eproto), true);
namespace mysimplerpc {

// ===================================================================

void RpcHeader::InitAsDefaultInstance() {
}
class RpcHeader::_Internal {
 public:
};

RpcHeader::RpcHeader()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:mysimplerpc.RpcHeader)
}
RpcHeader::RpcHeader(const RpcHeader& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  servicename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_servicename().empty()) {
    servicename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicename_);
  }
  methodname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_methodname().empty()) {
    methodname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.methodname_);
  }
  argssize_ = from.argssize_;
  // @@protoc_insertion_point(copy_constructor:mysimplerpc.RpcHeader)
}

void RpcHeader::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RpcHeader_rpcheader_2eproto.base);
  servicename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  argssize_ = 0u;
}

RpcHeader::~RpcHeader() {
  // @@protoc_insertion_point(destructor:mysimplerpc.RpcHeader)
  SharedDtor();
}

void RpcHeader::SharedDtor() {
  servicename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RpcHeader::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RpcHeader& RpcHeader::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RpcHeader_rpcheader_2eproto.base);
  return *internal_default_instance();
}


void RpcHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:mysimplerpc.RpcHeader)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  servicename_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  methodname_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  argssize_ = 0u;
  _internal_metadata_.Clear();
}

const char* RpcHeader::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes serviceName = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_servicename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes methodName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_methodname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 argsSize = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          argssize_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* RpcHeader::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mysimplerpc.RpcHeader)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes serviceName = 1;
  if (this->servicename().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_servicename(), target);
  }

  // bytes methodName = 2;
  if (this->methodname().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_methodname(), target);
  }

  // uint32 argsSize = 3;
  if (this->argssize() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_argssize(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mysimplerpc.RpcHeader)
  return target;
}

size_t RpcHeader::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mysimplerpc.RpcHeader)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes serviceName = 1;
  if (this->servicename().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_servicename());
  }

  // bytes methodName = 2;
  if (this->methodname().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_methodname());
  }

  // uint32 argsSize = 3;
  if (this->argssize() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_argssize());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RpcHeader::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mysimplerpc.RpcHeader)
  GOOGLE_DCHECK_NE(&from, this);
  const RpcHeader* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RpcHeader>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:mysimplerpc.RpcHeader)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:mysimplerpc.RpcHeader)
    MergeFrom(*source);
  }
}

void RpcHeader::MergeFrom(const RpcHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mysimplerpc.RpcHeader)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.servicename().size() > 0) {

    servicename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicename_);
  }
  if (from.methodname().size() > 0) {

    methodname_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.methodname_);
  }
  if (from.argssize() != 0) {
    _internal_set_argssize(from._internal_argssize());
  }
}

void RpcHeader::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mysimplerpc.RpcHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcHeader::CopyFrom(const RpcHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mysimplerpc.RpcHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcHeader::IsInitialized() const {
  return true;
}

void RpcHeader::InternalSwap(RpcHeader* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  servicename_.Swap(&other->servicename_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  methodname_.Swap(&other->methodname_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(argssize_, other->argssize_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RpcHeader::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace mysimplerpc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mysimplerpc::RpcHeader* Arena::CreateMaybeMessage< ::mysimplerpc::RpcHeader >(Arena* arena) {
  return Arena::CreateInternal< ::mysimplerpc::RpcHeader >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

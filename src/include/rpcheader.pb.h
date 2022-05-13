// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpcheader.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_rpcheader_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_rpcheader_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_rpcheader_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_rpcheader_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rpcheader_2eproto;
namespace mysimplerpc {
class RpcHeader;
class RpcHeaderDefaultTypeInternal;
extern RpcHeaderDefaultTypeInternal _RpcHeader_default_instance_;
}  // namespace mysimplerpc
PROTOBUF_NAMESPACE_OPEN
template<> ::mysimplerpc::RpcHeader* Arena::CreateMaybeMessage<::mysimplerpc::RpcHeader>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mysimplerpc {

// ===================================================================

class RpcHeader :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mysimplerpc.RpcHeader) */ {
 public:
  RpcHeader();
  virtual ~RpcHeader();

  RpcHeader(const RpcHeader& from);
  RpcHeader(RpcHeader&& from) noexcept
    : RpcHeader() {
    *this = ::std::move(from);
  }

  inline RpcHeader& operator=(const RpcHeader& from) {
    CopyFrom(from);
    return *this;
  }
  inline RpcHeader& operator=(RpcHeader&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RpcHeader& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RpcHeader* internal_default_instance() {
    return reinterpret_cast<const RpcHeader*>(
               &_RpcHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RpcHeader& a, RpcHeader& b) {
    a.Swap(&b);
  }
  inline void Swap(RpcHeader* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RpcHeader* New() const final {
    return CreateMaybeMessage<RpcHeader>(nullptr);
  }

  RpcHeader* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RpcHeader>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RpcHeader& from);
  void MergeFrom(const RpcHeader& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RpcHeader* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mysimplerpc.RpcHeader";
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
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_rpcheader_2eproto);
    return ::descriptor_table_rpcheader_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kServiceNameFieldNumber = 1,
    kMethodNameFieldNumber = 2,
    kArgsSizeFieldNumber = 3,
  };
  // bytes serviceName = 1;
  void clear_servicename();
  const std::string& servicename() const;
  void set_servicename(const std::string& value);
  void set_servicename(std::string&& value);
  void set_servicename(const char* value);
  void set_servicename(const void* value, size_t size);
  std::string* mutable_servicename();
  std::string* release_servicename();
  void set_allocated_servicename(std::string* servicename);
  private:
  const std::string& _internal_servicename() const;
  void _internal_set_servicename(const std::string& value);
  std::string* _internal_mutable_servicename();
  public:

  // bytes methodName = 2;
  void clear_methodname();
  const std::string& methodname() const;
  void set_methodname(const std::string& value);
  void set_methodname(std::string&& value);
  void set_methodname(const char* value);
  void set_methodname(const void* value, size_t size);
  std::string* mutable_methodname();
  std::string* release_methodname();
  void set_allocated_methodname(std::string* methodname);
  private:
  const std::string& _internal_methodname() const;
  void _internal_set_methodname(const std::string& value);
  std::string* _internal_mutable_methodname();
  public:

  // uint32 argsSize = 3;
  void clear_argssize();
  ::PROTOBUF_NAMESPACE_ID::uint32 argssize() const;
  void set_argssize(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_argssize() const;
  void _internal_set_argssize(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:mysimplerpc.RpcHeader)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr servicename_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr methodname_;
  ::PROTOBUF_NAMESPACE_ID::uint32 argssize_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_rpcheader_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RpcHeader

// bytes serviceName = 1;
inline void RpcHeader::clear_servicename() {
  servicename_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RpcHeader::servicename() const {
  // @@protoc_insertion_point(field_get:mysimplerpc.RpcHeader.serviceName)
  return _internal_servicename();
}
inline void RpcHeader::set_servicename(const std::string& value) {
  _internal_set_servicename(value);
  // @@protoc_insertion_point(field_set:mysimplerpc.RpcHeader.serviceName)
}
inline std::string* RpcHeader::mutable_servicename() {
  // @@protoc_insertion_point(field_mutable:mysimplerpc.RpcHeader.serviceName)
  return _internal_mutable_servicename();
}
inline const std::string& RpcHeader::_internal_servicename() const {
  return servicename_.GetNoArena();
}
inline void RpcHeader::_internal_set_servicename(const std::string& value) {
  
  servicename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void RpcHeader::set_servicename(std::string&& value) {
  
  servicename_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mysimplerpc.RpcHeader.serviceName)
}
inline void RpcHeader::set_servicename(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  servicename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mysimplerpc.RpcHeader.serviceName)
}
inline void RpcHeader::set_servicename(const void* value, size_t size) {
  
  servicename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mysimplerpc.RpcHeader.serviceName)
}
inline std::string* RpcHeader::_internal_mutable_servicename() {
  
  return servicename_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RpcHeader::release_servicename() {
  // @@protoc_insertion_point(field_release:mysimplerpc.RpcHeader.serviceName)
  
  return servicename_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RpcHeader::set_allocated_servicename(std::string* servicename) {
  if (servicename != nullptr) {
    
  } else {
    
  }
  servicename_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), servicename);
  // @@protoc_insertion_point(field_set_allocated:mysimplerpc.RpcHeader.serviceName)
}

// bytes methodName = 2;
inline void RpcHeader::clear_methodname() {
  methodname_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RpcHeader::methodname() const {
  // @@protoc_insertion_point(field_get:mysimplerpc.RpcHeader.methodName)
  return _internal_methodname();
}
inline void RpcHeader::set_methodname(const std::string& value) {
  _internal_set_methodname(value);
  // @@protoc_insertion_point(field_set:mysimplerpc.RpcHeader.methodName)
}
inline std::string* RpcHeader::mutable_methodname() {
  // @@protoc_insertion_point(field_mutable:mysimplerpc.RpcHeader.methodName)
  return _internal_mutable_methodname();
}
inline const std::string& RpcHeader::_internal_methodname() const {
  return methodname_.GetNoArena();
}
inline void RpcHeader::_internal_set_methodname(const std::string& value) {
  
  methodname_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void RpcHeader::set_methodname(std::string&& value) {
  
  methodname_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mysimplerpc.RpcHeader.methodName)
}
inline void RpcHeader::set_methodname(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  methodname_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mysimplerpc.RpcHeader.methodName)
}
inline void RpcHeader::set_methodname(const void* value, size_t size) {
  
  methodname_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mysimplerpc.RpcHeader.methodName)
}
inline std::string* RpcHeader::_internal_mutable_methodname() {
  
  return methodname_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RpcHeader::release_methodname() {
  // @@protoc_insertion_point(field_release:mysimplerpc.RpcHeader.methodName)
  
  return methodname_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RpcHeader::set_allocated_methodname(std::string* methodname) {
  if (methodname != nullptr) {
    
  } else {
    
  }
  methodname_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), methodname);
  // @@protoc_insertion_point(field_set_allocated:mysimplerpc.RpcHeader.methodName)
}

// uint32 argsSize = 3;
inline void RpcHeader::clear_argssize() {
  argssize_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 RpcHeader::_internal_argssize() const {
  return argssize_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 RpcHeader::argssize() const {
  // @@protoc_insertion_point(field_get:mysimplerpc.RpcHeader.argsSize)
  return _internal_argssize();
}
inline void RpcHeader::_internal_set_argssize(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  argssize_ = value;
}
inline void RpcHeader::set_argssize(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_argssize(value);
  // @@protoc_insertion_point(field_set:mysimplerpc.RpcHeader.argsSize)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace mysimplerpc

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_rpcheader_2eproto

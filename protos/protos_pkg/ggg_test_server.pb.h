// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ggg_test_server.proto
// Protobuf C++ Version: 4.24.0-main

#ifndef GOOGLE_PROTOBUF_INCLUDED_ggg_5ftest_5fserver_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ggg_5ftest_5fserver_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4024000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4024000 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ggg_5ftest_5fserver_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_ggg_5ftest_5fserver_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_ggg_5ftest_5fserver_2eproto;
namespace ggg_test_server {
class TestReq;
struct TestReqDefaultTypeInternal;
extern TestReqDefaultTypeInternal _TestReq_default_instance_;
class TestRsp;
struct TestRspDefaultTypeInternal;
extern TestRspDefaultTypeInternal _TestRsp_default_instance_;
}  // namespace ggg_test_server
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace ggg_test_server {

// ===================================================================


// -------------------------------------------------------------------

class TestRsp final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ggg_test_server.TestRsp) */ {
 public:
  inline TestRsp() : TestRsp(nullptr) {}
  ~TestRsp() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR TestRsp(::google::protobuf::internal::ConstantInitialized);

  inline TestRsp(const TestRsp& from)
      : TestRsp(nullptr, from) {}
  TestRsp(TestRsp&& from) noexcept
    : TestRsp() {
    *this = ::std::move(from);
  }

  inline TestRsp& operator=(const TestRsp& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestRsp& operator=(TestRsp&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TestRsp& default_instance() {
    return *internal_default_instance();
  }
  static inline const TestRsp* internal_default_instance() {
    return reinterpret_cast<const TestRsp*>(
               &_TestRsp_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TestRsp& a, TestRsp& b) {
    a.Swap(&b);
  }
  inline void Swap(TestRsp* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestRsp* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TestRsp* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TestRsp>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TestRsp& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const TestRsp& from) {
    TestRsp::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(TestRsp* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "ggg_test_server.TestRsp";
  }
  protected:
  explicit TestRsp(::google::protobuf::Arena* arena);
  TestRsp(::google::protobuf::Arena* arena, const TestRsp& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUidFieldNumber = 1,
    kMessageFieldNumber = 2,
  };
  // string uid = 1;
  void clear_uid() ;
  const std::string& uid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_uid(Arg_&& arg, Args_... args);
  std::string* mutable_uid();
  PROTOBUF_NODISCARD std::string* release_uid();
  void set_allocated_uid(std::string* value);

  private:
  const std::string& _internal_uid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uid(
      const std::string& value);
  std::string* _internal_mutable_uid();

  public:
  // string message = 2;
  void clear_message() ;
  const std::string& message() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_message(Arg_&& arg, Args_... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* value);

  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(
      const std::string& value);
  std::string* _internal_mutable_message();

  public:
  // @@protoc_insertion_point(class_scope:ggg_test_server.TestRsp)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      42, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr uid_;
    ::google::protobuf::internal::ArenaStringPtr message_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ggg_5ftest_5fserver_2eproto;
};// -------------------------------------------------------------------

class TestReq final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ggg_test_server.TestReq) */ {
 public:
  inline TestReq() : TestReq(nullptr) {}
  ~TestReq() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR TestReq(::google::protobuf::internal::ConstantInitialized);

  inline TestReq(const TestReq& from)
      : TestReq(nullptr, from) {}
  TestReq(TestReq&& from) noexcept
    : TestReq() {
    *this = ::std::move(from);
  }

  inline TestReq& operator=(const TestReq& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestReq& operator=(TestReq&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TestReq& default_instance() {
    return *internal_default_instance();
  }
  static inline const TestReq* internal_default_instance() {
    return reinterpret_cast<const TestReq*>(
               &_TestReq_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TestReq& a, TestReq& b) {
    a.Swap(&b);
  }
  inline void Swap(TestReq* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestReq* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TestReq* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TestReq>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TestReq& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const TestReq& from) {
    TestReq::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(TestReq* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "ggg_test_server.TestReq";
  }
  protected:
  explicit TestReq(::google::protobuf::Arena* arena);
  TestReq(::google::protobuf::Arena* arena, const TestReq& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUidFieldNumber = 1,
    kTidFieldNumber = 2,
  };
  // string uid = 1;
  void clear_uid() ;
  const std::string& uid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_uid(Arg_&& arg, Args_... args);
  std::string* mutable_uid();
  PROTOBUF_NODISCARD std::string* release_uid();
  void set_allocated_uid(std::string* value);

  private:
  const std::string& _internal_uid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uid(
      const std::string& value);
  std::string* _internal_mutable_uid();

  public:
  // string tid = 2;
  void clear_tid() ;
  const std::string& tid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_tid(Arg_&& arg, Args_... args);
  std::string* mutable_tid();
  PROTOBUF_NODISCARD std::string* release_tid();
  void set_allocated_tid(std::string* value);

  private:
  const std::string& _internal_tid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_tid(
      const std::string& value);
  std::string* _internal_mutable_tid();

  public:
  // @@protoc_insertion_point(class_scope:ggg_test_server.TestReq)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      38, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr uid_;
    ::google::protobuf::internal::ArenaStringPtr tid_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ggg_5ftest_5fserver_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TestReq

// string uid = 1;
inline void TestReq::clear_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.uid_.ClearToEmpty();
}
inline const std::string& TestReq::uid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:ggg_test_server.TestReq.uid)
  return _internal_uid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void TestReq::set_uid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.uid_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:ggg_test_server.TestReq.uid)
}
inline std::string* TestReq::mutable_uid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_uid();
  // @@protoc_insertion_point(field_mutable:ggg_test_server.TestReq.uid)
  return _s;
}
inline const std::string& TestReq::_internal_uid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.uid_.Get();
}
inline void TestReq::_internal_set_uid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.uid_.Set(value, GetArena());
}
inline std::string* TestReq::_internal_mutable_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.uid_.Mutable( GetArena());
}
inline std::string* TestReq::release_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:ggg_test_server.TestReq.uid)
  return _impl_.uid_.Release();
}
inline void TestReq::set_allocated_uid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.uid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.uid_.IsDefault()) {
          _impl_.uid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ggg_test_server.TestReq.uid)
}

// string tid = 2;
inline void TestReq::clear_tid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.tid_.ClearToEmpty();
}
inline const std::string& TestReq::tid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:ggg_test_server.TestReq.tid)
  return _internal_tid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void TestReq::set_tid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.tid_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:ggg_test_server.TestReq.tid)
}
inline std::string* TestReq::mutable_tid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_tid();
  // @@protoc_insertion_point(field_mutable:ggg_test_server.TestReq.tid)
  return _s;
}
inline const std::string& TestReq::_internal_tid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.tid_.Get();
}
inline void TestReq::_internal_set_tid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.tid_.Set(value, GetArena());
}
inline std::string* TestReq::_internal_mutable_tid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.tid_.Mutable( GetArena());
}
inline std::string* TestReq::release_tid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:ggg_test_server.TestReq.tid)
  return _impl_.tid_.Release();
}
inline void TestReq::set_allocated_tid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.tid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.tid_.IsDefault()) {
          _impl_.tid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ggg_test_server.TestReq.tid)
}

// -------------------------------------------------------------------

// TestRsp

// string uid = 1;
inline void TestRsp::clear_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.uid_.ClearToEmpty();
}
inline const std::string& TestRsp::uid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:ggg_test_server.TestRsp.uid)
  return _internal_uid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void TestRsp::set_uid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.uid_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:ggg_test_server.TestRsp.uid)
}
inline std::string* TestRsp::mutable_uid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_uid();
  // @@protoc_insertion_point(field_mutable:ggg_test_server.TestRsp.uid)
  return _s;
}
inline const std::string& TestRsp::_internal_uid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.uid_.Get();
}
inline void TestRsp::_internal_set_uid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.uid_.Set(value, GetArena());
}
inline std::string* TestRsp::_internal_mutable_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.uid_.Mutable( GetArena());
}
inline std::string* TestRsp::release_uid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:ggg_test_server.TestRsp.uid)
  return _impl_.uid_.Release();
}
inline void TestRsp::set_allocated_uid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.uid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.uid_.IsDefault()) {
          _impl_.uid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ggg_test_server.TestRsp.uid)
}

// string message = 2;
inline void TestRsp::clear_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.message_.ClearToEmpty();
}
inline const std::string& TestRsp::message() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:ggg_test_server.TestRsp.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void TestRsp::set_message(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:ggg_test_server.TestRsp.message)
}
inline std::string* TestRsp::mutable_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:ggg_test_server.TestRsp.message)
  return _s;
}
inline const std::string& TestRsp::_internal_message() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.message_.Get();
}
inline void TestRsp::_internal_set_message(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.message_.Set(value, GetArena());
}
inline std::string* TestRsp::_internal_mutable_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  return _impl_.message_.Mutable( GetArena());
}
inline std::string* TestRsp::release_message() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:ggg_test_server.TestRsp.message)
  return _impl_.message_.Release();
}
inline void TestRsp::set_allocated_message(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.message_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ggg_test_server.TestRsp.message)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace ggg_test_server


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ggg_5ftest_5fserver_2eproto_2epb_2eh

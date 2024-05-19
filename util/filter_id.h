// copyright skylanwei 2024-05-19

#ifndef TRPC_COMMON_UTIL_FILTER_ID_H_
#define TRPC_COMMON_UTIL_FILTER_ID_H_

namespace trpc {
namespace app {

// note: filter id must no more than 65535
enum class FilterId {
  TRACE_ID_FILTER =  1000,

};

}
}



#endif // TRPC_COMMON_UTIL_FILTER_ID_H_

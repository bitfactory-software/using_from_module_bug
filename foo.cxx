module;

#include <typeinfo>

export module foo;

export {

namespace library_namespace {

template <typename R, typename... ARGS>
class declare;
template <typename R, typename... ARGS>
class declare<R(ARGS...)> {};

 template <template <typename SIG> typename
 Method > using typedef_bound_methodtype_from_module =  
     Method<void const* (void const*, const std::type_info& to)>;

}

}

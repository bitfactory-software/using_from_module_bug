#include <iostream>
#include <typeinfo>

import foo;

using namespace library_namespace;

 template <template <typename SIG> typename
 Method > using typedef_bound_methodtype_from_main =  
     Method<void const* (void const*, const std::type_info& to)>;

int main()
{    
    std::cout << "OK: " << typeid(typedef_bound_methodtype_from_main<declare>).name() << std::endl;
    std::cout << "ERROR:" << typeid(typedef_bound_methodtype_from_module<declare>).name() << std::endl;
    return 0;
}
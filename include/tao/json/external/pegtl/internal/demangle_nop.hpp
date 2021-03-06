// Copyright (c) 2014-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_JSON_PEGTL_INCLUDE_INTERNAL_DEMANGLE_NOP_HPP
#define TAOCPP_JSON_PEGTL_INCLUDE_INTERNAL_DEMANGLE_NOP_HPP

#include <string>

#include "../config.hpp"

namespace tao
{
   namespace TAOCPP_JSON_PEGTL_NAMESPACE
   {
      namespace internal
      {
         inline std::string demangle( const char* symbol )
         {
            return symbol;
         }

      }  // namespace internal

   }  // namespace TAOCPP_JSON_PEGTL_NAMESPACE

}  // namespace tao

#endif

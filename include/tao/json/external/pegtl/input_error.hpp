// Copyright (c) 2014-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_JSON_PEGTL_INCLUDE_INPUT_ERROR_HPP
#define TAOCPP_JSON_PEGTL_INCLUDE_INPUT_ERROR_HPP

#include <cerrno>
#include <sstream>
#include <stdexcept>

#include "config.hpp"

namespace tao
{
   namespace TAOCPP_JSON_PEGTL_NAMESPACE
   {
      struct input_error
         : std::runtime_error
      {
         input_error( const std::string& message, const int in_errorno )
            : std::runtime_error( message ),
              errorno( in_errorno )
         {
         }

         int errorno;
      };

   }  // namespace TAOCPP_JSON_PEGTL_NAMESPACE

}  // namespace tao

#define TAOCPP_JSON_PEGTL_UNWRAP( ... ) __VA_ARGS__

#define TAOCPP_JSON_PEGTL_THROW_INPUT_ERROR( MESSAGE )                                 \
   do {                                                                           \
      const int errorno = errno;                                                  \
      std::ostringstream oss;                                                     \
      oss << "pegtl: " << TAOCPP_JSON_PEGTL_UNWRAP( MESSAGE ) << " errno " << errorno; \
      throw tao::TAOCPP_JSON_PEGTL_NAMESPACE::input_error( oss.str(), errorno );       \
   } while( false )

#endif

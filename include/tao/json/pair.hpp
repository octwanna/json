// Copyright (c) 2016-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_PAIR_HPP
#define TAOCPP_JSON_INCLUDE_PAIR_HPP

#include <string>
#include <type_traits>
#include <utility>

namespace tao
{
   namespace json
   {
      template< template< typename... > class Traits >
      class basic_value;

      template< template< typename... > class Traits >
      struct pair
      {
         mutable std::string key;
         mutable basic_value< Traits > value;

         template< typename U >
         pair( U&& v )
            : key( Traits< typename std::decay< U >::type >::default_key ),
              value( std::forward< U >( v ) )
         {
         }

         template< typename U >
         pair( U&& k, basic_value< Traits >&& v )
            : key( std::forward< U >( k ) ), value( std::move( v ) )
         {
         }

         template< typename U >
         pair( U&& k, const basic_value< Traits >& v )
            : key( std::forward< U >( k ) ), value( v )
         {
         }
      };

   }  // namespace json

}  // namespace tao

#endif

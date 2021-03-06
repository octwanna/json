// Copyright (c) 2017-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_EVENTS_JAXN_TO_STREAM_HPP
#define TAOCPP_JSON_INCLUDE_EVENTS_JAXN_TO_STREAM_HPP

#include "../../internal/hexdump.hpp"
#include "../../jaxn/is_identifier.hpp"
#include "../to_stream.hpp"

namespace tao
{
   namespace json
   {
      namespace events
      {
         namespace jaxn
         {
            // Events consumer to build a JAXN string representation.

            struct to_stream : events::to_stream
            {
               using events::to_stream::to_stream;

               using events::to_stream::number;

               void number( const double v )
               {
                  next();
                  if( !std::isfinite( v ) ) {
                     if( std::isnan( v ) ) {
                        os << "NaN";
                     }
                     else if( v < 0 ) {
                        os << "-Infinity";
                     }
                     else {
                        os << "Infinity";
                     }
                  }
                  else {
                     json_double_conversion::Dtostr( os, v );
                  }
               }

               void key( const tao::string_view v )
               {
                  if( json::jaxn::is_identifier( v ) ) {
                     next();
                     os.write( v.data(), v.size() );
                  }
                  else {
                     string( v );
                  }
                  os.put( ':' );
                  first = true;
               }

               void binary( const tao::byte_view v )
               {
                  next();
                  os.put( '$' );
                  internal::hexdump( os, v );
               }
            };

         }  // namespace jaxn

      }  // namespace events

   }  // namespace json

}  // namespace tao

#endif

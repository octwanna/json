// Copyright (c) 2014-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_JSON_PEGTL_INCLUDE_ANALYSIS_RULE_INFO_HPP
#define TAOCPP_JSON_PEGTL_INCLUDE_ANALYSIS_RULE_INFO_HPP

#include <string>
#include <vector>

#include "../config.hpp"

#include "rule_type.hpp"

namespace tao
{
   namespace TAOCPP_JSON_PEGTL_NAMESPACE
   {
      namespace analysis
      {
         struct rule_info
         {
            explicit rule_info( const rule_type in_type ) noexcept
               : type( in_type )
            {
            }

            rule_type type;
            std::vector< std::string > rules;
         };

      }  // namespace analysis

   }  // namespace TAOCPP_JSON_PEGTL_NAMESPACE

}  // namespace tao

#endif

//
// proxy.h:  proxies
//
// Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp11.
//
// Rcpp11 is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp11 is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp11.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp__vector__forward_proxy_h
#define Rcpp__vector__forward_proxy_h

namespace internal{
	template <int RTYPE> class string_proxy ;
	template <int RTYPE> class generic_proxy ;
	template <int RTYPE> class simple_name_proxy ; 
	template <int RTYPE> class string_name_proxy ;
	template <int RTYPE> class generic_name_proxy ;
}

namespace traits {
    template <int RTYPE> struct r_vector_cache_type ;
	template <int RTYPE> class r_vector_cache ;
	
	template <int RTYPE> struct r_vector_name_proxy ;
	template <int RTYPE> struct r_vector_proxy ;
	template <int RTYPE> struct r_vector_const_proxy ;
	
	template <int RTYPE> struct r_vector_iterator ;
	template <int RTYPE> struct r_vector_const_iterator ;
	
}


#endif
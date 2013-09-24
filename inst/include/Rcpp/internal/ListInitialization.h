// ListInitialization.h:  
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__internal__ListInitialization__h
#define Rcpp__internal__ListInitialization__h

namespace Rcpp{
namespace internal{
	
template <typename iterator, typename value_type> class ListInitialization {
public:
	ListInitialization( iterator iter_ ) : iter(iter_) {} ;
	ListInitialization<iterator,value_type> operator,( value_type x ){
		*iter = x ;
		return ListInitialization<iterator,value_type>( iter + 1 );
	}
	
private:	
	iterator iter ;
} ;

} // internal
} // Rcpp

#endif
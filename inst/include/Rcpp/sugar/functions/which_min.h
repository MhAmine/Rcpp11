#ifndef Rcpp__sugar__which_min_h
#define Rcpp__sugar__which_min_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool NA, typename T>
class WhichMin {
public:
    typedef typename Rcpp::SugarVectorExpression<RTYPE,NA,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    WhichMin(const VEC_TYPE& obj_ ) : obj(obj_){}

    int get() const {
        STORAGE current = obj[0] ;
        STORAGE min = current ;
        R_xlen_t index = 0 ;
        if( Rcpp::traits::is_na<RTYPE>(current) ) return NA_INTEGER ;
        R_xlen_t n = obj.size() ;
        for( R_xlen_t i=1; i<n; i++){
            current = obj[i] ;
            if( Rcpp::traits::is_na<RTYPE>(current) ) return NA_INTEGER ;
            if( current < min ){
                min = current ;
                index = i ;
            }
        }
        return index ;
    }

private:
    const VEC_TYPE& obj ;

} ;
   
template <int RTYPE, typename T>
class WhichMin<RTYPE,false,T> {
public:
    typedef typename Rcpp::SugarVectorExpression<RTYPE,false,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    WhichMin(const VEC_TYPE& obj_ ) : obj(obj_){}

    int get() const {
        STORAGE current = obj[0] ;
        STORAGE min = current ;
        R_xlen_t index = 0 ;
        R_xlen_t n = obj.size() ;
        for( R_xlen_t i=1; i<n; i++){
            current = obj[i] ;
            if( current < min ){
                min = current ;
                index = i ;
            }
        }
        return index ;
    }

private:
    const VEC_TYPE& obj ;

} ;

    
} // sugar



template <int RTYPE, bool NA, typename T>
int which_min( const SugarVectorExpression<RTYPE,NA,T>& t ){
    return sugar::WhichMin<RTYPE,NA,T>(t).get() ; 
}
  
} // Rcpp
#endif

